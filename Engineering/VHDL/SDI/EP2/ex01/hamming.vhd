--MASTER ENTITY
entity hamming is
port(
  entrada : in bit_vector(9 downto 0); --! 3 gestos mais 4 bits de paridade
  dados : out bit_vector(5 downto 0); --! 3 gestos, corrigindo erros de 1 bit
  erro: out bit --! erro nao corrigido
  );
end entity hamming;

architecture arch_ham of hamming is
signal game: bit_vector(5 downto 0);
signal errors: bit_vector(3 downto 0); -- vetor para erros, para evitar erros
signal p: bit_vector(3 downto 0); --1o sinal  de verificacao de erros no codigo
signal p2: bit_vector(3 downto 0); --2o sinal de verificacao de erros no codigo
begin
game <= entrada(9 downto 4);
errors <= entrada(3 downto 0);

--comeco do codigo de tratamento de Erros  |9|8|7|6|5|4|   |3|2|1|0
p(3) <= entrada(8) xor entrada(9) xor errors(3);  --Bit da 8a posicao
p(2) <= entrada(5) xor entrada(6) xor entrada(7) xor errors(2);  --Bit da 4a posicao
p(1) <= entrada(4) xor entrada(5) xor entrada(6) xor entrada(7) xor errors(1);  --Bit da 2a posicao
 p(0) <= entrada(4) xor entrada(5) xor entrada(7) xor entrada(8) xor errors(0);  --Bit da 1a posicao


with p select
dados <=  game(5) & game(4) & game(3) & game(2) & game(1) & game(0)           when "0000", --sem erros
          game(5) & game(4) & game(3) & game(2) & game(1) & (game(0) xor '1') when "0011", --erro na posicao 0 == A0 ou B0
          game(5) & game(4) & game(3) & game(2) & (game(1) xor '1') & game(0) when "0101", --erro na posicao 1 == A1 ou B1
          game(5) & game(4) & game(3) & (game(2) xor '1') & game(1) & game(0) when "0110", --erro na posicao 2 == A2 ou B2
          game(5) & game(4) & (game(3) xor '1') & game(2) & game(1) & game(0) when "0111", --erro na posicao 3 == A3 ou B3
          game(5) & (game(4) xor '1') & game(3) & game(2) & game(1) & game(0) when "1001", --erro na posicao 4 == A4 ou B4
          (game(5) xor '1') & game(4) & game(3) & game(2) & game(1) & game(0) when "1010", --erro na posicao 5 == A5 ou B5
          game(5) & game(4) & game(3) & game(2) & game(1) & game(0)       when others; --catch all

p2(3) <= entrada(8) xor entrada(9) xor errors(3) xor p(3);
p2(2) <= entrada(5) xor entrada(6) xor entrada(7) xor errors(2) xor p(2);
p2(1) <= entrada(4) xor entrada(5) xor entrada(6) xor entrada(7) xor errors(1) xor p(1);
p2(0) <= entrada(4) xor entrada(5) xor entrada(7) xor entrada(8) xor errors(0) xor p(0);


with p2 select
erro <=   '1'       when  "1000"|"0001"|"0010"|"0100"|"1100"|"1110"|"1111", --erro na posicao 5 == A5 ou B5
          '0' when others;


end architecture arch_ham;
