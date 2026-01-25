`timescale 1ns/1ps
`default_nettype none

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

    // Yosys-friendly small casts for address comparisons
localparam integer NN = N*N;
localparam [5:0] N6  = N;
localparam [5:0] NN6 = NN;


    // --------------------------------------------------------------------
    // MMIO-visible regs for input vectors
    // --------------------------------------------------------------------
    reg [31:0] a_lane [0:N-1];
    reg [31:0] b_lane [0:N-1];

    // Command pulse
    reg        start_pulse;

    // Sticky status
    reg        done_sticky;

    // Streaming interface to systolic
    reg                 in_valid;
    wire                in_ready;

    wire                sys_busy;
    wire                sys_done;

    wire [N*32-1:0]      a_vec_in;
    wire [N*32-1:0]      b_vec_in;
    wire [N*N*32-1:0]    c_mat_out;

    // Pack lanes into vectors (lane i at [i*32 +: 32])
    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : PACK_IN
            assign a_vec_in[i*32 +: 32] = a_lane[i];
            assign b_vec_in[i*32 +: 32] = b_lane[i];
        end
    endgenerate

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

    // Control logic: start pulse + in_valid handshake + sticky done
    always @(posedge clk) begin
        if (!rst_n) begin
            start_pulse <= 1'b0;
            in_valid    <= 1'b0;
            done_sticky <= 1'b0;

            for (k = 0; k < N; k = k + 1) begin
                a_lane[k] <= 32'd0;
                b_lane[k] <= 32'd0;
            end
        end else begin
            // defaults
            start_pulse <= 1'b0;

            // latch done sticky when systolic finishes
            if (sys_done) begin
                done_sticky <= 1'b1;
            end

            // drop in_valid when accepted
            if (in_valid && in_ready) begin
                in_valid <= 1'b0;
            end

            // Handle MMIO writes
            if (data_write_n != 2'b11) begin
                // A lanes: 0x00..0x00+N-1
                if (address < (6'h00 + N6)) begin
		    a_lane[address[0]] <= data_in;
                end
                // B lanes: 0x10..0x10+N-1
                else if (address >= 6'h10 && address < (6'h10 + N6)) begin
		    b_lane[address[0]] <= data_in;
                end
                // CTRL
                else if (address == 6'h20) begin
                    // bit1 clears sticky status
                    if (data_in[1]) begin
                        done_sticky <= 1'b0;
                    end

                    // bit0 = START (pulse) and begin streaming
                    if (data_in[0]) begin
                        start_pulse <= 1'b1;
                        in_valid    <= 1'b1;
                    end
                end
            end
        end
    end

    // Read mux
    wire [31:0] status_word = {29'd0, 1'b0, sys_busy, done_sticky};

    reg [31:0] c_word;
    integer idx;

always @(*) begin
    c_word = 32'd0;
    idx = 0;
    if (address >= 6'h30 && address < (6'h30 + NN6)) begin
        idx = address - 6'h30;       // idx is integer, this is fine
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

endmodule

`default_nettype wire
