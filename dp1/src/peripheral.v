/*
 * peripheral.v
 *
 * TinyQV Peripheral: Minimal NPU MVP
 *
 * Register map (address is 6-bit word index, not byte address):
 *   0x00: REG_A     (W) operand A
 *   0x01: REG_B     (W) operand B
 *   0x02: CTRL      (W) bit0 = start (pulse)
 *   0x03: RESULT    (R) computation result
 *   0x04: STATUS    (R) bit0 = done
 *   0x05: DONE_CLR  (W) write 1 to clear done (optional but recommended)
 *
 * Notes:
 * - data_write_n: 2'b10 indicates 32-bit write (what we use for MVP)
 * - data_read_n is not used for behavior, but is included to prevent warnings
 */

`default_nettype none

module tqvp_example (
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

    // --------------------------------------------------------------------
    // NPU control registers (MMIO-visible)
    // --------------------------------------------------------------------
    reg [31:0] reg_a;
    reg [31:0] reg_b;

    // start is a 1-cycle pulse into systolic
    reg        reg_start;

    // result + done are latched for easy software polling
    reg [31:0] reg_result;
    reg        reg_done;

    // --------------------------------------------------------------------
    // Compute core interface
    // --------------------------------------------------------------------
    wire [31:0] sys_result;
    wire        sys_done;

    systolic u_systolic (
        .clk    (clk),
        .rst_n  (rst_n),
        .start  (reg_start),
        .a      (reg_a),
        .b      (reg_b),
        .result (sys_result),
        .done   (sys_done)
    );

    // --------------------------------------------------------------------
    // Write decode
    // --------------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst_n) begin
            reg_a      <= 32'd0;
            reg_b      <= 32'd0;
            reg_start  <= 1'b0;
            reg_result <= 32'd0;
            reg_done   <= 1'b0;
        end else begin
            // default: start is a pulse
            reg_start <= 1'b0;

            // latch result/done when compute finishes
            if (sys_done) begin
                reg_result <= sys_result;
                reg_done   <= 1'b1;
            end

            // Handle writes
            if (data_write_n != 2'b11) begin
                case (address)
                    6'h00: reg_a <= data_in;           // REG_A
                    6'h01: reg_b <= data_in;           // REG_B
                    6'h02: reg_start <= data_in[0];    // CTRL.start pulse
                    6'h05: if (data_in[0]) reg_done <= 1'b0; // DONE_CLR
                    default: ;
                endcase
            end
        end
    end

    // --------------------------------------------------------------------
    // Read mux
    // --------------------------------------------------------------------
    assign data_out =
        (address == 6'h03) ? reg_result :
        (address == 6'h04) ? {31'd0, reg_done} :
        32'd0;

    // For MVP, always ready in 1 cycle
    assign data_ready = 1'b1;

    // No interrupt in MVP (keep it simple)
    assign user_interrupt = 1'b0;

    // For now, drive outputs low (or use debug bits if you want)
    assign uo_out = 8'd0;

    // Unused inputs
    wire _unused = &{ui_in, data_read_n, 1'b0};

endmodule
