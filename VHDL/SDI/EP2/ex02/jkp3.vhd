entity jkp3 is
  port(
    reset, clock: in bit;
    loadA, loadB: in bit;                       --! armazenam os gestos
    atualiza: in bit;                           --! atualiza o resultado z
    a1, a2, a3: in bit_vector(1 downto 0);      --! gestos do jogador A para os 3 jogos
    b1, b2, b3: in bit_vector(1 downto 0);      --! gestos do jogador B para os 3 jogos
    z: out bit_vector(1 downto 0)               --! resultado da disputa
  );
end jkp3;
architecture jpk3Mem of jkp3 is

    component flipflopd is
    port(
        D, reset, clock, EN: in bit;
        Q: out bit
      );
    end component;
    component jokempotriplo is
       port (
        a1, a2, a3:  in bit_vector(1 downto 0);
        b1, b2, b3: in bit_vector(1 downto 0);
        z_out:           out bit_vector(1 downto 0)
       );
    end component;
signal a1_in, a2_in, a3_in, b1_in, b2_in, b3_in, z_in : bit_vector(1 downto 0);

    begin
j1: jokempotriplo port map (
                            a1 => a1_in,
                            a2 => a2_in,
                            a3 => a3_in,
                            b1 => b1_in,
                            b2 => b2_in,
                            b3 => b3_in,
                            z_out => z_in
                            );
--flipflop para A
m1: flipflopd port map (
      						      D => a1(1),
                        reset => reset,
                        clock => clock,
                        EN => loadA,
                        Q => a1_in(1)
                        );
m2: flipflopd port map (
					                 D => a1(0),
                           reset => reset,
                           clock => clock,
                           EN => loadA,
                           Q => a1_in(0)
                        );
m3: flipflopd port map (
                        	D => a2(1),
                          reset => reset,
                          clock => clock,
                          EN => loadA,
                          Q => a2_in(1)
                          );
m4: flipflopd port map (
                        	D => a2(0),
                          reset => reset,
                          clock => clock,
                          EN => loadA,
                          Q => a2_in(0)
                          );
m5: flipflopd port map (
	                       D => a3(1),
                         reset => reset,
                         clock => clock,
                         EN => loadA,
                         Q => a3_in(1)
                         );
m6: flipflopd port map (
					              D => a3(0),
                        reset => reset,
                        clock => clock,
                        EN => loadA,
                        Q => a3_in(0)
                     );
--flipflop para B
m7: flipflopd port map (
                          D => b1(1),
                          reset => reset,
                          clock => clock,
                          EN => loadB,
                          Q => b1_in(1)
                      );
m8: flipflopd port map (
                          D => b1(0),
                          reset => reset,
                          clock => clock,
                          EN => loadB,
                          Q => b1_in(0)
                        );
m9: flipflopd port map (
                          D => b2(1),
                          reset => reset,
                          clock => clock,
                          EN => loadB,
                          Q => b2_in(1)
                        );
m10: flipflopd port map (
                          D => b2(0),
                          reset => reset,
                          clock => clock,
                          EN => loadB,
                          Q => b2_in(0)
                       );
m11: flipflopd port map (
                          D => b3(1),
                          reset => reset,
                          clock => clock,
                          EN => loadB,
                          Q => b3_in(1)
                        );
m12: flipflopd port map (
                          D => b3(0),
                          reset => reset,
                          clock => clock,
                          EN => loadB,
                          Q => b3_in(0)
                        );
--resultado z
m13: flipflopd port map (
                          D => z_in(1),
                          reset => reset,
                          clock => clock,
                          EN => atualiza,
                          Q => z(1)
                        );
m14: flipflopd port map (
                          D => z_in(0),
                          reset => reset,
                          clock => clock,
                          EN => atualiza,
                          Q => z(0)
                        );
-- agora a funcao para tratar os dados



end jpk3Mem;



--flipflop
entity flipflopd is
port(
    D, reset, clock, EN: in bit;
    Q: out bit
  );
end entity flipflopd;

architecture behavior of flipflopd is
begin
process (reset, clock)
begin
if reset='0' then Q <= '0';
elsif clock'EVENT and clock='1' and EN='1' then Q <= D;
end if;
end process ;
end behavior;

--jokempotriplo
entity jokempotriplo is
   port (
    a1, a2, a3:  in bit_vector(1 downto 0);
    b1 , b2, b3: in bit_vector(1 downto 0);
    z_out:           out bit_vector(1 downto 0)
   );
end entity jokempotriplo;

architecture jkpo of jokempotriplo is
signal resultado1 :   bit_vector (1 downto 0);   --resultado do jogo 1
signal resultado2 :   bit_vector (1 downto 0);
signal resultado3 :   bit_vector (1 downto 0);
signal resultado  :   bit_vector (5 downto 0);
begin
resultado1 <=   "10" when a1&b1 = "0111" or a1&b1 = "1001" or a1&b1 ="1110" else
                "01" when a1&b1 = "0110" or a1&b1 = "1011" or a1&b1 ="1101" else
                "11" when a1&b1 = "1111" or a1&b1 = "1010" or a1&b1 ="0101" else
                "00";
resultado2 <=   "10" when a2&b2 = "0111" or a2&b2 = "1001" or a2&b2 ="1110" else
                "01" when a2&b2 = "0110" or a2&b2 = "1011" or a2&b2 ="1101" else
                "11" when a2&b2 = "1111" or a2&b2 = "1010" or a2&b2 ="0101" else
                "00";
resultado3 <=   "10" when a3&b3 = "0111" or a3&b3 = "1001" or a3&b3 ="1110" else
                "01" when a3&b3 = "0110" or a3&b3 = "1011" or a3&b3 ="1101" else
                "11" when a3&b3 = "1111" or a3&b3 = "1010" or a3&b3 ="0101" else
                "00";
resultado <= resultado1 & resultado2 & resultado3;
with resultado select --dando o veredicto
z_out <= "10" when "101001" |"100110"|"011010"|"101011" |"101110"|"111010",--vitoria de A 10
     "01" when "011001"|"100101"|"010110"|"011101"|"110101"|"010111",--vitoria de B 01
     "00" when others;  -- espera - empate 11

end architecture jkpo;
