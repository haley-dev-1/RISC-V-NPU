/*
 * npu_fsm.v
 *
 * LLM-generated FSM orchestrating DMA load, compute, and store.
 */

`default_nettype none

module npu_fsm (
    input  wire clk,
    input  wire rst_n,

    input  wire start,
    input  wire abort,

    input  wire dma_load_done,
    input  wire dma_store_done,
    input  wire dma_error,

    input  wire core_done,
    input  wire core_error,

    output reg  dma_start_load,
    output reg  dma_start_store,
    output reg  dma_abort,
    output reg  core_start,
    output reg  core_abort,

    output reg  busy,
    output reg  done,
    output reg  error
);

    localparam S_IDLE    = 3'd0;
    localparam S_LOAD    = 3'd1;
    localparam S_COMPUTE = 3'd2;
    localparam S_STORE   = 3'd3;
    localparam S_DONE    = 3'd4;
    localparam S_ERROR   = 3'd5;

    reg [2:0] state;
    reg dma_load_done_d;
    reg dma_store_done_d;
    reg core_done_d;

    wire dma_load_done_rise = dma_load_done && !dma_load_done_d;
    wire dma_store_done_rise = dma_store_done && !dma_store_done_d;
    wire core_done_rise = core_done && !core_done_d;

    always @(posedge clk) begin
        if (!rst_n) begin
            state          <= S_IDLE;
            dma_start_load <= 1'b0;
            dma_start_store<= 1'b0;
            dma_abort      <= 1'b0;
            core_start     <= 1'b0;
            core_abort     <= 1'b0;
            busy           <= 1'b0;
            done           <= 1'b0;
            error          <= 1'b0;
            dma_load_done_d <= 1'b0;
            dma_store_done_d <= 1'b0;
            core_done_d <= 1'b0;
        end else begin
            dma_start_load  <= 1'b0;
            dma_start_store <= 1'b0;
            dma_abort       <= 1'b0;
            core_start      <= 1'b0;
            core_abort      <= 1'b0;

            dma_load_done_d <= dma_load_done;
            dma_store_done_d <= dma_store_done;
            core_done_d <= core_done;

            case (state)
                S_IDLE: begin
                    busy <= 1'b0;
                    done <= 1'b0;
                    error<= 1'b0;
                    if (start) begin
                        dma_start_load <= 1'b1;
                        busy <= 1'b1;
                        state <= S_LOAD;
                    end
                end
                S_LOAD: begin
                    busy <= 1'b1;
                    if (abort || dma_error) begin
                        dma_abort  <= 1'b1;
                        core_abort <= 1'b1;
                        error <= 1'b1;
                        busy  <= 1'b0;
                        state <= S_ERROR;
                    end else if (dma_load_done_rise) begin
                        core_start <= 1'b1;
                        state <= S_COMPUTE;
                    end
                end
                S_COMPUTE: begin
                    busy <= 1'b1;
                    if (abort || core_error) begin
                        dma_abort  <= 1'b1;
                        core_abort <= 1'b1;
                        error <= 1'b1;
                        busy  <= 1'b0;
                        state <= S_ERROR;
                    end else if (core_done_rise) begin
                        dma_start_store <= 1'b1;
                        state <= S_STORE;
                    end
                end
                S_STORE: begin
                    busy <= 1'b1;
                    if (abort || dma_error) begin
                        dma_abort  <= 1'b1;
                        core_abort <= 1'b1;
                        error <= 1'b1;
                        busy  <= 1'b0;
                        state <= S_ERROR;
                    end else if (dma_store_done_rise) begin
                        done <= 1'b1;
                        busy <= 1'b0;
                        state <= S_DONE;
                    end
                end
                S_DONE: begin
                    if (!start) begin
                        state <= S_IDLE;
                    end
                end
                S_ERROR: begin
                    if (!start) begin
                        state <= S_IDLE;
                    end
                end
                default: state <= S_IDLE;
            endcase
        end
    end

endmodule

`default_nettype wire
