`timescale 1ns/1ps
`default_nettype none

/*
 * tb_systolic.sv
 *
 * Testbench for systolic.v (wavefront streaming systolic array).
 *
 * This testbench is written to be friendly for Verilator:
 *  - Drive signals on negedge so they are stable before posedge sampling.
 *  - Check outputs after the DUT has had time to update registered signals
 *    (we often check at negedge after an event).
 *
 * What we test:
 *  - A simple 2x2 matrix multiply using the streaming wavefront schedule.
 *  - A few random tests (still 2x2 by default) to catch surprises.
 */

module tb_systolic;

  localparam int N = 2;

  // Clock
  logic clk = 1'b0;
  /* verilator lint_off BLKSEQ */
  always #5 clk = ~clk;
  /* verilator lint_on  BLKSEQ */

  // DUT control
  logic rst_n;
  logic start;
  logic busy;
  logic done;

  // Streaming interface
  logic                 in_valid;
  logic                 in_ready;
  logic [N*32-1:0]       a_vec_in;
  logic [N*32-1:0]       b_vec_in;

  // Output matrix packed
  logic [N*N*32-1:0]     c_mat_out;

  // DUT
  systolic #(.N(N)) dut (
    .clk      (clk),
    .rst_n    (rst_n),
    .start    (start),
    .busy     (busy),
    .done     (done),
    .in_valid (in_valid),
    .in_ready (in_ready),
    .a_vec_in (a_vec_in),
    .b_vec_in (b_vec_in),
    .c_mat_out(c_mat_out)
  );

  // --------------------------
  // Helper functions: wraparound 32-bit math (matches your unsigned MAC)
  // --------------------------
  function automatic logic [31:0] add_wrap32(input logic [31:0] x, input logic [31:0] y);
    logic [63:0] sum64;
    begin
      sum64 = {32'b0, x} + {32'b0, y};
      add_wrap32 = sum64[31:0];
    end
  endfunction

  function automatic logic [31:0] mul_wrap32(input logic [31:0] x, input logic [31:0] y);
    logic [63:0] prod64;
    begin
      prod64 = {32'b0, x} * {32'b0, y};
      mul_wrap32 = prod64[31:0];
    end
  endfunction

  // Compute expected C = A*B for 2x2 (wrap mod 2^32)
  task automatic compute_expected_2x2(
    input  logic [31:0] A00, A01, A10, A11,
    input  logic [31:0] B00, B01, B10, B11,
    output logic [31:0] C00, C01, C10, C11
  );
    logic [31:0] t0, t1;
    begin
      // C00 = A00*B00 + A01*B10
      t0  = mul_wrap32(A00, B00);
      t1  = mul_wrap32(A01, B10);
      C00 = add_wrap32(t0, t1);

      // C01 = A00*B01 + A01*B11
      t0  = mul_wrap32(A00, B01);
      t1  = mul_wrap32(A01, B11);
      C01 = add_wrap32(t0, t1);

      // C10 = A10*B00 + A11*B10
      t0  = mul_wrap32(A10, B00);
      t1  = mul_wrap32(A11, B10);
      C10 = add_wrap32(t0, t1);

      // C11 = A10*B01 + A11*B11
      t0  = mul_wrap32(A10, B01);
      t1  = mul_wrap32(A11, B11);
      C11 = add_wrap32(t0, t1);
    end
  endtask

  // Extract packed output (row-major)
  function automatic logic [31:0] c_at(input int idx);
    begin
      c_at = c_mat_out[idx*32 +: 32];
    end
  endfunction

  // --------------------------
  // Streaming driver for one 2x2 multiply
  //
  // For N=2, we feed exactly 2 beats:
  //  beat 0: A[:,0] and B[0,:]
  //  beat 1: A[:,1] and B[1,:]
  // --------------------------
  task automatic run_one_2x2_case(
    input logic [31:0] A00, A01, A10, A11,
    input logic [31:0] B00, B01, B10, B11
  );
    logic [31:0] expC00, expC01, expC10, expC11;
    begin
      compute_expected_2x2(A00, A01, A10, A11, B00, B01, B10, B11,
                           expC00, expC01, expC10, expC11);

      // Pulse start (1 cycle)
      @(negedge clk);
      start    = 1'b1;
      in_valid = 1'b0;
      a_vec_in = '0;
      b_vec_in = '0;

      @(posedge clk);
      @(negedge clk);
      start = 1'b0;

      // Wait until DUT says it can accept input
      while (!in_ready) begin
        @(negedge clk);
      end

      // Beat 0
      @(negedge clk);
      in_valid = 1'b1;
      // a_vec_in[row] = A[row][0]
      a_vec_in[0*32 +: 32] = A00;  // row 0, col 0
      a_vec_in[1*32 +: 32] = A10;  // row 1, col 0
      // b_vec_in[col] = B[0][col]
      b_vec_in[0*32 +: 32] = B00;  // row 0, col 0
      b_vec_in[1*32 +: 32] = B01;  // row 0, col 1

      // Wait for acceptance (in_ready should be high)
      @(posedge clk);

      // Beat 1
      @(negedge clk);
      // a_vec_in[row] = A[row][1]
      a_vec_in[0*32 +: 32] = A01;  // row 0, col 1
      a_vec_in[1*32 +: 32] = A11;  // row 1, col 1
      // b_vec_in[col] = B[1][col]
      b_vec_in[0*32 +: 32] = B10;  // row 1, col 0
      b_vec_in[1*32 +: 32] = B11;  // row 1, col 1

      @(posedge clk);

      // Stop driving inputs
      @(negedge clk);
      in_valid = 1'b0;
      a_vec_in = '0;
      b_vec_in = '0;

      // Wait for done pulse
      while (!done) begin
        @(posedge clk);
      end

      // Check after updates settle (negedge after done asserted)
      @(negedge clk);

      if (c_at(0) !== expC00) $fatal(1, "C00 mismatch: expected=%h got=%h", expC00, c_at(0));
      if (c_at(1) !== expC01) $fatal(1, "C01 mismatch: expected=%h got=%h", expC01, c_at(1));
      if (c_at(2) !== expC10) $fatal(1, "C10 mismatch: expected=%h got=%h", expC10, c_at(2));
      if (c_at(3) !== expC11) $fatal(1, "C11 mismatch: expected=%h got=%h", expC11, c_at(3));
    end
  endtask

  // --------------------------
  // Test sequence
  // --------------------------
  initial begin
    // init
    rst_n    = 1'b0;
    start    = 1'b0;
    in_valid = 1'b0;
    a_vec_in = '0;
    b_vec_in = '0;

    // reset a few cycles
    repeat (3) @(posedge clk);
    rst_n = 1'b1;
    @(posedge clk);

    // Directed test (easy to verify)
    // A = [ [1,2],
    //       [3,4] ]
    // B = [ [5,6],
    //       [7,8] ]
    // C = A*B = [ [19,22],
    //             [43,50] ]
    run_one_2x2_case(32'd1, 32'd2, 32'd3, 32'd4,
                     32'd5, 32'd6, 32'd7, 32'd8);

    // A few random tests
    for (int k = 0; k < 50; k++) begin
      run_one_2x2_case($urandom(), $urandom(), $urandom(), $urandom(),
                       $urandom(), $urandom(), $urandom(), $urandom());
    end

    $display("PASS: All systolic array tests passed.");
    $finish;
  end

endmodule

`default_nettype wire
