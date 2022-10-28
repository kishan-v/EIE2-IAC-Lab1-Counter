#include "Vcounter_challenge.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env)
{
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vcounter_challenge *top = new Vcounter_challenge;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter_challenge.vcd");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 1;
    top->en = 8;

    int reference_cycle = 0;
    // run simulation for many clock cycles
    for (i = 0; i < 300; i++)
    {
        if (top->count == 9) // Challenge is to implement pause at count 9
        {
            if (reference_cycle == 0) // reference_cycle has not beeen asserted so first cycle after reaching count 9
            {
                reference_cycle = i; // assert reference cycle so you can track from when the pause started
                top->en = 0;         // stop counting
            }
            else
            {                                // reference cycle asserted
                if (i < reference_cycle + 2) // mid-pause
                {
                    top->en = 0; // still, don't count
                }
                if (i >= reference_cycle + 2) // reaching end of pause
                {
                    top->en = 1;         // start counting again
                    reference_cycle = 0; // un-assert reference cycle as we don't need to track cycles anymore
                }
            }
        }
        // dump variables into VCD file and toggle clock
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }

        top->rst = (i < 2); // New in challenge: removed reset condition
        top->en = (i > 4);
        if (Verilated::gotFinish())
            exit(0);
    }
    tfp->close();
    exit(0);
}