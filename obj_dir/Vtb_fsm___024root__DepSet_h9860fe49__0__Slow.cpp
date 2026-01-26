// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fsm.h for the primary calling header

#include "Vtb_fsm__pch.h"
#include "Vtb_fsm___024root.h"

VL_ATTR_COLD void Vtb_fsm___024root___eval_static__TOP(Vtb_fsm___024root* vlSelf);

VL_ATTR_COLD void Vtb_fsm___024root___eval_static(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_static\n"); );
    // Body
    Vtb_fsm___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_fsm___024root___eval_static__TOP(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_fsm__DOT__clk = 0U;
    vlSelf->tb_fsm__DOT__rst_n = 0U;
}

VL_ATTR_COLD void Vtb_fsm___024root___eval_initial__TOP(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->tb_fsm__DOT__in_dma_done = 0U;
    vlSelf->tb_fsm__DOT__in_dma_error = 0U;
    vlSelf->tb_fsm__DOT__out_dma_done = 0U;
    vlSelf->tb_fsm__DOT__out_dma_error = 0U;
}

VL_ATTR_COLD void Vtb_fsm___024root___eval_final(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__stl(Vtb_fsm___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_fsm___024root___eval_phase__stl(Vtb_fsm___024root* vlSelf);

VL_ATTR_COLD void Vtb_fsm___024root___eval_settle(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_fsm___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("dp1/testbench/tb_fsm.sv", 20, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_fsm___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__stl(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_fsm___024root___stl_sequent__TOP__0(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___stl_sequent__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void Vtb_fsm___024root___eval_stl(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_fsm___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_fsm___024root___eval_triggers__stl(Vtb_fsm___024root* vlSelf);

VL_ATTR_COLD bool Vtb_fsm___024root___eval_phase__stl(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_fsm___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_fsm___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__act(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_fsm.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_fsm.clk or negedge tb_fsm.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__nba(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_fsm.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_fsm.clk or negedge tb_fsm.rst_n)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_fsm___024root___ctor_var_reset(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_fsm__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__cfg_start = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__cfg_clr_status = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__cfg_len_bytes = VL_RAND_RESET_I(32);
    vlSelf->tb_fsm__DOT__sts_done = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sts_error = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sts_errcode = VL_RAND_RESET_I(8);
    vlSelf->tb_fsm__DOT__in_dma_start = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__in_dma_done = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__in_dma_error = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__out_dma_start = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__out_dma_done = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__out_dma_error = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sa_clear = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sa_start = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sa_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sa_done = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__sa_error = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__run_cycles_left = 0;
    vlSelf->tb_fsm__DOT__inject_sa_error = 0;
    vlSelf->tb_fsm__DOT__clear_pulses = 0;
    vlSelf->tb_fsm__DOT__start_pulses = 0;
    vlSelf->tb_fsm__DOT__dut__DOT__start_seen = VL_RAND_RESET_I(1);
    vlSelf->tb_fsm__DOT__dut__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->tb_fsm__DOT__dut__DOT__state_n = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__rst_n__0 = VL_RAND_RESET_I(1);
}
