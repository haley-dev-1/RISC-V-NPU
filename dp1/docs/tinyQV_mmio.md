# tinyQV MMIO Map (DP1)

Base offsets (32-bit):

- `0x00 CMD`
  - [0] START (pulse)
  - [1] ABORT
  - [2] IRQ_EN
  - [3:7] OPCODE
  - [8:15] QPARAM

- `0x04 STATUS`
  - [0] BUSY (NPU FSM busy)
  - [1] DONE (latched)
  - [2] ERROR (latched)
  - [3] DMA_BUSY

- `0x08 SRC_DESC_PTR`
- `0x0C DST_DESC_PTR`
- `0x10 CONTROL`
- `0x14 PERF_CNT_LO`
- `0x18 PERF_CNT_HI`
- `0x1C WATCHDOG`

## CONTROL Register Usage (LLM-defined)

- `CONTROL[7:0]`   : DMA burst length in words (0 -> 1)
- `CONTROL[15:8]`  : DMA rows for 2D transfers (0 -> 1)
- `CONTROL[31]`    : Core hang mode (test-only watchdog trigger)

Other bits are currently reserved.

## Descriptor Format (memory)

```
0x00 ADDR   (32)
0x04 LEN    (32)  // bytes, must be 4-byte aligned
0x08 STRIDE (16)
0x0A FLAGS  (16)  // [0]=LAST
0x0C RESERVED
```

## tinyQV Core Opcodes

- `0`: Copy
- `1`: Scale/Bias (out = in * qparam + control[15:0])
- `2`: 4x4 matrix multiply (A*B) using systolic array

For opcode 2, input buffer layout:
- A matrix (16 words) then B matrix (16 words)
Output buffer:
- C matrix (16 words)
