#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
LOG="$ROOT/runme.log"

declare -a TEST_NAMES
declare -a TEST_PASSED
declare -a TEST_TOTAL

PASS_COUNT=0
TEST_COUNT=0

echo "[RUNME] Starting full verification run" | tee "$LOG"

run_test() {
  local name="$1"
  shift

  echo "" | tee -a "$LOG"
  echo "[RUN] $name" | tee -a "$LOG"

  local out
  set +e
  out=$("$@" 2>&1)
  local rc=$?
  set -e

  echo "$out" | tee -a "$LOG"

  # Determine pass/fail by parsing summary or fatal
  local passed=0
  local total=0

  if echo "$out" | grep -q "\[SUMMARY\]"; then
    passed=$(echo "$out" | awk '/\[SUMMARY\]/ {print $2; exit}')
    total=$(echo "$out" | awk '/\[SUMMARY\]/ {print $4; exit}')
  else
    total=1
    if [ $rc -eq 0 ] && ! echo "$out" | grep -q "\[FAIL\]"; then
      passed=1
    else
      passed=0
    fi
  fi

  if [ $rc -ne 0 ] || echo "$out" | grep -q "\[FAIL\]"; then
    echo "[RESULT] $name FAIL" | tee -a "$LOG"
  else
    echo "[RESULT] $name PASS" | tee -a "$LOG"
  fi

  TEST_NAMES+=("$name")
  TEST_PASSED+=("$passed")
  TEST_TOTAL+=("$total")

  PASS_COUNT=$((PASS_COUNT + passed))
  TEST_COUNT=$((TEST_COUNT + total))
}

cd "$ROOT/dp1"

# MAC
rm -rf obj_tb_mac
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_mac \
  --Mdir obj_tb_mac \
  src/mac.v \
  testbench/tb_mac.sv
run_test "MAC" ./obj_tb_mac/Vtb_mac

# SYSTOLIC
rm -rf obj_tb_systolic
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_systolic \
  --Mdir obj_tb_systolic \
  src/mac.v \
  src/systolic.v \
  testbench/tb_systolic.sv
run_test "SYSTOLIC" ./obj_tb_systolic/Vtb_systolic

# FSM
rm -rf obj_tb_fsm
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_fsm \
  --Mdir obj_tb_fsm \
  src/fsm.v \
  testbench/tb_fsm.sv
run_test "FSM" ./obj_tb_fsm/Vtb_fsm

# SRAM BUFFER
rm -rf obj_tb_sram_buffer
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_sram_buffer \
  --Mdir obj_tb_sram_buffer \
  src/sram_buffer.sv \
  testbench/tb_sram_buffer.sv
run_test "SRAM_BUFFER" ./obj_tb_sram_buffer/Vtb_sram_buffer

# DMA UNIT
rm -rf obj_tb_dma_unit
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_dma_unit \
  --Mdir obj_tb_dma_unit \
  src/dma.v \
  testbench/tb_dma_unit.sv
run_test "DMA_UNIT" ./obj_tb_dma_unit/Vtb_dma_unit

# DMA INTEGRATION
rm -rf obj_tb_dma
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_dma \
  --Mdir obj_tb_dma \
  src/mac.v \
  src/systolic.v \
  src/dma.v \
  src/sram_buffer.sv \
  src/peripheral.v \
  testbench/tb_dma.sv
run_test "DMA_INTEGRATION" ./obj_tb_dma/Vtb_dma

# PERIPHERAL
rm -rf obj_tb_peripheral
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_peripheral \
  --Mdir obj_tb_peripheral \
  src/mac.v \
  src/systolic.v \
  src/dma.v \
  src/sram_buffer.sv \
  src/peripheral.v \
  testbench/tb_peripheral.sv
run_test "PERIPHERAL" ./obj_tb_peripheral/Vtb_peripheral

# TT_WRAPPER (END-TO-END)
rm -rf obj_tb_tt_wrapper
verilator --binary -sv --timing -Wno-fatal \
  --top-module tb_tt_wrapper \
  --Mdir obj_tb_tt_wrapper \
  src/mac.v \
  src/systolic.v \
  src/dma.v \
  src/sram_buffer.sv \
  src/peripheral.v \
  src/tt_wrapper.v \
  src/test_harness/synchronizer.sv \
  src/test_harness/reclocking.sv \
  src/test_harness/rising_edge_detector.sv \
  src/test_harness/falling_edge_detector.sv \
  src/test_harness/spi_reg.sv \
  testbench/tb_tt_wrapper.sv
run_test "TT_WRAPPER" ./obj_tb_tt_wrapper/Vtb_tt_wrapper

# Summary
{
  echo "";
  for i in "${!TEST_NAMES[@]}"; do
    echo "[SUMMARY] ${TEST_NAMES[$i]} PASSED ${TEST_PASSED[$i]} OF ${TEST_TOTAL[$i]}";
  done
  echo "[SUMMARY] TOTAL PASSED $PASS_COUNT OF $TEST_COUNT";
} | tee -a "$LOG"

exit 0
