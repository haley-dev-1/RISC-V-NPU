// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_fsm__pch.h"
#include "Vtb_fsm.h"
#include "Vtb_fsm___024root.h"

// FUNCTIONS
Vtb_fsm__Syms::~Vtb_fsm__Syms()
{
}

Vtb_fsm__Syms::Vtb_fsm__Syms(VerilatedContext* contextp, const char* namep, Vtb_fsm* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_fsm.configure(this, name(), "tb_fsm", "tb_fsm", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fsm__test_happy_path.configure(this, name(), "tb_fsm.test_happy_path", "test_happy_path", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fsm__test_sa_error_path.configure(this, name(), "tb_fsm.test_sa_error_path", "test_sa_error_path", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fsm__test_start_held_high_no_retrigger.configure(this, name(), "tb_fsm.test_start_held_high_no_retrigger", "test_start_held_high_no_retrigger", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fsm__test_zero_len_error.configure(this, name(), "tb_fsm.test_zero_len_error", "test_zero_len_error", -9, VerilatedScope::SCOPE_OTHER);
}
