Iteration 1 - 2026-02-03 22:10 UTC

Goal:
Bring up TinyQV MMIO integration, dual-channel DMA, and end-to-end testbenches while preserving existing passing testbenches.

Context:
Repo contains DP1 peripheral tests under `dp1/testbench/`. Required DP1 artifacts and directory layout were missing. TinyQV sources were available under `dp1/` and must be treated as frozen IP.

Prompt Sent:
"please get the DMA and integration for the whole thing working. ensure all tests pass."

LLM Output:
- Created required directory structure: `hw/npu/`, `hw/tinyQV/`, `tb/`, `docs/`, `scripts/`, `agents/DP1/`.
- Imported TinyQV IP into `hw/tinyQV/` from `dp1/` without modifications (read-only).
- Implemented NPU RTL: `mac32`, `systolic_array`, `sram_buffer`, `dual_dma`, `npu_fsm`, `npu_if_bridge`, `tinyQV_top`.
- Added DMA unit testbench and end-to-end NPU testbench.
- Added `scripts/run_sim.sh` to run all existing passing DP1 benches plus new tests.
- Documented MMIO map, DMA descriptor format, and integration notes.

Tests Run:
- `scripts/run_sim.sh`
  - DP1: tb_mac, tb_systolic, tb_fsm (iverilog)
  - DP1: tb_peripheral, tb_dma (verilator)
  - New: dma_unit_tb, e2e_npu_tb (iverilog)

Results:
All tests passed. `sim.log` and `trace.vcd` generated.

Assumptions:
- Array size set to 4x4 to balance area vs. verification complexity.
- MMIO base defaulted to `0x0100_0000` (28-bit address space).
- Descriptor format uses 6 words with CFG[1:0] = buffer select and CFG[7:4] = burst length.

Tradeoffs:
- Systolic array is time-multiplexed with local B-weight storage rather than a fully pipelined wavefront to keep RTL small and deterministic for DP1 testing.
- DMA uses simple ready/valid, one-word-per-cycle semantics with burst gap insertion to keep verification straightforward.

Next Steps:
- If needed, expand systolic array to a fully pipelined wavefront implementation.
- Add bus-level integration to a TinyQV CPU wrapper if full SoC simulation is required.

TinyQV files treated as read-only:
- `hw/tinyQV/alu.v`
- `hw/tinyQV/core.v`
- `hw/tinyQV/counter.v`
- `hw/tinyQV/cpu.v`
- `hw/tinyQV/decode.v`
- `hw/tinyQV/latch_reg.v`
- `hw/tinyQV/mem_ctrl.v`
- `hw/tinyQV/register.v`
- `hw/tinyQV/time.v`
- `hw/tinyQV/qspi_ctrl.v`
- `hw/tinyQV/qspi_flash.v`
- `hw/tinyQV/tinyqv.v`

Existing testbenches preserved unchanged:
- `dp1/testbench/tb_mac.sv`
- `dp1/testbench/tb_systolic.sv`
- `dp1/testbench/tb_fsm.sv`
- `dp1/testbench/tb_peripheral.sv`
- `dp1/testbench/tb_dma.sv`
- `dp1/tb_*.v` (cocotb harnesses)

Iteration 2 - 2026-02-03 22:20 UTC

Goal:
Optimize DMA/integration RTL for performance and area without changing features or testbench behavior.

Context:
Existing RTL passed all tests. Focused on removing redundant arithmetic and reusing signals while keeping MMIO/DMA behavior intact.

Prompt Sent:
"maximum performance and minimum area, I want testbenches to work the same, keep the same features."

LLM Output:
- Refactored `dual_dma.v` to remove per-cycle multiply-based address/index generation.
- Implemented streaming row address counters and per-buffer linear offsets.
- Kept descriptor chaining, stride, burst, abort, and bounds checks unchanged.
- Gated FSM updates on abort to prevent override.

Tests Run:
- `scripts/run_sim.sh`

Results:
All tests passed.

Assumptions:
- Removing per-cycle multipliers improves timing/area despite a few extra counters.

Tradeoffs:
- Added small counter registers (row_base/row_rem/rows_rem) to eliminate large combinational multipliers.

Next Steps:
- If needed, apply similar counter-based indexing inside systolic array for further timing margin.

TinyQV files treated as read-only:
- `hw/tinyQV/alu.v`
- `hw/tinyQV/core.v`
- `hw/tinyQV/counter.v`
- `hw/tinyQV/cpu.v`
- `hw/tinyQV/decode.v`
- `hw/tinyQV/latch_reg.v`
- `hw/tinyQV/mem_ctrl.v`
- `hw/tinyQV/register.v`
- `hw/tinyQV/time.v`
- `hw/tinyQV/qspi_ctrl.v`
- `hw/tinyQV/qspi_flash.v`
- `hw/tinyQV/tinyqv.v`

