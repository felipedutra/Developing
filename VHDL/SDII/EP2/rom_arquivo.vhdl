library ieee;
use ieee.numeric_std.ALL;
use ieee.math_real.all;

entity rom_arquivo is
  generic(
      addressSize: natural := 5;
      wordSize:   natural := 8;
      datFileName: string := "conteudo_rom_ativ_02_carga.dat"
  );
  port (
    addr : in bit_vector(4 downto 0); -- 5bits de endereco
    data : out bit_vector (7 downto 0) -- 8 bits de tamanho de palavra de dados
  );
end rom_arquivo;

architecture rom_arquivo_arch of rom_arquivo is

constant MEM_DEPTH : integer := 2**addressSize;
type mem_type is array (0 to MEM_DEPTH-1) of signed(wordSize-1 downto 0);

function init_mem return mem_type is
    constant SCALE : real := 2**(real(wordSize-2));
    constant STEP  : real := 1.0/real(MEM_DEPTH);
    variable temp_mem : mem_type;
begin
    for i in 0 to MEM_DEPTH-1 loop
        temp_mem(i) := to_signed(integer(cos(2.0*MATH_PI*real(i)*STEP)*SCALE), wordSize);
    end loop;
    return temp_mem;
end;

constant mem : mem_type := init_mem;

begin

data <= mem(bit_vector(unsigned(addr)));



end rom_arquivo_arch;
