# TinyQV MMIO Integration (DP1)

This document describes the MMIO register interface implemented by `npu_if_bridge.v` and exposed through `tinyQV_top.v`.

## Base Address

`MMIO_BASE` is a parameter in `tinyQV_top.v` (default `0x0100_0000` in 28-bit space). All offsets below are relative to this base.

## Register Map (32-bit)

- `BASE + 0x00` CMD
  - [0] START
  - [1] ABORT
  - [2] IRQ_EN
  - [3:7] OPCODE
  - [8:15] QPARAM (matrix size)

- `BASE + 0x04` STATUS
  - [0] BUSY
  - [1] DONE
  - [2] ERROR
  - [3] DMA_BUSY

- `BASE + 0x08` SRC_DESC_PTR
- `BASE + 0x0C` DST_DESC_PTR
- `BASE + 0x10` CONTROL
- `BASE + 0x14` PERF_CNT_LO
- `BASE + 0x18` PERF_CNT_HI
- `BASE + 0x1C` WATCHDOG

## Operational Notes

- `START` is a one-shot pulse; it is ignored while BUSY.
- `ABORT` forces DMA/compute into ERROR.
- Configuration registers are locked while BUSY.
- DONE and ERROR are sticky and cleared on the next START.
- `IRQ` is level-high when DONE and `IRQ_EN` are set.

