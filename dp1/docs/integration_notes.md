# Integration Notes (DP1)

## Topology

- `tqvp_npu` (peripheral) instantiates:
  - `npu_if_bridge` for MMIO
  - `tinyQV_top` for DMA + core + FSM
  - Internal memory model (1K words)

## tinyQV_top Composition

- `dual_dma` performs SRC (load) and DST (store) transfers
- `sram_buffer` instances for input/output
- `tinyQV_core` reads input buffer and writes output buffer
- `npu_fsm` sequences LOAD -> COMPUTE -> STORE

## Dataflow

1. CPU writes descriptors and input data into system memory (internal mem model in simulation).
2. MMIO START triggers FSM.
3. DMA loads system memory into input SRAM buffer.
4. Core executes:
   - Copy/scale (opcode 0/1)
   - 4x4 matrix multiply via systolic array (opcode 2)
5. DMA stores output SRAM to system memory.
6. DONE/IRQ asserted.

## Notes

- DMA supports 2D strides using `CONTROL[15:8]` row count and descriptor STRIDE.
- Watchdog abort handled in `npu_if_bridge` (sets ERROR and asserts abort).
- Opcode 2 currently uses a behavioral matrix multiply inside `tinyQV_core` for correctness; the systolic array remains instantiated for future timing-accurate use.
