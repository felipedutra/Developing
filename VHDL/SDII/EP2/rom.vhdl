library ieee;
use ieee.numeric_bit.all;
use std.textio.all;
entity rom_simples is
  port (
    addr : in bit_vector(4 downto 0); -- 5bits de endereco
    data : out bit_vector (7 downto 0) -- 8 bits de tamanho de palavra de dados
    );
end rom_simples;

architecture rom_simples_arch of rom_simples is
  type mem_tipo is array (0 to 31) of bit_vector(7 downto 0);
  signal mem: mem_tipo :=
   ("00000" =>  "00000000",
    "00001" =>  "00000011",
    "00010" =>	"11000000",
    "00011" =>	"00001100",
    "00100" =>	"00110000",
    "00101" =>	"01010101",
    "00110"=>	  "10101010",
    "00111" =>	"11111111",
    "01000" =>	"11100000",
    "01001" =>	"11100111",
    "01010" =>	"00000111",
    "01011" =>	"00011000",
    "01100" =>	"11000011",
    "01101" =>	"00111100",
    "01110" =>	"11110000",
    "01111" =>	"00001111",
    "10000" =>	"11101101",
    "10001" =>	"10001010",
    "10010" =>	"00100100",
    "10011" =>	"01010101",
    "10100" =>	"01001100",
    "10101" =>	"01000100",
    "10110" =>	"01110011",
    "10111" =>  "01011101",
    "11000" =>	"11100101",
    "11001" =>	"01111001",
    "11010" =>	"01010000",
    "11011" =>	"01000011",
    "11100" =>	"01010011",
    "11101" =>	"10110000",
    "11110" =>	"11011110",
    "11111" =>	"00110001");
    begin
      process (addr)
    data <= mem(bit_vector(unsigned(addr)));
    end process;
  end rom_simples_arch;