Existing testbenches preserved unchanged:
- `dp1/testbench/tb_mac.sv`
- `dp1/testbench/tb_systolic.sv`
- `dp1/testbench/tb_fsm.sv`
- `dp1/testbench/tb_peripheral.sv`
- `dp1/testbench/tb_dma.sv`
- `dp1/tb_*.v` (cocotb harnesses)
- `tb/dma_unit_tb.v`
- `tb/e2e_npu_tb.v`

Iteration 3 - 2026-02-03 22:23 UTC

Goal:
Further reduce area and improve timing/throughput by removing multipliers and redundant arithmetic in the systolic array.

Context:
DMA path optimized previously. Remaining hot path was systolic array address generation (row/col multipliers).

Prompt Sent:
"yeah keep going, do as much as possible to get this to the smallest area with the maximum throughput possible."

LLM Output:
- Rewrote `systolic_array` address generation to use incremental row bases and counters.
- Removed per-cycle multipliers for A/B/C indexing.
- Replaced `size_eff*size_eff` and `+1>=size` comparators with size-1 comparisons.

Tests Run:
- `scripts/run_sim.sh`

Results:
All tests passed.

Assumptions:
- Small array sizes (4x4 default) benefit more from removing multipliers than from extra small counters.

Tradeoffs:
- Added a few small counters (row bases, size-1) to eliminate multiplier logic in the compute loop.

Next Steps:
- If more area reduction is needed, consider narrowing internal DMA counters and offsets based on MAX_LEN_BYTES and BUF_DEPTH.

TinyQV files treated as read-only:
- `hw/tinyQV/alu.v`
- `hw/tinyQV/core.v`
- `hw/tinyQV/counter.v`
- `hw/tinyQV/cpu.v`
- `hw/tinyQV/decode.v`
- `hw/tinyQV/latch_reg.v`
- `hw/tinyQV/mem_ctrl.v`
- `hw/tinyQV/register.v`
- `hw/tinyQV/time.v`
- `hw/tinyQV/qspi_ctrl.v`
- `hw/tinyQV/qspi_flash.v`
- `hw/tinyQV/tinyqv.v`

Existing testbenches preserved unchanged:
- `dp1/testbench/tb_mac.sv`
- `dp1/testbench/tb_systolic.sv`
- `dp1/testbench/tb_fsm.sv`
- `dp1/testbench/tb_peripheral.sv`
- `dp1/testbench/tb_dma.sv`
- `dp1/tb_*.v` (cocotb harnesses)
- `tb/dma_unit_tb.v`
- `tb/e2e_npu_tb.v`

Iteration 4 - 2026-02-03 22:29 UTC

Goal:
Reduce DMA area further by narrowing internal counters/offsets and trimming address widths while preserving behavior.

Context:
DMA previously optimized for multiplier removal. Remaining area was in wide 32-bit counters and offsets.

Prompt Sent:
"keep going! you're doing great!"

LLM Output:
- Narrowed DMA row/row-rem/rows-rem counters based on MAX_LEN_BYTES and BUF_DEPTH.
- Reduced buffer offsets to BUF_DEPTH-derived widths.
- Used MEM_SIZE_BYTES-derived address widths for internal DMA address counters.
- Added explicit rows_hi checks to preserve bounds behavior with narrowed counters.

Tests Run:
- `scripts/run_sim.sh`

Results:
All tests passed.

Assumptions:
- MEM_SIZE_BYTES and MAX_LEN_BYTES define safe internal width reductions.

Tradeoffs:
- Adds small width/casting logic, but removes large 32-bit counter logic from hot path.

Next Steps:
- If allowed, consider reducing width of descriptor registers by validating upper bits during descriptor load.

TinyQV files treated as read-only:
- `hw/tinyQV/alu.v`
- `hw/tinyQV/core.v`
- `hw/tinyQV/counter.v`
- `hw/tinyQV/cpu.v`
- `hw/tinyQV/decode.v`
- `hw/tinyQV/latch_reg.v`
- `hw/tinyQV/mem_ctrl.v`
- `hw/tinyQV/register.v`
- `hw/tinyQV/time.v`
- `hw/tinyQV/qspi_ctrl.v`
- `hw/tinyQV/qspi_flash.v`
- `hw/tinyQV/tinyqv.v`

Existing testbenches preserved unchanged:
- `dp1/testbench/tb_mac.sv`
- `dp1/testbench/tb_systolic.sv`
- `dp1/testbench/tb_fsm.sv`
- `dp1/testbench/tb_peripheral.sv`
- `dp1/testbench/tb_dma.sv`
- `dp1/tb_*.v` (cocotb harnesses)
- `tb/dma_unit_tb.v`
- `tb/e2e_npu_tb.v`
