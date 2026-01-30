/*
 * sram_buffer.v
 *
 * LLM-generated dual-port SRAM buffer with independent write and read ports.
 * - Write port intended for DMA (or core output)
 * - Read port intended for systolic array (or DMA store)
 */

`default_nettype none

module sram_buffer #(
    parameter DEPTH = 64,
    parameter ADDR_W = 6,
    parameter DATA_W = 32
) (
    input  wire              clk,
    input  wire              rst_n,

    input  wire              wr_en,
    input  wire [ADDR_W-1:0] wr_addr,
    input  wire [DATA_W-1:0] wr_data,

    input  wire              rd_en,
    input  wire [ADDR_W-1:0] rd_addr,
    output reg  [DATA_W-1:0] rd_data,
    output reg               rd_valid
);

    reg [DATA_W-1:0] mem [0:DEPTH-1];
    reg [ADDR_W-1:0] rd_addr_q;
    reg              rd_pending;

    always @(posedge clk) begin
        if (!rst_n) begin
            rd_data    <= {DATA_W{1'b0}};
            rd_valid   <= 1'b0;
            rd_addr_q  <= {ADDR_W{1'b0}};
            rd_pending <= 1'b0;
        end else begin
            rd_valid <= 1'b0;

            if (rd_pending) begin
                rd_data  <= mem[rd_addr_q];
                rd_valid <= 1'b1;
                rd_pending <= 1'b0;
            end

            if (rd_en) begin
                rd_addr_q  <= rd_addr;
                rd_pending <= 1'b1;
            end

            if (wr_en) begin
                mem[wr_addr] <= wr_data;
            end
        end
    end

endmodule

`default_nettype wire
