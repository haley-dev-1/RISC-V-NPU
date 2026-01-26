/*
 * systolic.v
 *
 * Wavefront-style systolic array for matrix multiply with INPUT SKEW + ACC FORWARDING.
 *
 * - A values shift RIGHT each cycle
 * - B values shift DOWN each cycle
 * - Each PE does MAC when both local A and B are valid
 *
 * IMPORTANT:
 * - Your MAC is registered (result/done update on posedge).
 * - We use accumulator forwarding so back-to-back wavefront MACs work:
 *     acc_fwd = mac_done ? mac_result : acc
 *
 * INPUT SKEW (classic systolic alignment):
 * - Delay A row r by r cycles before injecting into col 0
 * - Delay B col c by c cycles before injecting into row 0
 *
 * DONE handling:
 * - If we assert done in the same cycle as the final acc writeback (nonblocking),
 *   a testbench can observe done==1 while acc still holds the previous value.
 * - So we set done_pending when we reach the finish point, and pulse done
 *   on the *next* cycle.
 */

`default_nettype none
`timescale 1ns/1ps

module systolic #(
    parameter int N = 2
)(
    input  wire                     clk,
    input  wire                     rst_n,

    input  wire                     start,
    output reg                      busy,
    output reg                      done,

    input  wire                     in_valid,
    output wire                     in_ready,

    input  wire [N*32-1:0]           a_vec_in,
    input  wire [N*32-1:0]           b_vec_in,

    output wire [N*N*32-1:0]         c_mat_out
);

    // ------------------------------------------------------------------------
    // Pipes inside the array
    // ------------------------------------------------------------------------
    // Keep ports as unsigned vectors, but make internal storage signed so
    // signed values are preserved end-to-end (bitwise identical, but helps
    // avoid accidental unsigned expressions/ternaries).
    reg signed [31:0] a_pipe   [0:N-1][0:N-1];
    reg        a_vpipe  [0:N-1][0:N-1];

    reg signed [31:0] b_pipe   [0:N-1][0:N-1];
    reg        b_vpipe  [0:N-1][0:N-1];

    reg signed [31:0] acc      [0:N-1][0:N-1];

    // ------------------------------------------------------------------------
    // MACs + forwarding
    // ------------------------------------------------------------------------
    wire signed [31:0] mac_result [0:N-1][0:N-1];
    wire        mac_done   [0:N-1][0:N-1];
    wire        mac_valid  [0:N-1][0:N-1];
    wire signed [31:0] acc_fwd    [0:N-1][0:N-1];

    genvar r, c;
    generate
        for (r = 0; r < N; r = r + 1) begin: GEN_ROW
            for (c = 0; c < N; c = c + 1) begin: GEN_COL
                assign mac_valid[r][c] = busy && a_vpipe[r][c] && b_vpipe[r][c];
                assign acc_fwd[r][c]   = (mac_done[r][c]) ? mac_result[r][c] : acc[r][c];

                mac u_mac (
                    .clk   (clk),
                    .rst_n (rst_n),
                    .valid (mac_valid[r][c]),
                    .a     (a_pipe[r][c]),
                    .b     (b_pipe[r][c]),
                    .acc   (acc_fwd[r][c]),
                    .result(mac_result[r][c]),
                    .done  (mac_done[r][c])
                );
            end
        end
    endgenerate

    // ------------------------------------------------------------------------
    // Streaming handshake / control
    // ------------------------------------------------------------------------
    reg [$clog2(N+1)-1:0] beats_accepted;
    reg                   started;

    assign in_ready = busy && (beats_accepted < $clog2(N+1)'(N));
    
    // ------------------------------------------------------------------------
    // Unpack input vectors
    // ------------------------------------------------------------------------
    wire [31:0] a_in_word [0:N-1];
    wire [31:0] b_in_word [0:N-1];

    generate
        for (r = 0; r < N; r = r + 1) begin: UNPACK_A
            assign a_in_word[r] = a_vec_in[r*32 +: 32];
        end
        for (c = 0; c < N; c = c + 1) begin: UNPACK_B
            assign b_in_word[c] = b_vec_in[c*32 +: 32];
        end
    endgenerate

    // ------------------------------------------------------------------------
    // INPUT SKEW REGISTERS
    // A skew per row (delay by row index)
    // B skew per col (delay by col index)
    // ------------------------------------------------------------------------
    reg signed [31:0] a_skew   [0:N-1][0:N-1];
    reg        a_vskew  [0:N-1][0:N-1];

    reg signed [31:0] b_skew   [0:N-1][0:N-1];
    reg        b_vskew  [0:N-1][0:N-1];

    // ------------------------------------------------------------------------
    // Timing (simple drain)
    // With skew + registered MAC, 3*N is a safer drain estimate than 3*N-1.
    // ------------------------------------------------------------------------
    localparam int TOTAL_CYCLES = (3*N);

    reg [$clog2(TOTAL_CYCLES+1)-1:0] cycle_count;

    // Done is pulsed one cycle AFTER we decide we are finished.
    reg done_pending;

    integer i, j;

    always @(posedge clk) begin
        if (!rst_n) begin
            busy <= 1'b0;
            done <= 1'b0;
            started <= 1'b0;
            beats_accepted <= '0;
            cycle_count <= '0;
            done_pending <= 1'b0;

            for (i = 0; i < N; i = i + 1) begin
                for (j = 0; j < N; j = j + 1) begin
                    a_pipe[i][j]  <= 32'd0;
                    b_pipe[i][j]  <= 32'd0;
                    a_vpipe[i][j] <= 1'b0;
                    b_vpipe[i][j] <= 1'b0;
                    acc[i][j]     <= 32'd0;

                    a_skew[i][j]  <= 32'd0;
                    a_vskew[i][j] <= 1'b0;
                    b_skew[i][j]  <= 32'd0;
                    b_vskew[i][j] <= 1'b0;
                end
            end

        end else begin
            // Default: done is a 1-cycle pulse
            done <= 1'b0;

            // If we queued done last cycle, pulse it now (after acc writeback settled)
            if (done_pending) begin
                done <= 1'b1;
                busy <= 1'b0;
                done_pending <= 1'b0;
            end

            if (start && !busy) begin
                busy <= 1'b1;
                started <= 1'b0;
                beats_accepted <= '0;
                cycle_count <= '0;
                done_pending <= 1'b0;

                for (i = 0; i < N; i = i + 1) begin
                    for (j = 0; j < N; j = j + 1) begin
                        a_pipe[i][j]  <= 32'd0;
                        b_pipe[i][j]  <= 32'd0;
                        a_vpipe[i][j] <= 1'b0;
                        b_vpipe[i][j] <= 1'b0;
                        acc[i][j]     <= 32'd0;

                        a_skew[i][j]  <= 32'd0;
                        a_vskew[i][j] <= 1'b0;
                        b_skew[i][j]  <= 32'd0;
                        b_vskew[i][j] <= 1'b0;
                    end
                end
            end

            if (busy) begin
                // ------------------------------------------------------------
                // Step 0: Shift input skew registers
                // ------------------------------------------------------------
                for (i = 0; i < N; i = i + 1) begin
                    for (j = N-1; j > 0; j = j - 1) begin
                        a_skew[i][j]  <= a_skew[i][j-1];
                        a_vskew[i][j] <= a_vskew[i][j-1];
                    end
                end

                for (j = 0; j < N; j = j + 1) begin
                    for (i = N-1; i > 0; i = i - 1) begin
                        b_skew[j][i]  <= b_skew[j][i-1];
                        b_vskew[j][i] <= b_vskew[j][i-1];
                    end
                end

                // ------------------------------------------------------------
                // Step 1: Shift A right and B down inside the array
                // ------------------------------------------------------------
                for (i = 0; i < N; i = i + 1) begin
                    for (j = N-1; j > 0; j = j - 1) begin
                        a_pipe[i][j]  <= a_pipe[i][j-1];
                        a_vpipe[i][j] <= a_vpipe[i][j-1];
                    end
                end

                for (j = 0; j < N; j = j + 1) begin
                    for (i = N-1; i > 0; i = i - 1) begin
                        b_pipe[i][j]  <= b_pipe[i-1][j];
                        b_vpipe[i][j] <= b_vpipe[i-1][j];
                    end
                end

                // ------------------------------------------------------------
                // Step 2: Load new inputs into skew[?][0] when accepting a beat
                // ------------------------------------------------------------
                if (in_valid && in_ready) begin
                    if (!started) begin
                        started <= 1'b1;
                        cycle_count <= '0;
                    end

                    for (i = 0; i < N; i = i + 1) begin
                        a_skew[i][0]  <= a_in_word[i];
                        a_vskew[i][0] <= 1'b1;
                    end

                    for (j = 0; j < N; j = j + 1) begin
                        b_skew[j][0]  <= b_in_word[j];
                        b_vskew[j][0] <= 1'b1;
                    end

                    beats_accepted <= beats_accepted + 1'b1;

                end else begin
                    for (i = 0; i < N; i = i + 1) begin
                        a_skew[i][0]  <= 32'd0;
                        a_vskew[i][0] <= 1'b0;
                    end
                    for (j = 0; j < N; j = j + 1) begin
                        b_skew[j][0]  <= 32'd0;
                        b_vskew[j][0] <= 1'b0;
                    end
                end

                // ------------------------------------------------------------
                // Step 3: Inject skewed inputs into the array boundaries
                //  - A row i uses a_skew[i][i] (delay = i)
                //  - B col j uses b_skew[j][j] (delay = j)
                // ------------------------------------------------------------
                for (i = 0; i < N; i = i + 1) begin
                    a_pipe[i][0]  <= a_skew[i][i];
                    a_vpipe[i][0] <= a_vskew[i][i];
                end
                for (j = 0; j < N; j = j + 1) begin
                    b_pipe[0][j]  <= b_skew[j][j];
                    b_vpipe[0][j] <= b_vskew[j][j];
                end

                // ------------------------------------------------------------
                // Step 4: Accumulator writeback
                // ------------------------------------------------------------
                for (i = 0; i < N; i = i + 1) begin
                    for (j = 0; j < N; j = j + 1) begin
                        if (mac_done[i][j]) begin
                            acc[i][j] <= mac_result[i][j];
                        end
                    end
                end

                // ------------------------------------------------------------
                // Step 5: Done timing (pulse done next cycle)
                // ------------------------------------------------------------
                if (started) begin
                    cycle_count <= cycle_count + 1'b1;
		    if (cycle_count == $clog2(TOTAL_CYCLES+1)'(TOTAL_CYCLES - 1)) begin
                        done_pending <= 1'b1;  // pulse done next cycle
                    end
                end
            end
        end
    end

    // ------------------------------------------------------------------------
    // Pack outputs row-major
    // ------------------------------------------------------------------------
    generate
        for (r = 0; r < N; r = r + 1) begin: PACK_ROW
            for (c = 0; c < N; c = c + 1) begin: PACK_COL
                assign c_mat_out[((r*N + c)*32) +: 32] = acc[r][c];
            end
        end
    endgenerate

endmodule

`default_nettype wire
