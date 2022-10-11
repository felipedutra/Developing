library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
use ieee.math_real.all;

entity rom_vhd is
    generic (
        ADDR_WIDTH       : integer := 8;        
        DATA_WIDTH       : integer := 8
    );
    port (
        clk_i     : in  std_logic;
        addr_i    : in  std_logic_vector(ADDR_WIDTH-1 downto 0);          
        data_o    : out signed(DATA_WIDTH-1 downto 0)
    );
end rom_vhd;

architecture rtl of rom_vhd is

constant MEM_DEPTH : integer := 2**ADDR_WIDTH;
type mem_type is array (0 to MEM_DEPTH-1) of signed(DATA_WIDTH-1 downto 0);

function init_mem return mem_type is
    constant SCALE : real := 2**(real(DATA_WIDTH-2));
    constant STEP  : real := 1.0/real(MEM_DEPTH);
    variable temp_mem : mem_type;
begin
    for i in 0 to MEM_DEPTH-1 loop
        temp_mem(i) := to_signed(integer(cos(2.0*MATH_PI*real(i)*STEP)*SCALE), DATA_WIDTH); 
    end loop;
    return temp_mem;
end;

constant mem : mem_type := init_mem;

begin

process (clk_i)
begin
    if rising_edge(clk_i) then
	     data_o <= mem(to_integer(unsigned(addr_i)));
    end if;
end process;

end rtl;
