/*
 * systolic_array.v
 *
 * LLM-generated N x N systolic array for matrix multiply.
 * - Wavefront propagation of A (left->right) and B (top->bottom)
 * - Local weight storage via internal registers (B values)
 * - Uses mac32 PEs
 */

`default_nettype none

module systolic_array #(
    parameter N = 4,
    parameter DATA_W = 16,
    parameter ACC_W = 32
) (
    input  wire                     clk,
    input  wire                     rst_n,
    input  wire                     start,
    input  wire                     in_valid,
    input  wire [N*DATA_W-1:0]      a_in_flat,
    input  wire [N*DATA_W-1:0]      b_in_flat,
    output reg                      done,
    output reg                      out_valid,
    output reg  [N*N*ACC_W-1:0]     c_out_flat
);

    integer r, c;

    reg signed [DATA_W-1:0] a_pipe [0:N-1][0:N-1];
    reg signed [DATA_W-1:0] b_pipe [0:N-1][0:N-1];

    wire signed [31:0] acc_out [0:N-1][0:N-1];
    wire              acc_ovf [0:N-1][0:N-1];

    reg [7:0] cycle_count;
    reg       active;

    function automatic signed [DATA_W-1:0] get_a;
        input [N*DATA_W-1:0] vec;
        input integer idx;
        begin
            get_a = vec[(idx+1)*DATA_W-1 -: DATA_W];
        end
    endfunction

    function automatic signed [DATA_W-1:0] get_b;
        input [N*DATA_W-1:0] vec;
        input integer idx;
        begin
            get_b = vec[(idx+1)*DATA_W-1 -: DATA_W];
        end
    endfunction

    // Instantiate PEs
    genvar gi, gj;
    generate
        for (gi = 0; gi < N; gi = gi + 1) begin : gen_row
            for (gj = 0; gj < N; gj = gj + 1) begin : gen_col
                mac32 #(.SATURATE(1'b0)) pe (
                    .clk(clk),
                    .rst_n(rst_n),
                    .enable(active || start),
                    .clear(start),
                    .a({{(32-DATA_W){a_pipe[gi][gj][DATA_W-1]}}, a_pipe[gi][gj]}),
                    .b({{(32-DATA_W){b_pipe[gi][gj][DATA_W-1]}}, b_pipe[gi][gj]}),
                    .acc_in(acc_out[gi][gj]),
                    .acc_out(acc_out[gi][gj]),
                    .overflow(acc_ovf[gi][gj])
                );
            end
        end
    endgenerate

    // Wavefront propagation
    always @(posedge clk) begin
        if (!rst_n) begin
            for (r = 0; r < N; r = r + 1) begin
                for (c = 0; c < N; c = c + 1) begin
                    a_pipe[r][c] <= {DATA_W{1'b0}};
                    b_pipe[r][c] <= {DATA_W{1'b0}};
                end
            end
            cycle_count <= 8'd0;
            active      <= 1'b0;
            done        <= 1'b0;
            out_valid   <= 1'b0;
            c_out_flat  <= {N*N*ACC_W{1'b0}};
        end else begin
            done      <= 1'b0;
            out_valid <= 1'b0;

            // Determine whether to step this cycle
            if (start) begin
                active <= 1'b1;
                cycle_count <= 8'd0;
            end

            if (active || start) begin
                // Shift/inject wavefront
                for (r = 0; r < N; r = r + 1) begin
                    for (c = N-1; c > 0; c = c - 1) begin
                        a_pipe[r][c] <= a_pipe[r][c-1];
                    end
                    a_pipe[r][0] <= in_valid ? get_a(a_in_flat, r) : {DATA_W{1'b0}};
                end

                for (c = 0; c < N; c = c + 1) begin
                    for (r = N-1; r > 0; r = r - 1) begin
                        b_pipe[r][c] <= b_pipe[r-1][c];
                    end
                    b_pipe[0][c] <= in_valid ? get_b(b_in_flat, c) : {DATA_W{1'b0}};
                end

                // Advance cycle count
                if (start) begin
                    cycle_count <= 8'd1;
                end else begin
                    cycle_count <= cycle_count + 8'd1;
                end

                if (cycle_count == (2*N-2)) begin
                    active    <= 1'b0;
                    done      <= 1'b1;
                    out_valid <= 1'b1;
                    // Flatten output matrix
                    for (r = 0; r < N; r = r + 1) begin
                        for (c = 0; c < N; c = c + 1) begin
                            c_out_flat[((r*N+c)+1)*ACC_W-1 -: ACC_W] <= acc_out[r][c];
                        end
                    end
                end
            end
        end
    end

endmodule

`default_nettype wire
