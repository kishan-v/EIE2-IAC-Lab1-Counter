#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env)
{
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vtop *top = new Vtop;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    // init Vbuddy
    if (vbdOpen() != 1)
        return (-1);
    vbdHeader("Lab 1: Counter");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 1;

    // run simulation for many clock cycles
    for (i = 0; i < 1000; i++)
    {

        // dump variables into VCD file and toggle clock
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }

        // ++++ Send count value to Vbuddy
        // Takes in BCD value and converts to HEX such that it displays in only decimal digits
        vbdHex(4, (int(top->bcd) >> 12) & 0xF); // bcd is only 12 bits and therefore there can't be a non-zero 4th HEX digit
        vbdHex(3, (int(top->bcd) >> 8) & 0xF);  // right shift by 8 opsitions and then bitwise AND so only BCD[11:8] is converted to hex
        vbdHex(2, (int(top->bcd) >> 4) & 0xF);  // right shift by 4 positions and then bitwise AND so that only BCD[7:4] is converted to hex
        vbdHex(1, int(top->bcd) & 0xF);         // bitwise AND Least sig. 4 bits
        // vbdPlot(int(top->count), 0, 255);
        vbdCycle(i + 1);

        // ---- End of Vbuddy output section
        top->rst = (i < 2) | (i == 15);
        // top->en = vbdFlag();
        if (Verilated::gotFinish())
            exit(0);
    }
    vbdClose();
    tfp->close();
    exit(0);
}