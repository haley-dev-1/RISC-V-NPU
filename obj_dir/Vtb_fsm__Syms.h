// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_FSM__SYMS_H_
#define VERILATED_VTB_FSM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_fsm.h"

// INCLUDE MODULE CLASSES
#include "Vtb_fsm___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_fsm__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_fsm* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_fsm___024root              TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_fsm;
    VerilatedScope __Vscope_tb_fsm__test_happy_path;
    VerilatedScope __Vscope_tb_fsm__test_sa_error_path;
    VerilatedScope __Vscope_tb_fsm__test_start_held_high_no_retrigger;
    VerilatedScope __Vscope_tb_fsm__test_zero_len_error;

    // CONSTRUCTORS
    Vtb_fsm__Syms(VerilatedContext* contextp, const char* namep, Vtb_fsm* modelp);
    ~Vtb_fsm__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
