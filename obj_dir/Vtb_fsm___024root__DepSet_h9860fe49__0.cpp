// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fsm.h for the primary calling header

#include "Vtb_fsm__pch.h"
#include "Vtb_fsm___024root.h"

VL_ATTR_COLD void Vtb_fsm___024root___eval_initial__TOP(Vtb_fsm___024root* vlSelf);
VlCoroutine Vtb_fsm___024root___eval_initial__TOP__Vtiming__0(Vtb_fsm___024root* vlSelf);
VlCoroutine Vtb_fsm___024root___eval_initial__TOP__Vtiming__1(Vtb_fsm___024root* vlSelf);

void Vtb_fsm___024root___eval_initial(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_initial\n"); );
    // Body
    Vtb_fsm___024root___eval_initial__TOP(vlSelf);
    Vtb_fsm___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_fsm___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__clk__0 
        = vlSelf->tb_fsm__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__rst_n__0 
        = vlSelf->tb_fsm__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_fsm___024root___eval_initial__TOP__Vtiming__1(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "dp1/testbench/tb_fsm.sv", 
                                           32);
        vlSelf->tb_fsm__DOT__clk = (1U & (~ (IData)(vlSelf->tb_fsm__DOT__clk)));
    }
}

VL_INLINE_OPT void Vtb_fsm___024root___act_sequent__TOP__0(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_fsm__DOT__dut__DOT__state_n = vlSelf->tb_fsm__DOT__dut__DOT__state;
    if ((8U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
        if ((4U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0U;
        } else if ((2U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0U;
            } else if (vlSelf->tb_fsm__DOT__cfg_clr_status) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0U;
            }
        } else if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            if (vlSelf->tb_fsm__DOT__cfg_clr_status) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0U;
            }
        } else if (vlSelf->tb_fsm__DOT__out_dma_error) {
            vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0xaU;
        } else if (vlSelf->tb_fsm__DOT__out_dma_done) {
            vlSelf->tb_fsm__DOT__dut__DOT__state_n = 9U;
        }
    } else if ((4U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
        if ((2U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 8U;
            } else if (vlSelf->tb_fsm__DOT__sa_error) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0xaU;
            } else if (vlSelf->tb_fsm__DOT__sa_done) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 9U;
            }
        } else {
            vlSelf->tb_fsm__DOT__dut__DOT__state_n 
                = ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))
                    ? 6U : 5U);
        }
    } else if ((2U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
        if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            if (vlSelf->tb_fsm__DOT__in_dma_error) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 0xaU;
            } else if (vlSelf->tb_fsm__DOT__in_dma_done) {
                vlSelf->tb_fsm__DOT__dut__DOT__state_n = 4U;
            }
        } else {
            vlSelf->tb_fsm__DOT__dut__DOT__state_n = 3U;
        }
    } else if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
        vlSelf->tb_fsm__DOT__dut__DOT__state_n = ((0U 
                                                   == vlSelf->tb_fsm__DOT__cfg_len_bytes)
                                                   ? 0xaU
                                                   : 4U);
    } else if (((IData)(vlSelf->tb_fsm__DOT__cfg_start) 
                & (~ (IData)(vlSelf->tb_fsm__DOT__dut__DOT__start_seen)))) {
        vlSelf->tb_fsm__DOT__dut__DOT__state_n = 1U;
    }
}

