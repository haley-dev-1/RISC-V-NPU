/*
 * npu_if_bridge.v
 *
 * LLM-generated MMIO bridge for tinyQV NPU integration.
 *
 * Implements register map, start/abort, watchdog, and IRQ.
 */

`default_nettype none

module npu_if_bridge #(
    parameter MEM_BASE = 32'h0000_0000,
    parameter MEM_SIZE = 32'h0001_0000
) (
    input  wire        clk,
    input  wire        rst_n,

    input  wire [5:0]  address,
    input  wire [31:0] data_in,
    input  wire [1:0]  data_write_n,
    input  wire [1:0]  data_read_n,
    output reg  [31:0] data_out,
    output wire        data_ready,
    output wire        user_interrupt,

    output reg         npu_start,
    output reg         npu_abort,
    output reg  [31:0] src_desc_ptr,
    output reg  [31:0] dst_desc_ptr,
    output reg  [31:0] control,
    output reg  [4:0]  opcode,
    output reg  [7:0]  qparam,

    input  wire        npu_busy,
    input  wire        npu_done,
    input  wire        npu_error,
    input  wire        dma_busy
);

    localparam ADDR_CMD          = 6'h00;
    localparam ADDR_STATUS       = 6'h04;
    localparam ADDR_SRC_DESC_PTR = 6'h08;
    localparam ADDR_DST_DESC_PTR = 6'h0C;
    localparam ADDR_CONTROL      = 6'h10;
    localparam ADDR_PERF_LO      = 6'h14;
    localparam ADDR_PERF_HI      = 6'h18;
    localparam ADDR_WATCHDOG     = 6'h1C;

    reg        irq_en;
    reg        done;
    reg        error;
    reg [31:0] watchdog;
    reg [31:0] wd_count;
    reg [63:0] perf_count;

    assign data_ready = 1'b1;

    function automatic desc_ptr_valid;
        input [31:0] ptr;
        begin
            desc_ptr_valid = (ptr >= MEM_BASE) && (ptr + 32'd16 <= MEM_BASE + MEM_SIZE) && (ptr[1:0] == 2'b00);
        end
    endfunction

    // Read mux
    always @(*) begin
        case (address)
            ADDR_CMD:          data_out = {16'd0, qparam, opcode, irq_en, 1'b0, 1'b0};
            ADDR_STATUS:       data_out = {28'd0, dma_busy, error, done, npu_busy};
            ADDR_SRC_DESC_PTR: data_out = src_desc_ptr;
            ADDR_DST_DESC_PTR: data_out = dst_desc_ptr;
            ADDR_CONTROL:      data_out = control;
            ADDR_PERF_LO:      data_out = perf_count[31:0];
            ADDR_PERF_HI:      data_out = perf_count[63:32];
            ADDR_WATCHDOG:     data_out = watchdog;
            default:           data_out = 32'd0;
        endcase
    end

    // Write/control
    always @(posedge clk) begin
        if (!rst_n) begin
            irq_en       <= 1'b0;
            opcode       <= 5'd0;
            qparam       <= 8'd0;
            src_desc_ptr <= 32'd0;
            dst_desc_ptr <= 32'd0;
            control      <= 32'd0;
            watchdog     <= 32'd0;
            wd_count     <= 32'd0;
            perf_count   <= 64'd0;
            done         <= 1'b0;
            error        <= 1'b0;
            npu_start    <= 1'b0;
            npu_abort    <= 1'b0;
        end else begin
            npu_start <= 1'b0;
            npu_abort <= 1'b0;

            // perf counter
            if (npu_busy) begin
                perf_count <= perf_count + 64'd1;
            end

            // watchdog
            if (!npu_busy) begin
                wd_count <= 32'd0;
            end else begin
                wd_count <= wd_count + 32'd1;
                if (watchdog != 32'd0 && wd_count >= watchdog) begin
                    error     <= 1'b1;
                    npu_abort <= 1'b1;
                end
            end

            // Latch done/error
            if (npu_done) begin
                done <= 1'b1;
            end
            if (npu_error) begin
                error <= 1'b1;
            end

            if (data_write_n != 2'b11) begin
                case (address)
                    ADDR_CMD: begin
                        irq_en <= data_in[2];
                        if (!npu_busy) begin
                            opcode <= data_in[7:3];
                            qparam <= data_in[15:8];
                        end

                        if (data_in[1]) begin
                            npu_abort <= 1'b1;
                            error     <= 1'b1;
                        end

                        if (data_in[0] && !npu_busy) begin
                            if (!desc_ptr_valid(src_desc_ptr) || !desc_ptr_valid(dst_desc_ptr)) begin
                                error <= 1'b1;
                            end else begin
                                npu_start  <= 1'b1;
                                done       <= 1'b0;
                                error      <= 1'b0;
                                wd_count   <= 32'd0;
                                perf_count <= 64'd0;
                            end
                        end
                    end
                    ADDR_SRC_DESC_PTR: begin
                        if (!npu_busy) src_desc_ptr <= data_in;
                    end
                    ADDR_DST_DESC_PTR: begin
                        if (!npu_busy) dst_desc_ptr <= data_in;
                    end
                    ADDR_CONTROL: begin
                        if (!npu_busy) control <= data_in;
                    end
                    ADDR_WATCHDOG: begin
                        if (!npu_busy) watchdog <= data_in;
                    end
                    ADDR_STATUS: begin
                        if (!npu_busy) begin
                            if (data_in[1]) done  <= 1'b0;
                            if (data_in[2]) error <= 1'b0;
                        end
                    end
                    default: begin
                    end
                endcase
            end
        end
    end

    assign user_interrupt = irq_en && (done || error);

    wire _unused = &{data_read_n, 1'b0};

endmodule

`default_nettype wire
