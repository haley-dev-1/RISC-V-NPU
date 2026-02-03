`timescale 1ns/1ps
`default_nettype none

/* verilator lint_off DECLFILENAME */
module tqvp_example #(
    parameter integer N = 2   // MUST match systolic.v parameter N
)(
    input         clk,
    input         rst_n,

    input  [7:0]  ui_in,
    output [7:0]  uo_out,

    input  [5:0]   address,
    input  [31:0]  data_in,

    input  [1:0]   data_write_n,
    input  [1:0]   data_read_n,

    output [31:0]  data_out,
    output         data_ready,

    output         user_interrupt
);
/* verilator lint_on DECLFILENAME */

    localparam integer NN = N*N;

    // Avoid WIDTHTRUNC by explicitly selecting 6 bits from 32-bit ints
    localparam int unsigned N_INT  = N;
    localparam int unsigned NN_INT = NN;
    localparam [5:0] N6  = N_INT[5:0];
    localparam [5:0] NN6 = NN_INT[5:0];

    // Memory sizing for internal sysmem + scratchpads (word addressed)
    localparam int SYS_MEM_WORDS = 256;
    localparam int SPAD_WORDS    = 256;
    localparam int SYS_AW        = (SYS_MEM_WORDS <= 1) ? 1 : $clog2(SYS_MEM_WORDS);
    localparam int SPAD_AW       = (SPAD_WORDS <= 1) ? 1 : $clog2(SPAD_WORDS);
    localparam int EXPECTED_WORDS     = N*N;
    localparam int EXPECTED_LEN_BYTES = EXPECTED_WORDS * 4;

    // MMIO map (6-bit word addresses)
    localparam [5:0] ADDR_CTRL         = 6'h20;
    localparam [5:0] ADDR_STATUS       = 6'h21;
    localparam [5:0] ADDR_ACCEL_CTRL   = 6'h22;
    localparam [5:0] ADDR_ACCEL_STATUS = 6'h23;
    localparam [5:0] ADDR_SRC_A        = 6'h24;
    localparam [5:0] ADDR_SRC_B        = 6'h25;
    localparam [5:0] ADDR_DST_C        = 6'h26;
    localparam [5:0] ADDR_LEN          = 6'h27;
    localparam [5:0] ADDR_SPAD_A       = 6'h28;
    localparam [5:0] ADDR_SPAD_B       = 6'h29;
    localparam [5:0] ADDR_SPAD_C       = 6'h2A;
    localparam [5:0] ADDR_DIM_M        = 6'h2B;
    localparam [5:0] ADDR_DIM_N        = 6'h2C;
    localparam [5:0] ADDR_DIM_K        = 6'h2D;
    localparam [5:0] ADDR_SYS_ADDR     = 6'h2E;
    localparam [5:0] ADDR_SYS_DATA     = 6'h2F;

    // FIFO sizing
    localparam int FC_W  = (N <= 1) ? 1 : $clog2(N+1);
    localparam int PTR_W = (N <= 1) ? 1 : $clog2(N);

    // --------------------------------------------------------------------
    // MMIO-visible regs for input lanes (software writes these)
    // --------------------------------------------------------------------
    reg [31:0] a_lane [0:N-1];
    reg [31:0] b_lane [0:N-1];

    // --------------------------------------------------------------------
    // Internal system memory + scratchpads (word addressed)
    // --------------------------------------------------------------------
    reg [31:0] sys_mem   [0:SYS_MEM_WORDS-1];
    reg [31:0] spad_a_mem[0:SPAD_WORDS-1];
    reg [31:0] spad_b_mem[0:SPAD_WORDS-1];
    reg [31:0] spad_c_mem[0:SPAD_WORDS-1];

    // --------------------------------------------------------------------
    // DMA / accelerator MMIO config registers
    // --------------------------------------------------------------------
    reg [31:0] cfg_src_a_addr;
    reg [31:0] cfg_src_b_addr;
    reg [31:0] cfg_dst_c_addr;
    reg [31:0] cfg_len_bytes;
    reg [31:0] cfg_spad_a_base;
    reg [31:0] cfg_spad_b_base;
    reg [31:0] cfg_spad_c_base;
    reg [31:0] cfg_dim_m;
    reg [31:0] cfg_dim_n;
    reg [31:0] cfg_dim_k;

    reg [31:0] sys_addr_reg;
    reg        sys_err_sticky;

    // --------------------------------------------------------------------
    // Beat FIFO (depth N). Each entry stores one beat of A lanes and B lanes.
    // --------------------------------------------------------------------
    reg [31:0] a_fifo [0:N-1][0:N-1];  // [beat][lane]
    reg [31:0] b_fifo [0:N-1][0:N-1];  // [beat][lane]
    reg [FC_W-1:0]  fifo_count;
    reg [PTR_W-1:0] rd_ptr;
    reg [PTR_W-1:0] wr_ptr;

    // Run arming + stream gating:
    // - We may assert start_pulse early to set systolic busy
    // - But we HOLD in_valid low until we have queued all N beats
    //   to avoid bubbles/gaps breaking wavefront timing.
    reg run_armed;
    reg stream_en;

    // Command pulse
    reg start_pulse;

    // Sticky status
    reg done_sticky;

    // --------------------------------------------------------------------
    // Accelerator / DMA controller state
    // --------------------------------------------------------------------
    typedef enum logic [2:0] {
        ACC_IDLE     = 3'd0,
        ACC_IN_DMA   = 3'd1,
        ACC_SA_WAIT  = 3'd2,
        ACC_OUT_DMA  = 3'd3,
        ACC_DONE     = 3'd4,
        ACC_ERROR    = 3'd5
    } acc_state_t;

    acc_state_t acc_state;
    acc_state_t acc_state_n;
    reg         accel_done_sticky;
    reg         accel_error_sticky;
    reg [7:0]   accel_errcode;
    reg         accel_irq_en;

    logic       acc_set_done;
    logic       acc_set_error;
    logic [7:0] acc_error_code;

    logic       inA_start_req;
    logic       inB_start_req;
    logic       out_start_req;
    logic       sa_start_req;

    // DMA channel state (A/B inputs, C output)
    reg         inA_busy, inA_done_flag, inA_error;
    reg [31:0]  inA_sys_idx, inA_spad_idx, inA_words_left;

    reg         inB_busy, inB_done_flag, inB_error;
    reg [31:0]  inB_sys_idx, inB_spad_idx, inB_words_left;

    reg         out_busy, out_done_flag, out_error;
    reg [31:0]  out_sys_idx, out_spad_idx, out_words_left;

    // Controller-issued pulse
    reg sa_start_pulse;

    // Streaming interface to systolic
    wire in_ready;
    wire sys_busy;
    wire sys_done;

    wire [N*32-1:0]      a_vec_in;
    wire [N*32-1:0]      b_vec_in;
    wire [N*N*32-1:0]    c_mat_out;

    // DMA-driven systolic path
    wire dma_in_ready;
    wire dma_sys_busy;
    wire dma_sys_done;
    wire [N*32-1:0]   dma_a_vec_in;
    wire [N*32-1:0]   dma_b_vec_in;
    wire [N*N*32-1:0] dma_c_mat_out;

    reg  dma_streaming;
    reg [$clog2(N+1)-1:0] dma_beat_idx;

    // Pack the FIFO HEAD (rd_ptr) into vectors
    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : PACK_IN
            assign a_vec_in[i*32 +: 32] = a_fifo[rd_ptr][i];
            assign b_vec_in[i*32 +: 32] = b_fifo[rd_ptr][i];
        end
    endgenerate

    // DMA vector build from scratchpads (row-major A/B in spads)
    reg [N*32-1:0] dma_a_vec_in_r;
    reg [N*32-1:0] dma_b_vec_in_r;
    integer r_idx;
    integer c_idx;
    integer a_word_idx;
    integer b_word_idx;

    wire [31:0] spad_a_base_word = cfg_spad_a_base >> 2;
    wire [31:0] spad_b_base_word = cfg_spad_b_base >> 2;

    always @(*) begin
        dma_a_vec_in_r = {N*32{1'b0}};
        dma_b_vec_in_r = {N*32{1'b0}};

        for (r_idx = 0; r_idx < N; r_idx = r_idx + 1) begin
            a_word_idx = spad_a_base_word + (r_idx * N) + int'(dma_beat_idx);
            if (a_word_idx < SPAD_WORDS)
                dma_a_vec_in_r[r_idx*32 +: 32] = spad_a_mem[a_word_idx];
        end
        for (c_idx = 0; c_idx < N; c_idx = c_idx + 1) begin
            b_word_idx = spad_b_base_word + (int'(dma_beat_idx) * N) + c_idx;
            if (b_word_idx < SPAD_WORDS)
                dma_b_vec_in_r[c_idx*32 +: 32] = spad_b_mem[b_word_idx];
        end
    end

    assign dma_a_vec_in = dma_a_vec_in_r;
    assign dma_b_vec_in = dma_b_vec_in_r;

    // Gated in_valid presented to systolic
    wire in_valid = stream_en && (fifo_count != {FC_W{1'b0}});

    // Instantiate streaming systolic
    systolic #(.N(N)) u_systolic (
        .clk      (clk),
        .rst_n    (rst_n),

        .start    (start_pulse),
        .busy     (sys_busy),
        .done     (sys_done),

        .in_valid (in_valid),
        .in_ready (in_ready),

        .a_vec_in (a_vec_in),
        .b_vec_in (b_vec_in),

        .c_mat_out(c_mat_out)
    );

    // DMA-driven systolic instance (separate from MMIO streaming path)
    systolic #(.N(N)) u_systolic_dma (
        .clk      (clk),
        .rst_n    (rst_n),

        .start    (sa_start_pulse),
        .busy     (dma_sys_busy),
        .done     (dma_sys_done),

        .in_valid (dma_streaming && (dma_beat_idx < $clog2(N+1)'(N))),
        .in_ready (dma_in_ready),

        .a_vec_in (dma_a_vec_in),
        .b_vec_in (dma_b_vec_in),

        .c_mat_out(dma_c_mat_out)
    );

    integer k;
    integer b;
    integer mi;
    integer wr;
    integer wc;

    // Convenience wrap helpers (synthesizable)
    function automatic [PTR_W-1:0] ptr_inc(input [PTR_W-1:0] p);
        begin
            if (p == PTR_W'(N-1)) ptr_inc = {PTR_W{1'b0}};
            else                  ptr_inc = p + {{(PTR_W-1){1'b0}}, 1'b1};
        end
    endfunction

    // DMA parameter validation helper
    function automatic bit dma_params_ok(
        input [31:0] sys_addr,
        input [31:0] spad_addr,
        input [31:0] len_bytes
    );
        int unsigned sys_idx;
        int unsigned spad_idx;
        int unsigned words;
        begin
            if (len_bytes == 32'd0) begin
                dma_params_ok = 1'b0;
            end else if (len_bytes[1:0] != 2'b00) begin
                dma_params_ok = 1'b0;
            end else if ((sys_addr[1:0] != 2'b00) || (spad_addr[1:0] != 2'b00)) begin
                dma_params_ok = 1'b0;
            end else if ((sys_addr[31:SYS_AW+2] != 0) || (spad_addr[31:SPAD_AW+2] != 0)) begin
                dma_params_ok = 1'b0;
            end else begin
                sys_idx  = sys_addr  >> 2;
                spad_idx = spad_addr >> 2;
                words    = len_bytes >> 2;
                if ((sys_idx + words) > SYS_MEM_WORDS) begin
                    dma_params_ok = 1'b0;
                end else if ((spad_idx + words) > SPAD_WORDS) begin
                    dma_params_ok = 1'b0;
                end else begin
                    dma_params_ok = 1'b1;
                end
            end
        end
    endfunction

    // MMIO decode
    wire mmio_wr = (data_write_n != 2'b11);
    wire mmio_rd = (data_read_n != 2'b11);

    wire ctrl_wr       = mmio_wr && (address == ADDR_CTRL);
    wire accel_ctrl_wr = mmio_wr && (address == ADDR_ACCEL_CTRL);

    wire push_req = ctrl_wr && data_in[0];
    wire clr_req  = ctrl_wr && data_in[1];

    wire accel_start_req = accel_ctrl_wr && data_in[0];
    wire accel_clr_req   = accel_ctrl_wr && data_in[1];

    wire sys_data_wr = mmio_wr && (address == ADDR_SYS_DATA);
    wire sys_data_rd = mmio_rd && (address == ADDR_SYS_DATA);

    wire sys_addr_aligned = (sys_addr_reg[1:0] == 2'b00);
    wire sys_addr_hi_zero = (sys_addr_reg[31:SYS_AW+2] == 0);
    wire [SYS_AW-1:0] sys_addr_idx = sys_addr_reg[SYS_AW+1:2];
    wire sys_addr_valid = sys_addr_aligned && sys_addr_hi_zero;
    wire [31:0] sys_rdata = sys_addr_valid ? sys_mem[sys_addr_idx] : 32'd0;

    wire len_ok = (cfg_len_bytes == EXPECTED_LEN_BYTES[31:0]);

    wire spad_c_base_aligned = (cfg_spad_c_base[1:0] == 2'b00);
    wire spad_c_base_hi_zero = (cfg_spad_c_base[31:SPAD_AW+2] == 0);
    wire [31:0] spad_c_base_word = cfg_spad_c_base >> 2;
    wire spad_c_range_ok = spad_c_base_aligned && spad_c_base_hi_zero &&
                           ((spad_c_base_word + EXPECTED_WORDS) <= SPAD_WORDS);


    // FIFO pop when systolic accepts a beat
    wire pop_beat = in_valid && in_ready;

    // FIFO push if space and not already streaming (we only support prefill)
    wire fifo_full = (fifo_count == FC_W'(N));
    wire do_push   = push_req && !fifo_full && !stream_en;

    // Start pulse when we see the FIRST push of a run while idle.
    wire first_push_of_run = do_push && !run_armed && !sys_busy;

    // --------------------------------------------------------------------
    // Sequential
    // --------------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst_n) begin
            start_pulse <= 1'b0;
            done_sticky <= 1'b0;

            fifo_count  <= {FC_W{1'b0}};
            rd_ptr      <= {PTR_W{1'b0}};
            wr_ptr      <= {PTR_W{1'b0}};

            run_armed   <= 1'b0;
            stream_en   <= 1'b0;

            for (k = 0; k < N; k = k + 1) begin
                a_lane[k] <= 32'd0;
                b_lane[k] <= 32'd0;
            end
            for (b = 0; b < N; b = b + 1) begin
                for (k = 0; k < N; k = k + 1) begin
                    a_fifo[b][k] <= 32'd0;
                    b_fifo[b][k] <= 32'd0;
                end
            end
        end else begin
            // default
            start_pulse <= 1'b0;

            // DONE sticky + auto-clear stream state after completion
            if (sys_done) begin
                done_sticky <= 1'b1;

                fifo_count <= {FC_W{1'b0}};
                rd_ptr     <= {PTR_W{1'b0}};
                wr_ptr     <= {PTR_W{1'b0}};
                run_armed  <= 1'b0;
                stream_en  <= 1'b0;
            end

            // Handle lane + CTRL writes
            if (mmio_wr) begin
                // A lanes: 0x00..0x00+N-1
                if (address < (6'h00 + N6)) begin
                    a_lane[address[0]] <= data_in;
                end
                // B lanes: 0x10..0x10+N-1
                else if (address >= 6'h10 && address < (6'h10 + N6)) begin
                    b_lane[address[0]] <= data_in; // 0x10/0x11 -> [0]/[1]
                end
                // CTRL
                else if (address == 6'h20) begin
                    if (data_in[1]) begin
                        done_sticky <= 1'b0;

                        // Clear queued beats / state
                        fifo_count <= {FC_W{1'b0}};
                        rd_ptr     <= {PTR_W{1'b0}};
                        wr_ptr     <= {PTR_W{1'b0}};
                        run_armed  <= 1'b0;
                        stream_en  <= 1'b0;
                    end
                end
            end

            // Skip FIFO update if we just cleared or just finished (avoid overrides)
            if (!clr_req && !sys_done) begin : FIFO_UPDATE
                int unsigned count_next;
                count_next = int'(fifo_count);

                if (pop_beat) begin
                    rd_ptr     <= ptr_inc(rd_ptr);
                    count_next = count_next - 1;
                end

                if (do_push) begin
                    for (k = 0; k < N; k = k + 1) begin
                        a_fifo[wr_ptr][k] <= a_lane[k];
                        b_fifo[wr_ptr][k] <= b_lane[k];
                    end
                    wr_ptr     <= ptr_inc(wr_ptr);
                    count_next = count_next + 1;

                    if (first_push_of_run) begin
                        run_armed   <= 1'b1;
                        start_pulse <= 1'b1;
                    end
                end

                // Enable streaming only once we have queued ALL N beats
                if (run_armed && !stream_en && (count_next == int'(N))) begin
                    stream_en <= 1'b1;
                end

                fifo_count <= count_next[FC_W-1:0];
            end
        end
    end

    // --------------------------------------------------------------------
    // Accelerator controller (dual-channel DMA + compute)
    // --------------------------------------------------------------------
    always @(*) begin
        acc_state_n   = acc_state;
        inA_start_req = 1'b0;
        inB_start_req = 1'b0;
        out_start_req = 1'b0;
        sa_start_req  = 1'b0;

        acc_set_done  = 1'b0;
        acc_set_error = 1'b0;
        acc_error_code= 8'd0;

        case (acc_state)
            ACC_IDLE: begin
                if (accel_start_req) begin
                    if (!len_ok) begin
                        acc_state_n    = ACC_ERROR;
                        acc_set_error  = 1'b1;
                        acc_error_code = 8'd1; // invalid length
                    end else if (!spad_c_range_ok) begin
                        acc_state_n    = ACC_ERROR;
                        acc_set_error  = 1'b1;
                        acc_error_code = 8'd2; // spad_c out of range
                    end else begin
                        inA_start_req  = 1'b1;
                        inB_start_req  = 1'b1;
                        acc_state_n    = ACC_IN_DMA;
                    end
                end
            end

            ACC_IN_DMA: begin
                if (inA_error || inB_error) begin
                    acc_state_n    = ACC_ERROR;
                    acc_set_error  = 1'b1;
                    acc_error_code = inA_error ? 8'd3 : 8'd4; // input DMA error
                end else if (inA_done_flag && inB_done_flag) begin
                    sa_start_req = 1'b1;
                    acc_state_n  = ACC_SA_WAIT;
                end
            end

            ACC_SA_WAIT: begin
                if (dma_sys_done) begin
                    out_start_req = 1'b1;
                    acc_state_n   = ACC_OUT_DMA;
                end
            end

            ACC_OUT_DMA: begin
                if (out_error) begin
                    acc_state_n    = ACC_ERROR;
                    acc_set_error  = 1'b1;
                    acc_error_code = 8'd5; // output DMA error
                end else if (out_done_flag) begin
                    acc_state_n   = ACC_DONE;
                    acc_set_done  = 1'b1;
                end
            end

            ACC_DONE: begin
                if (accel_clr_req) acc_state_n = ACC_IDLE;
            end

            ACC_ERROR: begin
                if (accel_clr_req) acc_state_n = ACC_IDLE;
            end

            default: acc_state_n = ACC_IDLE;
        endcase
    end

    // --------------------------------------------------------------------
    // Accelerator / DMA / sysmem sequential logic
    // --------------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst_n) begin
            cfg_src_a_addr  <= 32'd0;
            cfg_src_b_addr  <= 32'd0;
            cfg_dst_c_addr  <= 32'd0;
            cfg_len_bytes   <= 32'd0;
            cfg_spad_a_base <= 32'd0;
            cfg_spad_b_base <= 32'd0;
            cfg_spad_c_base <= 32'd0;
            cfg_dim_m       <= 32'd0;
            cfg_dim_n       <= 32'd0;
            cfg_dim_k       <= 32'd0;

            sys_addr_reg    <= 32'd0;
            sys_err_sticky  <= 1'b0;

            accel_done_sticky  <= 1'b0;
            accel_error_sticky <= 1'b0;
            accel_errcode      <= 8'd0;
            accel_irq_en        <= 1'b0;

            acc_state <= ACC_IDLE;

            inA_busy      <= 1'b0;
            inA_done_flag <= 1'b0;
            inA_error     <= 1'b0;
            inA_sys_idx   <= 32'd0;
            inA_spad_idx  <= 32'd0;
            inA_words_left<= 32'd0;

            inB_busy      <= 1'b0;
            inB_done_flag <= 1'b0;
            inB_error     <= 1'b0;
            inB_sys_idx   <= 32'd0;
            inB_spad_idx  <= 32'd0;
            inB_words_left<= 32'd0;

            out_busy      <= 1'b0;
            out_done_flag <= 1'b0;
            out_error     <= 1'b0;
            out_sys_idx   <= 32'd0;
            out_spad_idx  <= 32'd0;
            out_words_left<= 32'd0;

            sa_start_pulse  <= 1'b0;

            dma_streaming <= 1'b0;
            dma_beat_idx  <= '0;

            for (mi = 0; mi < SYS_MEM_WORDS; mi = mi + 1) begin
                sys_mem[mi] = 32'd0;
            end
            for (mi = 0; mi < SPAD_WORDS; mi = mi + 1) begin
                spad_a_mem[mi] = 32'd0;
                spad_b_mem[mi] = 32'd0;
                spad_c_mem[mi] = 32'd0;
            end
        end else begin
            // default pulses
            sa_start_pulse  <= 1'b0;

            // MMIO writes to config registers
            if (mmio_wr) begin
                case (address)
                    ADDR_SRC_A:    cfg_src_a_addr  <= data_in;
                    ADDR_SRC_B:    cfg_src_b_addr  <= data_in;
                    ADDR_DST_C:    cfg_dst_c_addr  <= data_in;
                    ADDR_LEN:      cfg_len_bytes   <= data_in;
                    ADDR_SPAD_A:   cfg_spad_a_base <= data_in;
                    ADDR_SPAD_B:   cfg_spad_b_base <= data_in;
                    ADDR_SPAD_C:   cfg_spad_c_base <= data_in;
                    ADDR_DIM_M:    cfg_dim_m       <= data_in;
                    ADDR_DIM_N:    cfg_dim_n       <= data_in;
                    ADDR_DIM_K:    cfg_dim_k       <= data_in;
                    ADDR_SYS_ADDR: sys_addr_reg    <= data_in;
                    ADDR_ACCEL_CTRL: accel_irq_en  <= data_in[2];
                    default: begin end
                endcase
            end

            // SYS_MEM access window
            if (sys_data_wr) begin
                if (sys_addr_valid)
                    sys_mem[sys_addr_idx] <= data_in;
                else
                    sys_err_sticky <= 1'b1;
            end
            if (sys_data_rd && !sys_addr_valid) begin
                sys_err_sticky <= 1'b1;
            end

            // Update controller state
            acc_state <= acc_state_n;
            sa_start_pulse  <= sa_start_req;

            if (acc_set_done) begin
                accel_done_sticky <= 1'b1;
            end
            if (acc_set_error) begin
                accel_error_sticky <= 1'b1;
                accel_errcode      <= acc_error_code;
            end

            if (accel_clr_req) begin
                accel_done_sticky  <= 1'b0;
                accel_error_sticky <= 1'b0;
                accel_errcode      <= 8'd0;
                sys_err_sticky     <= 1'b0;
            end

            // DMA channel A (sysmem -> spad_a)
            if (inA_start_req) begin
                inA_done_flag <= 1'b0;
                inA_error     <= 1'b0;
                if (!dma_params_ok(cfg_src_a_addr, cfg_spad_a_base, cfg_len_bytes)) begin
                    inA_error <= 1'b1;
                    inA_busy  <= 1'b0;
                end else begin
                    inA_busy       <= 1'b1;
                    inA_sys_idx    <= cfg_src_a_addr  >> 2;
                    inA_spad_idx   <= cfg_spad_a_base >> 2;
                    inA_words_left <= cfg_len_bytes   >> 2;
                end
            end else if (inA_busy) begin
                spad_a_mem[inA_spad_idx] <= sys_mem[inA_sys_idx];
                inA_sys_idx    <= inA_sys_idx + 1;
                inA_spad_idx   <= inA_spad_idx + 1;
                inA_words_left <= inA_words_left - 1;
                if (inA_words_left == 32'd1) begin
                    inA_busy      <= 1'b0;
                    inA_done_flag <= 1'b1;
                end
            end

            // DMA channel B (sysmem -> spad_b)
            if (inB_start_req) begin
                inB_done_flag <= 1'b0;
                inB_error     <= 1'b0;
                if (!dma_params_ok(cfg_src_b_addr, cfg_spad_b_base, cfg_len_bytes)) begin
                    inB_error <= 1'b1;
                    inB_busy  <= 1'b0;
                end else begin
                    inB_busy       <= 1'b1;
                    inB_sys_idx    <= cfg_src_b_addr  >> 2;
                    inB_spad_idx   <= cfg_spad_b_base >> 2;
                    inB_words_left <= cfg_len_bytes   >> 2;
                end
            end else if (inB_busy) begin
                spad_b_mem[inB_spad_idx] <= sys_mem[inB_sys_idx];
                inB_sys_idx    <= inB_sys_idx + 1;
                inB_spad_idx   <= inB_spad_idx + 1;
                inB_words_left <= inB_words_left - 1;
                if (inB_words_left == 32'd1) begin
                    inB_busy      <= 1'b0;
                    inB_done_flag <= 1'b1;
                end
            end

            // Output DMA (spad_c -> sysmem)
            if (out_start_req) begin
                out_done_flag <= 1'b0;
                out_error     <= 1'b0;
                if (!dma_params_ok(cfg_dst_c_addr, cfg_spad_c_base, cfg_len_bytes)) begin
                    out_error <= 1'b1;
                    out_busy  <= 1'b0;
                end else begin
                    out_busy       <= 1'b1;
                    out_sys_idx    <= cfg_dst_c_addr  >> 2;
                    out_spad_idx   <= cfg_spad_c_base >> 2;
                    out_words_left <= cfg_len_bytes   >> 2;
                end
            end else if (out_busy) begin
                sys_mem[out_sys_idx] <= spad_c_mem[out_spad_idx];
                out_sys_idx    <= out_sys_idx + 1;
                out_spad_idx   <= out_spad_idx + 1;
                out_words_left <= out_words_left - 1;
                if (out_words_left == 32'd1) begin
                    out_busy      <= 1'b0;
                    out_done_flag <= 1'b1;
                end
            end

            // Streaming control for DMA-driven systolic
            if (sa_start_req) begin
                dma_streaming <= 1'b1;
                dma_beat_idx  <= '0;
            end else if (dma_streaming && dma_in_ready && (dma_beat_idx < $clog2(N+1)'(N))) begin
                if (dma_beat_idx == $clog2(N+1)'(N-1))
                    dma_streaming <= 1'b0;
                dma_beat_idx <= dma_beat_idx + 1'b1;
            end

            // Capture compute results into spad_c on done
            if (dma_sys_done) begin
                for (wr = 0; wr < N; wr = wr + 1) begin
                    for (wc = 0; wc < N; wc = wc + 1) begin
                        if ((spad_c_base_word + (wr * N) + wc) < SPAD_WORDS) begin
                            spad_c_mem[spad_c_base_word + (wr * N) + wc] <=
                                dma_c_mat_out[((wr * N + wc) * 32) +: 32];
                        end
                    end
                end
            end
        end
    end

    // --------------------------------------------------------------------
    // Read mux
    // --------------------------------------------------------------------
    wire [31:0] status_word = {29'd0, 1'b0, sys_busy, done_sticky};
    wire accel_busy = (acc_state != ACC_IDLE) && (acc_state != ACC_DONE) && (acc_state != ACC_ERROR);
    wire [31:0] accel_status_word =
        {16'd0, accel_errcode, 4'd0, sys_err_sticky, accel_error_sticky, accel_busy, accel_done_sticky};

    reg [31:0] c_word;
    integer idx;

    always @(*) begin
        c_word = 32'd0;
        idx = 0;

        if (address >= 6'h30 && address < (6'h30 + NN6)) begin
            idx = {26'd0, address} - 32'd48;  // 0x30 = 48
            c_word = c_mat_out[idx*32 +: 32];
        end
    end

    assign data_out =
        (address == ADDR_STATUS)       ? status_word :
        (address == ADDR_ACCEL_STATUS) ? accel_status_word :
        (address == ADDR_SRC_A)        ? cfg_src_a_addr :
        (address == ADDR_SRC_B)        ? cfg_src_b_addr :
        (address == ADDR_DST_C)        ? cfg_dst_c_addr :
        (address == ADDR_LEN)          ? cfg_len_bytes :
        (address == ADDR_SPAD_A)       ? cfg_spad_a_base :
        (address == ADDR_SPAD_B)       ? cfg_spad_b_base :
        (address == ADDR_SPAD_C)       ? cfg_spad_c_base :
        (address == ADDR_DIM_M)        ? cfg_dim_m :
        (address == ADDR_DIM_N)        ? cfg_dim_n :
        (address == ADDR_DIM_K)        ? cfg_dim_k :
        (address == ADDR_SYS_ADDR)     ? sys_addr_reg :
        (address == ADDR_SYS_DATA)     ? sys_rdata :
        (address >= 6'h30 && address < (6'h30 + NN6)) ? c_word :
        32'd0;

    assign data_ready = 1'b1;
    assign user_interrupt = 1'b0;
    assign uo_out = 8'd0;

    wire _unused = &{ui_in, data_read_n, accel_irq_en, 1'b0};

endmodule

`default_nettype wire
