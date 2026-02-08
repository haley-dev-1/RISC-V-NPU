`timescale 1ns/1ps
`default_nettype none

module tb_tt_wrapper;

  // Clock/reset
  logic clk = 1'b0;
  logic rst_n = 1'b0;

  // IOs
  logic [7:0] ui_in;
  wire  [7:0] uo_out;
  logic [7:0] uio_in;
  wire  [7:0] uio_out;
  wire  [7:0] uio_oe;
  logic       ena;

  // SPI pins mapped on uio_in
  localparam int SPI_CS_N_BIT = 4;
  localparam int SPI_CLK_BIT  = 5;
  localparam int SPI_MOSI_BIT = 6;
  localparam int SPI_MISO_BIT = 3; // uio_out[3]

  // MMIO addresses (6-bit)
  localparam [5:0] ADDR_CTRL   = 6'h20;
  localparam [5:0] ADDR_STATUS = 6'h21;

  integer pass_count;
  integer test_count;
  integer cycles;
  logic [31:0] rdata;

  // Clock
  /* verilator lint_off BLKSEQ */
  always #5 clk = ~clk;
  /* verilator lint_on  BLKSEQ */

  // DUT: SPI wrapper top
  tt_um_tqv_peripheral_harness dut (
    .ui_in(ui_in),
    .uo_out(uo_out),
    .uio_in(uio_in),
    .uio_out(uio_out),
    .uio_oe(uio_oe),
    .ena(ena),
    .clk(clk),
    .rst_n(rst_n)
  );

  // SPI helpers (mode 0, MSB-first)
  task automatic spi_cs(input bit level);
    begin
      uio_in[SPI_CS_N_BIT] = level;
      @(posedge clk);
    end
  endtask

  task automatic spi_clk_level(input bit level);
    begin
      uio_in[SPI_CLK_BIT] = level;
      @(posedge clk);
    end
  endtask

  task automatic spi_write_bit(input bit b);
    begin
      uio_in[SPI_MOSI_BIT] = b;
      // ensure clock low before rising edge
      uio_in[SPI_CLK_BIT] = 1'b0;
      @(posedge clk);
      // rising edge: sample
      uio_in[SPI_CLK_BIT] = 1'b1;
      @(posedge clk);
      // falling edge: shift
      uio_in[SPI_CLK_BIT] = 1'b0;
      @(posedge clk);
    end
  endtask

  task automatic spi_read_bit(output bit b);
    begin
      // ensure clock low before rising edge
      uio_in[SPI_CLK_BIT] = 1'b0;
      @(posedge clk);
      // rising edge: sample
      uio_in[SPI_CLK_BIT] = 1'b1;
      @(posedge clk);
      b = uio_out[SPI_MISO_BIT];
      // falling edge: shift
      uio_in[SPI_CLK_BIT] = 1'b0;
      @(posedge clk);
    end
  endtask

  task automatic spi_send_word_msb(input [31:0] word);
    integer k;
    begin
      for (k = 31; k >= 0; k = k - 1) begin
        spi_write_bit(word[k]);
      end
    end
  endtask

  task automatic spi_recv_word_msb(output [31:0] word);
    integer k;
    bit b;
    begin
      word = 32'd0;
      for (k = 0; k < 32; k = k + 1) begin
        spi_read_bit(b);
        word = {word[30:0], b};
      end
    end
  endtask

  // SPI transaction format:
  // [31]=reg_rw (1=write,0=read)
  // [30:29]=txn_width (2'b10 for 32-bit)
  // [5:0]=address
  function automatic [31:0] spi_cmd_word(
    input bit rw,
    input [5:0] addr
  );
    spi_cmd_word = {rw, 2'b10, 23'd0, addr};
  endfunction

  task automatic spi_write_reg(input [5:0] addr, input [31:0] data);
    begin
      spi_cs(1'b1);
      spi_clk_level(1'b0);
      spi_cs(1'b0);
      spi_send_word_msb(spi_cmd_word(1'b1, addr));
      spi_send_word_msb(data);
      spi_cs(1'b1);
    end
  endtask

  task automatic spi_read_reg(input [5:0] addr, output [31:0] data);
    begin
      spi_cs(1'b1);
      spi_clk_level(1'b0);
      spi_cs(1'b0);
      spi_send_word_msb(spi_cmd_word(1'b0, addr));
      // Allow TX_LOAD to capture reg_data_i before shifting out
      repeat (4) @(posedge clk);
      spi_recv_word_msb(data);
      spi_cs(1'b1);
    end
  endtask

  // Golden model
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

  task automatic run_case_2x2(
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

      // Beat 0
      spi_write_reg(6'h00, A00);
      spi_write_reg(6'h01, A10);
      spi_write_reg(6'h10, B00);
      spi_write_reg(6'h11, B01);
      spi_write_reg(ADDR_CTRL, 32'h0000_0002); // clear
      spi_write_reg(ADDR_CTRL, 32'h0000_0001); // start + push

      // Beat 1
      spi_write_reg(6'h00, A01);
      spi_write_reg(6'h01, A11);
      spi_write_reg(6'h10, B10);
      spi_write_reg(6'h11, B11);
      spi_write_reg(ADDR_CTRL, 32'h0000_0001); // push while busy

      // Poll done
      cycles = 0;
      while (1) begin
        spi_read_reg(ADDR_STATUS, rdata);
        if (^rdata === 1'bx) $fatal(1, "STATUS read has Xs: %h", rdata);
        if (rdata[0]) break;
        cycles++;
        if (cycles > 600) $fatal(1, "Timeout waiting for DONE");
      end

      spi_read_reg(6'h30, gotC00); if (gotC00 !== expC00) case_pass = 1'b0;
      spi_read_reg(6'h31, gotC01); if (gotC01 !== expC01) case_pass = 1'b0;
      spi_read_reg(6'h32, gotC10); if (gotC10 !== expC10) case_pass = 1'b0;
      spi_read_reg(6'h33, gotC11); if (gotC11 !== expC11) case_pass = 1'b0;

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

    ui_in = '0;
    uio_in = 8'hFF; // cs high, clk high by default
    ena = 1'b1;

    // reset
    repeat (3) @(posedge clk);
    rst_n = 1'b0;
    repeat (5) @(posedge clk);
    rst_n = 1'b1;

    // Directed test
    run_case_2x2(
      0,
      32'sd1,  -32'sd2,
      32'sd3,  32'sd4,
      -32'sd5, 32'sd6,
      32'sd7,  -32'sd8
    );

    // Random tests
    for (int t = 0; t < 10; t++) begin
      run_case_2x2(t + 1,
                   $urandom(), $urandom(), $urandom(), $urandom(),
                   $urandom(), $urandom(), $urandom(), $urandom());
    end

    $display("[SUMMARY] %0d OF %0d TESTS PASSED", pass_count, test_count);
    if (pass_count != test_count) $fatal(1, "tt_wrapper SPI tests failed.");
    $finish;
  end

endmodule

`default_nettype wire
