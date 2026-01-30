/*
 * dual_dma.v
 *
 * LLM-generated dual-channel DMA engine with descriptor-driven 2D strided access
 * and burst grouping. SRC channel loads system memory into input SRAM. DST channel
 * stores output SRAM into system memory.
 */

`default_nettype none

module dual_dma #(
    parameter MEM_BASE = 32'h0000_0000,
    parameter MEM_SIZE = 32'h0001_0000,
    parameter MAX_LEN  = 32'h0001_0000,
    parameter BUF_AW   = 7
) (
    input  wire        clk,
    input  wire        rst_n,

    input  wire        start_load,
    input  wire        start_store,
    input  wire        abort,

    input  wire [31:0] src_desc_ptr,
    input  wire [31:0] dst_desc_ptr,
    input  wire [31:0] control,

    // Shared system memory read port
    output wire        mem_rd_req,
    output wire [31:0] mem_rd_addr,
    input  wire        mem_rd_ready,
    input  wire        mem_rd_valid,
    input  wire [31:0] mem_rd_data,

    // System memory write port
    output wire        mem_wr_req,
    output wire [31:0] mem_wr_addr,
    output wire [31:0] mem_wr_data,
    input  wire        mem_wr_ready,

    // Input buffer write port (LOAD)
    output reg         in_buf_wr_en,
    output reg  [BUF_AW-1:0] in_buf_wr_addr,
    output reg  [31:0] in_buf_wr_data,

    // Output buffer read port (STORE)
    output reg         out_buf_rd_en,
    output reg  [BUF_AW-1:0] out_buf_rd_addr,
    input  wire        out_buf_rd_valid,
    input  wire [31:0] out_buf_rd_data,

    output wire        load_busy,
    output wire        store_busy,
    output wire        dma_busy,
    output reg         load_done,
    output reg         store_done,
    output reg         error
);

    localparam [2:0] CH_IDLE  = 3'd0;
    localparam [2:0] CH_DESC0 = 3'd1;
    localparam [2:0] CH_DESC1 = 3'd2;
    localparam [2:0] CH_DESC2 = 3'd3;
    localparam [2:0] CH_DESC3 = 3'd4;
    localparam [2:0] CH_RUN   = 3'd5;
    localparam [2:0] CH_DONE  = 3'd6;
    localparam [2:0] CH_ERR   = 3'd7;

    localparam DESC_BYTES = 16;

    // Configuration
    wire [7:0] cfg_burst_words = (control[7:0] == 8'd0) ? 8'd1 : control[7:0];
    wire [7:0] cfg_rows = (control[15:8] == 8'd0) ? 8'd1 : control[15:8];

    // SRC (load) state
    reg [2:0]  src_state;
    reg [31:0] src_desc_ptr_q;
    reg [31:0] src_desc_addr;
    reg [31:0] src_desc_len;
    reg [15:0] src_desc_stride;
    reg [15:0] src_desc_flags;
    reg [31:0] src_cur_addr;
    reg [31:0] src_row_words;
    reg [31:0] src_row_idx;
    reg [31:0] src_col_idx;
    reg [BUF_AW-1:0] src_buf_addr;
    reg [7:0]  src_burst_cnt;
    reg        src_burst_gap;

    // DST (store) state
    reg [2:0]  dst_state;
    reg [31:0] dst_desc_ptr_q;
    reg [31:0] dst_desc_addr;
    reg [31:0] dst_desc_len;
    reg [15:0] dst_desc_stride;
    reg [15:0] dst_desc_flags;
    reg [31:0] dst_cur_addr;
    reg [31:0] dst_row_words;
    reg [31:0] dst_row_idx;
    reg [31:0] dst_col_idx;
    reg [BUF_AW-1:0] dst_buf_addr;
    reg [7:0]  dst_burst_cnt;
    reg        dst_burst_gap;
    reg        dst_wr_pending;
    reg [31:0] dst_wr_data_q;
    reg        dst_buf_pending;

    // Read engine (single outstanding)
    reg        rd_busy;
    reg [1:0]  rd_owner; // 0=SRC_DESC,1=DST_DESC,2=SRC_DATA

    wire want_src_desc = (src_state == CH_DESC0) || (src_state == CH_DESC1) || (src_state == CH_DESC2) || (src_state == CH_DESC3);
    wire want_dst_desc = (dst_state == CH_DESC0) || (dst_state == CH_DESC1) || (dst_state == CH_DESC2) || (dst_state == CH_DESC3);
    wire want_src_data = (src_state == CH_RUN) && !src_burst_gap && (src_row_idx < cfg_rows) && (src_col_idx < src_row_words);

    wire [31:0] src_desc_addr_sel = (src_state == CH_DESC0) ? src_desc_ptr_q :
                                    (src_state == CH_DESC1) ? (src_desc_ptr_q + 32'd4) :
                                    (src_state == CH_DESC2) ? (src_desc_ptr_q + 32'd8) :
                                    (src_state == CH_DESC3) ? (src_desc_ptr_q + 32'd12) : 32'd0;

    wire [31:0] dst_desc_addr_sel = (dst_state == CH_DESC0) ? dst_desc_ptr_q :
                                    (dst_state == CH_DESC1) ? (dst_desc_ptr_q + 32'd4) :
                                    (dst_state == CH_DESC2) ? (dst_desc_ptr_q + 32'd8) :
                                    (dst_state == CH_DESC3) ? (dst_desc_ptr_q + 32'd12) : 32'd0;

    wire [1:0] sel_owner = want_src_desc ? 2'd0 : (want_dst_desc ? 2'd1 : 2'd2);
    wire [31:0] sel_addr = want_src_desc ? src_desc_addr_sel : (want_dst_desc ? dst_desc_addr_sel : src_cur_addr);

    assign mem_rd_req  = !rd_busy && mem_rd_ready && (want_src_desc || want_dst_desc || want_src_data);
    assign mem_rd_addr = sel_addr;

    assign mem_wr_req  = dst_wr_pending;
    assign mem_wr_addr = dst_cur_addr;
    assign mem_wr_data = dst_wr_data_q;

    assign load_busy  = (src_state != CH_IDLE) && (src_state != CH_DONE) && (src_state != CH_ERR);
    assign store_busy = (dst_state != CH_IDLE) && (dst_state != CH_DONE) && (dst_state != CH_ERR);
    assign dma_busy   = load_busy || store_busy;

    // Validity checks
    function automatic desc_ptr_valid;
        input [31:0] ptr;
        begin
            desc_ptr_valid = (ptr >= MEM_BASE) && (ptr + DESC_BYTES <= MEM_BASE + MEM_SIZE) && (ptr[1:0] == 2'b00);
        end
    endfunction

    function automatic range_valid;
        input [31:0] addr;
        input [31:0] len;
        input [15:0] stride;
        input [7:0]  rows;
        reg [63:0] last_addr;
        reg [31:0] use_stride;
        begin
            use_stride = (stride == 16'd0) ? len : {16'd0, stride};
            last_addr  = addr + (rows - 1) * use_stride + len;
            range_valid = (addr >= MEM_BASE) && (last_addr <= (MEM_BASE + MEM_SIZE));
        end
    endfunction

    // Read engine owner latch
    always @(posedge clk) begin
        if (!rst_n) begin
            rd_busy  <= 1'b0;
            rd_owner <= 2'd0;
        end else begin
            if (mem_rd_req) begin
                rd_busy  <= 1'b1;
                rd_owner <= sel_owner;
            end
            if (rd_busy && mem_rd_valid) begin
                rd_busy <= 1'b0;
            end
        end
    end

    // SRC channel
    always @(posedge clk) begin
        if (!rst_n) begin
            src_state       <= CH_IDLE;
            src_desc_ptr_q  <= 32'd0;
            src_desc_addr   <= 32'd0;
            src_desc_len    <= 32'd0;
            src_desc_stride <= 16'd0;
            src_desc_flags  <= 16'd0;
            src_cur_addr    <= 32'd0;
            src_row_words   <= 32'd0;
            src_row_idx     <= 32'd0;
            src_col_idx     <= 32'd0;
            src_buf_addr    <= {BUF_AW{1'b0}};
            src_burst_cnt   <= 8'd0;
            src_burst_gap   <= 1'b0;
            load_done       <= 1'b0;
        end else begin
            in_buf_wr_en <= 1'b0;

            if (start_load) begin
                src_state      <= CH_DESC0;
                src_desc_ptr_q <= src_desc_ptr;
                src_buf_addr   <= {BUF_AW{1'b0}};
                src_burst_cnt  <= 8'd0;
                src_burst_gap  <= 1'b0;
                load_done      <= 1'b0;
            end

            if (abort) begin
                src_state <= CH_IDLE;
            end

            if (mem_rd_valid && rd_owner == 2'd0) begin
                if (src_state == CH_DESC0) begin
                    src_desc_addr <= mem_rd_data;
                    src_state <= CH_DESC1;
                end else if (src_state == CH_DESC1) begin
                    src_desc_len <= mem_rd_data;
                    src_state <= CH_DESC2;
                end else if (src_state == CH_DESC2) begin
                    src_desc_stride <= mem_rd_data[15:0];
                    src_desc_flags  <= mem_rd_data[31:16];
                    // Validate here without waiting for DESC3
                    if (!desc_ptr_valid(src_desc_ptr_q) ||
                        (src_desc_len == 32'd0) ||
                        (src_desc_len > MAX_LEN) ||
                        (src_desc_len[1:0] != 2'b00) ||
                        !range_valid(src_desc_addr, src_desc_len, mem_rd_data[15:0], cfg_rows)) begin
                        src_state <= CH_ERR;
                    end else begin
                        src_state <= CH_DESC3;
                    end
                end else if (src_state == CH_DESC3) begin
                    src_row_words <= (src_desc_len >> 2);
                    src_row_idx   <= 32'd0;
                    src_col_idx   <= 32'd0;
                    src_cur_addr  <= src_desc_addr;
                    src_state     <= CH_RUN;
                end
            end

            if (mem_rd_valid && rd_owner == 2'd2 && src_state == CH_RUN) begin
                in_buf_wr_en   <= 1'b1;
                in_buf_wr_addr <= src_buf_addr;
                in_buf_wr_data <= mem_rd_data;
                src_buf_addr   <= src_buf_addr + 1'b1;

                // Advance burst
                src_burst_cnt <= src_burst_cnt + 8'd1;
                if (src_burst_cnt + 8'd1 >= cfg_burst_words) begin
                    src_burst_cnt <= 8'd0;
                    src_burst_gap <= 1'b1;
                end

                // Advance addresses
                src_col_idx <= src_col_idx + 32'd1;
                src_cur_addr <= src_cur_addr + 32'd4;

                if (src_col_idx + 32'd1 >= src_row_words) begin
                    src_col_idx <= 32'd0;
                    src_row_idx <= src_row_idx + 32'd1;
                    src_cur_addr <= src_desc_addr + (src_row_idx + 32'd1) * ((src_desc_stride == 16'd0) ? src_desc_len : {16'd0, src_desc_stride});

                    if (src_row_idx + 32'd1 >= cfg_rows) begin
                        if (src_desc_flags[0]) begin
                            src_state <= CH_DONE;
                            load_done <= 1'b1;
                        end else begin
                            src_desc_ptr_q <= src_desc_ptr_q + DESC_BYTES;
                            src_state <= CH_DESC0;
                        end
                    end
                end
            end

            if (src_burst_gap) begin
                src_burst_gap <= 1'b0;
            end
        end
    end

    // DST channel
    always @(posedge clk) begin
        if (!rst_n) begin
            dst_state       <= CH_IDLE;
            dst_desc_ptr_q  <= 32'd0;
            dst_desc_addr   <= 32'd0;
            dst_desc_len    <= 32'd0;
            dst_desc_stride <= 16'd0;
            dst_desc_flags  <= 16'd0;
            dst_cur_addr    <= 32'd0;
            dst_row_words   <= 32'd0;
            dst_row_idx     <= 32'd0;
            dst_col_idx     <= 32'd0;
            dst_buf_addr    <= {BUF_AW{1'b0}};
            dst_burst_cnt   <= 8'd0;
            dst_burst_gap   <= 1'b0;
            dst_wr_pending  <= 1'b0;
            dst_wr_data_q   <= 32'd0;
            dst_buf_pending <= 1'b0;
            store_done      <= 1'b0;
        end else begin
            out_buf_rd_en <= 1'b0;

            if (start_store) begin
                dst_state      <= CH_DESC0;
                dst_desc_ptr_q <= dst_desc_ptr;
                dst_buf_addr   <= {BUF_AW{1'b0}};
                dst_burst_cnt  <= 8'd0;
                dst_burst_gap  <= 1'b0;
                dst_wr_pending <= 1'b0;
                dst_buf_pending<= 1'b0;
                store_done     <= 1'b0;
            end

            if (abort) begin
                dst_state <= CH_IDLE;
                dst_wr_pending <= 1'b0;
                dst_buf_pending<= 1'b0;
            end

            if (mem_rd_valid && rd_owner == 2'd1) begin
                if (dst_state == CH_DESC0) begin
                    dst_desc_addr <= mem_rd_data;
                    dst_state <= CH_DESC1;
                end else if (dst_state == CH_DESC1) begin
                    dst_desc_len <= mem_rd_data;
                    dst_state <= CH_DESC2;
                end else if (dst_state == CH_DESC2) begin
                    dst_desc_stride <= mem_rd_data[15:0];
                    dst_desc_flags  <= mem_rd_data[31:16];
                    if (!desc_ptr_valid(dst_desc_ptr_q) ||
                        (dst_desc_len == 32'd0) ||
                        (dst_desc_len > MAX_LEN) ||
                        (dst_desc_len[1:0] != 2'b00) ||
                        !range_valid(dst_desc_addr, dst_desc_len, mem_rd_data[15:0], cfg_rows)) begin
                        dst_state <= CH_ERR;
                    end else begin
                        dst_state <= CH_DESC3;
                    end
                end else if (dst_state == CH_DESC3) begin
                    dst_row_words <= (dst_desc_len >> 2);
                    dst_row_idx   <= 32'd0;
                    dst_col_idx   <= 32'd0;
                    dst_cur_addr  <= dst_desc_addr;
                    dst_state     <= CH_RUN;
                end
            end

            if (dst_state == CH_RUN) begin
                if (!dst_buf_pending && !dst_wr_pending && !dst_burst_gap && (dst_row_idx < cfg_rows) && (dst_col_idx < dst_row_words)) begin
                    out_buf_rd_en   <= 1'b1;
                    out_buf_rd_addr <= dst_buf_addr;
                    dst_buf_pending <= 1'b1;
                end

                if (dst_buf_pending && out_buf_rd_valid && !dst_wr_pending) begin
                    dst_wr_data_q   <= out_buf_rd_data;
                    dst_wr_pending  <= 1'b1;
                    dst_buf_pending <= 1'b0;
                end

                if (dst_wr_pending && mem_wr_ready) begin
                    dst_wr_pending <= 1'b0;
                    dst_buf_addr   <= dst_buf_addr + 1'b1;
                    dst_cur_addr   <= dst_cur_addr + 32'd4;
                    dst_col_idx    <= dst_col_idx + 32'd1;

                    dst_burst_cnt <= dst_burst_cnt + 8'd1;
                    if (dst_burst_cnt + 8'd1 >= cfg_burst_words) begin
                        dst_burst_cnt <= 8'd0;
                        dst_burst_gap <= 1'b1;
                    end

                    if (dst_col_idx + 32'd1 >= dst_row_words) begin
                        dst_col_idx <= 32'd0;
                        dst_row_idx <= dst_row_idx + 32'd1;
                        dst_cur_addr <= dst_desc_addr + (dst_row_idx + 32'd1) * ((dst_desc_stride == 16'd0) ? dst_desc_len : {16'd0, dst_desc_stride});

                        if (dst_row_idx + 32'd1 >= cfg_rows) begin
                            if (dst_desc_flags[0]) begin
                                dst_state <= CH_DONE;
                                store_done <= 1'b1;
                            end else begin
                                dst_desc_ptr_q <= dst_desc_ptr_q + DESC_BYTES;
                                dst_state <= CH_DESC0;
                            end
                        end
                    end
                end
            end

            if (dst_burst_gap) begin
                dst_burst_gap <= 1'b0;
            end
        end
    end

    // Error handling
    always @(posedge clk) begin
        if (!rst_n) begin
            error <= 1'b0;
        end else begin
            if (start_load || start_store) begin
                error <= 1'b0;
            end
            if (abort || src_state == CH_ERR || dst_state == CH_ERR) begin
                error <= 1'b1;
            end
        end
    end

endmodule

`default_nettype wire
