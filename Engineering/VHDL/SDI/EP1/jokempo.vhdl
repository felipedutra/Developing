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
