`default_nettype none

module sram_buffer #(
    parameter integer DEPTH = 256,
    parameter integer ADDR_WIDTH = $clog2(DEPTH)
) (
    input  wire                 clk,
    input  wire                 we,
    input  wire [ADDR_WIDTH-1:0] waddr,
    input  wire [31:0]          wdata,
    input  wire                 re,
    input  wire [ADDR_WIDTH-1:0] raddr,
    output reg  [31:0]          rdata
);
    reg [31:0] mem [0:DEPTH-1];

    integer i;
    initial begin
        for (i = 0; i < DEPTH; i = i + 1) begin
            mem[i] = 32'b0;
        end
    end

    always @(posedge clk) begin
        if (we) begin
            mem[waddr] <= wdata;
        end
    end

    always @(*) begin
        if (re) begin
            rdata = mem[raddr];
        end else begin
            rdata = 32'b0;
        end
    end
endmodule

`default_nettype wire