void Vtb_fsm___024root___eval_act(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_fsm___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_fsm___024root___nba_sequent__TOP__1(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdly__tb_fsm__DOT__sa_busy;
    __Vdly__tb_fsm__DOT__sa_busy = 0;
    IData/*31:0*/ __Vdly__tb_fsm__DOT__run_cycles_left;
    __Vdly__tb_fsm__DOT__run_cycles_left = 0;
    // Body
    __Vdly__tb_fsm__DOT__run_cycles_left = vlSelf->tb_fsm__DOT__run_cycles_left;
    __Vdly__tb_fsm__DOT__sa_busy = vlSelf->tb_fsm__DOT__sa_busy;
    if (vlSelf->tb_fsm__DOT__rst_n) {
        if (vlSelf->tb_fsm__DOT__sa_clear) {
            vlSelf->tb_fsm__DOT__clear_pulses = ((IData)(1U) 
                                                 + vlSelf->tb_fsm__DOT__clear_pulses);
        }
        if (vlSelf->tb_fsm__DOT__sa_start) {
            vlSelf->tb_fsm__DOT__start_pulses = ((IData)(1U) 
                                                 + vlSelf->tb_fsm__DOT__start_pulses);
            __Vdly__tb_fsm__DOT__sa_busy = 1U;
            __Vdly__tb_fsm__DOT__run_cycles_left = 4U;
        }
        if (vlSelf->tb_fsm__DOT__cfg_clr_status) {
            vlSelf->tb_fsm__DOT__clear_pulses = 0U;
            vlSelf->tb_fsm__DOT__start_pulses = 0U;
            vlSelf->tb_fsm__DOT__sts_error = 0U;
            vlSelf->tb_fsm__DOT__sts_done = 0U;
            vlSelf->tb_fsm__DOT__sts_errcode = 0U;
        }
        if ((0xaU == (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state_n))) {
            vlSelf->tb_fsm__DOT__sts_error = 1U;
            vlSelf->tb_fsm__DOT__sts_errcode = (((1U 
                                                  == (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state)) 
                                                 & (0U 
                                                    == vlSelf->tb_fsm__DOT__cfg_len_bytes))
                                                 ? 1U
                                                 : 
                                                ((IData)(vlSelf->tb_fsm__DOT__in_dma_error)
                                                  ? 2U
                                                  : 
                                                 ((IData)(vlSelf->tb_fsm__DOT__sa_error)
                                                   ? 3U
                                                   : 
                                                  ((IData)(vlSelf->tb_fsm__DOT__out_dma_error)
                                                    ? 4U
                                                    : 0xffU))));
        }
        if ((9U == (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state_n))) {
            vlSelf->tb_fsm__DOT__sts_done = 1U;
        }
        if ((0U == (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            vlSelf->tb_fsm__DOT__dut__DOT__start_seen 
                = vlSelf->tb_fsm__DOT__cfg_start;
        }
        vlSelf->tb_fsm__DOT__dut__DOT__state = vlSelf->tb_fsm__DOT__dut__DOT__state_n;
        vlSelf->tb_fsm__DOT__sa_done = 0U;
        vlSelf->tb_fsm__DOT__sa_error = 0U;
        if (vlSelf->tb_fsm__DOT__sa_busy) {
            if ((0U != vlSelf->tb_fsm__DOT__run_cycles_left)) {
                __Vdly__tb_fsm__DOT__run_cycles_left 
                    = (vlSelf->tb_fsm__DOT__run_cycles_left 
                       - (IData)(1U));
                if ((1U == vlSelf->tb_fsm__DOT__run_cycles_left)) {
                    __Vdly__tb_fsm__DOT__sa_busy = 0U;
                    if (vlSelf->tb_fsm__DOT__inject_sa_error) {
                        vlSelf->tb_fsm__DOT__sa_error = 1U;
                    } else {
                        vlSelf->tb_fsm__DOT__sa_done = 1U;
                    }
                }
            }
        }
    } else {
        vlSelf->tb_fsm__DOT__clear_pulses = 0U;
        vlSelf->tb_fsm__DOT__start_pulses = 0U;
        vlSelf->tb_fsm__DOT__sts_error = 0U;
        vlSelf->tb_fsm__DOT__sts_done = 0U;
        vlSelf->tb_fsm__DOT__sts_errcode = 0U;
        vlSelf->tb_fsm__DOT__dut__DOT__start_seen = 0U;
        vlSelf->tb_fsm__DOT__dut__DOT__state = 0U;
        __Vdly__tb_fsm__DOT__sa_busy = 0U;
        __Vdly__tb_fsm__DOT__run_cycles_left = 0U;
        vlSelf->tb_fsm__DOT__sa_done = 0U;
        vlSelf->tb_fsm__DOT__sa_error = 0U;
    }
    vlSelf->tb_fsm__DOT__sa_busy = __Vdly__tb_fsm__DOT__sa_busy;
    vlSelf->tb_fsm__DOT__run_cycles_left = __Vdly__tb_fsm__DOT__run_cycles_left;
    vlSelf->tb_fsm__DOT__in_dma_start = 0U;
    vlSelf->tb_fsm__DOT__out_dma_start = 0U;
    vlSelf->tb_fsm__DOT__sa_clear = 0U;
    vlSelf->tb_fsm__DOT__sa_start = 0U;
    if ((1U & (~ ((IData)(vlSelf->tb_fsm__DOT__dut__DOT__state) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelf->tb_fsm__DOT__dut__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state)))) {
                    vlSelf->tb_fsm__DOT__in_dma_start = 1U;
                }
            }
        }
        if ((4U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
            if ((2U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
                if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
                    vlSelf->tb_fsm__DOT__out_dma_start = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelf->tb_fsm__DOT__dut__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state)))) {
                    vlSelf->tb_fsm__DOT__sa_clear = 1U;
                }
                if ((1U & (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) {
                    vlSelf->tb_fsm__DOT__sa_start = 1U;
                }
            }
        }
    }
}

void Vtb_fsm___024root___nba_sequent__TOP__0(Vtb_fsm___024root* vlSelf);

void Vtb_fsm___024root___eval_nba(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_fsm___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_fsm___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_fsm___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_fsm___024root___timing_resume(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_ha9d4021f__0.resume("@(posedge tb_fsm.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_fsm___024root___timing_commit(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_ha9d4021f__0.commit("@(posedge tb_fsm.clk)");
    }
}

void Vtb_fsm___024root___eval_triggers__act(Vtb_fsm___024root* vlSelf);

bool Vtb_fsm___024root___eval_phase__act(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_fsm___024root___eval_triggers__act(vlSelf);
    Vtb_fsm___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_fsm___024root___timing_resume(vlSelf);
        Vtb_fsm___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_fsm___024root___eval_phase__nba(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_fsm___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__nba(Vtb_fsm___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__act(Vtb_fsm___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_fsm___024root___eval(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_fsm___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("dp1/testbench/tb_fsm.sv", 20, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_fsm___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("dp1/testbench/tb_fsm.sv", 20, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_fsm___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_fsm___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_fsm___024root___eval_debug_assertions(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
