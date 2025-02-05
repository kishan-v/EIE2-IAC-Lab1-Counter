#!/bin/sh

# Can run this using source ./doit.sh

# Kishan: each time Vbuddy connected to WSL2 you must passthrough USB devices to WSL using 'usbipd wsl list' / 'usbpid wsl attach--busid'  command on Windows. Then may need to run sudo chmod -R 777 /dev/ttyUSB0

# cleanup
rm -rf ob_dir
rm -f counter.vcd

# run Verilator to translate Verilog into C++, including C++ testbench
verilator -Wall --cc --trace top.sv --exe top_tb.cpp

# build C++ project via make file automatically generated by Verilator
make -j -C obj_dir/ -f Vtop.mk Vtop

# run executable simulation file
obj_dir/Vtop