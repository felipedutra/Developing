library IEEE;
use IEEE.std_logic_1164.all;

entity comparador is
port (
    A,B: in std_logic_vector(1 downto 0); -- RECEBE DUAS ENTRADAS
    igual: out std_logic  -- SAÍDA UNICA
  );
end entity comparador;

architecture comportamental of comparador is
begin
    igual <= '1' when A=B else '0'; --A LÓGICA É BASICAMENTE A LÓGICA DE UM XOR
                                    --E UM XNOR, AMBOS CONECTADOS A UM OR2



end architecture comportamental;
