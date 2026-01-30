`timescale 1ns/1ps

`default_nettype none

module dma_unit_tb;
    localparam MEM_WORDS = 1024;
    localparam MEM_BYTES = MEM_WORDS * 4;
    localparam BUF_DEPTH = 128;
    localparam BUF_AW = 7;

    reg clk;
    reg rst_n;

    reg start_load;
    reg start_store;
    reg abort;
    reg [31:0] src_desc_ptr;
    reg [31:0] dst_desc_ptr;
    reg [31:0] control;

    wire mem_rd_req;
    wire [31:0] mem_rd_addr;
    reg mem_rd_ready;
    reg mem_rd_valid;
    reg [31:0] mem_rd_data;

    wire mem_wr_req;
    wire [31:0] mem_wr_addr;
    wire [31:0] mem_wr_data;
    reg mem_wr_ready;

    wire in_buf_wr_en;
    wire [BUF_AW-1:0] in_buf_wr_addr;
    wire [31:0] in_buf_wr_data;

    wire out_buf_rd_en;
    wire [BUF_AW-1:0] out_buf_rd_addr;
    wire out_buf_rd_valid;
    wire [31:0] out_buf_rd_data;

    wire load_busy;
    wire store_busy;
    wire dma_busy;
    wire load_done;
    wire store_done;
    wire error;

    // Memory model
    reg [31:0] mem [0:MEM_WORDS-1];
    reg rd_pending;
    reg [31:0] rd_addr_q;

    // Buffers
    sram_buffer #(.DEPTH(BUF_DEPTH), .ADDR_W(BUF_AW), .DATA_W(32)) in_buf (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(in_buf_wr_en),
        .wr_addr(in_buf_wr_addr),
        .wr_data(in_buf_wr_data),
        .rd_en(1'b0),
        .rd_addr({BUF_AW{1'b0}}),
        .rd_data(),
        .rd_valid()
    );

    sram_buffer #(.DEPTH(BUF_DEPTH), .ADDR_W(BUF_AW), .DATA_W(32)) out_buf (
        .clk(clk),
        .rst_n(rst_n),
        .wr_en(1'b0),
        .wr_addr({BUF_AW{1'b0}}),
        .wr_data(32'd0),
        .rd_en(out_buf_rd_en),
        .rd_addr(out_buf_rd_addr),
        .rd_data(out_buf_rd_data),
        .rd_valid(out_buf_rd_valid)
    );

    dual_dma #(
        .MEM_BASE(32'h0000_0000),
        .MEM_SIZE(MEM_BYTES),
        .MAX_LEN(MEM_BYTES),
        .BUF_AW(BUF_AW)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .start_load(start_load),
        .start_store(start_store),
        .abort(abort),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .control(control),
        .mem_rd_req(mem_rd_req),
        .mem_rd_addr(mem_rd_addr),
        .mem_rd_ready(mem_rd_ready),
        .mem_rd_valid(mem_rd_valid),
        .mem_rd_data(mem_rd_data),
        .mem_wr_req(mem_wr_req),
        .mem_wr_addr(mem_wr_addr),
        .mem_wr_data(mem_wr_data),
        .mem_wr_ready(mem_wr_ready),
        .in_buf_wr_en(in_buf_wr_en),
        .in_buf_wr_addr(in_buf_wr_addr),
        .in_buf_wr_data(in_buf_wr_data),
        .out_buf_rd_en(out_buf_rd_en),
        .out_buf_rd_addr(out_buf_rd_addr),
        .out_buf_rd_valid(out_buf_rd_valid),
        .out_buf_rd_data(out_buf_rd_data),
        .load_busy(load_busy),
        .store_busy(store_busy),
        .dma_busy(dma_busy),
        .load_done(load_done),
        .store_done(store_done),
        .error(error)
    );

    // Clock
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Memory read pipeline
    always @(posedge clk) begin
        if (!rst_n) begin
            rd_pending  <= 1'b0;
            mem_rd_valid <= 1'b0;
            mem_rd_data <= 32'd0;
            rd_addr_q   <= 32'd0;
        end else begin
            mem_rd_valid <= 1'b0;
            if (rd_pending) begin
                mem_rd_valid <= 1'b1;
                mem_rd_data  <= mem[rd_addr_q[31:2]];
                rd_pending   <= 1'b0;
            end

            if (mem_rd_req && mem_rd_ready) begin
                rd_addr_q  <= mem_rd_addr;
                rd_pending <= 1'b1;
            end

            if (mem_wr_req && mem_wr_ready) begin
                mem[mem_wr_addr[31:2]] <= mem_wr_data;
            end
        end
    end

    // Helper tasks
    task write_mem_word;
        input [31:0] addr;
        input [31:0] data;
        begin
            mem[addr[31:2]] = data;
        end
    endtask

    task setup_desc;
        input [31:0] desc_addr;
        input [31:0] buf_addr;
        input [31:0] len;
        input [15:0] stride;
        input [15:0] flags;
        begin
            write_mem_word(desc_addr + 32'd0, buf_addr);
            write_mem_word(desc_addr + 32'd4, len);
            write_mem_word(desc_addr + 32'd8, {flags, stride});
            write_mem_word(desc_addr + 32'd12, 32'd0);
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

    task pulse_start_load;
        begin
            start_load = 1;
            @(posedge clk);
            #1 start_load = 0;
        end
    endtask

    task pulse_start_store;
        begin
            start_store = 1;
            @(posedge clk);
            #1 start_store = 0;
        end
    endtask

    task pulse_abort;
        begin
            abort = 1;
            @(posedge clk);
            #1 abort = 0;
        end
    endtask

    integer fail_count;

    initial begin
        rst_n = 0;
        start_load = 0;
        start_store = 0;
        abort = 0;
        src_desc_ptr = 0;
        dst_desc_ptr = 0;
        control = 32'h0000_0101; // rows=1, burst=5
        mem_rd_ready = 1;
        mem_wr_ready = 1;
        fail_count = 0;

        wait_cycles(5);
        rst_n = 1;
        wait_cycles(2);

        // Test 1: Single descriptor load
        $display("Test1: Single descriptor load");
        setup_desc(32'h0000_0100, 32'h0000_0200, 32'd16, 16'd0, 16'h0001); // 4 words
        src_desc_ptr = 32'h0000_0100;

        // fill memory source
        write_mem_word(32'h0000_0200, 32'hA0);
        write_mem_word(32'h0000_0204, 32'hA1);
        write_mem_word(32'h0000_0208, 32'hA2);
        write_mem_word(32'h0000_020C, 32'hA3);

        pulse_start_load();
        wait_cycles(50);

        if (!load_done) begin
            $display("FAIL: load_done not asserted");
            fail_count = fail_count + 1;
        end
        if (in_buf.mem[0] != 32'hA0 || in_buf.mem[1] != 32'hA1 || in_buf.mem[2] != 32'hA2 || in_buf.mem[3] != 32'hA3) begin
            $display("FAIL: input buffer data mismatch");
            fail_count = fail_count + 1;
        end

        // Test 2: Multi-descriptor chain
        $display("Test2: Multi-descriptor chain");
        setup_desc(32'h0000_0120, 32'h0000_0300, 32'd8, 16'd0, 16'h0000);
        setup_desc(32'h0000_0130, 32'h0000_0310, 32'd8, 16'd0, 16'h0001);
        src_desc_ptr = 32'h0000_0120;
        write_mem_word(32'h0000_0300, 32'hB0);
        write_mem_word(32'h0000_0304, 32'hB1);
        write_mem_word(32'h0000_0310, 32'hB2);
        write_mem_word(32'h0000_0314, 32'hB3);

        pulse_start_load();
        wait_cycles(60);

        if (!load_done) begin
            $display("FAIL: chain load_done not asserted");
            fail_count = fail_count + 1;
        end
        if (in_buf.mem[0] != 32'hB0 || in_buf.mem[1] != 32'hB1 || in_buf.mem[2] != 32'hB2 || in_buf.mem[3] != 32'hB3) begin
            $display("FAIL: chain buffer mismatch");
            fail_count = fail_count + 1;
        end

        // Test 3: Abort mid-transfer
        $display("Test3: Abort mid-transfer");
        setup_desc(32'h0000_0140, 32'h0000_0400, 32'd64, 16'd0, 16'h0001);
        src_desc_ptr = 32'h0000_0140;
        pulse_start_load();
        wait_cycles(5);
        pulse_abort();
        wait_cycles(10);
        if (!error) begin
            $display("FAIL: abort did not set error");
            fail_count = fail_count + 1;
        end

        // Test 4: Backpressure during store
        $display("Test4: Backpressure store");
        // preload output buffer
        out_buf.mem[0] = 32'hC0;
        out_buf.mem[1] = 32'hC1;
        out_buf.mem[2] = 32'hC2;
        out_buf.mem[3] = 32'hC3;
        setup_desc(32'h0000_0200, 32'h0000_0500, 32'd16, 16'd0, 16'h0001);
        dst_desc_ptr = 32'h0000_0200;

        mem_wr_ready = 0;
        pulse_start_store();
        wait_cycles(5);
        mem_wr_ready = 1;
        wait_cycles(80);

        if (!store_done) begin
            $display("FAIL: store_done not asserted");
            fail_count = fail_count + 1;
        end
        if (mem[32'h0000_0500 >> 2] != 32'hC0 || mem[32'h0000_0504 >> 2] != 32'hC1) begin
            $display("FAIL: store data mismatch");
            fail_count = fail_count + 1;
        end

        // Test 5: Invalid descriptor detection (unaligned len)
        $display("Test5: Invalid descriptor");
        setup_desc(32'h0000_0300, 32'h0000_0600, 32'd6, 16'd0, 16'h0001);
        src_desc_ptr = 32'h0000_0300;
        pulse_start_load();
        wait_cycles(40);
        if (!error) begin
            $display("FAIL: invalid descriptor not flagged");
            fail_count = fail_count + 1;
        end

        if (fail_count == 0) begin
            $display("TEST PASS");
        end else begin
            $display("TEST FAIL (%0d failures)", fail_count);
        end

        $finish;
    end

endmodule

`default_nettype wire
