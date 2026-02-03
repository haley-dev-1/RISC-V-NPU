`default_nettype none

module dual_dma #(
    parameter integer MEM_SIZE_BYTES = 65536,
    parameter integer MAX_LEN_BYTES  = 4096,
    parameter integer BUF_DEPTH      = 256,
    parameter integer ADDR_WIDTH     = 32
) (
    input  wire                 clk,
    input  wire                 rst_n,

    input  wire                 start_src,
    input  wire                 start_dst,
    input  wire                 abort,
    input  wire [31:0]          src_desc_ptr,
    input  wire [31:0]          dst_desc_ptr,

    output reg                  src_done,
    output reg                  dst_done,
    output reg                  src_error,
    output reg                  dst_error,
    output wire                 busy,

    // Descriptor read ports
    output wire                 desc_src_req_valid,
    output wire [31:0]          desc_src_req_addr,
    input  wire                 desc_src_req_ready,
    input  wire                 desc_src_rsp_valid,
    input  wire [31:0]          desc_src_rsp_data,

    output wire                 desc_dst_req_valid,
    output wire [31:0]          desc_dst_req_addr,
    input  wire                 desc_dst_req_ready,
    input  wire                 desc_dst_rsp_valid,
    input  wire [31:0]          desc_dst_rsp_data,

    // SRC data read port
    output wire                 src_req_valid,
    output wire [31:0]          src_req_addr,
    input  wire                 src_req_ready,
    input  wire                 src_rsp_valid,
    input  wire [31:0]          src_rsp_data,

    // DST data write port
    output wire                 dst_req_valid,
    output wire [31:0]          dst_req_addr,
    output wire [31:0]          dst_req_data,
    input  wire                 dst_req_ready,

    // Buffer write port for SRC
    output reg                  src_buf_we,
    output reg  [1:0]           src_buf_sel,
    output reg  [$clog2(BUF_DEPTH)-1:0] src_buf_waddr,
    output reg  [31:0]          src_buf_wdata,

    // Buffer read port for DST
    output wire                 dst_buf_re,
    output wire [1:0]           dst_buf_sel,
    output wire [$clog2(BUF_DEPTH)-1:0] dst_buf_raddr,
    input  wire [31:0]          dst_buf_rdata
);
    localparam integer DESC_WORDS = 6;
    localparam integer DESC_BYTES = DESC_WORDS * 4;
    localparam integer BUF_AW     = $clog2(BUF_DEPTH);
    localparam integer BUF_W      = $clog2(BUF_DEPTH + 1);
    localparam integer MEM_AW     = $clog2(MEM_SIZE_BYTES);
    localparam integer LEN_WORDS_MAX = MAX_LEN_BYTES / 4;
    localparam integer LEN_W      = $clog2(LEN_WORDS_MAX + 1);
    localparam integer ROWS_W     = $clog2(BUF_DEPTH + 1);

    localparam [2:0] SRC_IDLE     = 3'd0;
    localparam [2:0] SRC_DESC     = 3'd1;
    localparam [2:0] SRC_VALIDATE = 3'd2;
    localparam [2:0] SRC_XFER     = 3'd3;
    localparam [2:0] SRC_DONE     = 3'd4;
    localparam [2:0] SRC_ERROR    = 3'd5;

    localparam [2:0] DST_IDLE     = 3'd0;
    localparam [2:0] DST_DESC     = 3'd1;
    localparam [2:0] DST_VALIDATE = 3'd2;
    localparam [2:0] DST_XFER     = 3'd3;
    localparam [2:0] DST_DONE     = 3'd4;
    localparam [2:0] DST_ERROR    = 3'd5;

    reg [2:0] src_state;
    reg [2:0] dst_state;

    reg [31:0] src_desc_ptr_reg;
    reg [31:0] dst_desc_ptr_reg;
    reg [2:0]  src_desc_word;
    reg [2:0]  dst_desc_word;

    reg [31:0] src_base_addr;
    reg [31:0] src_len_bytes;
    reg [31:0] src_stride;
    reg [31:0] src_rows;
    reg [31:0] src_cfg;
    reg [31:0] src_next_ptr;

    reg [31:0] dst_base_addr;
    reg [31:0] dst_len_bytes;
    reg [31:0] dst_stride;
    reg [31:0] dst_rows;
    reg [31:0] dst_cfg;
    reg [31:0] dst_next_ptr;

    reg [MEM_AW-1:0] src_row_base;
    reg [MEM_AW-1:0] src_cur_addr;
    reg [LEN_W-1:0]  src_row_rem;
    reg [ROWS_W-1:0] src_rows_rem;

    reg [MEM_AW-1:0] dst_row_base;
    reg [MEM_AW-1:0] dst_cur_addr;
    reg [LEN_W-1:0]  dst_row_rem;
    reg [ROWS_W-1:0] dst_rows_rem;

    reg [BUF_W-1:0] src_buf_offset_a;
    reg [BUF_W-1:0] src_buf_offset_b;
    reg [BUF_W-1:0] src_buf_offset_c;
    reg [BUF_W-1:0] dst_buf_offset_a;
    reg [BUF_W-1:0] dst_buf_offset_b;
    reg [BUF_W-1:0] dst_buf_offset_c;

    reg [3:0]  src_burst_cnt;
    reg [3:0]  dst_burst_cnt;
    reg        src_burst_gap;
    reg        dst_burst_gap;

    wire [LEN_W-1:0] src_row_words = src_len_bytes >> 2;
    wire [LEN_W-1:0] dst_row_words = dst_len_bytes >> 2;

    wire [3:0] src_burst_len = (src_cfg[7:4] == 4'd0) ? 4'd1 : src_cfg[7:4];
    wire [3:0] dst_burst_len = (dst_cfg[7:4] == 4'd0) ? 4'd1 : dst_cfg[7:4];

    wire [1:0] src_cfg_buf = src_cfg[1:0];
    wire [1:0] dst_cfg_buf = dst_cfg[1:0];

    wire src_active = (src_state == SRC_DESC) || (src_state == SRC_VALIDATE) || (src_state == SRC_XFER);
    wire dst_active = (dst_state == DST_DESC) || (dst_state == DST_VALIDATE) || (dst_state == DST_XFER);
    assign busy = src_active || dst_active;

    assign desc_src_req_valid = (src_state == SRC_DESC);
    assign desc_src_req_addr  = src_desc_ptr_reg + {27'b0, src_desc_word, 2'b00};

    assign desc_dst_req_valid = (dst_state == DST_DESC);
    assign desc_dst_req_addr  = dst_desc_ptr_reg + {27'b0, dst_desc_word, 2'b00};

    assign src_req_valid = (src_state == SRC_XFER) && !src_burst_gap;
    assign src_req_addr  = {{(32-MEM_AW){1'b0}}, src_cur_addr};

    assign dst_req_valid = (dst_state == DST_XFER) && !dst_burst_gap;
    assign dst_req_addr  = {{(32-MEM_AW){1'b0}}, dst_cur_addr};
    assign dst_req_data  = dst_buf_rdata;

    wire src_handshake = src_req_valid && src_req_ready && src_rsp_valid;
    wire dst_handshake = dst_req_valid && dst_req_ready;

    wire [BUF_W-1:0] src_buf_offset_sel = (src_cfg_buf == 2'd0) ? src_buf_offset_a :
                                          (src_cfg_buf == 2'd1) ? src_buf_offset_b :
                                          src_buf_offset_c;
    wire [BUF_W-1:0] dst_buf_offset_sel = (dst_cfg_buf == 2'd0) ? dst_buf_offset_a :
                                          (dst_cfg_buf == 2'd1) ? dst_buf_offset_b :
                                          dst_buf_offset_c;

    assign dst_buf_re   = (dst_state == DST_XFER);
    assign dst_buf_sel  = dst_cfg_buf;
    assign dst_buf_raddr = dst_buf_offset_sel[BUF_AW-1:0];

    wire src_rows_hi = |src_rows[31:ROWS_W];
    wire dst_rows_hi = |dst_rows[31:ROWS_W];

    function automatic bit desc_ptr_valid(input [31:0] ptr);
        begin
            desc_ptr_valid = (ptr[1:0] == 2'b00) && (ptr + DESC_BYTES <= MEM_SIZE_BYTES);
        end
    endfunction

    function automatic bit xfer_bounds_ok(
        input [31:0] base,
        input [31:0] len_bytes,
        input [31:0] stride,
        input [31:0] rows
    );
        reg [31:0] last_addr;
        begin
            if (rows == 0 || len_bytes == 0) begin
                xfer_bounds_ok = 1'b0;
            end else if (len_bytes > MAX_LEN_BYTES) begin
                xfer_bounds_ok = 1'b0;
            end else if (len_bytes[1:0] != 2'b00) begin
                xfer_bounds_ok = 1'b0;
            end else if (base[1:0] != 2'b00) begin
                xfer_bounds_ok = 1'b0;
            end else if (stride[1:0] != 2'b00) begin
                xfer_bounds_ok = 1'b0;
            end else begin
                last_addr = base + ((rows - 1) * stride) + len_bytes;
                xfer_bounds_ok = (base < MEM_SIZE_BYTES) && (last_addr <= MEM_SIZE_BYTES);
            end
        end
    endfunction

    function automatic bit buf_bounds_ok(
        input [LEN_W-1:0] row_words,
        input [ROWS_W-1:0] rows,
        input [BUF_W-1:0] offset
    );
        reg [LEN_W+ROWS_W-1:0] total_words;
        begin
            total_words = row_words * rows;
            buf_bounds_ok = ((total_words + offset) <= BUF_DEPTH);
        end
    endfunction

    always @(posedge clk) begin
        if (!rst_n) begin
            src_state <= SRC_IDLE;
            dst_state <= DST_IDLE;
            src_done <= 1'b0;
            dst_done <= 1'b0;
            src_error <= 1'b0;
            dst_error <= 1'b0;
            src_desc_ptr_reg <= 32'b0;
            dst_desc_ptr_reg <= 32'b0;
            src_desc_word <= 0;
            dst_desc_word <= 0;
            src_row_base <= {MEM_AW{1'b0}};
            src_cur_addr <= {MEM_AW{1'b0}};
            src_row_rem <= {LEN_W{1'b0}};
            src_rows_rem <= {ROWS_W{1'b0}};
            dst_row_base <= {MEM_AW{1'b0}};
            dst_cur_addr <= {MEM_AW{1'b0}};
            dst_row_rem <= {LEN_W{1'b0}};
            dst_rows_rem <= {ROWS_W{1'b0}};
            src_buf_offset_a <= 0;
            src_buf_offset_b <= 0;
            src_buf_offset_c <= 0;
            dst_buf_offset_a <= 0;
            dst_buf_offset_b <= 0;
            dst_buf_offset_c <= 0;
            src_burst_cnt <= 0;
            dst_burst_cnt <= 0;
            src_burst_gap <= 1'b0;
            dst_burst_gap <= 1'b0;
            src_buf_we <= 1'b0;
            src_buf_sel <= 2'b00;
            src_buf_waddr <= {BUF_AW{1'b0}};
            src_buf_wdata <= 32'b0;
        end else begin
            src_buf_we <= 1'b0;

            if (start_src) begin
                src_done <= 1'b0;
                src_error <= 1'b0;
            end
            if (start_dst) begin
                dst_done <= 1'b0;
                dst_error <= 1'b0;
            end

            if (abort) begin
                src_state <= SRC_ERROR;
                dst_state <= DST_ERROR;
            end else begin
                // SRC state machine
                case (src_state)
                    SRC_IDLE: begin
                        if (start_src) begin
                            if (!desc_ptr_valid(src_desc_ptr)) begin
                                src_error <= 1'b1;
                                src_state <= SRC_ERROR;
                            end else begin
                                src_desc_ptr_reg <= src_desc_ptr;
                                src_desc_word <= 0;
                                src_buf_offset_a <= 0;
                                src_buf_offset_b <= 0;
                                src_buf_offset_c <= 0;
                                src_state <= SRC_DESC;
                            end
                        end
                    end

                    SRC_DESC: begin
                        if (desc_src_req_ready && desc_src_rsp_valid) begin
                            case (src_desc_word)
                                3'd0: src_base_addr <= desc_src_rsp_data;
                                3'd1: src_len_bytes <= desc_src_rsp_data;
                                3'd2: src_stride <= desc_src_rsp_data;
                                3'd3: src_rows <= desc_src_rsp_data;
                                3'd4: src_cfg <= desc_src_rsp_data;
                                3'd5: src_next_ptr <= desc_src_rsp_data;
                                default: begin end
                            endcase

                            if (src_desc_word == DESC_WORDS-1) begin
                                src_state <= SRC_VALIDATE;
                            end else begin
                                src_desc_word <= src_desc_word + 1'b1;
                            end
                        end
                    end

                    SRC_VALIDATE: begin
                        if (src_rows_hi ||
                            !xfer_bounds_ok(src_base_addr, src_len_bytes, src_stride, src_rows) ||
                            !buf_bounds_ok(src_row_words, src_rows[ROWS_W-1:0], src_buf_offset_sel)) begin
                            src_error <= 1'b1;
                            src_state <= SRC_ERROR;
                        end else begin
                            src_row_base <= src_base_addr[MEM_AW-1:0];
                            src_cur_addr <= src_base_addr[MEM_AW-1:0];
                            src_row_rem <= src_row_words;
                            src_rows_rem <= src_rows[ROWS_W-1:0];
                            src_burst_cnt <= 0;
                            src_burst_gap <= 1'b0;
                            src_state <= SRC_XFER;
                        end
                    end

                    SRC_XFER: begin
                        if (src_handshake) begin
                            src_buf_we <= 1'b1;
                            src_buf_sel <= src_cfg_buf;
                        src_buf_waddr <= src_buf_offset_sel[BUF_AW-1:0];
                            src_buf_wdata <= src_rsp_data;

                            case (src_cfg_buf)
                                2'd0: src_buf_offset_a <= src_buf_offset_a + 1'b1;
                                2'd1: src_buf_offset_b <= src_buf_offset_b + 1'b1;
                                2'd2: src_buf_offset_c <= src_buf_offset_c + 1'b1;
                                default: begin end
                            endcase

                            if (src_row_rem == {{(LEN_W-1){1'b0}},1'b1}) begin
                                if (src_rows_rem == {{(ROWS_W-1){1'b0}},1'b1}) begin
                                    if (src_next_ptr != 0) begin
                                        if (!desc_ptr_valid(src_next_ptr)) begin
                                            src_error <= 1'b1;
                                            src_state <= SRC_ERROR;
                                        end else begin
                                            src_desc_ptr_reg <= src_next_ptr;
                                            src_desc_word <= 0;
                                            src_state <= SRC_DESC;
                                        end
                                    end else begin
                                        src_state <= SRC_DONE;
                                    end
                                end else begin
                                    src_rows_rem <= src_rows_rem - 1'b1;
                                    src_row_rem <= src_row_words;
                                    src_row_base <= src_row_base + src_stride[MEM_AW-1:0];
                                    src_cur_addr <= src_row_base + src_stride[MEM_AW-1:0];
                                end
                            end else begin
                                src_row_rem <= src_row_rem - 1'b1;
                                src_cur_addr <= src_cur_addr + 4;
                            end

                            if (src_burst_cnt + 1 >= src_burst_len) begin
                                src_burst_cnt <= 0;
                                src_burst_gap <= 1'b1;
                            end else begin
                                src_burst_cnt <= src_burst_cnt + 1'b1;
                            end
                        end else if (src_burst_gap) begin
                            src_burst_gap <= 1'b0;
                        end
                    end

                    SRC_DONE: begin
                        src_done <= 1'b1;
                        src_state <= SRC_IDLE;
                    end

                    SRC_ERROR: begin
                        src_error <= 1'b1;
                        src_state <= SRC_IDLE;
                    end

                    default: src_state <= SRC_IDLE;
                endcase

                // DST state machine
                case (dst_state)
                    DST_IDLE: begin
                        if (start_dst) begin
                            if (!desc_ptr_valid(dst_desc_ptr)) begin
                                dst_error <= 1'b1;
                                dst_state <= DST_ERROR;
                            end else begin
                                dst_desc_ptr_reg <= dst_desc_ptr;
                                dst_desc_word <= 0;
                                dst_buf_offset_a <= 0;
                                dst_buf_offset_b <= 0;
                                dst_buf_offset_c <= 0;
                                dst_state <= DST_DESC;
                            end
                        end
                    end

                    DST_DESC: begin
                        if (desc_dst_req_ready && desc_dst_rsp_valid) begin
                            case (dst_desc_word)
                                3'd0: dst_base_addr <= desc_dst_rsp_data;
                                3'd1: dst_len_bytes <= desc_dst_rsp_data;
                                3'd2: dst_stride <= desc_dst_rsp_data;
                                3'd3: dst_rows <= desc_dst_rsp_data;
                                3'd4: dst_cfg <= desc_dst_rsp_data;
                                3'd5: dst_next_ptr <= desc_dst_rsp_data;
                                default: begin end
                            endcase

                            if (dst_desc_word == DESC_WORDS-1) begin
                                dst_state <= DST_VALIDATE;
                            end else begin
                                dst_desc_word <= dst_desc_word + 1'b1;
                            end
                        end
                    end

                    DST_VALIDATE: begin
                        if (dst_rows_hi ||
                            !xfer_bounds_ok(dst_base_addr, dst_len_bytes, dst_stride, dst_rows) ||
                            !buf_bounds_ok(dst_row_words, dst_rows[ROWS_W-1:0], dst_buf_offset_sel)) begin
                            dst_error <= 1'b1;
                            dst_state <= DST_ERROR;
                        end else begin
                            dst_row_base <= dst_base_addr[MEM_AW-1:0];
                            dst_cur_addr <= dst_base_addr[MEM_AW-1:0];
                            dst_row_rem <= dst_row_words;
                            dst_rows_rem <= dst_rows[ROWS_W-1:0];
                            dst_burst_cnt <= 0;
                            dst_burst_gap <= 1'b0;
                            dst_state <= DST_XFER;
                        end
                    end

                    DST_XFER: begin
                        if (dst_handshake) begin
                            case (dst_cfg_buf)
                                2'd0: dst_buf_offset_a <= dst_buf_offset_a + 1'b1;
                                2'd1: dst_buf_offset_b <= dst_buf_offset_b + 1'b1;
                                2'd2: dst_buf_offset_c <= dst_buf_offset_c + 1'b1;
                                default: begin end
                            endcase

                            if (dst_row_rem == {{(LEN_W-1){1'b0}},1'b1}) begin
                                if (dst_rows_rem == {{(ROWS_W-1){1'b0}},1'b1}) begin
                                    if (dst_next_ptr != 0) begin
                                        if (!desc_ptr_valid(dst_next_ptr)) begin
                                            dst_error <= 1'b1;
                                            dst_state <= DST_ERROR;
                                        end else begin
                                            dst_desc_ptr_reg <= dst_next_ptr;
                                            dst_desc_word <= 0;
                                            dst_state <= DST_DESC;
                                        end
                                    end else begin
                                        dst_state <= DST_DONE;
                                    end
                                end else begin
                                    dst_rows_rem <= dst_rows_rem - 1'b1;
                                    dst_row_rem <= dst_row_words;
                                    dst_row_base <= dst_row_base + dst_stride[MEM_AW-1:0];
                                    dst_cur_addr <= dst_row_base + dst_stride[MEM_AW-1:0];
                                end
                            end else begin
                                dst_row_rem <= dst_row_rem - 1'b1;
                                dst_cur_addr <= dst_cur_addr + 4;
                            end

                            if (dst_burst_cnt + 1 >= dst_burst_len) begin
                                dst_burst_cnt <= 0;
                                dst_burst_gap <= 1'b1;
                            end else begin
                                dst_burst_cnt <= dst_burst_cnt + 1'b1;
                            end
                        end else if (dst_burst_gap) begin
                            dst_burst_gap <= 1'b0;
                        end
                    end

                    DST_DONE: begin
                        dst_done <= 1'b1;
                        dst_state <= DST_IDLE;
                    end

                    DST_ERROR: begin
                        dst_error <= 1'b1;
                        dst_state <= DST_IDLE;
                    end

                    default: dst_state <= DST_IDLE;
                endcase
            end
        end
    end
endmodule

`default_nettype wire
