`timescale 1ns/1ps
`default_nettype none

module tb_dma;

  integer cycles;
  logic [31:0] rdata;

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

  // Test vectors and addresses
  logic [31:0] A00, A01, A10, A11;
  logic [31:0] B00, B01, B10, B11;
  logic [31:0] C00, C01, C10, C11;
  logic [31:0] src_a_addr;
  logic [31:0] src_b_addr;
  logic [31:0] dst_c_addr;
  logic [31:0] got;

  // clock
  /* verilator lint_off BLKSEQ */
  always #5 clk = ~clk;  // 100MHz
  /* verilator lint_on  BLKSEQ */

  // Instantiate peripheral directly
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

  // MMIO helpers
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

  // Address map
  localparam [5:0] ADDR_ACCEL_CTRL   = 6'h22;
  localparam [5:0] ADDR_ACCEL_STATUS = 6'h23;
  localparam [5:0] ADDR_SRC_A        = 6'h24;
  localparam [5:0] ADDR_SRC_B        = 6'h25;
  localparam [5:0] ADDR_DST_C        = 6'h26;
  localparam [5:0] ADDR_LEN          = 6'h27;
  localparam [5:0] ADDR_SPAD_A       = 6'h28;
  localparam [5:0] ADDR_SPAD_B       = 6'h29;
  localparam [5:0] ADDR_SPAD_C       = 6'h2A;
  localparam [5:0] ADDR_SYS_ADDR     = 6'h2E;
  localparam [5:0] ADDR_SYS_DATA     = 6'h2F;

  // SYS_MEM helpers (byte addresses)
  task sysmem_write(input [31:0] addr, input [31:0] val);
    begin
      mmio_write(ADDR_SYS_ADDR, addr);
      mmio_write(ADDR_SYS_DATA, val);
    end
  endtask

  task sysmem_read(input [31:0] addr, output [31:0] val);
    begin
      mmio_write(ADDR_SYS_ADDR, addr);
      mmio_read(ADDR_SYS_DATA, val);
    end
  endtask

  // Signed golden model: wrap modulo 2^32
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
      sum_s  = prod_s + {{32{acc_in[31]}}, acc_in};
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

  initial begin
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

    A00 = 32'sd2;  A01 = -32'sd1;
    A10 = 32'sd3;  A11 = 32'sd4;
    B00 = -32'sd5; B01 = 32'sd6;
    B10 = 32'sd7;  B11 = -32'sd8;

    compute_expected_2x2(A00, A01, A10, A11, B00, B01, B10, B11,
                         C00, C01, C10, C11);

    src_a_addr = 32'h0000_0000;
    src_b_addr = 32'h0000_0040;
    dst_c_addr = 32'h0000_0080;

    // Write A matrix into SYS_MEM
    sysmem_write(src_a_addr + 32'd0,  A00);
    sysmem_write(src_a_addr + 32'd4,  A01);
    sysmem_write(src_a_addr + 32'd8,  A10);
    sysmem_write(src_a_addr + 32'd12, A11);

    // Write B matrix into SYS_MEM
    sysmem_write(src_b_addr + 32'd0,  B00);
    sysmem_write(src_b_addr + 32'd4,  B01);
    sysmem_write(src_b_addr + 32'd8,  B10);
    sysmem_write(src_b_addr + 32'd12, B11);

    // Configure DMA + compute
    mmio_write(ADDR_SRC_A,  src_a_addr);
    mmio_write(ADDR_SRC_B,  src_b_addr);
    mmio_write(ADDR_DST_C,  dst_c_addr);
    mmio_write(ADDR_LEN,    32'd16); // 2x2 words

    // Scratchpad bases (byte addresses)
    mmio_write(ADDR_SPAD_A, 32'h0000_0000);
    mmio_write(ADDR_SPAD_B, 32'h0000_0100);
    mmio_write(ADDR_SPAD_C, 32'h0000_0200);

    // Clear status then start
    mmio_write(ADDR_ACCEL_CTRL, 32'h0000_0002);
    mmio_write(ADDR_ACCEL_CTRL, 32'h0000_0001);

    // Poll DONE in ACCEL_STATUS (bit0)
    cycles = 0;
    while (1) begin
      mmio_read(ADDR_ACCEL_STATUS, rdata);
      if (^rdata === 1'bx) $fatal(1, "STATUS read has Xs: %h", rdata);
      if (rdata[2]) $fatal(1, "ACCEL_STATUS error set: %h", rdata);
      if (rdata[0]) break;
      cycles++;
      if (cycles > 800) $fatal(1, "Timeout waiting for DMA accel DONE");
    end

    // Read back results from SYS_MEM and compare
    sysmem_read(dst_c_addr + 32'd0,  got); if (got !== C00) $fatal(1, "C00 mismatch exp=%h got=%h", C00, got);
    sysmem_read(dst_c_addr + 32'd4,  got); if (got !== C01) $fatal(1, "C01 mismatch exp=%h got=%h", C01, got);
    sysmem_read(dst_c_addr + 32'd8,  got); if (got !== C10) $fatal(1, "C10 mismatch exp=%h got=%h", C10, got);
    sysmem_read(dst_c_addr + 32'd12, got); if (got !== C11) $fatal(1, "C11 mismatch exp=%h got=%h", C11, got);

    if ((&uo_out) === 1'bx) $fatal(1, "uo_out has Xs");
    if (data_ready !== 1'b1) $fatal(1, "data_ready not 1");
    if (user_interrupt !== 1'b0) $fatal(1, "user_interrupt not 0");

    $display("PASS: DMA end-to-end test passed.");
    $finish;
  end

endmodule

`default_nettype wire
