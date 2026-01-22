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

  // Expected result model (matches your RTL: unsigned math + truncation to 32 bits)
  function automatic logic [31:0] expected_wrap32(
    input logic [31:0] aa,
    input logic [31:0] bb,
    input logic [31:0] accc
  );
    logic [63:0] prod;
    logic [63:0] sum64;
    begin
      prod  = aa * bb;
      sum64 = prod + {32'b0, accc};
      expected_wrap32 = sum64[31:0];
    end
  endfunction

  // Apply one transaction and check done/result
  task automatic apply_and_check(
    input logic [31:0] aa,
    input logic [31:0] bb,
    input logic [31:0] accc
  );
    logic [31:0] exp;
    begin
      exp = expected_wrap32(aa, bb, accc);

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
        $fatal(1, "DONE not asserted when expected. a=%h b=%h acc=%h", aa, bb, accc);
      end

      if (result !== exp) begin
        $display("DEBUG t=%0t a=%h b=%h acc=%h exp=%h got=%h done=%b",
                 $time, aa, bb, accc, exp, result, done);
        $fatal(1, "Mismatch!");
      end

      // Drop valid; next cycle done should deassert
      valid = 1'b0;

      @(posedge clk);
      @(negedge clk);
      if (done !== 1'b0) begin
        $fatal(1, "DONE did not deassert as expected. done=%b", done);
      end
    end
  endtask

  initial begin
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

    // Directed tests
    apply_and_check(32'd2, 32'd3, 32'd4);            // 2*3+4=10
    apply_and_check(32'd0, 32'hDEADBEEF, 32'd123);   // 0*b+acc=acc
    apply_and_check(32'hFFFF_FFFF, 32'd2, 32'd0);    // wraparound
    apply_and_check(32'h8000_0000, 32'd2, 32'd1);    // overflow + acc

    // Random tests
    for (int i = 0; i < 200; i++) begin
      apply_and_check($urandom(), $urandom(), $urandom());
    end

    $display("PASS: All MAC tests passed.");
    $finish;
  end

endmodule

`default_nettype wire
