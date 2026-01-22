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

    always @(posedge clk) begin
        if (!rst_n) begin
            result <= 32'd0;
            done   <= 1'b0;
        end else begin
            done <= 1'b0;

            if (valid) begin
                result <= a * b + acc;
                done   <= 1'b1;
            end
        end
    end

endmodule
