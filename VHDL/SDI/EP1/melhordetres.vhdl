entity melhordetres is
   port (
   resultado1 : in  bit_vector (1 downto 0);   --resultado do jogo 1
   resultado2 : in  bit_vector (1 downto 0);
   resultado3 : in  bit_vector (1 downto 0);
   z:           out bit_vector (1 downto 0)
   );

end entity melhordetres;

architecture mdt of melhordetres is
signal game: bit_vector (5 downto 0);
	begin
  game <= (resultado1&resultado2&resultado3); --concatenando
  --10: A ganha/ 01: B ganha
  with game select
    z <= "10" when "100110" |"011010"|"101000",--vitoria de A
         "01" when "011001"|"100101"|"010100",--vitoria de B
         "00" when others;

end architecture mdt;
