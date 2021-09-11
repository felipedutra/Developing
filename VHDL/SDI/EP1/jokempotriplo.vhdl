entity jokempo is
port (
  a: in bit_vector(1 downto 0);
  b: in bit_vector(1 downto 0);
  y: out bit_vector(1 downto 0)
  );
end entity jokempo;

architecture jkpo of jokempo is
signal game: bit_vector(3 downto 0);
begin
		--pedra = 01 papel = 10 tesoura = 11
    game <= (a&b); --concatenando a e b
    with game select
      y <=  "10" when "0111" | "1001" |"1110",--vitoria de A
            "01" when "0110" | "1011" |"1101",
            "11" when "1111" | "1010" |"0101",
            "00" when others; -- catch all
end architecture jkpo;



entity jokempotriplo is
   port (
    a1, a2, a3:  in bit_vector(1 downto 0);
    b1 , b2, b3: in bit_vector(1 downto 0);
    z:           out bit_vector(1 downto 0)
   );

end entity jokempotriplo;

architecture jkpo of jokempotriplo is
  component melhordetres is


    port (
    resultado1 : in  bit_vector (1 downto 0);   −−! resultado do jogo 1
    resultado2 : in  bit_vector (1 downto 0);
    resultado3 : in  bit_vector (1 downto 0);
    z:           out bit_vector (1 downto 0)
    );
  end component;
  component jokempo is


  port (
      a: in bit_vector(1 downto 0);
      b: in bit_vector(1 downto 0);
      y: out bit_vector(1 downto 0)
      );
  end component;
begin

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





















--10: A ganha/ 01: B ganha

end architecture jkpo;
