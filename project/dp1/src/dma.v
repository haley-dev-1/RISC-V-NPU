`timescale 1ns/1ps
`default_nettype none

module dma #(
    parameter integer SYS_MEM_WORDS = 256,
    parameter integer SPAD_WORDS    = 256
)(
    input  wire        clk,
    input  wire        rst_n,

    input  wire        start_a,
    input  wire        start_b,
    input  wire        start_out,

    input  wire [31:0] src_a_addr,
    input  wire [31:0] src_b_addr,
    input  wire [31:0] dst_c_addr,
    input  wire [31:0] len_bytes,

    input  wire [31:0] spad_a_base,
    input  wire [31:0] spad_b_base,
    input  wire [31:0] spad_c_base,

    output reg         inA_busy,
    output reg         inA_done,
    output reg         inA_error,
    output reg [31:0]  inA_sys_idx,
    output reg [31:0]  inA_spad_idx,
    output wire        inA_fire,

    output reg         inB_busy,
    output reg         inB_done,
    output reg         inB_error,
    output reg [31:0]  inB_sys_idx,
    output reg [31:0]  inB_spad_idx,
    output wire        inB_fire,

    output reg         out_busy,
    output reg         out_done,
    output reg         out_error,
    output reg [31:0]  out_sys_idx,
    output reg [31:0]  out_spad_idx,
    output wire        out_fire
);

    localparam int SYS_AW  = (SYS_MEM_WORDS <= 1) ? 1 : $clog2(SYS_MEM_WORDS);
    localparam int SPAD_AW = (SPAD_WORDS <= 1) ? 1 : $clog2(SPAD_WORDS);

    reg [31:0] inA_words_left;
    reg [31:0] inB_words_left;
    reg [31:0] out_words_left;

    function automatic bit dma_params_ok(
        input [31:0] sys_addr,
        input [31:0] spad_addr,
        input [31:0] len_b
    );
        int unsigned sys_idx;
        int unsigned spad_idx;
        int unsigned words;
        begin
            if (len_b == 32'd0) begin
                dma_params_ok = 1'b0;
            end else if (len_b[1:0] != 2'b00) begin
                dma_params_ok = 1'b0;
            end else if ((sys_addr[1:0] != 2'b00) || (spad_addr[1:0] != 2'b00)) begin
                dma_params_ok = 1'b0;
            end else if ((sys_addr[31:SYS_AW+2] != 0) || (spad_addr[31:SPAD_AW+2] != 0)) begin
                dma_params_ok = 1'b0;
            end else begin
                sys_idx  = sys_addr  >> 2;
                spad_idx = spad_addr >> 2;
                words    = len_b >> 2;
                if ((sys_idx + words) > SYS_MEM_WORDS) begin
                    dma_params_ok = 1'b0;
                end else if ((spad_idx + words) > SPAD_WORDS) begin
                    dma_params_ok = 1'b0;
                end else begin
                    dma_params_ok = 1'b1;
                end
            end
        end
    endfunction

    assign inA_fire = inA_busy;
    assign inB_fire = inB_busy;
    assign out_fire = out_busy;

    always @(posedge clk) begin
        if (!rst_n) begin
            inA_busy       <= 1'b0;
            inA_done       <= 1'b0;
            inA_error      <= 1'b0;
            inA_sys_idx    <= 32'd0;
            inA_spad_idx   <= 32'd0;
            inA_words_left <= 32'd0;
            inB_busy       <= 1'b0;
            inB_done       <= 1'b0;
            inB_error      <= 1'b0;
            inB_sys_idx    <= 32'd0;
            inB_spad_idx   <= 32'd0;
            inB_words_left <= 32'd0;
            out_busy       <= 1'b0;
            out_done       <= 1'b0;
            out_error      <= 1'b0;
            out_sys_idx    <= 32'd0;
            out_spad_idx   <= 32'd0;
            out_words_left <= 32'd0;
            // no reg fire signals; fire is combinational from busy
        end else begin
            if (start_a) begin
                inA_done  <= 1'b0;
                inA_error <= 1'b0;
                if (!dma_params_ok(src_a_addr, spad_a_base, len_bytes)) begin
                    inA_error <= 1'b1;
                    inA_busy  <= 1'b0;
                end else begin
                    inA_busy       <= 1'b1;
                    inA_sys_idx    <= src_a_addr  >> 2;
                    inA_spad_idx   <= spad_a_base >> 2;
                    inA_words_left <= len_bytes   >> 2;
                end
            end else if (inA_busy) begin
                inA_sys_idx    <= inA_sys_idx + 1;
                inA_spad_idx   <= inA_spad_idx + 1;
                inA_words_left <= inA_words_left - 1;
                if (inA_words_left == 32'd1) begin
                    inA_busy <= 1'b0;
                    inA_done <= 1'b1;
                end
            end

            if (start_b) begin
                inB_done  <= 1'b0;
                inB_error <= 1'b0;
                if (!dma_params_ok(src_b_addr, spad_b_base, len_bytes)) begin
                    inB_error <= 1'b1;
                    inB_busy  <= 1'b0;
                end else begin
                    inB_busy       <= 1'b1;
                    inB_sys_idx    <= src_b_addr  >> 2;
                    inB_spad_idx   <= spad_b_base >> 2;
                    inB_words_left <= len_bytes   >> 2;
                end
            end else if (inB_busy) begin
                inB_sys_idx    <= inB_sys_idx + 1;
                inB_spad_idx   <= inB_spad_idx + 1;
                inB_words_left <= inB_words_left - 1;
                if (inB_words_left == 32'd1) begin
                    inB_busy <= 1'b0;
                    inB_done <= 1'b1;
                end
            end

            if (start_out) begin
                out_done  <= 1'b0;
                out_error <= 1'b0;
                if (!dma_params_ok(dst_c_addr, spad_c_base, len_bytes)) begin
                    out_error <= 1'b1;
                    out_busy  <= 1'b0;
                end else begin
                    out_busy       <= 1'b1;
                    out_sys_idx    <= dst_c_addr  >> 2;
                    out_spad_idx   <= spad_c_base >> 2;
                    out_words_left <= len_bytes   >> 2;
                end
            end else if (out_busy) begin
                out_sys_idx    <= out_sys_idx + 1;
                out_spad_idx   <= out_spad_idx + 1;
                out_words_left <= out_words_left - 1;
                if (out_words_left == 32'd1) begin
                    out_busy <= 1'b0;
                    out_done <= 1'b1;
                end
            end
        end
    end

endmodule

`default_nettype wire
