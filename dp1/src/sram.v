// Module: sram_256kb
// Description: 64K x 32-bit SRAM for AI-HDL 2026 Peripheral
// Designer: Shawn (Shijian) Ding
`timescale 1ns/1ps
module sram_256kb (
    input wire clk,
    input wire reset,    // Asynchronous reset
    input wire en,       // Chip Enable
    input wire we,       // Write Enable
    input wire [15:0] addr,
    input wire [31:0] wdata,
    output reg [31:0] rdata
);

    // 65,536 entries of 32-bit words = 256KB
    reg [31:0] mem [0:65535];

    // Synchronous Read/Write Logic
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            rdata <= 32'b0;
        end else if (en) begin
            if (we) begin
                mem[addr] <= wdata;
            end
            rdata <= mem[addr];
        end
    end

endmodule
