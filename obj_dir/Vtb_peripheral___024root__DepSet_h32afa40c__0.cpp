// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_peripheral.h for the primary calling header

#include "Vtb_peripheral__pch.h"
#include "Vtb_peripheral___024root.h"

VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0(Vtb_peripheral___024root* vlSelf);
VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__1(Vtb_peripheral___024root* vlSelf);

void Vtb_peripheral___024root___eval_initial(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_initial\n"); );
    // Body
    Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_peripheral___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_peripheral__DOT__clk__0 
        = vlSelf->tb_peripheral__DOT__clk;
}

VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0__0(Vtb_peripheral___024root* vlSelf);
VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0__1(Vtb_peripheral___024root* vlSelf);

VL_INLINE_OPT VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    co_await Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0__0(vlSelf);
    co_await Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__1(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "dp1/testbench/tb_peripheral.sv", 
                                           28);
        vlSelf->tb_peripheral__DOT__clk = (1U & (~ (IData)(vlSelf->tb_peripheral__DOT__clk)));
    }
}

VL_INLINE_OPT void Vtb_peripheral___024root___act_sequent__TOP__0(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___act_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ tb_peripheral__DOT__dut__DOT__c_word;
    tb_peripheral__DOT__dut__DOT__c_word = 0;
    IData/*31:0*/ tb_peripheral__DOT__dut__DOT__idx;
    tb_peripheral__DOT__dut__DOT__idx = 0;
    // Body
    tb_peripheral__DOT__dut__DOT__c_word = 0U;
    tb_peripheral__DOT__dut__DOT__idx = 0U;
    if (((0x30U <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
         & (0x34U > (IData)(vlSelf->tb_peripheral__DOT__address)))) {
        tb_peripheral__DOT__dut__DOT__idx = ((IData)(vlSelf->tb_peripheral__DOT__address) 
                                             - (IData)(0x30U));
        tb_peripheral__DOT__dut__DOT__c_word = (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx)))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[
                                                  (((IData)(0x1fU) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx))))) 
                                                | (vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[
                                                   (3U 
                                                    & (VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx))));
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr = 
        ((3U != (IData)(vlSelf->tb_peripheral__DOT__data_write_n)) 
         & (0x20U == (IData)(vlSelf->tb_peripheral__DOT__address)));
    vlSelf->tb_peripheral__DOT__data_out = ((0x21U 
                                             == (IData)(vlSelf->tb_peripheral__DOT__address))
                                             ? (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
                                                 << 1U) 
                                                | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__done_sticky))
                                             : (((0x30U 
                                                  <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
                                                 & (0x34U 
                                                    > (IData)(vlSelf->tb_peripheral__DOT__address)))
                                                 ? tb_peripheral__DOT__dut__DOT__c_word
                                                 : 0U));
    vlSelf->tb_peripheral__DOT__dut__DOT__clr_req = 
        ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr) 
         & (vlSelf->tb_peripheral__DOT__data_in >> 1U));
    vlSelf->tb_peripheral__DOT__dut__DOT__do_push = 
        ((~ ((2U == (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count)) 
             | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__stream_en))) 
         & ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr) 
            & vlSelf->tb_peripheral__DOT__data_in));
    vlSelf->tb_peripheral__DOT__dut__DOT__first_push_of_run 
        = ((~ ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__run_armed) 
               | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy))) 
           & (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__do_push));
}

