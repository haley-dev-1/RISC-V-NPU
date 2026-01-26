// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_fsm__pch.h"

//============================================================
// Constructors

Vtb_fsm::Vtb_fsm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_fsm__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_fsm::Vtb_fsm(const char* _vcname__)
    : Vtb_fsm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_fsm::~Vtb_fsm() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_fsm___024root___eval_debug_assertions(Vtb_fsm___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_fsm___024root___eval_static(Vtb_fsm___024root* vlSelf);
void Vtb_fsm___024root___eval_initial(Vtb_fsm___024root* vlSelf);
void Vtb_fsm___024root___eval_settle(Vtb_fsm___024root* vlSelf);
void Vtb_fsm___024root___eval(Vtb_fsm___024root* vlSelf);

void Vtb_fsm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_fsm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_fsm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_fsm___024root___eval_static(&(vlSymsp->TOP));
        Vtb_fsm___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_fsm___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_fsm___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_fsm::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_fsm::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_fsm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_fsm___024root___eval_final(Vtb_fsm___024root* vlSelf);

VL_ATTR_COLD void Vtb_fsm::final() {
    Vtb_fsm___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_fsm::hierName() const { return vlSymsp->name(); }
const char* Vtb_fsm::modelName() const { return "Vtb_fsm"; }
unsigned Vtb_fsm::threads() const { return 1; }
void Vtb_fsm::prepareClone() const { contextp()->prepareClone(); }
void Vtb_fsm::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_fsm::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_fsm::trace()' called on model that was Verilated without --trace option");
}
