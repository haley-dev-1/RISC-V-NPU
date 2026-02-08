`timescale 1ns/1ps
`default_nettype none

/*
 * tb_systolic.sv
 *
 * Testbench for systolic.v (wavefront streaming systolic array).
 *
 * Verilator-friendly:
 *  - Drive signals on negedge so they are stable before posedge sampling.
 *  - Check outputs after the DUT has had time to update registered signals.
 *
 * What we test:
 *  - 2x2 matrix multiply using the streaming wavefront schedule.
 *  - Signed correctness with a directed negative test.
 *  - Random tests to catch surprises.
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

  integer pass_count;
  integer test_count;

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
  // Helper function: 32-bit signed MAC wraparound (matches mac.v behavior)
  // --------------------------
  function automatic logic [31:0] mac_wrap32_signed(
    input logic [31:0] x,
    input logic [31:0] y,
    input logic [31:0] acc_in
  );
    longint signed prod_s;
    longint signed sum_s;
    logic dummy;
    begin
      prod_s = $signed(x) * $signed(y);

      // Explicit sign-extension to 64b avoids Verilator WIDTHEXPAND warnings
      sum_s  = prod_s + {{32{acc_in[31]}}, acc_in};

      // Touch upper bits so Verilator doesn't warn about unused [63:32]
      dummy = ^sum_s[63:32];
      if (dummy) begin end

      mac_wrap32_signed = sum_s[31:0]; // wrap modulo 2^32
    end
  endfunction

  // Compute expected C = A*B for 2x2 (wrap mod 2^32)
  task automatic compute_expected_2x2(
    input  logic [31:0] A00, A01, A10, A11,
    input  logic [31:0] B00, B01, B10, B11,
    output logic [31:0] C00, C01, C10, C11
  );
    logic [31:0] t0;
    begin
      // C00 = A00*B00 + A01*B10
      t0  = mac_wrap32_signed(A00, B00, 32'd0);
      C00 = mac_wrap32_signed(A01, B10, t0);

      // C01 = A00*B01 + A01*B11
      t0  = mac_wrap32_signed(A00, B01, 32'd0);
      C01 = mac_wrap32_signed(A01, B11, t0);

      // C10 = A10*B00 + A11*B10
      t0  = mac_wrap32_signed(A10, B00, 32'd0);
      C10 = mac_wrap32_signed(A11, B10, t0);

      // C11 = A10*B01 + A11*B11
      t0  = mac_wrap32_signed(A10, B01, 32'd0);
      C11 = mac_wrap32_signed(A11, B11, t0);
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
    input int case_id,
    input logic [31:0] A00, A01, A10, A11,
    input logic [31:0] B00, B01, B10, B11
  );
    logic [31:0] expC00, expC01, expC10, expC11;
    logic [31:0] gotC00, gotC01, gotC10, gotC11;
    bit case_pass;
    begin
      case_pass = 1'b1;
      // Reference busy so Verilator doesn't warn it's unused
      if (busy === 1'bx) $fatal(1, "busy is X");

      compute_expected_2x2(A00, A01, A10, A11, B00, B01, B10, B11,
                           expC00, expC01, expC10, expC11);

      $display("[RUN] case_%0d", case_id);
      $display("[INPUT] A=%h %h %h %h  B=%h %h %h %h", A00, A01, A10, A11, B00, B01, B10, B11);
      $display("[EXPECTED OUTPUT] C=%h %h %h %h", expC00, expC01, expC10, expC11);

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

      // Check after updates settle
      @(negedge clk);

      gotC00 = c_at(0);
      gotC01 = c_at(1);
      gotC10 = c_at(2);
      gotC11 = c_at(3);

      if (gotC00 !== expC00) case_pass = 1'b0;
      if (gotC01 !== expC01) case_pass = 1'b0;
      if (gotC10 !== expC10) case_pass = 1'b0;
      if (gotC11 !== expC11) case_pass = 1'b0;

      $display("[OUTPUT] C=%h %h %h %h", gotC00, gotC01, gotC10, gotC11);

      test_count = test_count + 1;
      if (case_pass) begin
        pass_count = pass_count + 1;
        $display("[PASS] case_%0d", case_id);
      end else begin
        $display("[FAIL] case_%0d", case_id);
      end
    end
  endtask

  initial begin
    pass_count = 0;
    test_count = 0;

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

    // Directed test
    run_one_2x2_case(0, 32'd1, 32'd2, 32'd3, 32'd4,
                     32'd5, 32'd6, 32'd7, 32'd8);

    // Directed signed test with negatives (note: negatives are -32'sdX)
    run_one_2x2_case(1, -32'sd1, 32'sd2, 32'sd3, -32'sd4,
                     32'sd5, -32'sd6, -32'sd7, 32'sd8);

    // Random tests
    for (int k = 0; k < 300; k++) begin
      run_one_2x2_case(2 + k,
                       $urandom(), $urandom(), $urandom(), $urandom(),
                       $urandom(), $urandom(), $urandom(), $urandom());
    end

    $display("[SUMMARY] %0d OF %0d TESTS PASSED", pass_count, test_count);
    if (pass_count != test_count) $fatal(1, "Systolic tests failed.");
    $finish;
  end

endmodule

`default_nettype wire
