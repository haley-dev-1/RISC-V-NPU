/*
 * systolic.v
 *
 * Wavefront-style systolic array for matrix multiply.
 *
 * Concept (what makes it "systolic"):
 *  - A values enter on the LEFT edge and shift RIGHT each cycle.
 *  - B values enter on the TOP edge and shift DOWN each cycle.
 *  - Each Processing Element (PE) multiplies the local A and B and accumulates into a local sum.
 *  - Valid bits "wavefront" through the array along with the data, so we only accumulate when both A and B are real.
 *
 * Streaming input interface:
 *  - For an N x N multiply, you feed N "beats" (cycles) of inputs.
 *  - On beat t (0..N-1):
 *      a_vec_in provides A[row][t] for every row
 *      b_vec_in provides B[t][col] for every col
 *  - After feeding N beats, the array continues "draining" internally until done.
 *
 * Notes:
 *  - This uses your existing unsigned 32-bit MAC as-is.
 *  - Arithmetic is "wraparound" mod 2^32 because result is 32-bit.
 */

`default_nettype none

module systolic #(
    parameter int N = 2  // Array dimension: N x N
)(
    input  wire                     clk,
    input  wire                     rst_n,

    // Control
    input  wire                     start,     // pulse high for 1 cycle to begin
    output reg                      busy,      // high while computing
    output reg                      done,      // 1-cycle pulse when results are ready

    // Streaming input handshake
    input  wire                     in_valid,
    output wire                     in_ready,

    // Packed streaming data:
    //  - a_vec_in holds N words: one per ROW of A
    //  - b_vec_in holds N words: one per COL of B
    // On beat t: a_vec_in[row] = A[row][t], b_vec_in[col] = B[t][col]
    input  wire [N*32-1:0]           a_vec_in,
    input  wire [N*32-1:0]           b_vec_in,

    // Output matrix C packed as N*N 32-bit words (row-major):
    // c_mat_out[(row*N + col)] is the 32-bit C[row][col]
    output wire [N*N*32-1:0]         c_mat_out
);

    // ------------------------------------------------------------------------
    // Internal pipes for A and B data and their validity
    // ------------------------------------------------------------------------

    // A shifts RIGHT across columns
    reg [31:0] a_pipe   [0:N-1][0:N-1];
    reg        a_vpipe  [0:N-1][0:N-1];

    // B shifts DOWN across rows
    reg [31:0] b_pipe   [0:N-1][0:N-1];
    reg        b_vpipe  [0:N-1][0:N-1];

    // Accumulators for each PE (the output C)
    reg [31:0] acc      [0:N-1][0:N-1];

    // ------------------------------------------------------------------------
    // MAC instances (one per PE)
    //
    // Important scheduling detail:
    //  - Your mac registers result/done on posedge when valid is high.
    //  - In this module, we update acc when we observe mac_done (which is a reg).
    //    That means we update acc one cycle "later", which is correct for registered outputs.
    // ------------------------------------------------------------------------

    wire [31:0] mac_result [0:N-1][0:N-1];
    wire        mac_done   [0:N-1][0:N-1];
    wire        mac_valid  [0:N-1][0:N-1];

    genvar r, c;
    generate
        for (r = 0; r < N; r = r + 1) begin: GEN_ROW
            for (c = 0; c < N; c = c + 1) begin: GEN_COL
                assign mac_valid[r][c] = busy && a_vpipe[r][c] && b_vpipe[r][c];

                mac u_mac (
                    .clk   (clk),
                    .rst_n (rst_n),
                    .valid (mac_valid[r][c]),
                    .a     (a_pipe[r][c]),
                    .b     (b_pipe[r][c]),
                    .acc   (acc[r][c]),
                    .result(mac_result[r][c]),
                    .done  (mac_done[r][c])
                );
            end
        end
    endgenerate

    // ------------------------------------------------------------------------
    // Control / timing
    //
    // We accept exactly N input beats after start.
    // After that, we "drain" the wavefront until the last PE has finished all multiplies.
    //
    // A classic estimate for an N×N systolic MM:
    //  - Feed beats: N cycles
    //  - Wavefront fill/drain across array adds about (2N-2) cycles
    //  - Because the MAC output is registered, we add 1 extra cycle for the final update.
    //
    // Total internal time from first accepted beat to done ~ (3N - 2) + 1 = (3N - 1)
    // We measure cycles from the first accepted beat.
    // ------------------------------------------------------------------------

    localparam int TOTAL_CYCLES = (3*N - 1);  // safe for this registered MAC integration

    reg [$clog2(N+1)-1:0] beats_accepted;
    reg [$clog2(TOTAL_CYCLES+1)-1:0] cycle_count;
    reg started;

    // Ready when we're busy and still accepting the N input beats
    assign in_ready = busy && (beats_accepted < N);

    // ------------------------------------------------------------------------
    // Unpack input vectors helper (pure wiring)
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
    // Sequential logic: shift wavefront pipes + track cycles + update accumulators
    // ------------------------------------------------------------------------
    integer i, j;

    always @(posedge clk) begin
        if (!rst_n) begin
            busy <= 1'b0;
            done <= 1'b0;
            started <= 1'b0;
            beats_accepted <= '0;
            cycle_count <= '0;

            // Clear all internal state
            for (i = 0; i < N; i = i + 1) begin
                for (j = 0; j < N; j = j + 1) begin
                    a_pipe[i][j]  <= 32'd0;
                    b_pipe[i][j]  <= 32'd0;
                    a_vpipe[i][j] <= 1'b0;
                    b_vpipe[i][j] <= 1'b0;
                    acc[i][j]     <= 32'd0;
                end
            end
        end else begin
            done <= 1'b0;

            // Start pulse initializes the run
            if (start && !busy) begin
                busy <= 1'b1;
                started <= 1'b0;          // becomes 1 once we accept the first beat
                beats_accepted <= '0;
                cycle_count <= '0;

                // Clear pipes/valids and accumulators at the beginning of a run
                for (i = 0; i < N; i = i + 1) begin
                    for (j = 0; j < N; j = j + 1) begin
                        a_pipe[i][j]  <= 32'd0;
                        b_pipe[i][j]  <= 32'd0;
                        a_vpipe[i][j] <= 1'b0;
                        b_vpipe[i][j] <= 1'b0;
                        acc[i][j]     <= 32'd0;
                    end
                end
            end

            if (busy) begin
                // ------------------------------------------------------------
                // Step 1: Shift A right and B down every cycle (the "systolic" rhythm)
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
                // Step 2: If we are accepting an input beat, inject new values
                // into the LEFT edge for A and TOP edge for B.
                // ------------------------------------------------------------
                if (in_valid && in_ready) begin
                    // Mark we have begun counting cycles since first beat
                    if (!started) begin
                        started <= 1'b1;
                        cycle_count <= '0;
                    end

                    // Inject A into left column
                    for (i = 0; i < N; i = i + 1) begin
                        a_pipe[i][0]  <= a_in_word[i];
                        a_vpipe[i][0] <= 1'b1;
                    end

                    // Inject B into top row
                    for (j = 0; j < N; j = j + 1) begin
                        b_pipe[0][j]  <= b_in_word[j];
                        b_vpipe[0][j] <= 1'b1;
                    end

                    beats_accepted <= beats_accepted + 1'b1;
                end else begin
                    // If no input beat, inject "invalid" on the boundaries (keeps wavefront clean)
                    for (i = 0; i < N; i = i + 1) begin
                        a_pipe[i][0]  <= 32'd0;
                        a_vpipe[i][0] <= 1'b0;
                    end
                    for (j = 0; j < N; j = j + 1) begin
                        b_pipe[0][j]  <= 32'd0;
                        b_vpipe[0][j] <= 1'b0;
                    end
                end

                // ------------------------------------------------------------
                // Step 3: Update accumulators when MAC outputs are done.
                // (mac_done/mac_result are registered in the MAC, so this is safe.)
                // ------------------------------------------------------------
                for (i = 0; i < N; i = i + 1) begin
                    for (j = 0; j < N; j = j + 1) begin
                        if (mac_done[i][j]) begin
                            acc[i][j] <= mac_result[i][j];
                        end
                    end
                end

                // ------------------------------------------------------------
                // Step 4: After first beat, count cycles until the array is finished.
                // ------------------------------------------------------------
                if (started) begin
                    cycle_count <= cycle_count + 1'b1;

                    if (cycle_count == (TOTAL_CYCLES - 1)) begin
                        busy <= 1'b0;
                        done <= 1'b1;  // pulse
                    end
                end
            end
        end
    end

    // ------------------------------------------------------------------------
    // Pack C outputs (row-major)
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
