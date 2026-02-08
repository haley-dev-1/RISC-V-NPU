`timescale 1ns/1ps
`default_nettype none

module tb_npu_mmio;

    reg clk = 0;
    always #5 clk = ~clk;  // 100MHz sim clock

    reg rst_n;

    reg  [7:0]  ui_in = 0;
    wire [7:0]  uo_out;

    reg  [5:0]  address;
    reg  [31:0] data_in;
    reg  [1:0]  data_write_n;
    reg  [1:0]  data_read_n;

    wire [31:0] data_out;
    wire        data_ready;
    wire        user_interrupt;

    // DUT
    tqvp_example dut (
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

    // simple MMIO write task (32-bit)
    task mmio_write(input [5:0] addr, input [31:0] val);
    begin
        @(posedge clk);
        address      <= addr;
        data_in      <= val;
        data_write_n <= 2'b10; // 32-bit write
        data_read_n  <= 2'b11;

        @(posedge clk);
        data_write_n <= 2'b11;
        data_in      <= 32'd0;
    end
    endtask

    // simple MMIO read task (32-bit)
    task mmio_read(input [5:0] addr, output [31:0] val);
    begin
        @(posedge clk);
        address     <= addr;
        data_read_n <= 2'b10; // 32-bit read
        data_write_n<= 2'b11;

        @(posedge clk);
        val = data_out;

        @(posedge clk);
        data_read_n <= 2'b11;
    end
    endtask

    integer r;

    initial begin
        // init
        rst_n = 0;
        address = 0;
        data_in = 0;
        data_write_n = 2'b11;
        data_read_n  = 2'b11;

        // reset
        repeat (4) @(posedge clk);
        rst_n = 1;

        // Write operands
        mmio_write(6'h00, 32'd3); // A
        mmio_write(6'h01, 32'd4); // B

        // Start
        mmio_write(6'h02, 32'd1);

        // Poll STATUS until done (should complete quickly)
        r = 0;
        while (r == 0) begin
            mmio_read(6'h04, r); // STATUS
            r = r & 32'h1;
        end

        // Read result
        mmio_read(6'h03, r);
        $display("RESULT=%0d (expected 12)", r);

        if (r !== 12) $fatal("FAIL: result mismatch");
        $display("PASS: peripheral MMIO path works");

        // Clear done and verify it clears
        mmio_write(6'h05, 32'd1);
        mmio_read(6'h04, r);
        if ((r & 1) !== 0) $fatal("FAIL: done did not clear");
        $display("PASS: done clear works");

        $finish;
    end

endmodule
