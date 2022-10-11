library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tb_contador is
end entity;

architecture tb of tb_contador is
component SOURCE is
  port (clock, zera, conta, carrega: in std_logic;  -- ENTRADAS MANUAIS COMO CLOCK etc
        entrada: in std_logic_vector (3 downto 0); -- NUMERO INICIAL
        contagem: out std_logic_vector (3 downto 0); -- SAÍDA MOMENTANEA DA CONTAGEM
        fim: out std_logic                            -- CONTAGEM (ATUALIZA A CADA CLOCK)
);
end component;

signal clock,zera : std_logic := '1';
signal contagem : std_logic_vector(3 downto 0);

begin

uut: SOURCE port map(
clock => clock,
zera => zera,
contagem => contagem);

clock: process
begin

zera <= '0';

clock <= '0';
wait for 20 ns;
clock <= '1';
wait for 20 ns;

end process;
end tb;
