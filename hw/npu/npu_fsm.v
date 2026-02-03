`default_nettype none

module npu_fsm (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        start,
    input  wire        abort,
    input  wire [7:0]  qparam,
    input  wire [31:0] control,
    input  wire [31:0] watchdog_cfg,

    output reg         dma_start_src,
    output reg         dma_start_dst,
    input  wire        dma_src_done,
    input  wire        dma_dst_done,
    input  wire        dma_src_error,
    input  wire        dma_dst_error,

    output reg         compute_start,
    input  wire        compute_done,

    output reg         busy,
    output reg         done,
    output reg         error,
    output reg [63:0]  perf_cnt,
    output reg [31:0]  watchdog_cnt
);
    localparam [2:0] ST_IDLE    = 3'd0;
    localparam [2:0] ST_LOAD    = 3'd1;
    localparam [2:0] ST_COMPUTE = 3'd2;
    localparam [2:0] ST_STORE   = 3'd3;
    localparam [2:0] ST_DONE    = 3'd4;
    localparam [2:0] ST_ERROR   = 3'd5;

    reg [2:0] state;
    wire watchdog_en = (watchdog_cfg != 0);

    always @(posedge clk) begin
        if (!rst_n) begin
            state <= ST_IDLE;
            busy <= 1'b0;
            done <= 1'b0;
            error <= 1'b0;
            dma_start_src <= 1'b0;
            dma_start_dst <= 1'b0;
            compute_start <= 1'b0;
            perf_cnt <= 64'b0;
            watchdog_cnt <= 32'b0;
        end else begin
            dma_start_src <= 1'b0;
            dma_start_dst <= 1'b0;
            compute_start <= 1'b0;
            done <= 1'b0;

            if (busy) begin
                perf_cnt <= perf_cnt + 1'b1;
            end

            if (busy && watchdog_en && watchdog_cnt != 0) begin
                watchdog_cnt <= watchdog_cnt - 1'b1;
            end

            if (abort) begin
                error <= 1'b1;
                busy <= 1'b0;
                state <= ST_ERROR;
            end else if ((busy && watchdog_en && watchdog_cnt == 1) || dma_src_error || dma_dst_error) begin
                error <= 1'b1;
                busy <= 1'b0;
                state <= ST_ERROR;
            end else begin
                case (state)
                    ST_IDLE: begin
                        busy <= 1'b0;
                        if (start) begin
                            perf_cnt <= 64'b0;
                            watchdog_cnt <= watchdog_cfg;
                            error <= 1'b0;
                            dma_start_src <= 1'b1;
                            busy <= 1'b1;
                            state <= ST_LOAD;
                        end
                    end

                    ST_LOAD: begin
                        if (dma_src_done) begin
                            compute_start <= 1'b1;
                            state <= ST_COMPUTE;
                        end
                    end

                    ST_COMPUTE: begin
                        if (compute_done) begin
                            dma_start_dst <= 1'b1;
                            state <= ST_STORE;
                        end
                    end

                    ST_STORE: begin
                        if (dma_dst_done) begin
                            state <= ST_DONE;
                            busy <= 1'b0;
                        end
                    end

                    ST_DONE: begin
                        done <= 1'b1;
                        if (start) begin
                            perf_cnt <= 64'b0;
                            watchdog_cnt <= watchdog_cfg;
                            error <= 1'b0;
                            dma_start_src <= 1'b1;
                            busy <= 1'b1;
                            state <= ST_LOAD;
                        end else begin
                            state <= ST_IDLE;
                        end
                    end

                    ST_ERROR: begin
                        if (start) begin
                            perf_cnt <= 64'b0;
                            watchdog_cnt <= watchdog_cfg;
                            error <= 1'b0;
                            dma_start_src <= 1'b1;
                            busy <= 1'b1;
                            state <= ST_LOAD;
                        end
                    end

                    default: state <= ST_IDLE;
                endcase
            end
        end
    end
endmodule

`default_nettype wire
