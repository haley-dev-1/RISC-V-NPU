// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_peripheral.h for the primary calling header

#include "Vtb_peripheral__pch.h"
#include "Vtb_peripheral__Syms.h"
#include "Vtb_peripheral___024root.h"

VlCoroutine Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0__1(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_initial__TOP__Vtiming__0__1\n"); );
    // Init
    IData/*31:0*/ tb_peripheral__DOT__cycles;
    tb_peripheral__DOT__cycles = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y = 0;
    IData/*31:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s = 0;
    QData/*63:0*/ __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    __Vtask_tb_peripheral__DOT__mmio_read__48__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    __Vtask_tb_peripheral__DOT__mmio_read__49__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    __Vtask_tb_peripheral__DOT__mmio_read__50__val = 0;
    CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0;
    IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    __Vtask_tb_peripheral__DOT__mmio_read__51__val = 0;
    // Body
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel17;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel17: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel18;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel18: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel19;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel19: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel20;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel20: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel21;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel21: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel22;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel22: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel23;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel23: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel24;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel24: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel25;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel25: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00 
        = VL_RANDOM_I();
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00 
        = VL_RANDOM_I();
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__28__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__29__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__30__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__31__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B00;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__32__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__33__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in = 0U;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B01;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A10;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__34__Vfuncout;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__t0;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__B11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__A11;
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__x), 
                      VL_EXTENDS_QI(64,32, __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__y));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s 
        = (__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__prod_s 
           + (((QData)((IData)((- (IData)((__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in 
                                           >> 0x1fU))))) 
               << 0x20U) | (QData)((IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__acc_in))));
    __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout 
        = (IData)(__Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__sum_s);
    __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11 
        = __Vfunc_tb_peripheral__DOT__mac_wrap32_signed__35__Vfuncout;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C00;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C01;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C10;
    vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11 
        = __Vtask_tb_peripheral__DOT__compute_expected_2x2__27__C11;
    __Vtask_tb_peripheral__DOT__mmio_write__36__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A00;
    __Vtask_tb_peripheral__DOT__mmio_write__36__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__36__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__36__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__37__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A10;
    __Vtask_tb_peripheral__DOT__mmio_write__37__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__37__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__37__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__38__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B00;
    __Vtask_tb_peripheral__DOT__mmio_write__38__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__38__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__38__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__39__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B01;
    __Vtask_tb_peripheral__DOT__mmio_write__39__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__39__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__39__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__val = 2U;
    __Vtask_tb_peripheral__DOT__mmio_write__40__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__40__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__40__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__41__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__41__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__41__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__42__val 
        = __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A01;
    __Vtask_tb_peripheral__DOT__mmio_write__42__addr = 0U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__42__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__42__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__43__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
    __Vtask_tb_peripheral__DOT__mmio_write__43__addr = 1U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__43__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__43__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__44__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
    __Vtask_tb_peripheral__DOT__mmio_write__44__addr = 0x10U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__44__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__44__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__45__val 
        = vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
    __Vtask_tb_peripheral__DOT__mmio_write__45__addr = 0x11U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__45__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__45__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__val = 1U;
    __Vtask_tb_peripheral__DOT__mmio_write__46__addr = 0x20U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       49);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_write__46__addr;
    vlSelf->tb_peripheral__DOT__data_in = __Vtask_tb_peripheral__DOT__mmio_write__46__val;
    vlSelf->tb_peripheral__DOT__data_write_n = 2U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       54);
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    vlSelf->tb_peripheral__DOT__data_in = 0U;
    tb_peripheral__DOT__cycles = 0U;
    {
        while (1U) {
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr = 0x21U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               62);
            vlSelf->tb_peripheral__DOT__address = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__addr;
            vlSelf->tb_peripheral__DOT__data_write_n = 3U;
            co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(negedge tb_peripheral.clk)", 
                                                               "dp1/testbench/tb_peripheral.sv", 
                                                               66);
            vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val 
                = vlSelf->tb_peripheral__DOT__data_out;
            vlSelf->tb_peripheral__DOT__rdata = vlSelf->__Vtask_tb_peripheral__DOT__mmio_read__47__val;
            if ((1U & vlSelf->tb_peripheral__DOT__rdata)) {
                goto __Vlabel26;
            }
            tb_peripheral__DOT__cycles = ((IData)(1U) 
                                          + tb_peripheral__DOT__cycles);
            if (VL_UNLIKELY(VL_LTS_III(32, 0x190U, tb_peripheral__DOT__cycles))) {
                VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:156: Assertion failed in %Ntb_peripheral.run_one_case_2x2: Timeout waiting for DONE\n",
                          64,VL_TIME_UNITED_Q(1000),
                          -9,vlSymsp->name());
                VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 156, "");
            }
        }
        __Vlabel26: ;
    }
    __Vtask_tb_peripheral__DOT__mmio_read__48__addr = 0x30U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__48__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__48__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__48__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:160: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C00 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 160, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__49__addr = 0x31U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__49__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__49__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__49__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:161: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C01 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 161, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__50__addr = 0x32U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__50__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__50__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__50__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:162: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C10 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 162, "");
    }
    __Vtask_tb_peripheral__DOT__mmio_read__51__addr = 0x33U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       62);
    vlSelf->tb_peripheral__DOT__address = __Vtask_tb_peripheral__DOT__mmio_read__51__addr;
    vlSelf->tb_peripheral__DOT__data_write_n = 3U;
    co_await vlSelf->__VtrigSched_h90828fb9__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_peripheral.clk)", 
                                                       "dp1/testbench/tb_peripheral.sv", 
                                                       66);
    __Vtask_tb_peripheral__DOT__mmio_read__51__val 
        = vlSelf->tb_peripheral__DOT__data_out;
    __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
        = __Vtask_tb_peripheral__DOT__mmio_read__51__val;
    if (VL_UNLIKELY((__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got 
                     != vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11))) {
        VL_WRITEF("[%0t] %%Fatal: tb_peripheral.sv:163: Assertion failed in %Ntb_peripheral.run_one_case_2x2: C11 mismatch exp=%x got=%x\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11,
                  32,__Vtask_tb_peripheral__DOT__run_one_case_2x2__26__got);
        VL_STOP_MT("dp1/testbench/tb_peripheral.sv", 163, "");
    }
    VL_WRITEF("PASS: Peripheral MMIO systolic tests passed.\n");
    VL_FINISH_MT("dp1/testbench/tb_peripheral.sv", 200, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_peripheral___024root___dump_triggers__act(Vtb_peripheral___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_peripheral___024root___eval_triggers__act(Vtb_peripheral___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_peripheral__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_peripheral___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_peripheral__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_peripheral__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, ((~ (IData)(vlSelf->tb_peripheral__DOT__clk)) 
                                     & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_peripheral__DOT__clk__0)));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_peripheral__DOT__clk__0 
        = vlSelf->tb_peripheral__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_peripheral___024root___dump_triggers__act(vlSelf);
    }
#endif
}
