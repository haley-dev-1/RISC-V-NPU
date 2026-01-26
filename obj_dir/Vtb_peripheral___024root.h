// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_peripheral.h for the primary calling header

#ifndef VERILATED_VTB_PERIPHERAL___024ROOT_H_
#define VERILATED_VTB_PERIPHERAL___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_peripheral__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_peripheral___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_peripheral__DOT__clk;
        CData/*0:0*/ tb_peripheral__DOT__rst_n;
        CData/*5:0*/ tb_peripheral__DOT__address;
        CData/*1:0*/ tb_peripheral__DOT__data_write_n;
        CData/*1:0*/ tb_peripheral__DOT__dut__DOT__fifo_count;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__rd_ptr;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__wr_ptr;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__run_armed;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__stream_en;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__start_pulse;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__done_sticky;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__in_ready;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__sys_busy;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__sys_done;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__in_valid;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__ctrl_wr;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__clr_req;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__pop_beat;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__do_push;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__first_push_of_run;
        CData/*1:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT__beats_accepted;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT__started;
        CData/*2:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT__cycle_count;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT__done_pending;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__done;
        CData/*0:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__done;
        CData/*5:0*/ __Vtask_tb_peripheral__DOT__mmio_read__47__addr;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_peripheral__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ tb_peripheral__DOT__rdata;
        IData/*31:0*/ tb_peripheral__DOT__data_in;
        IData/*31:0*/ tb_peripheral__DOT__data_out;
        VlWide<4>/*127:0*/ tb_peripheral__DOT__dut__DOT__c_mat_out;
        IData/*31:0*/ tb_peripheral__DOT__dut__DOT__FIFO_UPDATE__DOT__count_next;
        IData/*31:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result;
        IData/*31:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__0__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result;
        IData/*31:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__0__KET____DOT__u_mac__result;
        IData/*31:0*/ tb_peripheral__DOT__dut__DOT__u_systolic__DOT____Vcellout__GEN_ROW__BRA__1__KET____DOT__GEN_COL__BRA__1__KET____DOT__u_mac__result;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__A11;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B10;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__B11;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC00;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC01;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC10;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__run_one_case_2x2__26__expC11;
        IData/*31:0*/ __Vtask_tb_peripheral__DOT__mmio_read__47__val;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_peripheral__DOT__dut__DOT__a_vec_in;
        QData/*63:0*/ tb_peripheral__DOT__dut__DOT__b_vec_in;
        VlUnpacked<IData/*31:0*/, 2> tb_peripheral__DOT__dut__DOT__a_lane;
        VlUnpacked<IData/*31:0*/, 2> tb_peripheral__DOT__dut__DOT__b_lane;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__a_fifo;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__b_fifo;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_pipe;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vpipe;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_pipe;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vpipe;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_result;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_done;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__mac_valid;
    };
    struct {
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__acc_fwd;
        VlUnpacked<IData/*31:0*/, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_in_word;
        VlUnpacked<IData/*31:0*/, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_in_word;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_skew;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__a_vskew;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_skew;
        VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> tb_peripheral__DOT__dut__DOT__u_systolic__DOT__b_vskew;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h90828fb9__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_peripheral__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_peripheral___024root(Vtb_peripheral__Syms* symsp, const char* v__name);
    ~Vtb_peripheral___024root();
    VL_UNCOPYABLE(Vtb_peripheral___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
