`default_nettype none

module mac32 (
    input  wire [31:0] a,
    input  wire [31:0] b,
    input  wire [31:0] acc,
    input  wire        sat_en,
    output wire [31:0] result,
    output wire        overflow
);
    wire signed [63:0] prod_s = $signed(a) * $signed(b);
    wire signed [63:0] acc_s  = $signed({{32{acc[31]}}, acc});
    wire signed [63:0] sum_s  = prod_s + acc_s;

    wire signed [63:0] max_s = 64'sh0000_0000_7FFF_FFFF;
    wire signed [63:0] min_s = 64'shFFFF_FFFF_8000_0000;

    assign overflow = (sum_s > max_s) || (sum_s < min_s);
    assign result = (sat_en && overflow) ?
                    (sum_s < 0 ? 32'h8000_0000 : 32'h7FFF_FFFF) :
                    sum_s[31:0];
endmodule

`default_nettype wire
