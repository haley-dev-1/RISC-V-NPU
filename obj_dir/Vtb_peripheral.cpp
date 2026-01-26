// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_peripheral__pch.h"

//============================================================
// Constructors

Vtb_peripheral::Vtb_peripheral(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_peripheral__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_peripheral::Vtb_peripheral(const char* _vcname__)
    : Vtb_peripheral(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_peripheral::~Vtb_peripheral() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_peripheral___024root___eval_debug_assertions(Vtb_peripheral___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_peripheral___024root___eval_static(Vtb_peripheral___024root* vlSelf);
void Vtb_peripheral___024root___eval_initial(Vtb_peripheral___024root* vlSelf);
void Vtb_peripheral___024root___eval_settle(Vtb_peripheral___024root* vlSelf);
void Vtb_peripheral___024root___eval(Vtb_peripheral___024root* vlSelf);

void Vtb_peripheral::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_peripheral::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_peripheral___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_peripheral___024root___eval_static(&(vlSymsp->TOP));
        Vtb_peripheral___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_peripheral___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_peripheral___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_peripheral::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_peripheral::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_peripheral::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_peripheral___024root___eval_final(Vtb_peripheral___024root* vlSelf);

VL_ATTR_COLD void Vtb_peripheral::final() {
    Vtb_peripheral___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_peripheral::hierName() const { return vlSymsp->name(); }
const char* Vtb_peripheral::modelName() const { return "Vtb_peripheral"; }
unsigned Vtb_peripheral::threads() const { return 1; }
void Vtb_peripheral::prepareClone() const { contextp()->prepareClone(); }
void Vtb_peripheral::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_peripheral::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_peripheral::trace()' called on model that was Verilated without --trace option");
}
