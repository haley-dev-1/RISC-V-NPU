// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_peripheral__pch.h"
#include "Vtb_peripheral.h"
#include "Vtb_peripheral___024root.h"

// FUNCTIONS
Vtb_peripheral__Syms::~Vtb_peripheral__Syms()
{
}

Vtb_peripheral__Syms::Vtb_peripheral__Syms(VerilatedContext* contextp, const char* namep, Vtb_peripheral* modelp)
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
    __Vscope_tb_peripheral.configure(this, name(), "tb_peripheral", "tb_peripheral", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_peripheral__run_one_case_2x2.configure(this, name(), "tb_peripheral.run_one_case_2x2", "run_one_case_2x2", -9, VerilatedScope::SCOPE_OTHER);
}
