#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
SIM_LOG="$ROOT_DIR/sim.log"
TRACE_VCD="$ROOT_DIR/trace.vcd"

rm -f "$SIM_LOG" "$TRACE_VCD"
cd "$ROOT_DIR"

RTL_FILES=(
  "$ROOT_DIR/src/peripheral.v"
  "$ROOT_DIR/hw/npu/mac32.v"
  "$ROOT_DIR/hw/npu/systolic_array.v"
  "$ROOT_DIR/hw/npu/sram_buffer.v"
  "$ROOT_DIR/hw/npu/dual_dma.v"
  "$ROOT_DIR/hw/npu/npu_fsm.v"
  "$ROOT_DIR/hw/npu/tinyQV_core.v"
  "$ROOT_DIR/hw/npu/tinyQV_top.v"
  "$ROOT_DIR/hw/npu/npu_if_bridge.v"
)

run_test() {
  local name=$1
  local tb=$2
  local out="/tmp/${name}.vvp"
  iverilog -g2012 -o "$out" "${RTL_FILES[@]}" "$tb"
  vvp "$out" | tee -a "$SIM_LOG"
}

run_test "dma_unit_tb" "$ROOT_DIR/tb/dma_unit_tb.v"
run_test "e2e_npu_tb" "$ROOT_DIR/tb/e2e_npu_tb.v"

PASS_COUNT=$(grep -c "TEST PASS" "$SIM_LOG" || true)
if [ "$PASS_COUNT" -lt 2 ]; then
  echo "TEST FAIL" | tee -a "$SIM_LOG"
  exit 1
fi

echo "ALL TESTS PASS" | tee -a "$SIM_LOG"
