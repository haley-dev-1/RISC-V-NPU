/*
 * mac32.v
 *
 * LLM-generated 32-bit signed MAC with overflow detection and optional saturation.
 * Single-cycle accumulation: acc_out updates on clk when enable is high.
 */

`default_nettype none

module mac32 #(
    parameter SATURATE = 1'b0
) (
    input  wire              clk,
    input  wire              rst_n,
    input  wire              enable,
    input  wire              clear,
    input  wire signed [31:0] a,
    input  wire signed [31:0] b,
    input  wire signed [31:0] acc_in,
    output reg  signed [31:0] acc_out,
    output reg               overflow
);

    localparam signed [31:0] MAX_S = 32'sh7FFF_FFFF;
    localparam signed [31:0] MIN_S = 32'sh8000_0000;

    wire signed [63:0] prod = a * b;
    wire signed [63:0] sum  = prod + acc_in;

    wire overflow_hi = (sum > MAX_S);
    wire overflow_lo = (sum < MIN_S);

    always @(posedge clk) begin
        if (!rst_n) begin
            acc_out  <= 32'sd0;
            overflow <= 1'b0;
        end else if (clear) begin
            acc_out  <= 32'sd0;
            overflow <= 1'b0;
        end else if (enable) begin
            overflow <= overflow_hi || overflow_lo;
            if (SATURATE) begin
                if (overflow_hi) acc_out <= MAX_S;
                else if (overflow_lo) acc_out <= MIN_S;
                else acc_out <= sum[31:0];
            end else begin
                acc_out <= sum[31:0];
            end
        end
    end

endmodule

`default_nettype wire
