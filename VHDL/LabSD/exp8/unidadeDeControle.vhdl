- library declaration
library IEEE;
use IEEE.std_logic_1164.all;
-- entity
entity UnidadeDeControle is
port ( modo  : in std_logic;
		CLK,CLR : in std_logic;
		proximo : out std_logic);
end UnidadeDeControle;
-- architecture
architecture arch of UnidadeDeControle is
type state_type is (inicio, configuracao, operacao);
signal PS,NS : state_type;

begin
sync_proc: process(CLK,NS,CLR)
begin
-- take care of the asynchronous input
if (CLR = '1') then
PS <= inicio;
elsif (rising_edge(CLK)) then
PS <= NS;
end if;
end process sync_proc;

prox_estado : process (PS, modo)
begin
  proximo <= '0';
  case PS is
    when inicio =>
		proximo <= '0';
      if modo = '0' then NS <= configuracao;
		elsif modo = '1' then NS <= operacao;
      else   NS <=operacao;
		end if;
    when configuracao =>
		proximo <= '1';
      if modo = '0' then NS <= configuracao;
		elsif modo = '1' then NS <= operacao;
      else   NS <=operacao;
		end if;
    when operacao=>
		proximo <= '0';
		if modo = '0' then NS <= configuracao;
		elsif modo = '1' then NS <= operacao;
      else   NS <=operacao;
		end if;
	 when others =>
		proximo <= '0';
		NS <= configuracao;
	end case;
end process;
end arch;
