open_project floyd_matrix_hls

add_files floyd.c
add_files -tb ../common/main.c
add_files local_support.c

set_top Floyd

open_solution -reset solution
set_part virtex7
create_clock -period 10

csynth_design
cosim_design -rtl verilog -tool xsim -trace_level all
