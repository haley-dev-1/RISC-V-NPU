// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fsm.h for the primary calling header

#include "Vtb_fsm__pch.h"
#include "Vtb_fsm__Syms.h"
#include "Vtb_fsm___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_fsm___024root___eval_initial__TOP__Vtiming__0(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb_fsm__DOT__guard;
    tb_fsm__DOT__guard = 0;
    IData/*31:0*/ tb_fsm__DOT__old_clear;
    tb_fsm__DOT__old_clear = 0;
    IData/*31:0*/ tb_fsm__DOT__old_start;
    tb_fsm__DOT__old_start = 0;
    IData/*31:0*/ tb_fsm__DOT____Vrepeat2;
    tb_fsm__DOT____Vrepeat2 = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__4__n;
    __Vtask_tb_fsm__DOT__wait_cycles__4__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__5__n;
    __Vtask_tb_fsm__DOT__wait_cycles__5__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__6__n;
    __Vtask_tb_fsm__DOT__wait_cycles__6__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__8__n;
    __Vtask_tb_fsm__DOT__wait_cycles__8__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__12__n;
    __Vtask_tb_fsm__DOT__wait_cycles__12__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__17__n;
    __Vtask_tb_fsm__DOT__wait_cycles__17__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__21__n;
    __Vtask_tb_fsm__DOT__wait_cycles__21__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__22__n;
    __Vtask_tb_fsm__DOT__wait_cycles__22__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__23__n;
    __Vtask_tb_fsm__DOT__wait_cycles__23__n = 0;
    IData/*31:0*/ __Vtask_tb_fsm__DOT__wait_cycles__26__n;
    __Vtask_tb_fsm__DOT__wait_cycles__26__n = 0;
    // Body
    VL_WRITEF("tb_fsm starting...\n");
    vlSelf->tb_fsm__DOT__cfg_start = 0U;
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    vlSelf->tb_fsm__DOT__cfg_len_bytes = 0x40U;
    vlSelf->tb_fsm__DOT__inject_sa_error = 0U;
    vlSelf->tb_fsm__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       226);
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       226);
    vlSelf->tb_fsm__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       228);
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       228);
    VL_WRITEF("\n[TEST] happy path: clear->start->done sticky\n");
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       235);
    vlSelf->tb_fsm__DOT__cfg_start = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       237);
    vlSelf->tb_fsm__DOT__cfg_start = 0U;
    __Vtask_tb_fsm__DOT__wait_cycles__4__n = 1U;
    tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__4__n;
    while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_fsm.clk)", 
                                                           "dp1/testbench/tb_fsm.sv", 
                                                           253);
        tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                   - (IData)(1U));
    }
    if (VL_UNLIKELY((1U & (~ (((0U != (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state)) 
                               & (9U != (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))) 
                              & (0xaU != (IData)(vlSelf->tb_fsm__DOT__dut__DOT__state))))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:291: Assertion failed in %Ntb_fsm.test_happy_path: Expected sts_busy=1 shortly after start\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 291, "");
    }
    tb_fsm__DOT__guard = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__sts_done)))) {
        __Vtask_tb_fsm__DOT__wait_cycles__5__n = 1U;
        tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__5__n;
        while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
            co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_fsm.clk)", 
                                                               "dp1/testbench/tb_fsm.sv", 
                                                               253);
            tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                       - (IData)(1U));
        }
        tb_fsm__DOT__guard = ((IData)(1U) + tb_fsm__DOT__guard);
        if (VL_UNLIKELY((0x32U < tb_fsm__DOT__guard))) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:298: Assertion failed in %Ntb_fsm.test_happy_path: Timeout waiting for sts_done\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 298, "");
        }
    }
    if (VL_UNLIKELY(vlSelf->tb_fsm__DOT__sts_error)) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:301: Assertion failed in %Ntb_fsm.test_happy_path: Did not expect sts_error on happy path\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 301, "");
    }
    if (VL_UNLIKELY((0U != (IData)(vlSelf->tb_fsm__DOT__sts_errcode)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:302: Assertion failed in %Ntb_fsm.test_happy_path: Expected errcode=0, got %0#\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  8,(IData)(vlSelf->tb_fsm__DOT__sts_errcode));
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 302, "");
    }
    if (VL_UNLIKELY((1U != vlSelf->tb_fsm__DOT__clear_pulses))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:305: Assertion failed in %Ntb_fsm.test_happy_path: Expected exactly 1 sa_clear pulse, got %0d\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->tb_fsm__DOT__clear_pulses);
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 305, "");
    }
    if (VL_UNLIKELY((1U != vlSelf->tb_fsm__DOT__start_pulses))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:306: Assertion failed in %Ntb_fsm.test_happy_path: Expected exactly 1 sa_start pulse, got %0d\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->tb_fsm__DOT__start_pulses);
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 306, "");
    }
    __Vtask_tb_fsm__DOT__wait_cycles__6__n = 3U;
    tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__6__n;
    while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_fsm.clk)", 
                                                           "dp1/testbench/tb_fsm.sv", 
                                                           253);
        tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                   - (IData)(1U));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_fsm__DOT__sts_done))))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:310: Assertion failed in %Ntb_fsm.test_happy_path: Expected sts_done to remain sticky\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 310, "");
    }
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    __Vtask_tb_fsm__DOT__wait_cycles__8__n = 1U;
    tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__8__n;
    while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_fsm.clk)", 
                                                           "dp1/testbench/tb_fsm.sv", 
                                                           253);
        tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                   - (IData)(1U));
    }
    if (VL_UNLIKELY(((IData)(vlSelf->tb_fsm__DOT__sts_done) 
                     | (IData)(vlSelf->tb_fsm__DOT__sts_error)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:314: Assertion failed in %Ntb_fsm.test_happy_path: Expected sts_done/sts_error cleared by cfg_clr_status\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 314, "");
    }
    VL_WRITEF("[PASS] happy path\n");
    VL_WRITEF("\n[TEST] zero length -> error (errcode=1)\n");
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    vlSelf->tb_fsm__DOT__cfg_len_bytes = 0U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       235);
    vlSelf->tb_fsm__DOT__cfg_start = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       237);
    vlSelf->tb_fsm__DOT__cfg_start = 0U;
    tb_fsm__DOT__guard = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__sts_error)))) {
        __Vtask_tb_fsm__DOT__wait_cycles__12__n = 1U;
        tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__12__n;
        while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
            co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_fsm.clk)", 
                                                               "dp1/testbench/tb_fsm.sv", 
                                                               253);
            tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                       - (IData)(1U));
        }
        tb_fsm__DOT__guard = ((IData)(1U) + tb_fsm__DOT__guard);
        if (VL_UNLIKELY((0x14U < tb_fsm__DOT__guard))) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:333: Assertion failed in %Ntb_fsm.test_zero_len_error: Timeout waiting for sts_error\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 333, "");
        }
    }
    if (VL_UNLIKELY((1U != (IData)(vlSelf->tb_fsm__DOT__sts_errcode)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:336: Assertion failed in %Ntb_fsm.test_zero_len_error: Expected errcode=1, got %0#\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  8,(IData)(vlSelf->tb_fsm__DOT__sts_errcode));
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 336, "");
    }
    if (VL_UNLIKELY((0U != vlSelf->tb_fsm__DOT__start_pulses))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:339: Assertion failed in %Ntb_fsm.test_zero_len_error: Expected no sa_start pulse on validate error\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 339, "");
    }
    if (VL_UNLIKELY((0U != vlSelf->tb_fsm__DOT__clear_pulses))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:340: Assertion failed in %Ntb_fsm.test_zero_len_error: Expected no sa_clear pulse on validate error\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 340, "");
    }
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    vlSelf->tb_fsm__DOT__cfg_len_bytes = 0x40U;
    VL_WRITEF("[PASS] zero length error\n");
    VL_WRITEF("\n[TEST] sa_error -> error sticky (errcode=3)\n");
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    vlSelf->tb_fsm__DOT__inject_sa_error = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       235);
    vlSelf->tb_fsm__DOT__cfg_start = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       237);
    vlSelf->tb_fsm__DOT__cfg_start = 0U;
    tb_fsm__DOT__guard = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__sts_error)))) {
        __Vtask_tb_fsm__DOT__wait_cycles__17__n = 1U;
        tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__17__n;
        while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
            co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_fsm.clk)", 
                                                               "dp1/testbench/tb_fsm.sv", 
                                                               253);
            tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                       - (IData)(1U));
        }
        tb_fsm__DOT__guard = ((IData)(1U) + tb_fsm__DOT__guard);
        if (VL_UNLIKELY((0x32U < tb_fsm__DOT__guard))) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:361: Assertion failed in %Ntb_fsm.test_sa_error_path: Timeout waiting for sts_error\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 361, "");
        }
    }
    if (VL_UNLIKELY((3U != (IData)(vlSelf->tb_fsm__DOT__sts_errcode)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:364: Assertion failed in %Ntb_fsm.test_sa_error_path: Expected errcode=3, got %0#\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  8,(IData)(vlSelf->tb_fsm__DOT__sts_errcode));
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 364, "");
    }
    if (VL_UNLIKELY((1U != vlSelf->tb_fsm__DOT__clear_pulses))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:367: Assertion failed in %Ntb_fsm.test_sa_error_path: Expected 1 sa_clear pulse, got %0d\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->tb_fsm__DOT__clear_pulses);
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 367, "");
    }
    if (VL_UNLIKELY((1U != vlSelf->tb_fsm__DOT__start_pulses))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:368: Assertion failed in %Ntb_fsm.test_sa_error_path: Expected 1 sa_start pulse, got %0d\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  32,vlSelf->tb_fsm__DOT__start_pulses);
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 368, "");
    }
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    vlSelf->tb_fsm__DOT__inject_sa_error = 0U;
    VL_WRITEF("[PASS] sa_error path\n");
    VL_WRITEF("\n[TEST] start held high should not retrigger\n");
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       384);
    vlSelf->tb_fsm__DOT__cfg_start = 1U;
    tb_fsm__DOT__guard = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__sts_done)))) {
        __Vtask_tb_fsm__DOT__wait_cycles__21__n = 1U;
        tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__21__n;
        while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
            co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_fsm.clk)", 
                                                               "dp1/testbench/tb_fsm.sv", 
                                                               253);
            tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                       - (IData)(1U));
        }
        tb_fsm__DOT__guard = ((IData)(1U) + tb_fsm__DOT__guard);
        if (VL_UNLIKELY((0x50U < tb_fsm__DOT__guard))) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:392: Assertion failed in %Ntb_fsm.test_start_held_high_no_retrigger: Timeout waiting for sts_done with start held high\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 392, "");
        }
    }
    tb_fsm__DOT__old_clear = vlSelf->tb_fsm__DOT__clear_pulses;
    tb_fsm__DOT__old_start = vlSelf->tb_fsm__DOT__start_pulses;
    __Vtask_tb_fsm__DOT__wait_cycles__22__n = 0xaU;
    tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__22__n;
    while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_fsm.clk)", 
                                                           "dp1/testbench/tb_fsm.sv", 
                                                           253);
        tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                   - (IData)(1U));
    }
    if (VL_UNLIKELY(((vlSelf->tb_fsm__DOT__clear_pulses 
                      != tb_fsm__DOT__old_clear) | 
                     (vlSelf->tb_fsm__DOT__start_pulses 
                      != tb_fsm__DOT__old_start)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:400: Assertion failed in %Ntb_fsm.test_start_held_high_no_retrigger: Detected retrigger while cfg_start held high\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 400, "");
    }
    vlSelf->tb_fsm__DOT__cfg_start = 0U;
    __Vtask_tb_fsm__DOT__wait_cycles__23__n = 2U;
    tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__23__n;
    while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_fsm.clk)", 
                                                           "dp1/testbench/tb_fsm.sv", 
                                                           253);
        tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                   - (IData)(1U));
    }
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       244);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       246);
    vlSelf->tb_fsm__DOT__cfg_clr_status = 0U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       235);
    vlSelf->tb_fsm__DOT__cfg_start = 1U;
    co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_fsm.clk)", 
                                                       "dp1/testbench/tb_fsm.sv", 
                                                       237);
    vlSelf->tb_fsm__DOT__cfg_start = 0U;
    tb_fsm__DOT__guard = 0U;
    while ((1U & (~ (IData)(vlSelf->tb_fsm__DOT__sts_done)))) {
        __Vtask_tb_fsm__DOT__wait_cycles__26__n = 1U;
        tb_fsm__DOT____Vrepeat2 = __Vtask_tb_fsm__DOT__wait_cycles__26__n;
        while (VL_LTS_III(32, 0U, tb_fsm__DOT____Vrepeat2)) {
            co_await vlSelf->__VtrigSched_ha9d4021f__0.trigger(0U, 
                                                               nullptr, 
                                                               "@(posedge tb_fsm.clk)", 
                                                               "dp1/testbench/tb_fsm.sv", 
                                                               253);
            tb_fsm__DOT____Vrepeat2 = (tb_fsm__DOT____Vrepeat2 
                                       - (IData)(1U));
        }
        tb_fsm__DOT__guard = ((IData)(1U) + tb_fsm__DOT__guard);
        if (VL_UNLIKELY((0x50U < tb_fsm__DOT__guard))) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:412: Assertion failed in %Ntb_fsm.test_start_held_high_no_retrigger: Timeout waiting for second sts_done\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 412, "");
        }
    }
    if (VL_UNLIKELY(((1U != vlSelf->tb_fsm__DOT__clear_pulses) 
                     | (1U != vlSelf->tb_fsm__DOT__start_pulses)))) {
        VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:416: Assertion failed in %Ntb_fsm.test_start_held_high_no_retrigger: Expected exactly 1 clear/start pulse in second epoch (after clr_status)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("dp1/testbench/tb_fsm.sv", 416, "");
    }
    VL_WRITEF("[PASS] start held high no retrigger\n\nALL FSM TESTS PASSED\n");
    VL_FINISH_MT("dp1/testbench/tb_fsm.sv", 439, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fsm___024root___dump_triggers__act(Vtb_fsm___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_fsm___024root___eval_triggers__act(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_fsm__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->tb_fsm__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__clk__0))) 
                                     | ((~ (IData)(vlSelf->tb_fsm__DOT__rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__rst_n__0))));
    vlSelf->__VactTriggered.set(2U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__clk__0 
        = vlSelf->tb_fsm__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_fsm__DOT__rst_n__0 
        = vlSelf->tb_fsm__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fsm___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_fsm___024root___nba_sequent__TOP__0(Vtb_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fsm___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->tb_fsm__DOT__rst_n) {
        if (VL_UNLIKELY(vlSelf->tb_fsm__DOT__in_dma_start)) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:87: Assertion failed in %Ntb_fsm: ERROR: in_dma_start pulsed even though USE_DMA=0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 87, "");
        }
        if (VL_UNLIKELY(vlSelf->tb_fsm__DOT__out_dma_start)) {
            VL_WRITEF("[%0t] %%Fatal: tb_fsm.sv:88: Assertion failed in %Ntb_fsm: ERROR: out_dma_start pulsed even though USE_DMA=0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("dp1/testbench/tb_fsm.sv", 88, "");
        }
    }
}
