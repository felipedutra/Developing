entity rom_simples is
  port (
    addr : in bit_vector(4 downto 0);
    data : out bit_vector (7 downto 0) );
end rom_simples;
