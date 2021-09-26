create_project -force vivado_syn ./syn -part xc7z020clg484-1

add_files -norecurse "
    floyd_matrix_hls/solution/syn/verilog/mul_tmp.v
    floyd_matrix_hls/solution/syn/verilog/mul.v
    floyd_matrix_hls/solution/syn/verilog/Floyd.v
"

add_files -fileset constrs_1 -norecurse xdc.xdc

launch_runs synth_1 -jobs 4
wait_on_run synth_1

exit