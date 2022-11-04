module counter #(
    parameter WIDTH = 8
) (
    // interface signals
    input  logic             clk,   // clock 
    input  logic             rst,   // reset 
    input  logic             ld,    // load counter from data
    input  logic [WIDTH-1:0] v,     // value to preload
    output logic [WIDTH-1:0] count  // count output
);

  always_ff @(posedge clk)
    if (rst) count <= {WIDTH{1'b0}};
    /* -- Task 3 Step 1: increment each cycle, but if load is asserted then load value v to counter
    else count <= ld ? v : count + {{WIDTH - 1{1'b0}}, 1'b1};
    */

    // -- Task 3 Step 2: only increment when load (flag) is asserted 
    else
      count <= ld ? count + {{WIDTH - 1{1'b0}}, 1'b1} : count;

endmodule