void Vtb_peripheral___024root___eval_act(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_act\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_peripheral___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_peripheral___024root___nba_sequent__TOP__0(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__Vfuncout;
    __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__p;
    __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__p = 0;
    CData/*0:0*/ __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__Vfuncout;
    __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__Vfuncout = 0;
    CData/*0:0*/ __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__p;
    __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__p = 0;
    CData/*0:0*/ __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_lane__v0;
    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_lane__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_lane__v0;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_lane__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v0;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v1;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v1 = 0;
    CData/*0:0*/ __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_lane__v0;
    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_lane__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_lane__v0;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_lane__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v0;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v1;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v1 = 0;
    CData/*0:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr;
    __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr = 0;
    CData/*0:0*/ __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v0;
    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v0;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v0;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v0;
    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v0;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v1;
    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v1 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v1;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v1 = 0;
    CData/*0:0*/ __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v1;
    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v1 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v1;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v2;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v2 = 0;
    CData/*1:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count;
    __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count = 0;
    CData/*0:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__stream_en;
    __Vdly__tb_peripheral__DOT__dut__DOT__stream_en = 0;
    CData/*0:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse;
    __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse = 0;
    CData/*0:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr;
    __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr = 0;
    CData/*0:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy;
    __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy = 0;
    CData/*0:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started;
    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started = 0;
    CData/*1:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted;
    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted = 0;
    CData/*2:0*/ __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count;
    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v0;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v4 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v4 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v4 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v4;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v4 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v5 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v5;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v5 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v6 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v7 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v6 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v7 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v6 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v6;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v6 = 0;
    IData/*31:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v7 = 0;
    CData/*0:0*/ __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v7;
    __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v7 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v8;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v8 = 0;
    CData/*0:0*/ __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v8;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v8 = 0;
    // Body
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v0 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v1 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v0 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v1 = 0U;
    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count;
    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5 = 0U;
    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8 = 0U;
    __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy 
        = vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7 = 0U;
    __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse 
        = vlSelf->tb_peripheral__DOT__dut__DOT__start_pulse;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v8 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v8 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v0 = 0U;
    __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr = vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr;
    __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr = vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v0 = 0U;
    __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v2 = 0U;
    __Vdly__tb_peripheral__DOT__dut__DOT__stream_en 
        = vlSelf->tb_peripheral__DOT__dut__DOT__stream_en;
    __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count 
        = vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count;
    if (vlSelf->tb_peripheral__DOT__rst_n) {
        __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse = 0U;
        if (vlSelf->tb_peripheral__DOT__dut__DOT__sys_done) {
            __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr = 0U;
            __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr = 0U;
            __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count = 0U;
            __Vdly__tb_peripheral__DOT__dut__DOT__stream_en = 0U;
            vlSelf->tb_peripheral__DOT__dut__DOT__done_sticky = 1U;
        }
        if ((3U != (IData)(vlSelf->tb_peripheral__DOT__data_write_n))) {
            if ((2U > (IData)(vlSelf->tb_peripheral__DOT__address))) {
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_lane__v0 
                    = vlSelf->tb_peripheral__DOT__data_in;
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v0 = 1U;
                __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_lane__v0 
                    = (1U & (IData)(vlSelf->tb_peripheral__DOT__address));
            }
            if ((2U <= (IData)(vlSelf->tb_peripheral__DOT__address))) {
                if (((0x10U <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
                     & (0x12U > (IData)(vlSelf->tb_peripheral__DOT__address)))) {
                    __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_lane__v0 
                        = vlSelf->tb_peripheral__DOT__data_in;
                    __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v0 = 1U;
                    __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_lane__v0 
                        = (1U & (IData)(vlSelf->tb_peripheral__DOT__address));
                }
                if ((1U & (~ ((0x10U <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
                              & (0x12U > (IData)(vlSelf->tb_peripheral__DOT__address)))))) {
                    if ((0x20U == (IData)(vlSelf->tb_peripheral__DOT__address))) {
                        if ((2U & vlSelf->tb_peripheral__DOT__data_in)) {
                            __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr = 0U;
                            __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr = 0U;
                            __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count = 0U;
                            __Vdly__tb_peripheral__DOT__dut__DOT__stream_en = 0U;
                        }
                    }
                }
            }
        }
        if ((1U & ((~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__clr_req)) 
                   & (~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_done))))) {
            vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next 
                = vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count;
            if (vlSelf->tb_peripheral__DOT__dut__DOT__pop_beat) {
                __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__p 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr;
                __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__Vfuncout 
                    = (1U & ((~ (IData)(__Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__p)) 
                             & ((IData)(1U) + (IData)(__Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__p))));
                __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr 
                    = __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__52__Vfuncout;
                vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next 
                    = (vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next 
                       - (IData)(1U));
            }
            if (vlSelf->tb_peripheral__DOT__dut__DOT__do_push) {
                if (vlSelf->tb_peripheral__DOT__dut__DOT__first_push_of_run) {
                    __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse = 1U;
                }
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v0 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__a_lane
                    [0U];
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v0 = 1U;
                __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v0 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr;
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v0 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__b_lane
                    [0U];
                __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v0 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr;
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v1 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__a_lane
                    [1U];
                __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v1 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr;
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v1 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__b_lane
                    [1U];
                __Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v1 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr;
                __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__p 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr;
                __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__Vfuncout 
                    = (1U & ((~ (IData)(__Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__p)) 
                             & ((IData)(1U) + (IData)(__Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__p))));
                __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr 
                    = __Vfunc_tb_peripheral__DOT__dut__DOT__ptr_inc__53__Vfuncout;
                vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next 
                    = ((IData)(1U) + vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next);
            }
            if ((((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__run_armed) 
                  & (~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__stream_en))) 
                 & (2U == vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next))) {
                __Vdly__tb_peripheral__DOT__dut__DOT__stream_en = 1U;
            }
            __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count 
                = (3U & vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next);
        }
        if (vlSelf->tb_peripheral__DOT__dut__DOT__sys_done) {
            vlSelf->tb_peripheral__DOT__dut__DOT__run_armed = 0U;
        }
        if ((3U != (IData)(vlSelf->tb_peripheral__DOT__data_write_n))) {
            if ((2U <= (IData)(vlSelf->tb_peripheral__DOT__address))) {
                if ((1U & (~ ((0x10U <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
                              & (0x12U > (IData)(vlSelf->tb_peripheral__DOT__address)))))) {
                    if ((0x20U == (IData)(vlSelf->tb_peripheral__DOT__address))) {
                        if ((2U & vlSelf->tb_peripheral__DOT__data_in)) {
                            vlSelf->tb_peripheral__DOT__dut__DOT__done_sticky = 0U;
                            vlSelf->tb_peripheral__DOT__dut__DOT__run_armed = 0U;
                        }
                    }
                }
            }
        }
        if ((1U & ((~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__clr_req)) 
                   & (~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_done))))) {
            if (vlSelf->tb_peripheral__DOT__dut__DOT__do_push) {
                if (vlSelf->tb_peripheral__DOT__dut__DOT__first_push_of_run) {
                    vlSelf->tb_peripheral__DOT__dut__DOT__run_armed = 1U;
                }
            }
        }
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = 0U;
        if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid
            [1U][1U]) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = 1U;
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result 
                = ((IData)(VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                                         vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe
                                                         [1U]
                                                         [1U]), 
                                       VL_EXTENDS_QI(64,32, 
                                                     vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe
                                                     [1U]
                                                     [1U]))) 
                   + vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd
                   [1U][1U]);
        }
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = 0U;
        if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid
            [1U][0U]) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = 1U;
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result 
                = ((IData)(VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                                         vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe
                                                         [1U]
                                                         [0U]), 
                                       VL_EXTENDS_QI(64,32, 
                                                     vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe
                                                     [1U]
                                                     [0U]))) 
                   + vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd
                   [1U][0U]);
        }
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = 0U;
        if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid
            [0U][1U]) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = 1U;
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result 
                = ((IData)(VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                                         vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe
                                                         [0U]
                                                         [1U]), 
                                       VL_EXTENDS_QI(64,32, 
                                                     vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe
                                                     [0U]
                                                     [1U]))) 
                   + vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd
                   [0U][1U]);
        }
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = 0U;
        if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid
            [0U][0U]) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = 1U;
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result 
                = ((IData)(VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, 
                                                         vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe
                                                         [0U]
                                                         [0U]), 
                                       VL_EXTENDS_QI(64,32, 
                                                     vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe
                                                     [0U]
                                                     [0U]))) 
                   + vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd
                   [0U][0U]);
        }
        vlSelf->tb_peripheral__DOT__dut__DOT__sys_done = 0U;
        if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending) {
            vlSelf->tb_peripheral__DOT__dut__DOT__sys_done = 1U;
            __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy = 0U;
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending = 0U;
        }
        if (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__start_pulse) 
             & (~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy)))) {
            __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy = 1U;
            __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started = 0U;
            __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted = 0U;
            __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count = 0U;
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending = 0U;
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v0 = 1U;
        }
        if (vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) {
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew
                [0U][0U];
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4 = 1U;
            if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
                [0U][0U]) {
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
                    [0U][0U];
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4 = 1U;
            }
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew
                [0U][0U];
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4 = 1U;
            if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
                [0U][1U]) {
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
                    [0U][1U];
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5 = 1U;
            }
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew
                [1U][0U];
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5 = 1U;
            if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
                [1U][0U]) {
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
                    [1U][0U];
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6 = 1U;
            }
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew
                [1U][0U];
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5 = 1U;
            if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
                [1U][1U]) {
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
                    [1U][1U];
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7 = 1U;
            }
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew
                [0U][0U];
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4 = 1U;
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew
                [1U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew
                [1U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe
                [1U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe
                [1U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v4 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe
                [0U][1U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v5 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe
                [0U][1U];
            if (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__in_valid) 
                 & (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__in_ready))) {
                __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted 
                    = (3U & ((IData)(1U) + (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted)));
                if ((1U & (~ (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started)))) {
                    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started = 1U;
                    __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count = 0U;
                }
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_in_word
                    [0U];
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6 = 1U;
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v6 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_in_word
                    [0U];
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v7 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_in_word
                    [1U];
                __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v7 
                    = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_in_word
                    [1U];
            } else {
                __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8 = 1U;
            }
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew
                [0U][0U];
            __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6 = 1U;
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v6 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v7 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew
                [1U][1U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v7 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew
                [1U][1U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v6 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v6 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew
                [0U][0U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v7 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew
                [1U][1U];
            __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v7 
                = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew
                [1U][1U];
            if (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started) {
                __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count)));
                if ((5U == (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count))) {
                    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending = 1U;
                }
            }
        }
    } else {
        __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v1 = 1U;
        __Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v1 = 1U;
        __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse = 0U;
        __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr = 0U;
        __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr = 0U;
        __Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v2 = 1U;
        __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count = 0U;
        __Vdly__tb_peripheral__DOT__dut__DOT__stream_en = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__done_sticky = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__run_armed = 0U;
        __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started = 0U;
        __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted = 0U;
        __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count = 0U;
        __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v8 = 1U;
        __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__sys_done = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending = 0U;
        __Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v8 = 1U;
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr = __Vdly__tb_peripheral__DOT__dut__DOT__rd_ptr;
    vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr = __Vdly__tb_peripheral__DOT__dut__DOT__wr_ptr;
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__a_lane[__Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_lane__v0] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_lane__v0;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__a_lane__v1) {
        vlSelf->tb_peripheral__DOT__dut__DOT__a_lane[0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_lane[1U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__b_lane[__Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_lane__v0] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_lane__v0;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__b_lane__v1) {
        vlSelf->tb_peripheral__DOT__dut__DOT__b_lane[0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__b_lane[1U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[__Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v0][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v0;
        vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[__Vdlyvdim0__tb_peripheral__DOT__dut__DOT__b_fifo__v1][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__b_fifo__v1;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[__Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v0][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v0;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[__Vdlyvdim0__tb_peripheral__DOT__dut__DOT__a_fifo__v1][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__a_fifo__v1;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__a_fifo__v2) {
        vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[1U][1U] = 0U;
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count 
        = __Vdly__tb_peripheral__DOT__dut__DOT__fifo_count;
    vlSelf->tb_peripheral__DOT__dut__DOT__stream_en 
        = __Vdly__tb_peripheral__DOT__dut__DOT__stream_en;
    vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in 
        = (((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo
                            [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                            [1U])) << 0x20U) | (QData)((IData)(
                                                               vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo
                                                               [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                                                               [0U])));
    vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in 
        = (((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo
                            [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                            [1U])) << 0x20U) | (QData)((IData)(
                                                               vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo
                                                               [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                                                               [0U])));
    vlSelf->tb_peripheral__DOT__dut__DOT__start_pulse 
        = __Vdly__tb_peripheral__DOT__dut__DOT__start_pulse;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started 
        = __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count 
        = __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count;
    vlSelf->tb_peripheral__DOT__dut__DOT__in_valid 
        = ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__stream_en) 
           & (0U != (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count)));
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_in_word[0U] 
        = (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_in_word[1U] 
        = (IData)((vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in 
                   >> 0x20U));
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_in_word[0U] 
        = (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_in_word[1U] 
        = (IData)((vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in 
                   >> 0x20U));
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted 
        = __Vdly__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted;
    vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy 
        = __Vdly__tb_peripheral__DOT__dut__DOT__sys_busy;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[0U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[0U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[1U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[1U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[0U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[0U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[1U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[1U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result;
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[1U][1U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v4;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew__v5;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v4;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v5;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v4;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v5;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v4;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v5;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v4;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v5;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v4;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v5;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][0U] = 1U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][0U] = 1U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v4;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew__v5;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][0U] = 1U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][0U] = 1U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v6;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew__v7;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][0U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v6;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe__v7;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v6;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v7;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v6;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe__v7;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v6;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe__v7;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][0U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v8) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][0U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v4;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v5;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v6;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v7;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew__v8) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][0U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe__v8) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[0U][0U] = 0U;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[0U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v4;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[0U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v5;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[1U][0U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v6;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[1U][1U] 
            = __Vdlyvval__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v7;
    }
    if (__Vdlyvset__tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc__v8) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[1U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[0U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[0U][1U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[1U][0U] = 0U;
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[1U][1U] = 0U;
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__in_ready 
        = ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
           & (2U > (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted)));
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid[0U][0U] 
        = (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
            & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe
            [0U][0U]) & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe
           [0U][0U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid[0U][1U] 
        = (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
            & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe
            [0U][1U]) & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe
           [0U][1U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid[1U][0U] 
        = (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
            & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe
            [1U][0U]) & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe
           [1U][0U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid[1U][1U] 
        = (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
            & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe
            [1U][1U]) & vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe
           [1U][1U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd[0U][0U] 
        = (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
           [0U][0U] ? vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
           [0U][0U] : vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
           [0U][0U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd[0U][1U] 
        = (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
           [0U][1U] ? vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
           [0U][1U] : vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
           [0U][1U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd[1U][0U] 
        = (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
           [1U][0U] ? vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
           [1U][0U] : vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
           [1U][0U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd[1U][1U] 
        = (vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done
           [1U][1U] ? vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result
           [1U][1U] : vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
           [1U][1U]);
    vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[0U] 
        = (IData)((((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                    [0U][1U])) << 0x20U) 
                   | (QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                     [0U][0U]))));
    vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[1U] 
        = (IData)(((((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                     [0U][1U])) << 0x20U) 
                    | (QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                      [0U][0U]))) >> 0x20U));
    vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[2U] 
        = (IData)((((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                    [1U][1U])) << 0x20U) 
                   | (QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                     [1U][0U]))));
    vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[3U] 
        = (IData)(((((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                     [1U][1U])) << 0x20U) 
                    | (QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc
                                      [1U][0U]))) >> 0x20U));
    vlSelf->tb_peripheral__DOT__dut__DOT__pop_beat 
        = ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__in_valid) 
           & (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__in_ready));
}

VL_INLINE_OPT void Vtb_peripheral___024root___nba_sequent__TOP__1(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr = 
        ((3U != (IData)(vlSelf->tb_peripheral__DOT__data_write_n)) 
         & (0x20U == (IData)(vlSelf->tb_peripheral__DOT__address)));
    vlSelf->tb_peripheral__DOT__dut__DOT__clr_req = 
        ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr) 
         & (vlSelf->tb_peripheral__DOT__data_in >> 1U));
}

VL_INLINE_OPT void Vtb_peripheral___024root___nba_comb__TOP__0(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___nba_comb__TOP__0\n"); );
    // Init
    IData/*31:0*/ tb_peripheral__DOT__dut__DOT__c_word;
    tb_peripheral__DOT__dut__DOT__c_word = 0;
    IData/*31:0*/ tb_peripheral__DOT__dut__DOT__idx;
    tb_peripheral__DOT__dut__DOT__idx = 0;
    // Body
    tb_peripheral__DOT__dut__DOT__c_word = 0U;
    tb_peripheral__DOT__dut__DOT__idx = 0U;
    if (((0x30U <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
         & (0x34U > (IData)(vlSelf->tb_peripheral__DOT__address)))) {
        tb_peripheral__DOT__dut__DOT__idx = ((IData)(vlSelf->tb_peripheral__DOT__address) 
                                             - (IData)(0x30U));
        tb_peripheral__DOT__dut__DOT__c_word = (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx)))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[
                                                  (((IData)(0x1fU) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx))))) 
                                                | (vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out[
                                                   (3U 
                                                    & (VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & VL_MULS_III(32, (IData)(0x20U), tb_peripheral__DOT__dut__DOT__idx))));
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__do_push = 
        ((~ ((2U == (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count)) 
             | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__stream_en))) 
         & ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr) 
            & vlSelf->tb_peripheral__DOT__data_in));
    vlSelf->tb_peripheral__DOT__data_out = ((0x21U 
                                             == (IData)(vlSelf->tb_peripheral__DOT__address))
                                             ? (((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
                                                 << 1U) 
                                                | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__done_sticky))
                                             : (((0x30U 
                                                  <= (IData)(vlSelf->tb_peripheral__DOT__address)) 
                                                 & (0x34U 
                                                    > (IData)(vlSelf->tb_peripheral__DOT__address)))
                                                 ? tb_peripheral__DOT__dut__DOT__c_word
                                                 : 0U));
    vlSelf->tb_peripheral__DOT__dut__DOT__first_push_of_run 
        = ((~ ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__run_armed) 
               | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy))) 
           & (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__do_push));
}

void Vtb_peripheral___024root___eval_nba(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_peripheral___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_peripheral___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_peripheral___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtb_peripheral___024root___timing_resume(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h90828fb9__0.resume("@(negedge tb_peripheral.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_peripheral___024root___timing_commit(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h90828fb9__0.commit("@(negedge tb_peripheral.clk)");
    }
}

void Vtb_peripheral___024root___eval_triggers__act(Vtb_peripheral___024root* vlSelf);

bool Vtb_peripheral___024root___eval_phase__act(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_peripheral___024root___eval_triggers__act(vlSelf);
    Vtb_peripheral___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_peripheral___024root___timing_resume(vlSelf);
        Vtb_peripheral___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_peripheral___024root___eval_phase__nba(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_peripheral___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__nba(Vtb_peripheral___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__act(Vtb_peripheral___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_peripheral___024root___eval(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_peripheral___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("dp1/testbench/tb_peripheral.sv", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_peripheral___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("dp1/testbench/tb_peripheral.sv", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_peripheral___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_peripheral___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_peripheral___024root___eval_debug_assertions(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
