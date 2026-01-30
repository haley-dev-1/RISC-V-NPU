`timescale 1ns/1ps

`default_nettype none

module e2e_npu_tb;
    reg clk;
    reg rst_n;

    reg [7:0] ui_in;
    wire [7:0] uo_out;

    reg [5:0] address;
    reg [31:0] data_in;
    reg [1:0] data_write_n;
    reg [1:0] data_read_n;
    wire [31:0] data_out;
    wire data_ready;
    wire user_interrupt;

    tqvp_npu dut (
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

    // Clock
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    task mmio_write;
        input [5:0] addr;
        input [31:0] val;
        begin
            address = addr;
            data_in = val;
            data_write_n = 2'b10; // 32-bit
            @(posedge clk);
            #1 data_write_n = 2'b11;
        end
    endtask

    task mmio_read;
        input [5:0] addr;
        output [31:0] val;
        begin
            address = addr;
            data_read_n = 2'b10;
            @(posedge clk);
            #1 val = data_out;
            data_read_n = 2'b11;
        end
    endtask

    task write_mem_word;
        input [31:0] addr;
        input [31:0] val;
        begin
            dut.mem[addr[31:2]] = val;
        end
    endtask

    task wait_cycles;
        input integer n;
        integer k;
        begin
            for (k = 0; k < n; k = k + 1) begin
                @(posedge clk);
            end
        end
    endtask

    task wait_done_or_error;
        input integer max_cycles;
        output reg [31:0] status_out;
        integer c;
        reg done_flag;
        begin
            done_flag = 0;
            status_out = 32'd0;
            c = 0;
            while (c < max_cycles && !done_flag) begin
                mmio_read(6'h04, status_out);
                if (status_out[1] || status_out[2]) begin
                    done_flag = 1;
                end
                c = c + 1;
            end
        end
    endtask

    integer i, j, k;
    integer fail_count;
    reg [31:0] status;
    reg [31:0] exp;

    initial begin
        $dumpfile("trace.vcd");
        $dumpvars(0, e2e_npu_tb);

        ui_in = 0;
        address = 0;
        data_in = 0;
        data_write_n = 2'b11;
        data_read_n = 2'b11;
        fail_count = 0;

        rst_n = 0;
        wait_cycles(5);
        rst_n = 1;
        wait_cycles(5);


        // Common control
        mmio_write(6'h10, 32'h0000_0104); // rows=1, burst=4

        // Scenario 1: Copy (opcode 0)
        $display("Scenario1: Copy");
        // descriptors
        write_mem_word(32'h0000_0100, 32'h0000_0200); // src addr
        write_mem_word(32'h0000_0104, 32'd64);       // len = 16 words
        write_mem_word(32'h0000_0108, 32'h0001_0000); // flags=LAST, stride=0
        write_mem_word(32'h0000_010C, 32'd0);

        write_mem_word(32'h0000_0120, 32'h0000_0300); // dst addr
        write_mem_word(32'h0000_0124, 32'd64);
        write_mem_word(32'h0000_0128, 32'h0001_0000);
        write_mem_word(32'h0000_012C, 32'd0);

        // input data
        for (i = 0; i < 16; i = i + 1) begin
            write_mem_word(32'h0000_0200 + i*4, 32'h1000_0000 + i);
        end

        mmio_write(6'h08, 32'h0000_0100);
        mmio_write(6'h0C, 32'h0000_0120);
        mmio_write(6'h00, 32'h0000_0001); // START

        // wait for done
        wait_done_or_error(2000, status);
        if (!status[1]) begin
            $display("FAIL: Copy did not complete");
            fail_count = fail_count + 1;
        end

        for (i = 0; i < 16; i = i + 1) begin
            if (dut.mem[(32'h0000_0300 + i*4) >> 2] != (32'h1000_0000 + i)) begin
                $display("FAIL: Copy mismatch at %0d", i);
                fail_count = fail_count + 1;
            end
        end

        // Scenario 2: 4x4 matrix multiply (opcode 2)
        $display("Scenario2: MatMul");
        // A matrix at 0x0400, B matrix at 0x0440
        for (i = 0; i < 16; i = i + 1) begin
            write_mem_word(32'h0000_0400 + i*4, i + 1); // A
            write_mem_word(32'h0000_0440 + i*4, (i + 1) * 2); // B
        end

        write_mem_word(32'h0000_0200, 32'h0000_0400); // src addr
        write_mem_word(32'h0000_0204, 32'd128);      // len = 32 words (A+B)
        write_mem_word(32'h0000_0208, 32'h0001_0000);
        write_mem_word(32'h0000_020C, 32'd0);

        write_mem_word(32'h0000_0220, 32'h0000_0500); // dst addr
        write_mem_word(32'h0000_0224, 32'd64);        // len = 16 words
        write_mem_word(32'h0000_0228, 32'h0001_0000);
        write_mem_word(32'h0000_022C, 32'd0);

        mmio_write(6'h08, 32'h0000_0200);
        mmio_write(6'h0C, 32'h0000_0220);
        mmio_write(6'h00, 32'h0000_0011); // START + opcode=2 (bits[7:3])

        wait_done_or_error(4000, status);
        if (!status[1]) begin
            $display("FAIL: MatMul did not complete");
            fail_count = fail_count + 1;
        end

        // Compute expected C = A*B (4x4)
        for (i = 0; i < 4; i = i + 1) begin
            for (j = 0; j < 4; j = j + 1) begin
                exp = 0;
                for (k = 0; k < 4; k = k + 1) begin
                    exp = exp + ( (i*4 + k + 1) * ((k*4 + j + 1) * 2) );
                end
                if (dut.mem[(32'h0000_0500 + (i*4 + j)*4) >> 2] !== exp) begin
                    $display("FAIL: MatMul mismatch at (%0d,%0d) exp=%0d got=%0d", i, j, exp,
                             dut.mem[(32'h0000_0500 + (i*4 + j)*4) >> 2]);
                    fail_count = fail_count + 1;
                end
            end
        end

        // Scenario 3: Multi-descriptor chain (copy)
        $display("Scenario3: Descriptor chain copy");
        mmio_write(6'h00, 32'h0000_0000); // set opcode back to 0
        write_mem_word(32'h0000_0300, 32'h0000_0600);
        write_mem_word(32'h0000_0304, 32'd32); // 8 words
        write_mem_word(32'h0000_0308, 32'h0000_0000);
        write_mem_word(32'h0000_030C, 32'd0);

        write_mem_word(32'h0000_0310, 32'h0000_0620);
        write_mem_word(32'h0000_0314, 32'd32);
        write_mem_word(32'h0000_0318, 32'h0001_0000); // LAST
        write_mem_word(32'h0000_031C, 32'd0);

        write_mem_word(32'h0000_0320, 32'h0000_0700);
        write_mem_word(32'h0000_0324, 32'd64); // 16 words
        write_mem_word(32'h0000_0328, 32'h0001_0000);
        write_mem_word(32'h0000_032C, 32'd0);

        for (i = 0; i < 8; i = i + 1) begin
            write_mem_word(32'h0000_0600 + i*4, 32'h2000_0000 + i);
            write_mem_word(32'h0000_0620 + i*4, 32'h2000_0010 + i);
        end

        mmio_write(6'h08, 32'h0000_0300);
        mmio_write(6'h0C, 32'h0000_0320);
        mmio_write(6'h00, 32'h0000_0001); // START

        wait_done_or_error(3000, status);
        for (i = 0; i < 16; i = i + 1) begin
            exp = (i < 8) ? (32'h2000_0000 + i) : (32'h2000_0010 + (i - 8));
            if (dut.mem[(32'h0000_0700 + i*4) >> 2] != exp) begin
                $display("FAIL: Chain copy mismatch at %0d", i);
                fail_count = fail_count + 1;
            end
        end

        // Scenario 4: Watchdog timeout
        $display("Scenario4: Watchdog timeout");
        mmio_write(6'h1C, 32'd20); // watchdog small
        mmio_write(6'h10, 32'h8000_0104); // control[31]=hang
        mmio_write(6'h08, 32'h0000_0100);
        mmio_write(6'h0C, 32'h0000_0120);
        mmio_write(6'h00, 32'h0000_0001);
        wait_done_or_error(2000, status);
        if (!status[2]) begin
            $display("FAIL: Watchdog error not set");
            fail_count = fail_count + 1;
        end

        if (fail_count == 0) begin
            $display("TEST PASS");
        end else begin
            $display("TEST FAIL (%0d failures)", fail_count);
            $fatal(1);
        end

        $finish;
    end

endmodule

`default_nettype wire
