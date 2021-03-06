library ieee;
use ieee.numeric_bit.ALL;
use ieee.math_real.all;
use std.textio.all;
entity rom_arquivo is
  port (
    addr : in  bit_vector (addressSize-1  downto 0); -- 5bits de endereco
    data : out bit_vector (wordSize-1  downto 0) -- 8 bits de tamanho de palavra de dados
  );
end rom_arquivo;

architecture rom_arquivo_arch of rom_arquivo is
  type mem_tipo is array (0 to 31) of bit_vector(7 downto 0);

  function init_mem(mif_file_name : in string) return mem_tipo is
      file mif_file : text open read_mode is mif_file_name;
      variable mif_line : line;
      variable temp_bv : bit_vector(wordSize-1 downto 0);
      variable temp_mem : mem_tipo;

      begin
        for i in mem_tipo'range loop
            readline(mif_file, mif_line);
            read(mif_line, temp_bv);
            temp_mem(i) := temp_bv;
      end loop;
      return temp_mem;
  end function;

constant MEM_DEPTH : integer := 2**addressSize;
--type mem_type is array (0 to MEM_DEPTH-1) of signed(wordSize-1 downto 0);

signal mem : mem_tipo := init_mem("conteudo_rom_ativ_02_carga.dat";

begin
process (addr)
    begin
data <= mem(to_integer(unsigned(addr)));
end process;
end rom_arquivo_arch;
