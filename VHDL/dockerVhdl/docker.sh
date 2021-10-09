docker pull ghdl/ghdl:ubuntu18-mcode
docker run --name ghdl --rm  -u $(id -u):$(id -g) -v ~/Developing/Developing/VHDL/:/workspace -w /workspace -it ghdl/ghdl:ubuntu18-mcode  /bin/bash



ghdl -i design.vhd testbench.vhd  && ghdl -m  testbench && ghdl -r  testbench
