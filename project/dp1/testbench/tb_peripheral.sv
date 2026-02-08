`timescale 1ns/1ps
`default_nettype none

module tb_peripheral;

  integer cycles;
  logic [31:0] rdata;
  integer pass_count;
  integer test_count;

  // clock/reset
  logic clk = 0;
  logic rst_n = 0;

  // DUT IO
  logic [7:0]  ui_in;
  wire  [7:0]  uo_out;

  logic [5:0]  address;
  logic [31:0] data_in;
  logic [1:0]  data_write_n;
  logic [1:0]  data_read_n;

  wire  [31:0] data_out;
  wire         data_ready;
  wire         user_interrupt;

  // clock
  /* verilator lint_off BLKSEQ */
  always #5 clk = ~clk;  // 100MHz
  /* verilator lint_on  BLKSEQ */

  // Instantiate peripheral directly (simplest)
  tqvp_example #(.N(2)) dut (
    .clk(clk),
    .rst_n(rst_n),
    .ui_in(ui_in),
    .uo_out(uo_out),
    .address(address),
    .data_in(data_in),
    .data_write_n(data_write_n),
    .data_read_n(data_read_n),
    .data_out(data_out),
    .data_ready(data_ready),
    .user_interrupt(user_interrupt)
  );

  // --- MMIO helpers (word addresses, like your peripheral expects) ---
  task mmio_write(input [5:0] addr, input [31:0] val);
    begin
      @(negedge clk);
      address      = addr;
      data_in      = val;
      data_write_n = 2'b10; // 32-bit write
      data_read_n  = 2'b11;
      @(negedge clk);
      data_write_n = 2'b11; // idle
      data_in      = '0;
    end
  endtask

  task mmio_read(input [5:0] addr, output [31:0] val);
    begin
      @(negedge clk);
      address      = addr;
      data_write_n = 2'b11;
      data_read_n  = 2'b10;
      @(negedge clk);
      val = data_out;
    end
  endtask

  // --------------------------
  // Signed golden model: wrap modulo 2^32
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

      mac_wrap32_signed = sum_s[31:0];
    end
  endfunction

  task automatic compute_expected_2x2(
    input  logic [31:0] A00, A01, A10, A11,
    input  logic [31:0] B00, B01, B10, B11,
    output logic [31:0] C00, C01, C10, C11
  );
    logic [31:0] t0;
    begin
      t0  = mac_wrap32_signed(A00, B00, 32'd0);
      C00 = mac_wrap32_signed(A01, B10, t0);

      t0  = mac_wrap32_signed(A00, B01, 32'd0);
      C01 = mac_wrap32_signed(A01, B11, t0);

      t0  = mac_wrap32_signed(A10, B00, 32'd0);
      C10 = mac_wrap32_signed(A11, B10, t0);

      t0  = mac_wrap32_signed(A10, B01, 32'd0);
      C11 = mac_wrap32_signed(A11, B11, t0);
    end
  endtask

  // Run one 2x2 case through MMIO.
  // Mapping: each beat k provides A[:,k] in 0x00.. and B[k,:] in 0x10..
  task automatic run_one_case_2x2(
    input int case_id,
    input logic [31:0] A00, A01, A10, A11,
    input logic [31:0] B00, B01, B10, B11
  );
    logic [31:0] expC00, expC01, expC10, expC11;
    logic [31:0] gotC00, gotC01, gotC10, gotC11;
    bit case_pass;
    begin
      case_pass = 1'b1;
      compute_expected_2x2(A00, A01, A10, A11, B00, B01, B10, B11,
                           expC00, expC01, expC10, expC11);

      $display("[RUN] case_%0d", case_id);
      $display("[INPUT] A=%h %h %h %h  B=%h %h %h %h", A00, A01, A10, A11, B00, B01, B10, B11);
      $display("[EXPECTED OUTPUT] C=%h %h %h %h", expC00, expC01, expC10, expC11);

      // Beat 0: A[:,0] and B[0,:]
      mmio_write(6'h00, A00);
      mmio_write(6'h01, A10);
      mmio_write(6'h10, B00);
      mmio_write(6'h11, B01);

      // Clear status then START+PUSH first beat
      mmio_write(6'h20, 32'h0000_0002); // CTRL.CLR_STATUS
      mmio_write(6'h20, 32'h0000_0001); // CTRL.CMD (start when idle)

      // Beat 1: A[:,1] and B[1,:] (write lanes then PUSH)
      mmio_write(6'h00, A01);
      mmio_write(6'h01, A11);
      mmio_write(6'h10, B10);
      mmio_write(6'h11, B11);
      mmio_write(6'h20, 32'h0000_0001); // CTRL.CMD (push when busy)

      // Poll DONE in STATUS (0x21 bit0)
      cycles = 0;
      while (1) begin
        mmio_read(6'h21, rdata);

        // Use all bits of rdata so Verilator doesn't warn about [31:1] unused
        if (^rdata === 1'bx) $fatal(1, "STATUS read has Xs: %h", rdata);

        if (rdata[0]) break;
        cycles++;
        if (cycles > 400) $fatal(1, "Timeout waiting for DONE");
      end

      // Read back results and check
      mmio_read(6'h30, gotC00); if (gotC00 !== expC00) case_pass = 1'b0;
      mmio_read(6'h31, gotC01); if (gotC01 !== expC01) case_pass = 1'b0;
      mmio_read(6'h32, gotC10); if (gotC10 !== expC10) case_pass = 1'b0;
      mmio_read(6'h33, gotC11); if (gotC11 !== expC11) case_pass = 1'b0;

      $display("[OUTPUT] C=%h %h %h %h", gotC00, gotC01, gotC10, gotC11);

      // Reference these outputs so Verilator doesn't warn they're unused
      if ((&uo_out) === 1'bx) case_pass = 1'b0;
      if (data_ready !== 1'b1) case_pass = 1'b0;
      if (user_interrupt !== 1'b0) case_pass = 1'b0;

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

    ui_in = '0;
    address = '0;
    data_in = '0;
    data_write_n = 2'b11;
    data_read_n  = 2'b11;

    // reset
    repeat (3) @(negedge clk);
    rst_n = 0;
    repeat (5) @(negedge clk);
    rst_n = 1;

    // Directed signed test (note: negatives are -32'sdX)
    run_one_case_2x2(
      0,
      32'sd1,  -32'sd2,
      32'sd3,  32'sd4,
      -32'sd5, 32'sd6,
      32'sd7,  -32'sd8
    );

    // Random stress (a few cases)
    for (int t = 0; t < 25; t++) begin
      run_one_case_2x2(t + 1,
                       $urandom(), $urandom(), $urandom(), $urandom(),
                       $urandom(), $urandom(), $urandom(), $urandom());
    end

    $display("[SUMMARY] %0d OF %0d TESTS PASSED", pass_count, test_count);
    if (pass_count != test_count) $fatal(1, "Peripheral MMIO systolic tests failed.");
    $finish;
  end

endmodule

`default_nettype wire
