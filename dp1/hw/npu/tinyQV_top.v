/*
 * tinyQV_top.v
 *
 * LLM-generated integration wrapper for tinyQV core, DMA, SRAM buffers, and FSM.
 */

`default_nettype none

module tinyQV_top #(
    parameter N = 4,
    parameter DATA_W = 16,
    parameter ACC_W = 32,
    parameter BUF_DEPTH = 128,
    parameter BUF_AW = 7
) (
    input  wire        clk,
    input  wire        rst_n,

    input  wire        start,
    input  wire        abort,

    input  wire [4:0]  opcode,
    input  wire [7:0]  qparam,
    input  wire [31:0] control,

    input  wire [31:0] src_desc_ptr,
    input  wire [31:0] dst_desc_ptr,

    // System memory interface
    output wire        mem_rd_req,
    output wire [31:0] mem_rd_addr,
    input  wire        mem_rd_ready,
    input  wire        mem_rd_valid,
    input  wire [31:0] mem_rd_data,

    output wire        mem_wr_req,
    output wire [31:0] mem_wr_addr,
    output wire [31:0] mem_wr_data,
    input  wire        mem_wr_ready,

    output wire        dma_busy,
    output wire        busy,
    output wire        done,
    output wire        error
);

    // DMA control signals
    wire dma_start_load;
    wire dma_start_store;
    wire dma_abort;
    wire core_start;
    wire core_abort;

    wire dma_load_done;
    wire dma_store_done;
    wire dma_error;

    wire core_done;
    wire core_error;

    // SRAM ports
    wire        in_buf_wr_en;
    wire [BUF_AW-1:0] in_buf_wr_addr;
    wire [31:0] in_buf_wr_data;

    wire        in_buf_rd_en;
    wire [BUF_AW-1:0] in_buf_rd_addr;
    wire [31:0] in_buf_rd_data;
    wire        in_buf_rd_valid;

    wire        out_buf_wr_en;
    wire [BUF_AW-1:0] out_buf_wr_addr;
    wire [31:0] out_buf_wr_data;

    wire        out_buf_rd_en;
    wire [BUF_AW-1:0] out_buf_rd_addr;
    wire [31:0] out_buf_rd_data;
    wire        out_buf_rd_valid;

    // Input buffer
    sram_buffer #(
        .DEPTH(BUF_DEPTH),
        .ADDR_W(BUF_AW),
        .DATA_W(32)
    ) in_buffer (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(in_buf_wr_en),
        .wr_addr(in_buf_wr_addr),
        .wr_data(in_buf_wr_data),
        .rd_en(in_buf_rd_en),
        .rd_addr(in_buf_rd_addr),
        .rd_data(in_buf_rd_data),
        .rd_valid(in_buf_rd_valid)
    );

    // Output buffer
    sram_buffer #(
        .DEPTH(BUF_DEPTH),
        .ADDR_W(BUF_AW),
        .DATA_W(32)
    ) out_buffer (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(out_buf_wr_en),
        .wr_addr(out_buf_wr_addr),
        .wr_data(out_buf_wr_data),
        .rd_en(out_buf_rd_en),
        .rd_addr(out_buf_rd_addr),
        .rd_data(out_buf_rd_data),
        .rd_valid(out_buf_rd_valid)
    );

    // DMA engine
    dual_dma #(
        .MEM_BASE(32'h0000_0000),
        .MEM_SIZE(32'h0001_0000),
        .MAX_LEN(32'h0001_0000),
        .BUF_AW(BUF_AW)
    ) dma (
        .clk(clk),
        .rst_n(rst_n),
        .start_load(dma_start_load),
        .start_store(dma_start_store),
        .abort(dma_abort),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .control(control),
        .mem_rd_req(mem_rd_req),
        .mem_rd_addr(mem_rd_addr),
        .mem_rd_ready(mem_rd_ready),
        .mem_rd_valid(mem_rd_valid),
        .mem_rd_data(mem_rd_data),
        .mem_wr_req(mem_wr_req),
        .mem_wr_addr(mem_wr_addr),
        .mem_wr_data(mem_wr_data),
        .mem_wr_ready(mem_wr_ready),
        .in_buf_wr_en(in_buf_wr_en),
        .in_buf_wr_addr(in_buf_wr_addr),
        .in_buf_wr_data(in_buf_wr_data),
        .out_buf_rd_en(out_buf_rd_en),
        .out_buf_rd_addr(out_buf_rd_addr),
        .out_buf_rd_valid(out_buf_rd_valid),
        .out_buf_rd_data(out_buf_rd_data),
        .load_busy(),
        .store_busy(),
        .dma_busy(dma_busy),
        .load_done(dma_load_done),
        .store_done(dma_store_done),
        .error(dma_error)
    );

    // Core
    tinyQV_core #(
        .N(N),
        .DATA_W(DATA_W),
        .ACC_W(ACC_W),
        .BUF_DEPTH(BUF_DEPTH),
        .BUF_AW(BUF_AW)
    ) core (
        .clk(clk),
        .rst_n(rst_n),
        .start(core_start),
        .abort(core_abort),
        .opcode(opcode),
        .qparam(qparam),
        .control(control),
        .in_rd_en(in_buf_rd_en),
        .in_rd_addr(in_buf_rd_addr),
        .in_rd_data(in_buf_rd_data),
        .in_rd_valid(in_buf_rd_valid),
        .out_wr_en(out_buf_wr_en),
        .out_wr_addr(out_buf_wr_addr),
        .out_wr_data(out_buf_wr_data),
        .busy(),
        .done(core_done),
        .error(core_error)
    );

    // FSM
    npu_fsm fsm (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .abort(abort),
        .dma_load_done(dma_load_done),
        .dma_store_done(dma_store_done),
        .dma_error(dma_error),
        .core_done(core_done),
        .core_error(core_error),
        .dma_start_load(dma_start_load),
        .dma_start_store(dma_start_store),
        .dma_abort(dma_abort),
        .core_start(core_start),
        .core_abort(core_abort),
        .busy(busy),
        .done(done),
        .error(error)
    );

endmodule

`default_nettype wire
