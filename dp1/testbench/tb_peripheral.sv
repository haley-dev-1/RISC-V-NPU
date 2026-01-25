`timescale 1ns/1ps
`default_nettype none

module tb_peripheral;

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

  // clock
  always #5 clk = ~clk;  // 100MHz

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
    data_read_n  = 2'b10; // read indicator (DUT ignores, fine)
    @(negedge clk);
    val = data_out;
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

    // --- Load A lanes (0x00..0x01 for N=2) ---
    mmio_write(6'h00, 32'sd3);  // A[0]
    mmio_write(6'h01, 32'sd4);  // A[1]

    // --- Load B lanes (0x10..0x11) ---
    mmio_write(6'h10, 32'sd5);  // B[0]
    mmio_write(6'h11, 32'sd6);  // B[1]

    // Clear status then start
    mmio_write(6'h20, 32'h0000_0002); // CTRL.CLR_STATUS
    mmio_write(6'h20, 32'h0000_0001); // CTRL.START

    // Poll DONE in STATUS (0x21 bit0)
cycles = 0;
while (1) begin
  mmio_read(6'h21, rdata);
  if (rdata[0]) break;

  cycles++;
  if (cycles > 200) $fatal(1, "Timeout waiting for DONE");
end

$display("DONE after %0d polls", cycles);

mmio_read(6'h30, rdata); $display("C[0]=0x%08x", rdata);
mmio_read(6'h31, rdata); $display("C[1]=0x%08x", rdata);
mmio_read(6'h32, rdata); $display("C[2]=0x%08x", rdata);
mmio_read(6'h33, rdata); $display("C[3]=0x%08x", rdata);

    $finish;
  end

endmodule

`default_nettype wire
