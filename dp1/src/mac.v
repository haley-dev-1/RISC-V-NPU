/*
 * mac.v
 *
 * Simple Multiply-Accumulate (MAC) unit
 *
 * Computes:
 *   result = a * b + acc
 *
 * This module is purely computational and does not know about
 * addresses, peripherals, or system-level control.
 */

`timescale 1ns/1ps
`default_nettype wire

module mac (
    input  wire        clk,
    input  wire        rst_n,

    input  wire        valid,   // When high, perform MAC
    input  wire [31:0] a,       // Operand A
    input  wire [31:0] b,       // Operand B
    input  wire [31:0] acc,     // Accumulator input

    output reg  [31:0] result,  // MAC output
    output reg         done     // Asserted for 1 cycle when complete
);

    // Signed intermediates to avoid Verilog/SystemVerilog signedness pitfalls.
    // External interface is preserved exactly (ports remain 32-bit vectors).
    // Operation is performed as:
    //   result = (signed(a) * signed(b) + signed(acc)) mod 2^32
    // using signed 64-bit intermediates and truncating the low 32 bits.

    wire signed [31:0] a_s   = $signed(a);
    wire signed [31:0] b_s   = $signed(b);
    wire signed [31:0] acc_s = $signed(acc);

    wire signed [63:0] prod_s = $signed(a_s) * $signed(b_s);

    // Explicit sign-extension to 64b avoids Verilator WIDTHEXPAND warnings
    wire signed [63:0] acc_ext_s = {{32{acc_s[31]}}, acc_s};
    wire signed [63:0] sum_s     = prod_s + acc_ext_s;

    // Consume upper bits so Verilator doesn't warn about unused sum_s[63:32]
    wire sum_hi_xor = ^sum_s[63:32];
    wire _unused    = sum_hi_xor;

    always @(posedge clk) begin
        if (!rst_n) begin
            result <= 32'd0;
            done   <= 1'b0;
        end else begin
            done <= 1'b0;

            if (valid) begin
                // Truncate/wrap to 32 bits (matches typical hardware behavior)
                result <= sum_s[31:0];
                done   <= 1'b1;
            end
        end
    end

endmodule
