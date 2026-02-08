`timescale 1ns/1ps
`default_nettype none

module tb_sram_buffer;

  localparam int DEPTH = 16;
  localparam int AW    = 4;

  logic clk = 1'b0;
  always #5 clk = ~clk;

  logic [0:0] we;
  logic [0:0][AW-1:0] waddr;
  logic [0:0][31:0] wdata;

  logic [0:0] re;
  logic [0:0][AW-1:0] raddr;
  wire  [0:0][31:0] rdata;

  integer pass_count;
  integer test_count;

  sram_buffer #(
    .DEPTH(DEPTH),
    .ADDR_WIDTH(AW),
    .RD_PORTS(1),
    .WR_PORTS(1)
  ) dut (
    .clk(clk),
    .re(re),
    .raddr(raddr),
    .rdata(rdata),
    .we(we),
    .waddr(waddr),
    .wdata(wdata)
  );

  task automatic check_eq(input [31:0] exp, input [31:0] got, input [255:0] name);
    begin
      test_count = test_count + 1;
      if (exp === got) begin
        pass_count = pass_count + 1;
        $display("[PASS] %s exp=%h got=%h", name, exp, got);
      end else begin
        $display("[FAIL] %s exp=%h got=%h", name, exp, got);
      end
    end
  endtask

  initial begin
    pass_count = 0;
    test_count = 0;

    we = 1'b0;
    re = 1'b0;
    waddr[0] = '0;
    wdata[0] = '0;
    raddr[0] = '0;

    // Write two locations
    $display("[RUN] write_read_basic");
    @(posedge clk);
    we[0]    = 1'b1;
    waddr[0] = 4'd3;
    wdata[0] = 32'hA5A5_0001;
    @(posedge clk);
    waddr[0] = 4'd7;
    wdata[0] = 32'hA5A5_0002;
    @(posedge clk);
    we[0] = 1'b0;

    // Read back (async read)
    re[0]    = 1'b1;
    raddr[0] = 4'd3;
    #1;
    check_eq(32'hA5A5_0001, rdata[0], "read_addr_3");
    raddr[0] = 4'd7;
    #1;
    check_eq(32'hA5A5_0002, rdata[0], "read_addr_7");

    // Read default (unwritten)
    raddr[0] = 4'd1;
    #1;
    check_eq(32'h0000_0000, rdata[0], "read_unwritten");

    $display("[SUMMARY] %0d OF %0d TESTS PASSED", pass_count, test_count);
    if (pass_count != test_count) $fatal(1, "SRAM buffer tests failed.");
    $finish;
  end

endmodule

`default_nettype wire
