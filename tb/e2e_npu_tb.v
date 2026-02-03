`timescale 1ns/1ps
`default_nettype none

module e2e_npu_tb;
    localparam integer MEM_WORDS = 2048;
    localparam integer MEM_BYTES = MEM_WORDS * 4;
    localparam integer BUF_DEPTH = 256;
    localparam [27:0] MMIO_BASE  = 28'h1000_000;

    reg clk = 1'b0;
    always #5 clk = ~clk;

    reg rst_n = 1'b0;

    // MMIO interface
    reg [27:0] data_addr;
    reg [31:0] data_out;
    reg [1:0]  data_write_n;
    reg [1:0]  data_read_n;
    wire [31:0] data_in;
    wire data_ready;
    wire irq;

    // DMA memory interfaces
    wire desc_src_req_valid;
    wire [31:0] desc_src_req_addr;
    wire desc_src_req_ready;
    wire desc_src_rsp_valid;
    wire [31:0] desc_src_rsp_data;

    wire desc_dst_req_valid;
    wire [31:0] desc_dst_req_addr;
    wire desc_dst_req_ready;
    wire desc_dst_rsp_valid;
    wire [31:0] desc_dst_rsp_data;

    wire src_req_valid;
    wire [31:0] src_req_addr;
    wire src_req_ready;
    wire src_rsp_valid;
    wire [31:0] src_rsp_data;

    wire dst_req_valid;
    wire [31:0] dst_req_addr;
    wire [31:0] dst_req_data;
    wire dst_req_ready;

    reg [31:0] mem [0:MEM_WORDS-1];

    integer i;

    tinyQV_top #(
        .BUF_DEPTH(BUF_DEPTH),
        .MMIO_BASE(MMIO_BASE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .data_addr(data_addr),
        .data_out(data_out),
        .data_write_n(data_write_n),
        .data_read_n(data_read_n),
        .data_in(data_in),
        .data_ready(data_ready),
        .irq(irq),
        .desc_src_req_valid(desc_src_req_valid),
        .desc_src_req_addr(desc_src_req_addr),
        .desc_src_req_ready(desc_src_req_ready),
        .desc_src_rsp_valid(desc_src_rsp_valid),
        .desc_src_rsp_data(desc_src_rsp_data),
        .desc_dst_req_valid(desc_dst_req_valid),
        .desc_dst_req_addr(desc_dst_req_addr),
        .desc_dst_req_ready(desc_dst_req_ready),
        .desc_dst_rsp_valid(desc_dst_rsp_valid),
        .desc_dst_rsp_data(desc_dst_rsp_data),
        .src_req_valid(src_req_valid),
        .src_req_addr(src_req_addr),
        .src_req_ready(src_req_ready),
        .src_rsp_valid(src_rsp_valid),
        .src_rsp_data(src_rsp_data),
        .dst_req_valid(dst_req_valid),
        .dst_req_addr(dst_req_addr),
        .dst_req_data(dst_req_data),
        .dst_req_ready(dst_req_ready)
    );

    // Memory model: always ready, zero-latency
    assign desc_src_req_ready = 1'b1;
    assign desc_src_rsp_valid = desc_src_req_valid;
    assign desc_src_rsp_data  = mem[desc_src_req_addr[31:2]];

    assign desc_dst_req_ready = 1'b1;
    assign desc_dst_rsp_valid = desc_dst_req_valid;
    assign desc_dst_rsp_data  = mem[desc_dst_req_addr[31:2]];

    assign src_req_ready = 1'b1;
    assign src_rsp_valid = src_req_valid;
    assign src_rsp_data  = mem[src_req_addr[31:2]];

    assign dst_req_ready = 1'b1;
    always @(posedge clk) begin
        if (dst_req_valid && dst_req_ready) begin
            mem[dst_req_addr[31:2]] <= dst_req_data;
        end
    end

    task mmio_write(input [7:0] off, input [31:0] val);
        begin
            @(posedge clk);
            data_addr = MMIO_BASE + off;
            data_out = val;
            data_write_n = 2'b10;
            data_read_n = 2'b11;
            @(posedge clk);
            data_write_n = 2'b11;
            data_out = 32'b0;
        end
    endtask

    task mmio_read(input [7:0] off, output [31:0] val);
        begin
            @(posedge clk);
            data_addr = MMIO_BASE + off;
            data_read_n = 2'b10;
            data_write_n = 2'b11;
            @(posedge clk);
            val = data_in;
            data_read_n = 2'b11;
        end
    endtask

    task write_desc(
        input [31:0] desc_addr,
        input [31:0] base,
        input [31:0] len,
        input [31:0] stride,
        input [31:0] rows,
        input [31:0] cfg,
        input [31:0] next
    );
        integer idx;
        begin
            idx = desc_addr[31:2];
            mem[idx+0] = base;
            mem[idx+1] = len;
            mem[idx+2] = stride;
            mem[idx+3] = rows;
            mem[idx+4] = cfg;
            mem[idx+5] = next;
        end
    endtask

    initial begin
        $dumpfile("trace.vcd");
        $dumpvars(0, e2e_npu_tb);

        data_addr = 0;
        data_out = 0;
        data_write_n = 2'b11;
        data_read_n = 2'b11;

        for (i = 0; i < MEM_WORDS; i = i + 1) begin
            mem[i] = 32'b0;
        end

        // Reset
        repeat (4) @(posedge clk);
        rst_n = 1'b1;

        // Matrix A (2x2) at 0x100
        mem[64] = 32'd1;
        mem[65] = 32'd2;
        mem[66] = 32'd3;
        mem[67] = 32'd4;

        // Matrix B (2x2) at 0x200
        mem[128] = 32'd5;
        mem[129] = 32'd6;
        mem[130] = 32'd7;
        mem[131] = 32'd8;

        // Descriptors
        write_desc(32'h0000_0400, 32'h0000_0100, 32'd8, 32'd8, 32'd2, 32'h0000_0020, 32'h0000_0420);
        write_desc(32'h0000_0420, 32'h0000_0200, 32'd8, 32'd8, 32'd2, 32'h0000_0021, 32'h0000_0000);
        write_desc(32'h0000_0440, 32'h0000_0300, 32'd8, 32'd8, 32'd2, 32'h0000_0022, 32'h0000_0000);

        // Program MMIO
        mmio_write(8'h08, 32'h0000_0400); // SRC_DESC_PTR
        mmio_write(8'h0C, 32'h0000_0440); // DST_DESC_PTR
        mmio_write(8'h1C, 32'd500);       // WATCHDOG

        // CMD: start + irq_en + qparam(size=2)
        mmio_write(8'h00, 32'h0000_0205);

        // Poll for done
        begin : wait_done
            integer cycles;
            reg [31:0] status;
            cycles = 0;
            status = 32'b0;
            while (status[1] == 1'b0) begin
                mmio_read(8'h04, status);
                cycles = cycles + 1;
                if (cycles > 2000) $fatal(1, "Timeout waiting for DONE");
            end
        end

        // Check output C matrix at 0x300
        if (mem[192] !== 32'd19 || mem[193] !== 32'd22 || mem[194] !== 32'd43 || mem[195] !== 32'd50) begin
            $fatal(1, "E2E mismatch: C matrix incorrect");
        end

        $display("PASS: E2E NPU test passed.");
        $finish;
    end
endmodule

`default_nettype wire
