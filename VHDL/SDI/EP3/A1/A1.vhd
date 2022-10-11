entity bass_hero_solo is
  port (clk, reset: in bit;
        target:     in bit_vector  (3 downto 0);
        played:     in bit_vector  (3 downto 0);
        score:      out bit_vector (2 downto 0);
        cheers:     out bit
        );
end entity;

architecture behavior of bass_hero_solo is
  type state_type is (A,B,C,D,E);
  signal last_state, present_state, next_state: state_type;
  signal X: bit;
begin


--bloco sequencial: estado atual
ESTADO_ATUAL: process (reset,clk) is
  begin
  if (reset = '1') then
    present_state <= C;
    last_state <= C;



  elsif (clk'EVENT and clk='1') then
    last_state <= present_state;
    present_state <= next_state;

  end if;
end process ESTADO_ATUAL;
--bloco combinatorio: proximo estado
X <=
  '1' when target = played else
  '0';

next_state <=
  A when( present_state = A) and (X = '0') else -- loop
  A when( present_state = B) and (X = '0') else -- de b para apro
  B when( present_state = A) and (X = '1') else -- de a para b
  B when( present_state = C) and (X = '0') else -- de c para b
  C when( present_state = D) and (X = '0') else -- de d para c
  C when( present_state = B) and (X = '1') else -- de b para c
  D when( present_state = E) and (X = '0') else -- de e para d
  D when( present_state = C) and (X = '1') else -- de c para d
  E when( present_state = D) and (X = '1') else -- de d para e
  E when( present_state = E) and (X = '1') else -- de c para d
  C;

--bloco combinatorio: saida
--A = 101 B = 111 C = 000 D = 001 A = 010
with present_state select
score <=  "110" when A,
          "111" when B,
          "000" when C,
          "001" when D,
          "010" when E; --catch all
cheers <=   '1' when ( last_state = E and present_state = E and reset = '0') else
            '0';

end behavior;
