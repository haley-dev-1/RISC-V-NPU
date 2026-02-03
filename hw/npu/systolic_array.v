`default_nettype none

module systolic_array #(
    parameter integer N = 4,
    parameter integer ADDR_WIDTH = 8
) (
    input  wire                 clk,
    input  wire                 rst_n,
    input  wire                 start,
    input  wire [3:0]           size,
    output reg                  busy,
    output reg                  done,

    output reg                  a_rd_en,
    output reg  [ADDR_WIDTH-1:0] a_rd_addr,
    input  wire [31:0]          a_rd_data,

    output reg                  b_rd_en,
    output reg  [ADDR_WIDTH-1:0] b_rd_addr,
    input  wire [31:0]          b_rd_data,

    output reg                  c_wr_en,
    output reg  [ADDR_WIDTH-1:0] c_wr_addr,
    output reg  [31:0]          c_wr_data
);
    localparam integer MAX_ELEMS = N * N;

    reg [31:0] b_weight [0:MAX_ELEMS-1];
    reg [3:0] size_eff;
    reg [3:0] size_m1;

    reg [1:0] state;
    localparam [1:0] ST_IDLE   = 2'd0;
    localparam [1:0] ST_LOAD_B = 2'd1;
    localparam [1:0] ST_COMP   = 2'd2;
    localparam [1:0] ST_DONE   = 2'd3;

    reg [ADDR_WIDTH-1:0] b_load_addr;
    reg [3:0] b_load_row;
    reg [3:0] b_load_col;
    reg [3:0] i_idx;
    reg [3:0] j_idx;
    reg [3:0] k_idx;
    reg [31:0] acc;
    reg [ADDR_WIDTH-1:0] a_row_base;
    reg [ADDR_WIDTH-1:0] c_row_base;
    reg [ADDR_WIDTH-1:0] b_row_base;

    wire [31:0] mac_result;
    wire [ADDR_WIDTH-1:0] b_index = b_row_base + j_idx;

    function automatic [3:0] clamp_size(input [3:0] in_size);
        begin
            if (in_size == 0) begin
                clamp_size = N[3:0];
            end else if (in_size > N[3:0]) begin
                clamp_size = N[3:0];
            end else begin
                clamp_size = in_size;
            end
        end
    endfunction

    mac32 u_mac (
        .a(a_rd_data),
        .b(b_weight[b_index]),
        .acc(acc),
        .sat_en(1'b1),
        .result(mac_result),
        .overflow()
    );

    integer bi;
    always @(*) begin
        a_rd_en = (state == ST_COMP);
        a_rd_addr = a_row_base + k_idx;
        b_rd_en = (state == ST_LOAD_B);
        b_rd_addr = b_load_addr;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            state <= ST_IDLE;
            busy <= 1'b0;
            done <= 1'b0;
            c_wr_en <= 1'b0;
            c_wr_addr <= {ADDR_WIDTH{1'b0}};
            c_wr_data <= 32'b0;
            b_load_addr <= 0;
            b_load_row <= 0;
            b_load_col <= 0;
            i_idx <= 0;
            j_idx <= 0;
            k_idx <= 0;
            acc <= 32'b0;
            a_row_base <= 0;
            c_row_base <= 0;
            b_row_base <= 0;
            size_eff <= N[3:0];
            size_m1 <= N[3:0] - 1'b1;
            for (bi = 0; bi < MAX_ELEMS; bi = bi + 1) begin
                b_weight[bi] <= 32'b0;
            end
        end else begin
            done <= 1'b0;
            c_wr_en <= 1'b0;

            case (state)
                ST_IDLE: begin
                    busy <= 1'b0;
                    if (start) begin
                        size_eff <= clamp_size(size);
                        size_m1 <= clamp_size(size) - 1'b1;
                        b_load_addr <= 0;
                        b_load_row <= 0;
                        b_load_col <= 0;
                        i_idx <= 0;
                        j_idx <= 0;
                        k_idx <= 0;
                        acc <= 32'b0;
                        a_row_base <= 0;
                        c_row_base <= 0;
                        b_row_base <= 0;
                        busy <= 1'b1;
                        state <= ST_LOAD_B;
                    end
                end

                ST_LOAD_B: begin
                    b_weight[b_load_addr] <= b_rd_data;

                    b_load_addr <= b_load_addr + 1'b1;
                    if (b_load_col == size_m1) begin
                        b_load_col <= 0;
                        if (b_load_row == size_m1) begin
                            i_idx <= 0;
                            j_idx <= 0;
                            k_idx <= 0;
                            acc <= 32'b0;
                            a_row_base <= 0;
                            c_row_base <= 0;
                            b_row_base <= 0;
                            state <= ST_COMP;
                        end else begin
                            b_load_row <= b_load_row + 1'b1;
                        end
                    end else begin
                        b_load_col <= b_load_col + 1'b1;
                    end
                end

                ST_COMP: begin
                    if (k_idx == size_m1) begin
                        c_wr_en <= 1'b1;
                        c_wr_addr <= c_row_base + j_idx;
                        c_wr_data <= mac_result;

                        acc <= 32'b0;
                        k_idx <= 0;
                        b_row_base <= 0;
                        if (j_idx == size_m1) begin
                            j_idx <= 0;
                            if (i_idx == size_m1) begin
                                state <= ST_DONE;
                            end else begin
                                i_idx <= i_idx + 1'b1;
                                a_row_base <= a_row_base + size_eff;
                                c_row_base <= c_row_base + size_eff;
                            end
                        end else begin
                            j_idx <= j_idx + 1'b1;
                        end
                    end else begin
                        acc <= mac_result;
                        k_idx <= k_idx + 1'b1;
                        b_row_base <= b_row_base + size_eff;
                    end
                end

                ST_DONE: begin
                    busy <= 1'b0;
                    done <= 1'b1;
                    state <= ST_IDLE;
                end

                default: begin
                    state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire
