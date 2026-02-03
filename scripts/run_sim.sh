#!/bin/bash
set -euo pipefail

ROOT="/home/mcs46/RISC-V-NPU"
LOG="$ROOT/sim.log"
VCD="$ROOT/trace.vcd"

rm -f "$LOG" "$VCD"

run_test() {
  local name="$1"
  shift
  echo "[RUN] $name" | tee -a "$LOG"
  iverilog -g2012 -s "$name" -o "/tmp/${name}.out" "$@" >>"$LOG" 2>&1
  vvp "/tmp/${name}.out" >>"$LOG" 2>&1
}

run_verilator() {
  local name="$1"
  shift
  echo "[RUN] $name (verilator)" | tee -a "$LOG"
  verilator --binary -sv --timing -Wno-fatal --top-module "$name" --Mdir "/tmp/obj_${name}" -o "/tmp/${name}_sim" "$@" >>"$LOG" 2>&1
  "/tmp/${name}_sim" >>"$LOG" 2>&1
}

# Existing DP1 self-checking testbenches (unchanged)
run_test tb_mac \
  "$ROOT/dp1/src/mac.v" \
  "$ROOT/dp1/testbench/tb_mac.sv"

run_test tb_systolic \
  "$ROOT/dp1/src/mac.v" \
  "$ROOT/dp1/src/systolic.v" \
  "$ROOT/dp1/testbench/tb_systolic.sv"

run_test tb_fsm \
  "$ROOT/dp1/src/fsm.v" \
  "$ROOT/dp1/testbench/tb_fsm.sv"

run_verilator tb_peripheral \
  "$ROOT/dp1/src/mac.v" \
  "$ROOT/dp1/src/systolic.v" \
  "$ROOT/dp1/src/fsm.v" \
  "$ROOT/dp1/src/peripheral.v" \
  "$ROOT/dp1/testbench/tb_peripheral.sv"

run_verilator tb_dma \
  "$ROOT/dp1/src/mac.v" \
  "$ROOT/dp1/src/systolic.v" \
  "$ROOT/dp1/src/fsm.v" \
  "$ROOT/dp1/src/peripheral.v" \
  "$ROOT/dp1/testbench/tb_dma.sv"

# New DMA + E2E NPU tests
run_test dma_unit_tb \
  "$ROOT/hw/npu/dual_dma.v" \
  "$ROOT/tb/dma_unit_tb.v"

run_test e2e_npu_tb \
  "$ROOT/hw/npu/mac32.v" \
  "$ROOT/hw/npu/sram_buffer.v" \
  "$ROOT/hw/npu/systolic_array.v" \
  "$ROOT/hw/npu/dual_dma.v" \
  "$ROOT/hw/npu/npu_fsm.v" \
  "$ROOT/hw/npu/npu_if_bridge.v" \
  "$ROOT/hw/npu/tinyQV_top.v" \
  "$ROOT/tb/e2e_npu_tb.v"

if [ ! -f "$VCD" ]; then
  echo "trace.vcd not produced by tests" | tee -a "$LOG"
  exit 1
fi

echo "All tests passed." | tee -a "$LOG"
