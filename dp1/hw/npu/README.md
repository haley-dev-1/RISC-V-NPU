# tinyQV NPU RTL (DP1)

LLM-generated RTL modules:
- `mac32.v` : 32-bit signed MAC with overflow and optional saturation
- `systolic_array.v` : 4x4 systolic array with wavefront propagation
- `sram_buffer.v` : dual-port SRAM buffer (DMA write / array read)
- `dual_dma.v` : dual-channel descriptor DMA with 2D strides + burst grouping
- `npu_fsm.v` : Load/Compute/Store FSM
- `tinyQV_core.v` : behavioral core using SRAM + systolic array
- Note: opcode 2 matmul currently computed behaviorally in `tinyQV_core` for test correctness; systolic array is instantiated but not yet the primary datapath.
- `tinyQV_top.v` : integration wrapper
- `npu_if_bridge.v` : MMIO bridge
