library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity contador is
    port (clock, zera, conta, carrega: in std_logic;  -- ENTRADAS MANUAIS COMO CLOCK etc
          entrada: in std_logic_vector (3 downto 0); -- NUMERO INICIAL
          contagem: out std_logic_vector (3 downto 0); -- SAÍDA MOMENTANEA DA CONTAGEM
          fim: out std_logic                            -- CONTAGEM (ATUALIZA A CADA CLOCK)
  );
end entity contador;

architecture comportamental of contador is
    signal IQ: integer range 0 to 15;
begin
    process (clock, zera, conta, carrega, entrada, IQ)
    begin
      if zera ='1' then IQ <=0;
    elsif clock'event and clock ='1' then
      if carrega = '1' then
        IQ <= to_integer(unsigned(entrada));
      elsif conta = '1' then
        if IQ = 15 then IQ <=0;
        else IQ <= IQ + 1;
        end if;
      else IQ <= IQ;
    end if;
  end if;
  end process;
  contagem <= std_logic_vector(to_unsigned(IQ, contagem'length));
  fim <= '1'when IQ = 15 else '0';
end architecture comportamental;
