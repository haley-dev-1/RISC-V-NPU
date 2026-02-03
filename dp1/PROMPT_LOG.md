# Prompt Log - DP1

- 2026-02-03: Received task to get DMA working, keep existing testbenches unchanged, run all tests, and improve security/efficiency. Confirmed plan to add MMIO-controlled dual-channel DMA, internal sysmem/spads, and new end-to-end DMA testbench.
- 2026-02-03: Implemented dual-channel DMA controller + sysmem/spad windows and separate DMA-driven systolic path in `src/peripheral.v`. Added MMIO register map for DMA config and sysmem access, plus status/error reporting and bounds/alignment checks.
- 2026-02-03: Added new end-to-end DMA testbench `testbench/tb_dma.sv` to validate dual-channel input DMA, compute, and output DMA through MMIO sysmem window.
- 2026-02-03: Test runs attempted: `verilator --binary ...` (tb_peripheral) failed because verilator not installed; `make all` failed because cocotb-config missing; `bash verify.sh` failed due to non-executable lint.sh; `bash lint.sh` failed because verilator missing.
- 2026-02-03: Additional attempt: `verilator --binary ... tb_dma` failed because verilator is not installed.
- 2026-02-03: Adjusted `src/peripheral.v` array reset initialization to use blocking assignments (Verilator BLKLOOPINIT workaround) and widened DMA beat arithmetic to avoid width warnings.
- 2026-02-03: Installed cocotb (downgraded to 1.9.2 for LogicArray.assign compatibility) and riscv-model in local venv; reran cocotb tests with CPUD override to use in-repo CPU sources.
- 2026-02-03: Ran Verilator unit testbenches (tb_mac, tb_systolic, tb_fsm, tb_peripheral, tb_dma). All passed; Verilator emitted warnings only.
- 2026-02-03: Cocotb tests passed for alu/core/counter/cpu/decode/mem_ctrl/qspi_ctrl/register; qspi_flash tests failed with spi_data_out expectation mismatch.
- 2026-02-03: Reran full cocotb suite with CPUD override (alu/core/counter/cpu/decode/mem_ctrl/qspi_ctrl/register passed; qspi_flash failed on spi_data_out expectation). Reran Verilator unit benches (tb_mac/tb_systolic/tb_fsm/tb_peripheral/tb_dma passed). verify.sh now executes but fails at lint.sh due to existing Verilator warnings.
- 2026-02-03: Reran full cocotb suite from dp1 with CPUD override and venv PATH. All cocotb tests passed except `test_qspi_flash` which still fails on `spi_data_out == 0xF` assertion. Ran `./verify.sh`; lint.sh fails with existing Verilator warnings in tb_*.v and synth_out.v (MODDUP/EOFNEWLINE/UNUSEDSIGNAL/etc.), so verify.sh exits with nonzero.
- 2026-02-03: Ran Verilator unit benches from dp1: tb_mac, tb_systolic, tb_fsm, tb_peripheral, tb_dma. All passed; Verilator emitted warnings (UNUSEDSIGNAL/BLKSEQ/VARHIDDEN/INITIALDLY/etc.).
- 2026-02-03: Ran ./verify.sh; lint.sh fails due to existing Verilator warnings across tb_*.v and synth_out.v, so verify.sh exits with nonzero.
