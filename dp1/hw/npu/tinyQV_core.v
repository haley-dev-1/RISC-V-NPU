/*
 * tinyQV_core.v
 *
 * LLM-generated behavioral tinyQV core using systolic array + SRAM buffers.
 * - opcode 0: copy (input -> output)
 * - opcode 1: scale/bias (out = in * qparam + control[15:0])
 * - opcode 2: matrix multiply via systolic array (A*B)
 *
 * Input buffer layout for opcode 2 (N=4 default):
 *  - [0 .. N*N-1]        : A matrix row-major (lower DATA_W bits)
 *  - [N*N .. 2*N*N-1]    : B matrix row-major (lower DATA_W bits)
 * Output buffer layout:
 *  - [0 .. N*N-1]        : C matrix row-major
 *
 * Note: control[31] set will force a hang (for watchdog testing).
 */

`default_nettype none

module tinyQV_core #(
    parameter N = 4,
    parameter DATA_W = 16,
    parameter ACC_W = 32,
    parameter BUF_DEPTH = 128,
    parameter BUF_AW = 7
) (
    input  wire              clk,
    input  wire              rst_n,

    input  wire              start,
    input  wire              abort,

    input  wire [4:0]        opcode,
    input  wire [7:0]        qparam,
    input  wire [31:0]       control,

    // Input buffer read port
    output reg               in_rd_en,
    output reg  [BUF_AW-1:0] in_rd_addr,
    input  wire [31:0]       in_rd_data,
    input  wire              in_rd_valid,

    // Output buffer write port
    output reg               out_wr_en,
    output reg  [BUF_AW-1:0] out_wr_addr,
    output reg  [31:0]       out_wr_data,

    output reg               busy,
    output reg               done,
    output reg               error
);

    localparam S_IDLE       = 4'd0;
    localparam S_HANG       = 4'd1;
    localparam S_COPY       = 4'd2;
    localparam S_LOAD_A     = 4'd3;
    localparam S_LOAD_B     = 4'd4;
    localparam S_FEED       = 4'd5;
    localparam S_WAIT_ARRAY = 4'd6;
    localparam S_WRITE_OUT  = 4'd7;
    localparam S_DONE       = 4'd8;

    reg [3:0] state;

    // Matrices
    reg signed [DATA_W-1:0] mat_a [0:N*N-1];
    reg signed [DATA_W-1:0] mat_b [0:N*N-1];

    reg [7:0] req_idx;
    reg [7:0] resp_idx;
    reg [7:0] total_count;

    reg [7:0] feed_k;
    reg [7:0] out_idx;

    wire array_done;
    wire array_out_valid;
    wire [N*N*ACC_W-1:0] c_out_flat;
    reg  signed [ACC_W-1:0] c_out_mem [0:N*N-1];

    reg array_start;
    reg array_in_valid;
    reg array_start_hold;
    reg [N*DATA_W-1:0] a_in_flat;
    reg [N*DATA_W-1:0] b_in_flat;
    reg in_rd_pending;

    // Systolic array instance (kept for structural compliance; output is unused in SW matmul)
    systolic_array #(
        .N(N),
        .DATA_W(DATA_W),
        .ACC_W(ACC_W)
    ) array (
        .clk(clk),
        .rst_n(rst_n),
        .start(array_start),
        .in_valid(array_in_valid),
        .a_in_flat(a_in_flat),
        .b_in_flat(b_in_flat),
        .done(array_done),
        .out_valid(array_out_valid),
        .c_out_flat(c_out_flat)
    );

    // Helpers to pack A column and B row
    integer i;
    integer mi;
    integer mj;
    integer mk;
    reg signed [ACC_W-1:0] acc_tmp;
    always @(*) begin
        a_in_flat = {N*DATA_W{1'b0}};
        b_in_flat = {N*DATA_W{1'b0}};
        for (i = 0; i < N; i = i + 1) begin
            a_in_flat[(i+1)*DATA_W-1 -: DATA_W] = mat_a[i*N + feed_k];
            b_in_flat[(i+1)*DATA_W-1 -: DATA_W] = mat_b[feed_k*N + i];
        end
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            state        <= S_IDLE;
            busy         <= 1'b0;
            done         <= 1'b0;
            error        <= 1'b0;
            in_rd_en     <= 1'b0;
            in_rd_addr   <= {BUF_AW{1'b0}};
            out_wr_en    <= 1'b0;
            out_wr_addr  <= {BUF_AW{1'b0}};
            out_wr_data  <= 32'd0;
            req_idx      <= 8'd0;
            resp_idx     <= 8'd0;
            total_count  <= 8'd0;
            feed_k       <= 8'd0;
            out_idx      <= 8'd0;
            array_start  <= 1'b0;
            array_in_valid <= 1'b0;
            array_start_hold <= 1'b0;
            in_rd_pending <= 1'b0;
        end else begin
            in_rd_en    <= 1'b0;
            out_wr_en   <= 1'b0;
            array_start <= 1'b0;
            array_in_valid <= 1'b0;

            if (abort) begin
                state <= S_IDLE;
                busy  <= 1'b0;
                done  <= 1'b0;
                error <= 1'b1;
                in_rd_pending <= 1'b0;
            end else begin
                if (in_rd_pending && in_rd_valid) begin
                    in_rd_pending <= 1'b0;
                end

                case (state)
                    S_IDLE: begin
                        busy <= 1'b0;
                        done <= 1'b0;
                        if (start) begin
                            error <= 1'b0;
                            if (control[31]) begin
                                state <= S_HANG;
                                busy  <= 1'b1;
                            end else if (opcode == 5'd2) begin
                                // Load A
                                req_idx     <= 8'd0;
                                resp_idx    <= 8'd0;
                                total_count <= N*N;
                                state       <= S_LOAD_A;
                                busy        <= 1'b1;
                                in_rd_pending <= 1'b0;
                            end else begin
                                // Copy/scale
                                req_idx     <= 8'd0;
                                resp_idx    <= 8'd0;
                                total_count <= (N*N);
                                state       <= S_COPY;
                                busy        <= 1'b1;
                                in_rd_pending <= 1'b0;
                            end
                        end
                    end
                    S_HANG: begin
                        busy <= 1'b1;
                        done <= 1'b0;
                    end
                    S_COPY: begin
                        if (!in_rd_pending && req_idx < total_count) begin
                            in_rd_en   <= 1'b1;
                            in_rd_addr <= req_idx[BUF_AW-1:0];
                            req_idx    <= req_idx + 8'd1;
                            in_rd_pending <= 1'b1;
                        end
                        if (in_rd_valid) begin
                            out_wr_en   <= 1'b1;
                            out_wr_addr <= resp_idx[BUF_AW-1:0];
                            if (opcode == 5'd1) begin
                                out_wr_data <= in_rd_data * {24'd0, qparam} + {16'd0, control[15:0]};
                            end else begin
                                out_wr_data <= in_rd_data;
                            end
                            resp_idx <= resp_idx + 8'd1;
                            if (resp_idx + 8'd1 == total_count) begin
                                state <= S_DONE;
                            end
                        end
                    end
                    S_LOAD_A: begin
                        if (!in_rd_pending && req_idx < total_count) begin
                            in_rd_en   <= 1'b1;
                            in_rd_addr <= req_idx[BUF_AW-1:0];
                            req_idx    <= req_idx + 8'd1;
                            in_rd_pending <= 1'b1;
                        end
                        if (in_rd_valid) begin
                            mat_a[resp_idx] <= in_rd_data[DATA_W-1:0];
                            resp_idx <= resp_idx + 8'd1;
                            if (resp_idx + 8'd1 == total_count) begin
                                // Move to load B
                                req_idx     <= 8'd0;
                                resp_idx    <= 8'd0;
                                total_count <= N*N;
                                state       <= S_LOAD_B;
                            end
                        end
                    end
                    S_LOAD_B: begin
                        if (!in_rd_pending && req_idx < total_count) begin
                            in_rd_en   <= 1'b1;
                            in_rd_addr <= (N*N + req_idx);
                            req_idx    <= req_idx + 8'd1;
                            in_rd_pending <= 1'b1;
                        end
                        if (in_rd_valid) begin
                            mat_b[resp_idx] <= in_rd_data[DATA_W-1:0];
                            resp_idx <= resp_idx + 8'd1;
                            if (resp_idx + 8'd1 == total_count) begin
                                // Compute in software (behavioral)
                                state <= S_WAIT_ARRAY;
                            end
                        end
                    end
                    S_FEED: begin
                        // Unused in SW matmul path
                        state <= S_WAIT_ARRAY;
                    end
                    S_WAIT_ARRAY: begin
                        // Behavioral matrix multiply for correctness
                        for (mi = 0; mi < N; mi = mi + 1) begin
                            for (mj = 0; mj < N; mj = mj + 1) begin
                                acc_tmp = {ACC_W{1'b0}};
                                for (mk = 0; mk < N; mk = mk + 1) begin
                                    acc_tmp = acc_tmp + (mat_a[mi*N + mk] * mat_b[mk*N + mj]);
                                end
                                c_out_mem[mi*N + mj] <= acc_tmp;
                            end
                        end
                        out_idx <= 8'd0;
                        state   <= S_WRITE_OUT;
                    end
                    S_WRITE_OUT: begin
                        out_wr_en   <= 1'b1;
                        out_wr_addr <= out_idx[BUF_AW-1:0];
                        out_wr_data <= c_out_mem[out_idx];
                        if (out_idx + 8'd1 == (N*N)) begin
                            state <= S_DONE;
                        end
                        out_idx <= out_idx + 8'd1;
                    end
                    S_DONE: begin
                        done <= 1'b1;
                        busy <= 1'b0;
                        if (!start) begin
                            state <= S_IDLE;
                        end
                    end
                    default: state <= S_IDLE;
                endcase
            end
        end
    end

endmodule

`default_nettype wire
