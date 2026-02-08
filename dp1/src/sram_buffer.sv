`timescale 1ns/1ps
`default_nettype none

module sram_buffer #(
    parameter integer DEPTH     = 256,
    parameter integer ADDR_WIDTH = (DEPTH <= 1) ? 1 : $clog2(DEPTH),
    parameter integer RD_PORTS  = 1,
    parameter integer WR_PORTS  = 1
)(
    input  wire                       clk,
    input  wire [RD_PORTS-1:0]         re,
    input  wire [RD_PORTS-1:0][ADDR_WIDTH-1:0] raddr,
    output reg  [RD_PORTS-1:0][31:0]   rdata,
    input  wire [WR_PORTS-1:0]         we,
    input  wire [WR_PORTS-1:0][ADDR_WIDTH-1:0] waddr,
    input  wire [WR_PORTS-1:0][31:0]   wdata
);

    reg [31:0] mem [0:DEPTH-1];
    integer i;
    integer p;

    initial begin
        for (i = 0; i < DEPTH; i = i + 1) begin
            mem[i] = 32'd0;
        end
    end

    always @(posedge clk) begin
        for (p = 0; p < WR_PORTS; p = p + 1) begin
            if (we[p]) begin
                mem[waddr[p]] <= wdata[p];
            end
        end
    end

    always @(*) begin
        for (p = 0; p < RD_PORTS; p = p + 1) begin
            if (re[p]) begin
                rdata[p] = mem[raddr[p]];
            end else begin
                rdata[p] = 32'd0;
            end
        end
    end

endmodule

`default_nettype wire
