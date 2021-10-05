library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity rom_simples is
  port (
    addr : in bit_vector(4 downto 0);
    data : out bit_vector (7 downto 0) );
end rom_simples;





architecture rom_simples_arch of rom_simples is
  type mem_tipo is array (0 to 2047) of std_logic_vector(10 downto 0);
