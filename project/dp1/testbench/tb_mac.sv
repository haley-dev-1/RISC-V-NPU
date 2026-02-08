`timescale 1ns/1ps
`default_nettype none

module tb_mac;

  // Clock
  logic clk = 1'b0;
  /* verilator lint_off BLKSEQ */
  always #5 clk = ~clk;   // 100 MHz sim clock
  /* verilator lint_on  BLKSEQ */

  // DUT signals
  logic        rst_n;
  logic        valid;
  logic [31:0] a, b, acc;
  logic [31:0] result;
  logic        done;

  // Instantiate DUT
  mac dut (
    .clk   (clk),
    .rst_n (rst_n),
    .valid (valid),
    .a     (a),
    .b     (b),
    .acc   (acc),
    .result(result),
    .done  (done)
  );

  // Expected result model (matches RTL: signed a/b/acc, 64-bit intermediates,
  // and truncation/wrap to 32 bits).
  function automatic logic [31:0] expected_wrap32_signed(
    input logic [31:0] aa,
    input logic [31:0] bb,
    input logic [31:0] accc
  );
    longint signed prod_s;
    longint signed sum_s;
    logic dummy;
    begin
      prod_s = $signed(aa) * $signed(bb);

      // Explicit sign-extension to 64b avoids Verilator WIDTHEXPAND warnings
      sum_s  = prod_s + {{32{accc[31]}}, accc};

      // Touch upper bits so Verilator doesn't warn about unused [63:32]
      dummy = ^sum_s[63:32];
      if (dummy) begin end

      expected_wrap32_signed = sum_s[31:0]; // wrap modulo 2^32
    end
  endfunction

  integer pass_count;
  integer test_count;

  // Apply one transaction and check done/result
  task automatic apply_and_check(
    input int case_id,
    input logic [31:0] aa,
    input logic [31:0] bb,
    input logic [31:0] accc
  );
    logic [31:0] exp;
    bit case_pass;
    begin
      exp = expected_wrap32_signed(aa, bb, accc);
      case_pass = 1'b1;

      $display("[RUN] case_%0d", case_id);
      $display("[INPUT] a=%h b=%h acc=%h", aa, bb, accc);
      $display("[EXPECTED OUTPUT] result=%h done=1", exp);

      // Drive inputs before compute edge
      @(negedge clk);
      a     = aa;
      b     = bb;
      acc   = accc;
      valid = 1'b1;

      // Compute happens here (posedge)
      @(posedge clk);

      // Wait half cycle so NBAs are definitely visible, then check
      @(negedge clk);

      if (done !== 1'b1) begin
        $display("DEBUG t=%0t rst_n=%b valid=%b a=%h b=%h acc=%h -> done=%b result=%h",
                 $time, rst_n, valid, a, b, acc, done, result);
        case_pass = 1'b0;
      end

      if (result !== exp) begin
        $display("DEBUG t=%0t a=%h b=%h acc=%h exp=%h got=%h done=%b",
                 $time, aa, bb, accc, exp, result, done);
        case_pass = 1'b0;
      end

      // Drop valid; next cycle done should deassert
      valid = 1'b0;

      @(posedge clk);
      @(negedge clk);
      if (done !== 1'b0) begin
        case_pass = 1'b0;
      end

      $display("[OUTPUT] result=%h done=%b", result, done);
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

    // Init
    rst_n = 1'b0;
    valid = 1'b0;
    a = '0; b = '0; acc = '0;

    // Reset for a few cycles
    repeat (3) @(posedge clk);
    rst_n = 1'b1;

    // Make sure we’re out of reset cleanly
    @(posedge clk);
    if (!rst_n) $fatal(1, "Reset still low unexpectedly.");

    // Directed tests (signed)
    apply_and_check(0, 32'sd2,   32'sd3,   32'sd4);              // 2*3+4=10
    apply_and_check(1, 32'sd0,   32'sd12345, -32'sd7);           // 0*b+acc=acc
    apply_and_check(2, -32'sd2,  32'sd3,   32'sd4);              // -2*3+4=-2
    apply_and_check(3, -32'sd2,  -32'sd3,  32'sd4);              // (-2)*(-3)+4=10
    apply_and_check(4, 32'sd7,   -32'sd8,  32'sd1);              // 7*-8+1=-55

    // Edge cases
    apply_and_check(5, 32'sd1,   32'sd1,   32'sd0);
    apply_and_check(6, -32'sd1,  32'sd1,   32'sd0);
    apply_and_check(7, -32'sd1,  -32'sd1,  32'sd0);
    apply_and_check(8, 32'sh7FFF_FFFF, 32'sd2, 32'sd0);          // INT_MAX*2
    apply_and_check(9, 32'sh8000_0000, 32'sd2, 32'sd1);          // INT_MIN*2+1
    apply_and_check(10, 32'sh8000_0000, 32'sh8000_0000, 32'sd0); // INT_MIN*INT_MIN

    // Random tests (>= 200 vectors)
    for (int i = 0; i < 500; i++) begin
      apply_and_check(11 + i, $urandom(), $urandom(), $urandom());
    end

    $display("[SUMMARY] %0d OF %0d TESTS PASSED", pass_count, test_count);
    if (pass_count != test_count) $fatal(1, "MAC tests failed.");
    $finish;
  end

endmodule

`default_nettype wire
