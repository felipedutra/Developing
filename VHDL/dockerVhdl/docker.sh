docker pull ghdl/ghdl:ubuntu18-mcode
docker run --rm --name ghdl -u $(id -u):$(id -g) -v ~/Developing/VHDL/dockerVhdl:/workspace -w /workspace -it ghdl/ghdl:ubuntu18-mcode  /bin/bash
