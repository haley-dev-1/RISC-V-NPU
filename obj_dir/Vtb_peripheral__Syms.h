// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_PERIPHERAL__SYMS_H_
#define VERILATED_VTB_PERIPHERAL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_peripheral.h"

// INCLUDE MODULE CLASSES
#include "Vtb_peripheral___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_peripheral__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_peripheral* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_peripheral___024root       TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_peripheral;
    VerilatedScope __Vscope_tb_peripheral__run_one_case_2x2;

    // CONSTRUCTORS
    Vtb_peripheral__Syms(VerilatedContext* contextp, const char* namep, Vtb_peripheral* modelp);
    ~Vtb_peripheral__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
