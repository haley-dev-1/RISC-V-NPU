// fsm.v
// -----------------------------------------------------------------------------
// Accelerator Controller / FSM (MVP - Phase 1)
//
// What this module does:
//   - Sequences accelerator phases (NOT streaming element-by-element):
//       1) Input DMA:  System RAM -> Input SRAM (scratchpad)
//       2) Systolic:   clear accumulators -> start compute -> wait done
//       3) Output DMA: Output SRAM -> System RAM
//   - Exposes simple status to CPU via MMIO regfile (busy/done/error/errcode)
//
// Key clarifications (architecture contract):
//   - CPU writes MMIO registers using normal RISC-V stores (SW). No CPU RTL changes.
//   - The MMIO register file (mmio_rf) is CPU-visible and holds config inputs to this FSM.
//   - DMA "registers/state" (latched addr/len, counters, busy/done) live INSIDE each DMA engine.
//     This FSM does NOT read DMA internal registers. It only sees DMA status wires (busy/done/error).
//   - There is NO separate "DMA control/config registers" module in MVP. The DMA engine internally
//     latches the job parameters provided on dma_start.
//
// Compute assumptions (MVP):
//   - Fixed 4x4 systolic array (wavefront). Signed MAC behavior.
//   - Accumulator is signed 32-bit inside systolic array (FSM ensures sa_clear before sa_start).
//   - DMA is 1D contiguous copy per phase (no striding/tiling/double-buffering in MVP).
//
// IRQ policy (MVP):
//   - IRQ is intentionally unused to avoid integration complexity across a multi-person team.
//   - irq is tied LOW in this module.
//   - TODO (Phase 2): connect irq to CPU interrupt line using sts_done/irq_enable for better CPU-side
//     latency/power (PPA gains are CPU-side; accelerator datapath unaffected).
//
// Upstream dependencies (who drives this FSM):
//   - mmio_rf.v (CPU-visible register file) provides cfg_* signals
//   - SoC interconnect routes CPU MMIO writes/reads to mmio_rf
//
// Downstream dependencies (this FSM drives):
//   - input_dma.v  : System RAM -> Input SRAM
//   - output_dma.v : Output SRAM -> System RAM
//   - systolic_4x4.v : compute (signed MAC)
//
// -----------------------------------------------------------------------------

