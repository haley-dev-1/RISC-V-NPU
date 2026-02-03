`default_nettype none

module tinyQV_top #(
    parameter integer N            = 4,
    parameter integer BUF_DEPTH    = 256,
    parameter [27:0]  MMIO_BASE    = 28'h1000_000
) (
    input  wire        clk,
    input  wire        rst_n,

    // TinyQV-style MMIO interface
    input  wire [27:0] data_addr,
    input  wire [31:0] data_out,
    input  wire [1:0]  data_write_n,
    input  wire [1:0]  data_read_n,
    output wire [31:0] data_in,
    output wire        data_ready,
    output wire        irq,

    // DMA descriptor ports
    output wire        desc_src_req_valid,
    output wire [31:0] desc_src_req_addr,
    input  wire        desc_src_req_ready,
    input  wire        desc_src_rsp_valid,
    input  wire [31:0] desc_src_rsp_data,

    output wire        desc_dst_req_valid,
    output wire [31:0] desc_dst_req_addr,
    input  wire        desc_dst_req_ready,
    input  wire        desc_dst_rsp_valid,
    input  wire [31:0] desc_dst_rsp_data,

    // DMA data ports
    output wire        src_req_valid,
    output wire [31:0] src_req_addr,
    input  wire        src_req_ready,
    input  wire        src_rsp_valid,
    input  wire [31:0] src_rsp_data,

    output wire        dst_req_valid,
    output wire [31:0] dst_req_addr,
    output wire [31:0] dst_req_data,
    input  wire        dst_req_ready
);
    localparam integer BUF_AW = $clog2(BUF_DEPTH);

    wire start_pulse;
    wire abort_pulse;
    wire irq_en;
    wire [4:0] opcode;
    wire [7:0] qparam;
    wire [31:0] src_desc_ptr;
    wire [31:0] dst_desc_ptr;
    wire [31:0] control;
    wire [31:0] watchdog_cfg;

    wire fsm_busy;
    wire fsm_done;
    wire fsm_error;
    wire [63:0] perf_cnt;
    wire [31:0] watchdog_cnt;

    wire dma_busy;
    wire dma_src_done;
    wire dma_dst_done;
    wire dma_src_error;
    wire dma_dst_error;

    wire dma_start_src;
    wire dma_start_dst;

    wire compute_start;
    wire compute_done;

    wire src_buf_we;
    wire [1:0] src_buf_sel;
    wire [BUF_AW-1:0] src_buf_waddr;
    wire [31:0] src_buf_wdata;

    wire dst_buf_re;
    wire [1:0] dst_buf_sel;
    wire [BUF_AW-1:0] dst_buf_raddr;
    wire [31:0] dst_buf_rdata;

    wire a_rd_en;
    wire [BUF_AW-1:0] a_rd_addr;
    wire [31:0] a_rd_data;

    wire b_rd_en;
    wire [BUF_AW-1:0] b_rd_addr;
    wire [31:0] b_rd_data;

    wire c_wr_en;
    wire [BUF_AW-1:0] c_wr_addr;
    wire [31:0] c_wr_data;
    wire c_rd_en;
    wire [BUF_AW-1:0] c_rd_addr;
    wire [31:0] c_rd_data;

    npu_if_bridge #(
        .BASE_ADDR(MMIO_BASE)
    ) u_bridge (
        .clk(clk),
        .rst_n(rst_n),
        .mmio_addr(data_addr),
        .mmio_wdata(data_out),
        .mmio_write_n(data_write_n),
        .mmio_read_n(data_read_n),
        .mmio_rdata(data_in),
        .mmio_ready(data_ready),
        .start_pulse(start_pulse),
        .abort_pulse(abort_pulse),
        .irq_en(irq_en),
        .opcode(opcode),
        .qparam(qparam),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .control(control),
        .watchdog(watchdog_cfg),
        .busy(fsm_busy),
        .done(fsm_done),
        .error(fsm_error),
        .dma_busy(dma_busy),
        .perf_cnt(perf_cnt),
        .irq(irq)
    );

    dual_dma #(
        .BUF_DEPTH(BUF_DEPTH)
    ) u_dma (
        .clk(clk),
        .rst_n(rst_n),
        .start_src(dma_start_src),
        .start_dst(dma_start_dst),
        .abort(abort_pulse),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .src_done(dma_src_done),
        .dst_done(dma_dst_done),
        .src_error(dma_src_error),
        .dst_error(dma_dst_error),
        .busy(dma_busy),
        .desc_src_req_valid(desc_src_req_valid),
        .desc_src_req_addr(desc_src_req_addr),
        .desc_src_req_ready(desc_src_req_ready),
        .desc_src_rsp_valid(desc_src_rsp_valid),
        .desc_src_rsp_data(desc_src_rsp_data),
        .desc_dst_req_valid(desc_dst_req_valid),
        .desc_dst_req_addr(desc_dst_req_addr),
        .desc_dst_req_ready(desc_dst_req_ready),
        .desc_dst_rsp_valid(desc_dst_rsp_valid),
        .desc_dst_rsp_data(desc_dst_rsp_data),
        .src_req_valid(src_req_valid),
        .src_req_addr(src_req_addr),
        .src_req_ready(src_req_ready),
        .src_rsp_valid(src_rsp_valid),
        .src_rsp_data(src_rsp_data),
        .dst_req_valid(dst_req_valid),
        .dst_req_addr(dst_req_addr),
        .dst_req_data(dst_req_data),
        .dst_req_ready(dst_req_ready),
        .src_buf_we(src_buf_we),
        .src_buf_sel(src_buf_sel),
        .src_buf_waddr(src_buf_waddr),
        .src_buf_wdata(src_buf_wdata),
        .dst_buf_re(dst_buf_re),
        .dst_buf_sel(dst_buf_sel),
        .dst_buf_raddr(dst_buf_raddr),
        .dst_buf_rdata(dst_buf_rdata)
    );

    npu_fsm u_fsm (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_pulse),
        .abort(abort_pulse),
        .qparam(qparam),
        .control(control),
        .watchdog_cfg(watchdog_cfg),
        .dma_start_src(dma_start_src),
        .dma_start_dst(dma_start_dst),
        .dma_src_done(dma_src_done),
        .dma_dst_done(dma_dst_done),
        .dma_src_error(dma_src_error),
        .dma_dst_error(dma_dst_error),
        .compute_start(compute_start),
        .compute_done(compute_done),
        .busy(fsm_busy),
        .done(fsm_done),
        .error(fsm_error),
        .perf_cnt(perf_cnt),
        .watchdog_cnt(watchdog_cnt)
    );

    systolic_array #(
        .N(N),
        .ADDR_WIDTH(BUF_AW)
    ) u_array (
        .clk(clk),
        .rst_n(rst_n),
        .start(compute_start),
        .size(qparam[3:0]),
        .busy(),
        .done(compute_done),
        .a_rd_en(a_rd_en),
        .a_rd_addr(a_rd_addr),
        .a_rd_data(a_rd_data),
        .b_rd_en(b_rd_en),
        .b_rd_addr(b_rd_addr),
        .b_rd_data(b_rd_data),
        .c_wr_en(c_wr_en),
        .c_wr_addr(c_wr_addr),
        .c_wr_data(c_wr_data)
    );

    // Buffer A
    sram_buffer #(
        .DEPTH(BUF_DEPTH),
        .ADDR_WIDTH(BUF_AW)
    ) u_buf_a (
        .clk(clk),
        .we(src_buf_we && (src_buf_sel == 2'd0)),
        .waddr(src_buf_waddr),
        .wdata(src_buf_wdata),
        .re(a_rd_en),
        .raddr(a_rd_addr),
        .rdata(a_rd_data)
    );

    // Buffer B
    sram_buffer #(
        .DEPTH(BUF_DEPTH),
        .ADDR_WIDTH(BUF_AW)
    ) u_buf_b (
        .clk(clk),
        .we(src_buf_we && (src_buf_sel == 2'd1)),
        .waddr(src_buf_waddr),
        .wdata(src_buf_wdata),
        .re(b_rd_en),
        .raddr(b_rd_addr),
        .rdata(b_rd_data)
    );

    // Buffer C (write from array, read by DMA)
    assign c_rd_en = dst_buf_re;
    assign c_rd_addr = dst_buf_raddr;

    sram_buffer #(
        .DEPTH(BUF_DEPTH),
        .ADDR_WIDTH(BUF_AW)
    ) u_buf_c (
        .clk(clk),
        .we(c_wr_en || (src_buf_we && (src_buf_sel == 2'd2))),
        .waddr(c_wr_en ? c_wr_addr : src_buf_waddr),
        .wdata(c_wr_en ? c_wr_data : src_buf_wdata),
        .re(c_rd_en),
        .raddr(c_rd_addr),
        .rdata(c_rd_data)
    );

    assign dst_buf_rdata = (dst_buf_sel == 2'd2) ? c_rd_data : 32'b0;

endmodule

`default_nettype wire
