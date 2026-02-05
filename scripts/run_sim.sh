#!/bin/bash
set -euo pipefail

ROOT="/home/mcs46/RISC-V-NPU"
LOG="$ROOT/sim.log"
VCD="$ROOT/trace.vcd"

rm -f "$LOG" "$VCD"

any_fail=0
pass_count=0
test_count=0
declare -a TEST_NAMES
declare -a TEST_STATUS

filter_output() {
  # Hide simulator noise: $finish backtraces and VCD info lines
  sed -E \
    -e '/VCD info: /d' \
    -e '/\$finish/d' \
    -e '/[Ff]inish called/d'
}

allow_output() {
  # Keep only bracketed lines for clean console output
  grep -E '^\[(RUN|INPUT|EXPECTED OUTPUT|OUTPUT|PASS|FAIL|SUMMARY)\]'
}

detect_fail() {
  # Detect common FAIL markers in testbench output
  grep -q -E 'Result: \\[FAIL\\]|\\[FAIL\\]|FAIL:'
}

record_result() {
  local name="$1"
  local status="$2"
  TEST_NAMES+=("$name")
  TEST_STATUS+=("$status")
  test_count=$((test_count + 1))
  if [ "$status" = "PASS" ]; then
    pass_count=$((pass_count + 1))
  else
    any_fail=1
  fi
}

print_results() {
  printf "\n[RESULTS]\n"
  printf "%-20s %s\n" "TEST" "STATUS"
  local i
  for i in "${!TEST_NAMES[@]}"; do
    printf "%-20s %s\n" "${TEST_NAMES[$i]}" "${TEST_STATUS[$i]}"
  done
  printf "[SUMMARY] %d OF %d TESTS PASSED\n" "$pass_count" "$test_count"
}

run_test() {
  local name="$1"
  shift
  echo "[RUN] $name" | tee -a "$LOG"
  iverilog -g2012 -s "$name" -o "/tmp/${name}.out" "$@" >>"$LOG" 2>&1
  set +e
  local out
  out=$(vvp "/tmp/${name}.out" 2>&1)
  local rc=$?
  set -e

  local filtered cleaned status
  filtered=$(printf "%s\n" "$out" | filter_output)
  cleaned=$(printf "%s\n" "$filtered" | allow_output || true)
  printf "%s\n" "$cleaned" >>"$LOG"
  if [ -n "$cleaned" ]; then
    printf "%s\n" "$cleaned"
  fi

  status="PASS"
  if [ $rc -ne 0 ] || printf "%s\n" "$out" | detect_fail; then
    status="FAIL"
  fi
  record_result "$name" "$status"
  echo "[$status] $name"
}

run_verilator() {
  local name="$1"
  shift
  echo "[RUN] $name (verilator)" | tee -a "$LOG"
  verilator --binary -sv --timing -Wno-fatal --top-module "$name" --Mdir "/tmp/obj_${name}" -o "/tmp/${name}_sim" "$@" >>"$LOG" 2>&1
  set +e
  local out
  out=$("/tmp/${name}_sim" 2>&1)
  local rc=$?
  set -e

  local filtered cleaned status
  filtered=$(printf "%s\n" "$out" | filter_output)
  cleaned=$(printf "%s\n" "$filtered" | allow_output || true)
  printf "%s\n" "$cleaned" >>"$LOG"
  if [ -n "$cleaned" ]; then
    printf "%s\n" "$cleaned"
  fi

  status="PASS"
  if [ $rc -ne 0 ] || printf "%s\n" "$out" | detect_fail; then
    status="FAIL"
  fi
  record_result "$name" "$status"
  echo "[$status] $name"
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

# Formatted ALU test output
run_test tb_alu_fmt \
  "$ROOT/dp1/alu.v" \
  "$ROOT/dp1/tb_alu.v" \
  "$ROOT/dp1/tb_alu_fmt.sv"

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

print_results | tee -a "$LOG"

if [ ! -f "$VCD" ]; then
  echo "trace.vcd not produced by tests" | tee -a "$LOG"
  any_fail=1
fi

if [ "$any_fail" -ne 0 ]; then
  exit 1
fi