`timescale 1ns/1ps

module fsm #(
  parameter bit USE_DMA = 1'b1
) (
  input  logic        clk,
  input  logic        rst_n,

  // ----------------------------
  // Config inputs from MMIO RF (latched by mmio_rf; written by CPU)
  // ----------------------------
  input  logic        cfg_start,       // CPU "command": start job (level or pulse)
  input  logic        cfg_clr_status,  // CPU clears sticky done/error
  input  logic        cfg_irq_en,      // kept for Phase 2 (unused in MVP)

  input  logic [31:0] cfg_src_addr,    // system memory base (input)
  input  logic [31:0] cfg_dst_addr,    // system memory base (output)
  input  logic [31:0] cfg_len_bytes,   // bytes to transfer (MVP: same for in/out)

  input  logic [31:0] cfg_spad_a_base, // Input SRAM base for A (or packed input)
  input  logic [31:0] cfg_spad_b_base, // Input SRAM base for B (unused in MVP if packed)
  input  logic [31:0] cfg_spad_c_base, // Output SRAM base for C

  // optional dims kept for future; MVP can ignore or validate nonzero
  input  logic [15:0] cfg_m,
  input  logic [15:0] cfg_n,
  input  logic [15:0] cfg_k,

  // ----------------------------
  // Status outputs back to MMIO RF / CPU polling
  // ----------------------------
  output logic        sts_busy,
  output logic        sts_done,      // sticky until cfg_clr_status
  output logic        sts_error,     // sticky until cfg_clr_status
  output logic [7:0]  sts_errcode,
  output logic        irq,           // MVP: tied low

  // ----------------------------
  // Input DMA control (System RAM -> Input SRAM)
  // ----------------------------
  output logic        in_dma_start,
  output logic [31:0] in_dma_sys_addr,
  output logic [31:0] in_dma_spad_addr,
  output logic [31:0] in_dma_len_bytes,
  input  logic        in_dma_busy,
  input  logic        in_dma_done,
  input  logic        in_dma_error,

  // ----------------------------
  // Output DMA control (Output SRAM -> System RAM)
  // ----------------------------
  output logic        out_dma_start,
  output logic [31:0] out_dma_sys_addr,
  output logic [31:0] out_dma_spad_addr,
  output logic [31:0] out_dma_len_bytes,
  input  logic        out_dma_busy,
  input  logic        out_dma_done,
  input  logic        out_dma_error,

  // ----------------------------
  // Systolic array control (fixed 4x4, signed MAC)
  // ----------------------------
  output logic        sa_clear,        // pulse to clear signed accumulators
  output logic        sa_start,        // pulse to start compute
  output logic [31:0] sa_spad_a_base,
  output logic [31:0] sa_spad_b_base,
  output logic [31:0] sa_spad_c_base,
  input  logic        sa_busy,
  input  logic        sa_done,
  input  logic        sa_error
);

  // ---------------------------------------------------------------------------
  // IRQ is unused in MVP: tie low to avoid integration complexity.
  // TODO (Phase 2): irq = cfg_irq_en & sts_done (and wire to CPU interrupt line).
  // ---------------------------------------------------------------------------
  assign irq = 1'b0;

  // ---------------------------------------------------------------------------
  // Start consumption helper: allows cfg_start to be level-based without re-trigger.
  // CPU SW can either pulse START or set START then clear it later.
  // ---------------------------------------------------------------------------
  logic start_seen;

  // ---------------------------------------------------------------------------
  // FSM states
  // ---------------------------------------------------------------------------
  typedef enum logic [3:0] {
    S_IDLE         = 4'd0,
    S_VALIDATE     = 4'd1,

    S_IN_DMA_KICK  = 4'd2,
    S_IN_DMA_WAIT  = 4'd3,

    S_SA_CLEAR     = 4'd4,
    S_SA_START     = 4'd5,
    S_SA_WAIT      = 4'd6,

    S_OUT_DMA_KICK = 4'd7,
    S_OUT_DMA_WAIT = 4'd8,

    S_DONE         = 4'd9,
    S_ERROR        = 4'd10
  } state_t;

  state_t state, state_n;

  // ---------------------------------------------------------------------------
  // Combinational defaults
  // ---------------------------------------------------------------------------
  always_comb begin
    // defaults
    state_n         = state;

    in_dma_start    = 1'b0;
    in_dma_sys_addr = 32'd0;
    in_dma_spad_addr= 32'd0;
    in_dma_len_bytes= 32'd0;

    out_dma_start    = 1'b0;
    out_dma_sys_addr = 32'd0;
    out_dma_spad_addr= 32'd0;
    out_dma_len_bytes= 32'd0;

    sa_clear        = 1'b0;
    sa_start        = 1'b0;
    sa_spad_a_base  = cfg_spad_a_base;
    sa_spad_b_base  = cfg_spad_b_base;
    sa_spad_c_base  = cfg_spad_c_base;

    // busy is true in active states (not idle, not terminal)
    sts_busy        = (state != S_IDLE) && (state != S_DONE) && (state != S_ERROR);

    unique case (state)
      S_IDLE: begin
        if (cfg_start && !start_seen) begin
          state_n = S_VALIDATE;
        end
      end

      S_VALIDATE: begin
        // MVP validation kept minimal to reduce failure modes.
        // You can tighten constraints later (alignment, bounds, etc.).
        if (cfg_len_bytes == 32'd0) begin
          state_n = S_ERROR;
        end else begin
          if (USE_DMA) state_n = S_IN_DMA_KICK;
          else         state_n = S_SA_CLEAR;
        end
      end

      // -----------------------
      // Input DMA: System -> SRAM
      // -----------------------
      S_IN_DMA_KICK: begin
        // MVP: treat cfg_src_addr as base of packed input; load into spad_a_base.
        // If later you split A and B into separate DMAs, keep ports and add sequencing.
        in_dma_start     = 1'b1;             // one-cycle pulse
        in_dma_sys_addr  = cfg_src_addr;
        in_dma_spad_addr = cfg_spad_a_base;
        in_dma_len_bytes = cfg_len_bytes;
        state_n          = S_IN_DMA_WAIT;
      end

      S_IN_DMA_WAIT: begin
        if (in_dma_error) begin
          state_n = S_ERROR;
        end else if (in_dma_done) begin
          state_n = S_SA_CLEAR;
        end
      end

      // -----------------------
      // Systolic compute
      // -----------------------
      S_SA_CLEAR: begin
        // IMPORTANT for signed 32-bit MAC accumulation:
        // Clear accumulators before starting compute.
        sa_clear = 1'b1; // pulse
        state_n  = S_SA_START;
      end

      S_SA_START: begin
        sa_start = 1'b1; // pulse
        state_n  = S_SA_WAIT;
      end

      S_SA_WAIT: begin
        if (sa_error) begin
          state_n = S_ERROR;
        end else if (sa_done) begin
          if (USE_DMA) state_n = S_OUT_DMA_KICK;
          else         state_n = S_DONE;
        end
      end

      // -----------------------
      // Output DMA: SRAM -> System
      // -----------------------
      S_OUT_DMA_KICK: begin
        out_dma_start     = 1'b1;            // one-cycle pulse
        out_dma_sys_addr  = cfg_dst_addr;
        out_dma_spad_addr = cfg_spad_c_base;
        out_dma_len_bytes = cfg_len_bytes;
        state_n           = S_OUT_DMA_WAIT;
      end

      S_OUT_DMA_WAIT: begin
        if (out_dma_error) begin
          state_n = S_ERROR;
        end else if (out_dma_done) begin
          state_n = S_DONE;
        end
      end

      // -----------------------
      // Terminal
      // -----------------------
      S_DONE: begin
        if (cfg_clr_status) state_n = S_IDLE;
      end

      S_ERROR: begin
        if (cfg_clr_status) state_n = S_IDLE;
      end

      default: begin
        state_n = S_IDLE;
      end
    endcase
  end

  // ---------------------------------------------------------------------------
  // Sequential: state + sticky status
  // ---------------------------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      state       <= S_IDLE;
      sts_done    <= 1'b0;
      sts_error   <= 1'b0;
      sts_errcode <= 8'd0;
      start_seen  <= 1'b0;
    end else begin
      state <= state_n;

      // Consume cfg_start once per job if it is level-based.
      // Allow re-trigger after CPU deasserts cfg_start.
      if (state == S_IDLE) begin
        if (cfg_start)  start_seen <= 1'b1;
        else            start_seen <= 1'b0;
      end

      // Clear sticky flags when CPU requests it.
      if (cfg_clr_status) begin
        sts_done    <= 1'b0;
        sts_error   <= 1'b0;
        sts_errcode <= 8'd0;
      end

      // Set sticky done/error on entering terminal states.
      if (state_n == S_DONE) begin
        sts_done <= 1'b1;
      end

      if (state_n == S_ERROR) begin
        sts_error <= 1'b1;

        // Minimal error codes for MVP:
        // 1 = invalid length
        // 2 = input DMA error
        // 3 = systolic error
        // 4 = output DMA error
        if (state == S_VALIDATE && cfg_len_bytes == 32'd0) begin
          sts_errcode <= 8'd1;
        end else if (in_dma_error) begin
          sts_errcode <= 8'd2;
        end else if (sa_error) begin
          sts_errcode <= 8'd3;
        end else if (out_dma_error) begin
          sts_errcode <= 8'd4;
        end else begin
          sts_errcode <= 8'd255;
        end
      end
    end
  end

endmodule
