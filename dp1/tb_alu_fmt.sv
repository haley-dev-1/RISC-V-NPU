`timescale 1ns/1ps
`default_nettype none

module tb_alu_fmt;
  // Clock
  reg clk = 1'b0;
  always #5 clk = ~clk;

  // DUT signals
  reg         rstn;
  reg  [3:0]  op;
  reg  [31:0] a;
  reg  [31:0] b;
  wire [31:0] d;
  wire        cmp;

  // Instantiate wrapper DUT (32-bit nibble-serial)
  tb_alu dut (
    .clk (clk),
    .rstn(rstn),
    .op  (op),
    .a   (a),
    .b   (b),
    .d   (d),
    .cmp (cmp)
  );

  localparam [3:0] OP_ADD = 4'b0000;
  localparam [3:0] OP_SUB = 4'b1000;
  localparam [3:0] OP_AND = 4'b0111;
  localparam [3:0] OP_SLT = 4'b0010;

  integer pass_count;

  task automatic run_test(
    input integer idx,
    input [3:0]  op_in,
    input [31:0] a_in,
    input [31:0] b_in,
    input [31:0] expected
  );
    reg [31:0] received;
    begin
      op = op_in;
      a  = a_in;
      b  = b_in;

      // Reset counter alignment to nibble 0
      rstn = 1'b0;
      @(posedge clk);
      rstn = 1'b1;

      // Run 8 cycles to cover all 32 bits
      repeat (8) @(posedge clk);
      @(negedge clk);
      received = d;

      $display("test %0d ....", idx);
      $display("expected 0x%08h", expected);
      $display("received 0x%08h", received);
      if (received === expected) begin
        $display("Result: [PASS]");
        pass_count = pass_count + 1;
      end else begin
        $display("Result: [FAIL]");
      end
    end
  endtask

  initial begin
    rstn = 1'b0;
    op   = 4'b0;
    a    = 32'h0;
    b    = 32'h0;
    pass_count = 0;

    $display("dp1/tb_alu.v");

    run_test(1, OP_ADD, 32'h00000002, 32'h00000003, 32'h00000005);
    run_test(2, OP_SUB, 32'h00000010, 32'h00000001, 32'h0000000F);
    run_test(3, OP_AND, 32'hF0F0F0F0, 32'h0F0F0F0F, 32'h00000000);
    run_test(4, OP_SLT, 32'hFFFFFFFF, 32'h00000001, 32'h00000001);

    $display("dp1/tb_alu.v");
    $display("%0d OF 4 TESTS PASS", pass_count);

    if (pass_count != 4) $finish(1);
    $finish;
  end

endmodule

`default_nettype wire
