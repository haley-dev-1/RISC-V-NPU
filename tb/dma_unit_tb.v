`timescale 1ns/1ps
`default_nettype none

module dma_unit_tb;
    localparam integer MEM_WORDS = 1024;
    localparam integer MEM_BYTES = MEM_WORDS * 4;
    localparam integer BUF_DEPTH = 256;
    localparam integer BUF_AW    = $clog2(BUF_DEPTH);

    reg clk = 1'b0;
    always #5 clk = ~clk;

    reg rst_n = 1'b0;

    reg start_src;
    reg start_dst;
    reg abort;
    reg [31:0] src_desc_ptr;
    reg [31:0] dst_desc_ptr;

    wire src_done;
    wire dst_done;
    wire src_error;
    wire dst_error;
    wire busy;

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
    reg src_req_ready;
    wire src_rsp_valid;
    wire [31:0] src_rsp_data;

    wire dst_req_valid;
    wire [31:0] dst_req_addr;
    wire [31:0] dst_req_data;
    reg dst_req_ready;

    wire src_buf_we;
    wire [1:0] src_buf_sel;
    wire [BUF_AW-1:0] src_buf_waddr;
    wire [31:0] src_buf_wdata;

    wire dst_buf_re;
    wire [1:0] dst_buf_sel;
    wire [BUF_AW-1:0] dst_buf_raddr;
    wire [31:0] dst_buf_rdata;

    reg [31:0] mem [0:MEM_WORDS-1];
    reg [31:0] bufA [0:BUF_DEPTH-1];
    reg [31:0] bufB [0:BUF_DEPTH-1];
    reg [31:0] bufC [0:BUF_DEPTH-1];

    integer i;

    dual_dma #(
        .MEM_SIZE_BYTES(MEM_BYTES),
        .BUF_DEPTH(BUF_DEPTH)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .start_src(start_src),
        .start_dst(start_dst),
        .abort(abort),
        .src_desc_ptr(src_desc_ptr),
        .dst_desc_ptr(dst_desc_ptr),
        .src_done(src_done),
        .dst_done(dst_done),
        .src_error(src_error),
        .dst_error(dst_error),
        .busy(busy),
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
        .dst_req_ready(dst_req_ready),
        .src_buf_we(src_buf_we),
        .src_buf_sel(src_buf_sel),
        .src_buf_waddr(src_buf_waddr),
        .src_buf_wdata(src_buf_wdata),
        .dst_buf_re(dst_buf_re),
        .dst_buf_sel(dst_buf_sel),
        .dst_buf_raddr(dst_buf_raddr),
        .dst_buf_rdata(dst_buf_rdata)
    );

    // Descriptor ports are always ready, zero-latency
    assign desc_src_req_ready = 1'b1;
    assign desc_src_rsp_valid = desc_src_req_valid;
    assign desc_src_rsp_data  = mem[desc_src_req_addr[31:2]];

    assign desc_dst_req_ready = 1'b1;
    assign desc_dst_rsp_valid = desc_dst_req_valid;
    assign desc_dst_rsp_data  = mem[desc_dst_req_addr[31:2]];

    // SRC data read port
    assign src_rsp_valid = src_req_valid && src_req_ready;
    assign src_rsp_data  = mem[src_req_addr[31:2]];

    // DST data write port
    always @(posedge clk) begin
        if (dst_req_valid && dst_req_ready) begin
            mem[dst_req_addr[31:2]] <= dst_req_data;
        end
    end

    // Buffer write port
    always @(posedge clk) begin
        if (src_buf_we) begin
            case (src_buf_sel)
                2'd0: bufA[src_buf_waddr] <= src_buf_wdata;
                2'd1: bufB[src_buf_waddr] <= src_buf_wdata;
                2'd2: bufC[src_buf_waddr] <= src_buf_wdata;
                default: begin end
            endcase
        end
    end

    // Buffer read port
    assign dst_buf_rdata = (dst_buf_sel == 2'd2) ? bufC[dst_buf_raddr] :
                           (dst_buf_sel == 2'd1) ? bufB[dst_buf_raddr] :
                           bufA[dst_buf_raddr];

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

    task wait_for_src_done;
        integer cycles;
        begin
            cycles = 0;
            while (!src_done && !src_error) begin
                @(posedge clk);
                cycles = cycles + 1;
                if (cycles > 2000) $fatal(1, "Timeout waiting for SRC done");
            end
        end
    endtask

    task wait_for_dst_done;
        integer cycles;
        begin
            cycles = 0;
            while (!dst_done && !dst_error) begin
                @(posedge clk);
                cycles = cycles + 1;
                if (cycles > 2000) $fatal(1, "Timeout waiting for DST done");
            end
        end
    endtask

    initial begin
        $dumpfile("trace.vcd");
        $dumpvars(0, dma_unit_tb);

        // Init
        start_src = 1'b0;
        start_dst = 1'b0;
        abort = 1'b0;
        src_desc_ptr = 32'b0;
        dst_desc_ptr = 32'b0;
        src_req_ready = 1'b1;
        dst_req_ready = 1'b1;

        for (i = 0; i < MEM_WORDS; i = i + 1) begin
            mem[i] = 32'b0;
        end
        for (i = 0; i < BUF_DEPTH; i = i + 1) begin
            bufA[i] = 32'b0;
            bufB[i] = 32'b0;
            bufC[i] = 32'b0;
        end

        // Reset
        repeat (4) @(posedge clk);
        rst_n = 1'b1;

        // Test 1: Single descriptor SRC copy into bufA
        mem[16] = 32'h1111_0001;
        mem[17] = 32'h2222_0002;
        mem[18] = 32'h3333_0003;
        mem[19] = 32'h4444_0004;

        write_desc(32'h0000_0100, 32'h0000_0040, 32'd16, 32'd16, 32'd1, 32'h0000_0010, 32'h0);
        src_desc_ptr = 32'h0000_0100;
        @(posedge clk);
        start_src = 1'b1;
        @(posedge clk);
        start_src = 1'b0;

        wait_for_src_done();
        if (src_error) $fatal(1, "SRC error during test 1");
        if (bufA[0] !== 32'h1111_0001 || bufA[1] !== 32'h2222_0002 || bufA[2] !== 32'h3333_0003 || bufA[3] !== 32'h4444_0004)
            $fatal(1, "Test 1 failed: bufA mismatch");

        // Test 2: Multi-descriptor chain into bufB
        mem[32] = 32'hAAAA_0001;
        mem[33] = 32'hBBBB_0002;
        mem[40] = 32'hCCCC_0003;
        mem[41] = 32'hDDDD_0004;

        write_desc(32'h0000_0140, 32'h0000_0080, 32'd8, 32'd8, 32'd1, 32'h0000_0011, 32'h0000_0160);
        write_desc(32'h0000_0160, 32'h0000_00A0, 32'd8, 32'd8, 32'd1, 32'h0000_0011, 32'h0);

        src_desc_ptr = 32'h0000_0140;
        @(posedge clk);
        start_src = 1'b1;
        @(posedge clk);
        start_src = 1'b0;

        wait_for_src_done();
        if (src_error) $fatal(1, "SRC error during test 2");
        if (bufB[0] !== 32'hAAAA_0001 || bufB[1] !== 32'hBBBB_0002 || bufB[2] !== 32'hCCCC_0003 || bufB[3] !== 32'hDDDD_0004)
            $fatal(1, "Test 2 failed: bufB chain mismatch");

        // Test 3: Abort mid-transfer
        mem[48] = 32'h1000_0001;
        mem[49] = 32'h1000_0002;
        mem[50] = 32'h1000_0003;
        mem[51] = 32'h1000_0004;
        mem[52] = 32'h1000_0005;
        mem[53] = 32'h1000_0006;
        mem[54] = 32'h1000_0007;
        mem[55] = 32'h1000_0008;

        write_desc(32'h0000_01A0, 32'h0000_00C0, 32'd32, 32'd32, 32'd1, 32'h0000_0010, 32'h0);
        src_desc_ptr = 32'h0000_01A0;
        @(posedge clk);
        start_src = 1'b1;
        @(posedge clk);
        start_src = 1'b0;

        repeat (3) @(posedge clk);
        abort = 1'b1;
        @(posedge clk);
        abort = 1'b0;

        wait_for_src_done();
        if (!src_error) $fatal(1, "Test 3 failed: abort did not set error");

        // Test 4: Backpressure on SRC
        src_req_ready = 1'b1;
        write_desc(32'h0000_01E0, 32'h0000_0100, 32'd32, 32'd32, 32'd1, 32'h0000_0010, 32'h0);
        src_desc_ptr = 32'h0000_01E0;
        @(posedge clk);
        start_src = 1'b1;
        @(posedge clk);
        start_src = 1'b0;

        repeat (2) @(posedge clk);
        src_req_ready = 1'b0;
        repeat (5) @(posedge clk);
        src_req_ready = 1'b1;

        wait_for_src_done();
        if (src_error) $fatal(1, "Test 4 failed: SRC error under backpressure");

        // Test 5: Invalid descriptor
        write_desc(32'h0000_0220, 32'h0000_2000, 32'd4, 32'd4, 32'd1, 32'h0000_0010, 32'h0);
        src_desc_ptr = 32'h0000_0220;
        @(posedge clk);
        start_src = 1'b1;
        @(posedge clk);
        start_src = 1'b0;

        wait_for_src_done();
        if (!src_error) $fatal(1, "Test 5 failed: invalid descriptor not flagged");

        // Test 6: Single descriptor DST copy from bufC
        bufC[0] = 32'hCAFE_0001;
        bufC[1] = 32'hCAFE_0002;
        bufC[2] = 32'hCAFE_0003;
        bufC[3] = 32'hCAFE_0004;

        write_desc(32'h0000_0260, 32'h0000_0200, 32'd16, 32'd16, 32'd1, 32'h0000_0022, 32'h0);
        dst_desc_ptr = 32'h0000_0260;
        @(posedge clk);
        start_dst = 1'b1;
        @(posedge clk);
        start_dst = 1'b0;

        wait_for_dst_done();
        if (dst_error) $fatal(1, "DST error during test 6");
        if (mem[128] !== 32'hCAFE_0001 || mem[129] !== 32'hCAFE_0002 || mem[130] !== 32'hCAFE_0003 || mem[131] !== 32'hCAFE_0004)
            $fatal(1, "Test 6 failed: DST memory mismatch");

        $display("PASS: DMA unit tests passed.");
        $finish;
    end
endmodule

`default_nettype wire
