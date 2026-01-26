// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_fsm.h for the primary calling header

#ifndef VERILATED_VTB_FSM___024ROOT_H_
#define VERILATED_VTB_FSM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_fsm__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_fsm___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_fsm__DOT__clk;
    CData/*0:0*/ tb_fsm__DOT__rst_n;
    CData/*0:0*/ tb_fsm__DOT__cfg_start;
    CData/*0:0*/ tb_fsm__DOT__cfg_clr_status;
    CData/*0:0*/ tb_fsm__DOT__sts_done;
    CData/*0:0*/ tb_fsm__DOT__sts_error;
    CData/*7:0*/ tb_fsm__DOT__sts_errcode;
    CData/*0:0*/ tb_fsm__DOT__in_dma_start;
    CData/*0:0*/ tb_fsm__DOT__in_dma_done;
    CData/*0:0*/ tb_fsm__DOT__in_dma_error;
    CData/*0:0*/ tb_fsm__DOT__out_dma_start;
    CData/*0:0*/ tb_fsm__DOT__out_dma_done;
    CData/*0:0*/ tb_fsm__DOT__out_dma_error;
    CData/*0:0*/ tb_fsm__DOT__sa_clear;
    CData/*0:0*/ tb_fsm__DOT__sa_start;
    CData/*0:0*/ tb_fsm__DOT__sa_busy;
    CData/*0:0*/ tb_fsm__DOT__sa_done;
    CData/*0:0*/ tb_fsm__DOT__sa_error;
    CData/*0:0*/ tb_fsm__DOT__inject_sa_error;
    CData/*0:0*/ tb_fsm__DOT__dut__DOT__start_seen;
    CData/*3:0*/ tb_fsm__DOT__dut__DOT__state;
    CData/*3:0*/ tb_fsm__DOT__dut__DOT__state_n;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fsm__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fsm__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_fsm__DOT__cfg_len_bytes;
    IData/*31:0*/ tb_fsm__DOT__run_cycles_left;
    IData/*31:0*/ tb_fsm__DOT__clear_pulses;
    IData/*31:0*/ tb_fsm__DOT__start_pulses;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_ha9d4021f__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_fsm__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_fsm___024root(Vtb_fsm__Syms* symsp, const char* v__name);
    ~Vtb_fsm___024root();
    VL_UNCOPYABLE(Vtb_fsm___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
