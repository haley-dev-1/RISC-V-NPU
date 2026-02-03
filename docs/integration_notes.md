# Integration Notes (DP1)

## TinyQV Source Handling

TinyQV sources are copied into `hw/tinyQV/` and treated as frozen IP. No modifications are made to those files.

## NPU Integration Flow

1. CPU programs SRC/DST descriptor pointers via MMIO.
2. CPU writes CMD.START with QPARAM matrix size.
3. `npu_fsm` triggers SRC DMA to load A/B buffers.
4. `systolic_array` computes C into the C buffer.
5. `dual_dma` writes C back to system memory via DST channel.
6. DONE/IRQ signals completion.

## DMA + Buffer Mapping

- SRC channel writes into A or B buffers based on `CFG[1:0]`.
- DST channel reads from buffer C (`CFG[1:0]=2`).
- Chained descriptors append into buffers using a running buffer offset.

## Verification

- `tb/dma_unit_tb.v` validates descriptor chaining, abort, backpressure, and invalid descriptor detection.
- `tb/e2e_npu_tb.v` exercises full MMIO → DMA → compute → DMA flow.

