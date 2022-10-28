// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_challenge.h for the primary calling header

#include "verilated.h"

#include "Vcounter_challenge__Syms.h"
#include "Vcounter_challenge___024root.h"

void Vcounter_challenge___024root___ctor_var_reset(Vcounter_challenge___024root* vlSelf);

Vcounter_challenge___024root::Vcounter_challenge___024root(Vcounter_challenge__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcounter_challenge___024root___ctor_var_reset(this);
}

void Vcounter_challenge___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vcounter_challenge___024root::~Vcounter_challenge___024root() {
}
