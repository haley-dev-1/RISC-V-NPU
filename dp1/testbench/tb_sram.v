`timescale 1ns/1ps

module tb_sram();
    reg clk;
    reg reset;
    reg en;
    reg we;
    reg [15:0] addr;
    reg [31:0] wdata;
    wire [31:0] rdata;

    // Instantiate the SRAM
    sram_256kb dut (
        .clk(clk),
        .reset(reset),
        .en(en),
        .we(we),
        .addr(addr),
        .wdata(wdata),
        .rdata(rdata)
    );

    // Clock generation
    always #5 clk = ~clk;

    initial begin
        // Initialize signals
        clk = 0;
        reset = 1;
        en = 0;
        we = 0;
        addr = 0;
        wdata = 0;

        #20 reset = 0;
        #10 en = 1;

        // Test Case 1: Write/Read at Address 0x0000
        $display("Testing Address 0x0000...");
        addr = 16'h0000; wdata = 32'hDEADBEEF; we = 1;
        #10 we = 0;
        #10;
        if (rdata === 32'hDEADBEEF) $display("PASS: Addr 0x0000 read correct value.");
        else $display("FAIL: Addr 0x0000 read %h", rdata);

        // Test Case 2: Write/Read at Address 0xFFFF
        $display("Testing Address 0xFFFF...");
        addr = 16'hFFFF; wdata = 32'hCAFEBABE; we = 1;
        #10 we = 0;
        #10;
        if (rdata === 32'hCAFEBABE) $display("PASS: Addr 0xFFFF read correct value.");
        else $display("FAIL: Addr 0xFFFF read %h", rdata);

        $display("SRAM Testing Complete.");
        $finish;
    end
endmodule
