`timescale 1ns/1ps
`default_nettype none

/*
 * tb_systolic.sv
 *
 * Simple self-checking testbench for systolic.v (MVP version).
 * Verifies:
 *   - start pulse triggers one compute
 *   - done asserts
 *   - result equals a*b (since acc=0 in systolic.v MVP)
 */

module tb_systolic;

  // Clock: 100MHz (10ns period)
  logic clk = 0;
  always #5 clk = ~clk;

  // DUT signals
  logic rst_n;
  logic start;
  logic [31:0] a, b;
  wire  [31:0] result;
  wire         done;

  // Instantiate DUT
  systolic dut (
    .clk(clk),
    .rst_n(rst_n),
    .start(start),
    .a(a),
    .b(b),
    .result(result),
    .done(done)
  );

  initial begin
    // Init
    rst_n = 0;
    start = 0;
    a = 0; b = 0;

    // Reset
    repeat (3) @(posedge clk);
    rst_n = 1;

    // Provide operands
    a = 32'd7;
    b = 32'd6;   // expected 42

    // Pulse start for 1 cycle
    @(posedge clk);
    start = 1'b1;
    @(posedge clk);
    start = 1'b0;

    // Wait for done to assert (should be quick in MVP)
    // Timeout to avoid hanging if something breaks.
    int cycles = 0;
    while (done !== 1'b1 && cycles < 20) begin
      @(posedge clk);
      cycles++;
    end

    if (done !== 1'b1) $fatal(1, "FAIL: systolic done never asserted");

    $display("Systolic result = %0d (expected 42)", result);
    if (result !== 32'd42) $fatal(1, "FAIL: systolic result mismatch");

    $display("PASS: systolic MVP compute works");
    $finish;
  end

endmodule
