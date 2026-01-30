/*
 * tinyQV NPU peripheral integration
 *
 * LLM-generated peripheral: MMIO bridge + tinyQV_top + internal memory model.
 */

`default_nettype none

module tqvp_npu (
    input         clk,
    input         rst_n,

    input  [7:0]  ui_in,
    output [7:0]  uo_out,

    input  [5:0]  address,
    input  [31:0] data_in,

    input  [1:0]  data_write_n,
    input  [1:0]  data_read_n,

    output [31:0] data_out,
    output        data_ready,

    output        user_interrupt
);

    localparam MEM_WORDS = 1024;
    localparam MEM_BYTES = MEM_WORDS * 4;
    localparam ADDR_BITS = 10; // log2(1024)

    // MMIO bridge signals
    wire        npu_start;
    wire        npu_abort;
    wire [31:0] src_desc_ptr;
    wire [31:0] dst_desc_ptr;
    wire [31:0] control;
    wire [4:0]  opcode;
    wire [7:0]  qparam;

    wire        npu_busy;
    wire        npu_done;
    wire        npu_error;
    wire        dma_busy;

    // System memory interface
    wire        mem_rd_req;
    wire [31:0] mem_rd_addr;
    wire        mem_rd_ready;
    wire        mem_rd_valid;
    wire [31:0] mem_rd_data;

    wire        mem_wr_req;
    wire [31:0] mem_wr_addr;
    wire [31:0] mem_wr_data;
    wire        mem_wr_ready;

    // Internal memory model
    reg [31:0] mem [0:MEM_WORDS-1];
    reg        rd_pending;
    reg [ADDR_BITS-1:0] rd_addr_q;
    reg        mem_rd_valid_r;
    reg [31:0] mem_rd_data_r;

    assign mem_rd_ready = !rd_pending;
    assign mem_rd_valid = mem_rd_valid_r;
    assign mem_rd_data  = mem_rd_data_r;
    assign mem_wr_ready = 1'b1;

    always @(posedge clk) begin
        if (!rst_n) begin
            rd_pending     <= 1'b0;
            mem_rd_valid_r <= 1'b0;
            mem_rd_data_r  <= 32'd0;
            rd_addr_q      <= {ADDR_BITS{1'b0}};
        end else begin
            mem_rd_valid_r <= 1'b0;
            if (rd_pending) begin
                mem_rd_valid_r <= 1'b1;
                mem_rd_data_r  <= mem[rd_addr_q];
                rd_pending     <= 1'b0;
            end

            if (mem_rd_req && mem_rd_ready) begin
                rd_addr_q  <= mem_rd_addr[ADDR_BITS+1:2];
                rd_pending <= 1'b1;
            end

            if (mem_wr_req && mem_wr_ready) begin
                mem[mem_wr_addr[ADDR_BITS+1:2]] <= mem_wr_data;
            end
        end
    end

    // MMIO bridge
    npu_if_bridge #(
        .MEM_BASE(32'h0000_0000),
        .MEM_SIZE(MEM_BYTES)
    ) bridge (
        .clk(clk),
        .rst_n(rst_n),
        .address(address),
        .data_in(data_in),
        .data_write_n(data_write_n),
        .data_read_n(data_read_n),
        .data_out(data_out),
        .data_ready(data_ready),
        .user_interrupt(user_interrupt),
        .npu_start(npu_start),
        .npu_abort(npu_abort),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .control(control),
        .opcode(opcode),
        .qparam(qparam),
        .npu_busy(npu_busy),
        .npu_done(npu_done),
        .npu_error(npu_error),
        .dma_busy(dma_busy)
    );

    // NPU top
    tinyQV_top #(
        .N(4),
        .DATA_W(16),
        .ACC_W(32),
        .BUF_DEPTH(128),
        .BUF_AW(7)
    ) npu (
        .clk(clk),
        .rst_n(rst_n),
        .start(npu_start),
        .abort(npu_abort),
        .opcode(opcode),
        .qparam(qparam),
        .control(control),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .mem_rd_req(mem_rd_req),
        .mem_rd_addr(mem_rd_addr),
        .mem_rd_ready(mem_rd_ready),
        .mem_rd_valid(mem_rd_valid),
        .mem_rd_data(mem_rd_data),
        .mem_wr_req(mem_wr_req),
        .mem_wr_addr(mem_wr_addr),
        .mem_wr_data(mem_wr_data),
        .mem_wr_ready(mem_wr_ready),
        .dma_busy(dma_busy),
        .busy(npu_busy),
        .done(npu_done),
        .error(npu_error)
    );

    // Debug outputs
    assign uo_out[0] = npu_busy;
    assign uo_out[1] = npu_done;
    assign uo_out[2] = npu_error;
    assign uo_out[3] = dma_busy;
    assign uo_out[7:4] = opcode[3:0];

    wire _unused = &{ui_in, 1'b0};

endmodule

`default_nettype wire
