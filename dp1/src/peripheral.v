`timescale 1ns/1ps
`default_nettype none

/* verilator lint_off DECLFILENAME */
module tqvp_example #(
    parameter integer N = 2   // MUST match systolic.v parameter N
)(
    input         clk,
    input         rst_n,

    input  [7:0]  ui_in,
    output [7:0]  uo_out,

    input  [5:0]   address,
    input  [31:0]  data_in,

    input  [1:0]   data_write_n,
    input  [1:0]   data_read_n,

    output [31:0]  data_out,
    output         data_ready,

    output         user_interrupt
);
/* verilator lint_on DECLFILENAME */

    localparam integer NN = N*N;

    // Avoid WIDTHTRUNC by explicitly selecting 6 bits from 32-bit ints
    localparam int unsigned N_INT  = N;
    localparam int unsigned NN_INT = NN;
    localparam [5:0] N6  = N_INT[5:0];
    localparam [5:0] NN6 = NN_INT[5:0];

    // FIFO sizing
    localparam int FC_W  = (N <= 1) ? 1 : $clog2(N+1);
    localparam int PTR_W = (N <= 1) ? 1 : $clog2(N);

    // --------------------------------------------------------------------
    // MMIO-visible regs for input lanes (software writes these)
    // --------------------------------------------------------------------
    reg [31:0] a_lane [0:N-1];
    reg [31:0] b_lane [0:N-1];

    // --------------------------------------------------------------------
    // Beat FIFO (depth N). Each entry stores one beat of A lanes and B lanes.
    // --------------------------------------------------------------------
    reg [31:0] a_fifo [0:N-1][0:N-1];  // [beat][lane]
    reg [31:0] b_fifo [0:N-1][0:N-1];  // [beat][lane]
    reg [FC_W-1:0]  fifo_count;
    reg [PTR_W-1:0] rd_ptr;
    reg [PTR_W-1:0] wr_ptr;

    // Run arming + stream gating:
    // - We may assert start_pulse early to set systolic busy
    // - But we HOLD in_valid low until we have queued all N beats
    //   to avoid bubbles/gaps breaking wavefront timing.
    reg run_armed;
    reg stream_en;

    // Command pulse
    reg start_pulse;

    // Sticky status
    reg done_sticky;

    // Streaming interface to systolic
    wire in_ready;
    wire sys_busy;
    wire sys_done;

    wire [N*32-1:0]      a_vec_in;
    wire [N*32-1:0]      b_vec_in;
    wire [N*N*32-1:0]    c_mat_out;

    // Pack the FIFO HEAD (rd_ptr) into vectors
    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : PACK_IN
            assign a_vec_in[i*32 +: 32] = a_fifo[rd_ptr][i];
            assign b_vec_in[i*32 +: 32] = b_fifo[rd_ptr][i];
        end
    endgenerate

    // Gated in_valid presented to systolic
    wire in_valid = stream_en && (fifo_count != {FC_W{1'b0}});

    // Instantiate streaming systolic
    systolic #(.N(N)) u_systolic (
        .clk      (clk),
        .rst_n    (rst_n),

        .start    (start_pulse),
        .busy     (sys_busy),
        .done     (sys_done),

        .in_valid (in_valid),
        .in_ready (in_ready),

        .a_vec_in (a_vec_in),
        .b_vec_in (b_vec_in),

        .c_mat_out(c_mat_out)
    );

    integer k;
    integer b;

    // Convenience wrap helpers (synthesizable)
    function automatic [PTR_W-1:0] ptr_inc(input [PTR_W-1:0] p);
        begin
            if (p == PTR_W'(N-1)) ptr_inc = {PTR_W{1'b0}};
            else                  ptr_inc = p + {{(PTR_W-1){1'b0}}, 1'b1};
        end
    endfunction

    // MMIO decode
    wire mmio_wr = (data_write_n != 2'b11);
    wire ctrl_wr = mmio_wr && (address == 6'h20);

    wire push_req = ctrl_wr && data_in[0];
    wire clr_req  = ctrl_wr && data_in[1];

    // FIFO pop when systolic accepts a beat
    wire pop_beat = in_valid && in_ready;

    // FIFO push if space and not already streaming (we only support prefill)
    wire fifo_full = (fifo_count == FC_W'(N));
    wire do_push   = push_req && !fifo_full && !stream_en;

    // Start pulse when we see the FIRST push of a run while idle.
    wire first_push_of_run = do_push && !run_armed && !sys_busy;

    // --------------------------------------------------------------------
    // Sequential
    // --------------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst_n) begin
            start_pulse <= 1'b0;
            done_sticky <= 1'b0;

            fifo_count  <= {FC_W{1'b0}};
            rd_ptr      <= {PTR_W{1'b0}};
            wr_ptr      <= {PTR_W{1'b0}};

            run_armed   <= 1'b0;
            stream_en   <= 1'b0;

            for (k = 0; k < N; k = k + 1) begin
                a_lane[k] <= 32'd0;
                b_lane[k] <= 32'd0;
            end
            for (b = 0; b < N; b = b + 1) begin
                for (k = 0; k < N; k = k + 1) begin
                    a_fifo[b][k] <= 32'd0;
                    b_fifo[b][k] <= 32'd0;
                end
            end
        end else begin
            // default
            start_pulse <= 1'b0;

            // DONE sticky + auto-clear stream state after completion
            if (sys_done) begin
                done_sticky <= 1'b1;

                fifo_count <= {FC_W{1'b0}};
                rd_ptr     <= {PTR_W{1'b0}};
                wr_ptr     <= {PTR_W{1'b0}};
                run_armed  <= 1'b0;
                stream_en  <= 1'b0;
            end

            // Handle lane + CTRL writes
            if (mmio_wr) begin
                // A lanes: 0x00..0x00+N-1
                if (address < (6'h00 + N6)) begin
                    a_lane[address[0]] <= data_in;
                end
                // B lanes: 0x10..0x10+N-1
                else if (address >= 6'h10 && address < (6'h10 + N6)) begin
                    b_lane[address[0]] <= data_in; // 0x10/0x11 -> [0]/[1]
                end
                // CTRL
                else if (address == 6'h20) begin
                    if (data_in[1]) begin
                        done_sticky <= 1'b0;

                        // Clear queued beats / state
                        fifo_count <= {FC_W{1'b0}};
                        rd_ptr     <= {PTR_W{1'b0}};
                        wr_ptr     <= {PTR_W{1'b0}};
                        run_armed  <= 1'b0;
                        stream_en  <= 1'b0;
                    end
                end
            end

            // Skip FIFO update if we just cleared or just finished (avoid overrides)
            if (!clr_req && !sys_done) begin : FIFO_UPDATE
                int unsigned count_next;
                count_next = int'(fifo_count);

                if (pop_beat) begin
                    rd_ptr     <= ptr_inc(rd_ptr);
                    count_next = count_next - 1;
                end

                if (do_push) begin
                    for (k = 0; k < N; k = k + 1) begin
                        a_fifo[wr_ptr][k] <= a_lane[k];
                        b_fifo[wr_ptr][k] <= b_lane[k];
                    end
                    wr_ptr     <= ptr_inc(wr_ptr);
                    count_next = count_next + 1;

                    if (first_push_of_run) begin
                        run_armed   <= 1'b1;
                        start_pulse <= 1'b1;
                    end
                end

                // Enable streaming only once we have queued ALL N beats
                if (run_armed && !stream_en && (count_next == int'(N))) begin
                    stream_en <= 1'b1;
                end

                fifo_count <= count_next[FC_W-1:0];
            end
        end
    end

    // --------------------------------------------------------------------
    // Read mux
    // --------------------------------------------------------------------
    wire [31:0] status_word = {29'd0, 1'b0, sys_busy, done_sticky};

    reg [31:0] c_word;
    integer idx;

    always @(*) begin
        c_word = 32'd0;
        idx = 0;

        if (address >= 6'h30 && address < (6'h30 + NN6)) begin
            idx = {26'd0, address} - 32'd48;  // 0x30 = 48
            c_word = c_mat_out[idx*32 +: 32];
        end
    end

    assign data_out =
        (address == 6'h21) ? status_word :
        (address >= 6'h30 && address < (6'h30 + NN6)) ? c_word :
        32'd0;

    assign data_ready = 1'b1;
    assign user_interrupt = 1'b0;
    assign uo_out = 8'd0;

    wire _unused = &{ui_in, data_read_n, 1'b0};

// --- SHAWN'S SRAM INTEGRATION ---
    // Mapping to MMIO addresses:
    // 0x3E (Weight Buffer) and 0x3F (Data Buffer)
    wire en_a = (address == 6'h3E); 
    wire en_b = (address == 6'h3F);

    wire [31:0] rdata_a, rdata_b;

    sram_256kb mem_a (
        .clk(clk),
        .reset(!rst_n),      // HL uses active-low reset rst_n
        .en(en_a),
        .we(en_a && mmio_wr), 
        .addr(data_in[15:0]), // Using data_in for testing address indexing
        .wdata(data_in),
        .rdata(rdata_a)
    );

    sram_256kb mem_b (
        .clk(clk),
        .reset(!rst_n),
        .en(en_b),
        .we(en_b && mmio_wr),
        .addr(data_in[15:0]),
        .wdata(data_in),
        .rdata(rdata_b)
    );


endmodule

`default_nettype wire
