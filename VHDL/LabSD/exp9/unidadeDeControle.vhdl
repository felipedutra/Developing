-- library declaration
library IEEE;
use IEEE.std_logic_1164.all;
--entity
entity UnidadeDeControle is
port ( modo,Gravar  : in std_logic;
		CLK,CLR : in std_logic;
		LOAD,G1,G2,MN,NN,Seletor: out std_logic);
end UnidadeDeControle;
-- architecture
architecture arch of UnidadeDeControle is
type state_type is (inicio, conf, opA,opB);
signal present_state,next_state : state_type;
signal sig_MN: std_logic;
begin
sync_proc: process(CLK,next_state,CLR)
begin

-- take care of the asynchronous input
if (CLR = '1') then
present_state <= inicio;
elsif (rising_edge(CLK)) then
present_state <= next_state;
end if;
end process sync_proc;

prox_estado : process (present_state, Seletor,Gravar)
begin
  LOAD <= '0';
  case present_state is
    when inicio =>
		LOAD <= '0';
    if Gravar = '0' then next_state <= opA;
			elsif Gravar = '1' then next_state <= conf;
			else   next_state <=inicio;
		end if;
    when conf =>
		LOAD <= '1';
      if Gravar = '0' and modo = '0' then next_state <= opA;
			elsif Gravar = '0'and modo = '1' then next_state <= opB;
			elsif Gravar = '1' then next_state <= conf;
			else   next_state <=conf;
		end if;
    when opA=>
			LOAD <= '0';
			if Gravar = '1' then next_state <= conf;
			elsif Gravar = '0' and modo = '1' then next_state <= opB;
			elsif Gravar = '0' and modo = '0' then next_state <= opA;
			else   next_state <=opA;
			end if;
			when opB=>
				LOAD <= '0';
				if Gravar = '1' then next_state <= conf;
				elsif Gravar = '0' and modo = '1' then next_state <= opB;
				elsif Gravar = '0' and modo = '0' then next_state <= opA;
				else   next_state <=opB;
				end if;
				 	when others =>
				LOAD <= '0';
				next_state <= opA;
			end case;
		end process;

with present_state select   -- bloco de saída score
      Seletor <=  '0' when opA,
                	'1' when opB,
              		--catch all
                	'0' when others;


end arch;
