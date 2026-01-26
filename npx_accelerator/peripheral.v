`timescale 1ns/1ps

module peripheral (
    input wire clk,
    input wire reset,
    input wire [31:0] cpu_addr,
    input wire [31:0] cpu_wdata,
    input wire cpu_we,
    input wire cpu_en,
    output wire [31:0] sram_rdata
);

    // --- 1. Address Decoding Logic ---
    // Buffer A (Weights): Mapped to 0x4000_0000
    // Buffer B (Data):    Mapped to 0x4001_0000
    wire en_a = cpu_en && (cpu_addr[31:16] == 16'h4000);
    wire en_b = cpu_en && (cpu_addr[31:16] == 16'h4001);

    wire [31:0] rdata_a;
    wire [31:0] rdata_b;

    // --- 2. Instantiate SRAM Buffer A (Weight Memory) ---
    sram_256kb mem_a (
        .clk(clk),
        .reset(reset),
        .en(en_a),
        .we(en_a && cpu_we),
        .addr(cpu_addr[15:0]),
        .wdata(cpu_wdata),
        .rdata(rdata_a)
    );

    // --- 3. Instantiate SRAM Buffer B (Activation/Data Memory) ---
    sram_256kb mem_b (
        .clk(clk),
        .reset(reset),
        .en(en_b),
        .we(en_b && cpu_we),
        .addr(cpu_addr[15:0]),
        .wdata(cpu_wdata),
        .rdata(rdata_b)
    );

    // --- 4. Read Data Multiplexer ---
    // Directs the correct SRAM output back to the CPU based on the address
    assign sram_rdata = en_a ? rdata_a : 
                        en_b ? rdata_b : 32'h0;

endmodule
