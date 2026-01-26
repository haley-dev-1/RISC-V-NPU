// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_peripheral.h for the primary calling header

#include "Vtb_peripheral__pch.h"
#include "Vtb_peripheral___024root.h"

VL_ATTR_COLD void Vtb_peripheral___024root___eval_static__TOP(Vtb_peripheral___024root* vlSelf);

VL_ATTR_COLD void Vtb_peripheral___024root___eval_static(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_static\n"); );
    // Body
    Vtb_peripheral___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_peripheral___024root___eval_static__TOP(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_peripheral__DOT__clk = 0U;
    vlSelf->tb_peripheral__DOT__rst_n = 0U;
}

VL_ATTR_COLD void Vtb_peripheral___024root___eval_final(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__stl(Vtb_peripheral___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_peripheral___024root___eval_phase__stl(Vtb_peripheral___024root* vlSelf);

VL_ATTR_COLD void Vtb_peripheral___024root___eval_settle(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_settle\n"); );
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
            Vtb_peripheral___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("dp1/testbench/tb_peripheral.sv", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_peripheral___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__stl(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_peripheral___024root___stl_sequent__TOP__0(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ tb_peripheral__DOT__dut__DOT__c_word;
    tb_peripheral__DOT__dut__DOT__c_word = 0;
    IData/*31:0*/ tb_peripheral__DOT__dut__DOT__idx;
    tb_peripheral__DOT__dut__DOT__idx = 0;
    // Body
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
    vlSelf->tb_peripheral__DOT__dut__DOT__in_valid 
        = ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__stream_en) 
           & (0U != (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count)));
    vlSelf->tb_peripheral__DOT__dut__DOT__in_ready 
        = ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy) 
           & (2U > (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted)));
    vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in 
        = ((0xffffffff00000000ULL & vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in) 
           | (IData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo
                             [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                             [0U])));
    vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in 
        = ((0xffffffff00000000ULL & vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in) 
           | (IData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo
                             [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                             [0U])));
    vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in 
        = ((0xffffffffULL & vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in) 
           | ((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo
                              [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                              [1U])) << 0x20U));
    vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in 
        = ((0xffffffffULL & vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in) 
           | ((QData)((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo
                              [vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr]
                              [1U])) << 0x20U));
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
    vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr = 
        ((3U != (IData)(vlSelf->tb_peripheral__DOT__data_write_n)) 
         & (0x20U == (IData)(vlSelf->tb_peripheral__DOT__address)));
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[0U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[0U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[0U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[0U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[1U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[1U][0U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[1U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done;
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[1U][1U] 
        = vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result;
    vlSelf->tb_peripheral__DOT__dut__DOT__pop_beat 
        = ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__in_valid) 
           & (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__in_ready));
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
    vlSelf->tb_peripheral__DOT__dut__DOT__clr_req = 
        ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr) 
         & (vlSelf->tb_peripheral__DOT__data_in >> 1U));
    vlSelf->tb_peripheral__DOT__dut__DOT__do_push = 
        ((~ ((2U == (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count)) 
             | (IData)(vlSelf->tb_peripheral__DOT__dut__DOT__stream_en))) 
         & ((IData)(vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr) 
            & vlSelf->tb_peripheral__DOT__data_in));
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

VL_ATTR_COLD void Vtb_peripheral___024root___eval_stl(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_peripheral___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_peripheral___024root___eval_triggers__stl(Vtb_peripheral___024root* vlSelf);

VL_ATTR_COLD bool Vtb_peripheral___024root___eval_phase__stl(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_peripheral___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_peripheral___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__act(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_peripheral.clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_peripheral.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__nba(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_peripheral.clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_peripheral.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_peripheral___024root___ctor_var_reset(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_peripheral__DOT__rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_peripheral__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__address = VL_RAND_RESET_I(6);
    vlSelf->tb_peripheral__DOT__data_in = VL_RAND_RESET_I(32);
    vlSelf->tb_peripheral__DOT__data_write_n = VL_RAND_RESET_I(2);
    vlSelf->tb_peripheral__DOT__data_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__a_lane[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__b_lane[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__a_fifo[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__b_fifo[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__fifo_count = VL_RAND_RESET_I(2);
    vlSelf->tb_peripheral__DOT__dut__DOT__rd_ptr = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__wr_ptr = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__run_armed = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__stream_en = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__start_pulse = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__done_sticky = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__in_ready = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__sys_busy = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__sys_done = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__a_vec_in = VL_RAND_RESET_Q(64);
    vlSelf->tb_peripheral__DOT__dut__DOT__b_vec_in = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(128, vlSelf->tb_peripheral__DOT__dut__DOT__c_mat_out);
    vlSelf->tb_peripheral__DOT__dut__DOT__in_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__ctrl_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__clr_req = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__pop_beat = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__do_push = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__first_push_of_run = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted = VL_RAND_RESET_I(2);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_in_word[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_in_word[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count = VL_RAND_RESET_I(3);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result = VL_RAND_RESET_I(32);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result = VL_RAND_RESET_I(32);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result = VL_RAND_RESET_I(32);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done = VL_RAND_RESET_I(1);
    vlSelf->tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 = VL_RAND_RESET_I(32);
    vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = VL_RAND_RESET_I(6);
    vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__tb_peripheral__DOT__clk__0 = VL_RAND_RESET_I(1);
}
