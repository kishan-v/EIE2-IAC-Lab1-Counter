// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_challenge.h for the primary calling header

#include "verilated.h"

#include "Vcounter_challenge___024root.h"

VL_INLINE_OPT void Vcounter_challenge___024root___sequent__TOP__0(Vcounter_challenge___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_challenge__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_challenge___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->count = ((IData)(vlSelf->rst) ? 0U : (0xffU 
                                                  & ((IData)(vlSelf->count) 
                                                     + (IData)(vlSelf->en))));
}

void Vcounter_challenge___024root___eval(Vcounter_challenge___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_challenge__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_challenge___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vcounter_challenge___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vcounter_challenge___024root___eval_debug_assertions(Vcounter_challenge___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_challenge__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_challenge___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
