`default_nettype none

module npu_if_bridge #(
    parameter [27:0] BASE_ADDR = 28'h1000_000
) (
    input  wire        clk,
    input  wire        rst_n,

    input  wire [27:0] mmio_addr,
    input  wire [31:0] mmio_wdata,
    input  wire [1:0]  mmio_write_n,
    input  wire [1:0]  mmio_read_n,
    output reg  [31:0] mmio_rdata,
    output wire        mmio_ready,

    output reg         start_pulse,
    output reg         abort_pulse,
    output reg         irq_en,
    output reg  [4:0]  opcode,
    output reg  [7:0]  qparam,
    output reg  [31:0] src_desc_ptr,
    output reg  [31:0] dst_desc_ptr,
    output reg  [31:0] control,
    output reg  [31:0] watchdog,

    input  wire        busy,
    input  wire        done,
    input  wire        error,
    input  wire        dma_busy,
    input  wire [63:0] perf_cnt,

    output wire        irq
);
    localparam [7:0] REG_CMD         = 8'h00;
    localparam [7:0] REG_STATUS      = 8'h04;
    localparam [7:0] REG_SRC_DESC    = 8'h08;
    localparam [7:0] REG_DST_DESC    = 8'h0C;
    localparam [7:0] REG_CONTROL     = 8'h10;
    localparam [7:0] REG_PERF_LO     = 8'h14;
    localparam [7:0] REG_PERF_HI     = 8'h18;
    localparam [7:0] REG_WATCHDOG    = 8'h1C;

    wire addr_hit = (mmio_addr[27:8] == BASE_ADDR[27:8]);
    wire [7:0] addr_off = mmio_addr[7:0] - BASE_ADDR[7:0];

    wire write_en = addr_hit && (mmio_write_n == 2'b10);
    wire read_en  = addr_hit && (mmio_read_n == 2'b10);

    reg done_latched;
    reg error_latched;

    assign mmio_ready = 1'b1;
    assign irq = done_latched && irq_en;

    always @(posedge clk) begin
        if (!rst_n) begin
            start_pulse <= 1'b0;
            abort_pulse <= 1'b0;
            irq_en <= 1'b0;
            opcode <= 5'b0;
            qparam <= 8'b0;
            src_desc_ptr <= 32'b0;
            dst_desc_ptr <= 32'b0;
            control <= 32'b0;
            watchdog <= 32'b0;
            done_latched <= 1'b0;
            error_latched <= 1'b0;
        end else begin
            start_pulse <= 1'b0;
            abort_pulse <= 1'b0;

            if (done) begin
                done_latched <= 1'b1;
            end
            if (error) begin
                error_latched <= 1'b1;
            end

            if (write_en) begin
                case (addr_off)
                    REG_CMD: begin
                        start_pulse <= mmio_wdata[0] && !busy;
                        abort_pulse <= mmio_wdata[1];
                        irq_en <= mmio_wdata[2];
                        opcode <= mmio_wdata[7:3];
                        qparam <= mmio_wdata[15:8];
                        if (mmio_wdata[0]) begin
                            done_latched <= 1'b0;
                            error_latched <= 1'b0;
                        end
                    end
                    REG_SRC_DESC: begin
                        if (!busy) src_desc_ptr <= mmio_wdata;
                    end
                    REG_DST_DESC: begin
                        if (!busy) dst_desc_ptr <= mmio_wdata;
                    end
                    REG_CONTROL: begin
                        if (!busy) control <= mmio_wdata;
                    end
                    REG_WATCHDOG: begin
                        if (!busy) watchdog <= mmio_wdata;
                    end
                    default: begin end
                endcase
            end
        end
    end

    always @(*) begin
        if (read_en) begin
            case (addr_off)
                REG_CMD: begin
                    mmio_rdata = {16'b0, qparam, opcode, irq_en, 2'b00};
                end
                REG_STATUS: begin
                    mmio_rdata = {28'b0, dma_busy, error_latched, done_latched, busy};
                end
                REG_SRC_DESC: begin
                    mmio_rdata = src_desc_ptr;
                end
                REG_DST_DESC: begin
                    mmio_rdata = dst_desc_ptr;
                end
                REG_CONTROL: begin
                    mmio_rdata = control;
                end
                REG_PERF_LO: begin
                    mmio_rdata = perf_cnt[31:0];
                end
                REG_PERF_HI: begin
                    mmio_rdata = perf_cnt[63:32];
                end
                REG_WATCHDOG: begin
                    mmio_rdata = watchdog;
                end
                default: begin
                    mmio_rdata = 32'b0;
                end
            endcase
        end else begin
            mmio_rdata = 32'b0;
        end
    end
endmodule

`default_nettype wire
