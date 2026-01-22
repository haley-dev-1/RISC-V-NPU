/*
 * systolic.v
 *
 * Minimal systolic array controller (MVP)
 *
 * Currently implements a single MAC operation.
 * Designed to scale later into a full systolic array.
 */

`default_nettype none

module systolic (
    input  wire        clk,
    input  wire        rst_n,

    input  wire        start,     // Start computation
    input  wire [31:0] a,         // Operand A
    input  wire [31:0] b,         // Operand B

    output wire [31:0] result,    // Computation result
    output reg         done       // Computation complete
);

    reg mac_valid;

    wire mac_done;
    wire [31:0] mac_result;

    // Single MAC instance
    mac u_mac (
        .clk(clk),
        .rst_n(rst_n),
        .valid(mac_valid),
        .a(a),
        .b(b),
        .acc(32'd0),
        .result(mac_result),
        .done(mac_done)
    );

    assign result = mac_result;

    always @(posedge clk) begin
        if (!rst_n) begin
            mac_valid <= 1'b0;
            done      <= 1'b0;
        end else begin
            done <= 1'b0;

            if (start) begin
                mac_valid <= 1'b1;
            end else begin
                mac_valid <= 1'b0;
            end

            if (mac_done) begin
                done <= 1'b1;
            end
        end
    end

endmodule
