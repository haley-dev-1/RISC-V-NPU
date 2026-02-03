# NPU RTL Overview (DP1)

This directory contains the LLM-generated NPU integration RTL for DP1. TinyQV source files are treated as read-only IP under `hw/tinyQV/` and are not modified.

## Modules

- `mac32.v`
  - 32-bit signed MAC with optional saturation and overflow flag.
- `systolic_array.v`
  - Time-multiplexed 4x4 matrix multiply engine with local B-weight storage.
  - Uses `qparam[3:0]` as runtime size (clamped to 1..4).
- `sram_buffer.v`
  - Simple dual-port SRAM: one write port and one read port.
- `dual_dma.v`
  - Descriptor-driven dual-channel DMA (SRC read, DST write) with strided 2D transfers.
  - Supports chained descriptors and burst gap insertion.
- `npu_fsm.v`
  - Sequencing: IDLE -> LOAD (SRC DMA) -> COMPUTE -> STORE (DST DMA) -> DONE.
  - Watchdog timeout and error propagation.
- `npu_if_bridge.v`
  - MMIO register bank that exposes CMD/STATUS/DESC/CONTROL/PERF/WATCHDOG.
  - Locks config registers while BUSY.
- `tinyQV_top.v`
  - Top-level wrapper connecting MMIO, DMA, buffers, and compute.
  - Exposes TinyQV-style MMIO interface and memory DMA ports.

## Array Size Choice

A 4x4 array (`N=4`) is used to balance area and functional coverage. It fits within small SRAM buffers (default 256 words), keeps RTL complexity manageable for DP1 verification, and still demonstrates full DMA→compute→DMA flow for end-to-end tests.

## DMA Descriptor Format

Each descriptor is 6 words (24 bytes), 32-bit aligned:

Word 0: BASE_ADDR (byte address)
Word 1: LEN_BYTES (bytes per row)
Word 2: STRIDE_BYTES (bytes between rows)
Word 3: ROWS
Word 4: CFG
- CFG[1:0]  = BUF_SEL (0=A, 1=B, 2=C)
- CFG[7:4]  = BURST_LEN (0 treated as 1)
Word 5: NEXT_DESC_PTR (0 = end of chain)

Bounds and alignment checks:
- BASE_ADDR, STRIDE, LEN_BYTES must be 4-byte aligned
- LEN_BYTES <= MAX_LEN_BYTES
- (BASE_ADDR + (ROWS-1)*STRIDE + LEN_BYTES) <= MEM_SIZE_BYTES
- Buffer depth check for chained descriptors

## MMIO Register Map

Offsets are relative to `MMIO_BASE`:

- 0x00 CMD
  - [0] START
  - [1] ABORT
  - [2] IRQ_EN
  - [3:7] OPCODE
  - [8:15] QPARAM (matrix size)
- 0x04 STATUS
  - [0] BUSY
  - [1] DONE
  - [2] ERROR
  - [3] DMA_BUSY
- 0x08 SRC_DESC_PTR
- 0x0C DST_DESC_PTR
- 0x10 CONTROL
- 0x14 PERF_CNT_LO
- 0x18 PERF_CNT_HI
- 0x1C WATCHDOG

