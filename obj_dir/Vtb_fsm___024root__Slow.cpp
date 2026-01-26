// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fsm.h for the primary calling header

#include "Vtb_fsm__pch.h"
#include "Vtb_fsm__Syms.h"
#include "Vtb_fsm___024root.h"

void Vtb_fsm___024root___ctor_var_reset(Vtb_fsm___024root* vlSelf);

Vtb_fsm___024root::Vtb_fsm___024root(Vtb_fsm__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_fsm___024root___ctor_var_reset(this);
}

void Vtb_fsm___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_fsm___024root::~Vtb_fsm___024root() {
}
