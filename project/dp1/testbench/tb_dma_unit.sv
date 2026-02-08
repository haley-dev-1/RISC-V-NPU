`timescale 1ns/1ps
`default_nettype none

module tb_dma_unit;

  localparam int SYS_MEM_WORDS = 64;
  localparam int SPAD_WORDS    = 64;

  logic clk = 1'b0;
  logic rst_n = 1'b0;

  // DMA control
  logic start_a, start_b, start_out;
  logic [31:0] src_a_addr, src_b_addr, dst_c_addr;
  logic [31:0] len_bytes;
  logic [31:0] spad_a_base, spad_b_base, spad_c_base;

  // DMA status/indices
  wire        inA_busy, inA_done, inA_error, inA_fire;
  wire [31:0] inA_sys_idx, inA_spad_idx;
  wire        inB_busy, inB_done, inB_error, inB_fire;
  wire [31:0] inB_sys_idx, inB_spad_idx;
  wire        out_busy, out_done, out_error, out_fire;
  wire [31:0] out_sys_idx, out_spad_idx;

  // Simple memories for the DMA to move data between
  logic [31:0] sys_mem [0:SYS_MEM_WORDS-1];
  logic [31:0] spad_a  [0:SPAD_WORDS-1];
  logic [31:0] spad_b  [0:SPAD_WORDS-1];
  logic [31:0] spad_c  [0:SPAD_WORDS-1];

  integer i;
  integer pass_count;
  integer test_count;

  always #5 clk = ~clk;

  dma #(
    .SYS_MEM_WORDS(SYS_MEM_WORDS),
    .SPAD_WORDS(SPAD_WORDS)
  ) dut (
    .clk(clk),
    .rst_n(rst_n),
    .start_a(start_a),
    .start_b(start_b),
    .start_out(start_out),
    .src_a_addr(src_a_addr),
    .src_b_addr(src_b_addr),
    .dst_c_addr(dst_c_addr),
    .len_bytes(len_bytes),
    .spad_a_base(spad_a_base),
    .spad_b_base(spad_b_base),
    .spad_c_base(spad_c_base),
    .inA_busy(inA_busy),
    .inA_done(inA_done),
    .inA_error(inA_error),
    .inA_sys_idx(inA_sys_idx),
    .inA_spad_idx(inA_spad_idx),
    .inA_fire(inA_fire),
    .inB_busy(inB_busy),
    .inB_done(inB_done),
    .inB_error(inB_error),
    .inB_sys_idx(inB_sys_idx),
    .inB_spad_idx(inB_spad_idx),
    .inB_fire(inB_fire),
    .out_busy(out_busy),
    .out_done(out_done),
    .out_error(out_error),
    .out_sys_idx(out_sys_idx),
    .out_spad_idx(out_spad_idx),
    .out_fire(out_fire)
  );

  // Memory moves based on DMA indices
  always @(posedge clk) begin
    if (inA_fire) begin
      spad_a[inA_spad_idx] <= sys_mem[inA_sys_idx];
    end
    if (inB_fire) begin
      spad_b[inB_spad_idx] <= sys_mem[inB_sys_idx];
    end
    if (out_fire) begin
      sys_mem[out_sys_idx] <= spad_c[out_spad_idx];
    end
  end

  task automatic reset_mem;
    begin
      for (i = 0; i < SYS_MEM_WORDS; i = i + 1) begin
        sys_mem[i] = 32'd0;
      end
      for (i = 0; i < SPAD_WORDS; i = i + 1) begin
        spad_a[i] = 32'd0;
        spad_b[i] = 32'd0;
        spad_c[i] = 32'd0;
      end
    end
  endtask

  task automatic expect_eq(
    input [31:0] exp,
    input [31:0] got,
    input [255:0] tag
  );
    begin
      if (exp !== got) begin
        $display("[FAIL] %s exp=%h got=%h", tag, exp, got);
      end
    end
  endtask

  task automatic run_test(
    input [255:0] name,
    input bit     pass
  );
    begin
      test_count = test_count + 1;
      if (pass) pass_count = pass_count + 1;
      $display("[%s] %s", pass ? "PASS" : "FAIL", name);
    end
  endtask

  initial begin
    pass_count = 0;
    test_count = 0;

    start_a   = 1'b0;
    start_b   = 1'b0;
    start_out = 1'b0;
    src_a_addr = 32'd0;
    src_b_addr = 32'd0;
    dst_c_addr = 32'd0;
    len_bytes  = 32'd0;
    spad_a_base = 32'd0;
    spad_b_base = 32'd0;
    spad_c_base = 32'd0;

    reset_mem();

    repeat (2) @(posedge clk);
    rst_n = 1'b0;
    repeat (4) @(posedge clk);
    rst_n = 1'b1;

    // Test 1: A channel copy
    $display("[RUN] dma_a_copy");
    sys_mem[0] = 32'h1111_1111;
    sys_mem[1] = 32'h2222_2222;
    sys_mem[2] = 32'h3333_3333;
    sys_mem[3] = 32'h4444_4444;

    src_a_addr  = 32'h0000_0000;
    spad_a_base = 32'h0000_0000;
    len_bytes   = 32'd16;
    start_a     = 1'b1;
    @(posedge clk);
    start_a     = 1'b0;

    while (!inA_done && !inA_error) @(posedge clk);
    @(posedge clk);

    run_test("dma_a_copy", (inA_done && !inA_error &&
                            spad_a[0] == 32'h1111_1111 &&
                            spad_a[1] == 32'h2222_2222 &&
                            spad_a[2] == 32'h3333_3333 &&
                            spad_a[3] == 32'h4444_4444));

    // Test 2: B channel copy with offset
    $display("[RUN] dma_b_copy");
    sys_mem[8] = 32'hAAAA_AAAA;
    sys_mem[9] = 32'hBBBB_BBBB;
    src_b_addr  = 32'h0000_0020; // word index 8
    spad_b_base = 32'h0000_0010; // word index 4
    len_bytes   = 32'd8;
    start_b     = 1'b1;
    @(posedge clk);
    start_b     = 1'b0;

    while (!inB_done && !inB_error) @(posedge clk);
    @(posedge clk);

    run_test("dma_b_copy", (inB_done && !inB_error &&
                            spad_b[4] == 32'hAAAA_AAAA &&
                            spad_b[5] == 32'hBBBB_BBBB));

    // Test 3: OUT channel copy
    $display("[RUN] dma_out_copy");
    spad_c[2]  = 32'hCAFE_0001;
    spad_c[3]  = 32'hCAFE_0002;
    dst_c_addr = 32'h0000_0030; // word index 12
    spad_c_base= 32'h0000_0008; // word index 2
    len_bytes  = 32'd8;
    start_out  = 1'b1;
    @(posedge clk);
    start_out  = 1'b0;

    while (!out_done && !out_error) @(posedge clk);
    @(posedge clk);

    run_test("dma_out_copy", (out_done && !out_error &&
                              sys_mem[12] == 32'hCAFE_0001 &&
                              sys_mem[13] == 32'hCAFE_0002));

    // Test 4: invalid length (unaligned)
    $display("[RUN] dma_invalid_len");
    len_bytes  = 32'd6;
    src_a_addr = 32'h0000_0000;
    spad_a_base= 32'h0000_0000;
    start_a    = 1'b1;
    @(posedge clk);
    start_a    = 1'b0;
    @(posedge clk);

    run_test("dma_invalid_len", (inA_error && !inA_busy));

    $display("[SUMMARY] %0d OF %0d TESTS PASSED", pass_count, test_count);
    if (pass_count != test_count) $fatal(1, "DMA unit tests failed.");
    $finish;
  end

endmodule

`default_nettype wire
