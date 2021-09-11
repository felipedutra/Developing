--! Code your testbench here
--! or browse Examples

library ieee;
use ieee.numeric_bit.all;
use ieee.math_real.all;

entity testbench is

end testbench;

architecture tb of testbench is

component hamming is
port(
entrada: in bit_vector(9 downto 0); --! 3 gestos mais 4 bits de paridade
dados : out bit_vector(5 downto 0); --! 3 gestos, corrigindo erros de 1 bit
erro: out bit --! erro nao corrigido
);
end component;

	signal a_in : bit_vector (9 downto 0);
	signal dados_out : bit_vector (5 downto 0);
    Signal erro_out: bit;
    
    begin
      
      DUT: hamming port map(a_in, dados_out, erro_out);
      process
      type test_add is record
      	t_in: bit_vector(9 downto 0);
        t_data: bit_vector(5 downto 0);
        t_error: bit;
        str: string (1 to 3);
      end record;

	type tests_array is array (natural range <>) of test_add;
    
    							   -- Pedra = 01, Papel = 10, Tesoura = 11, Espera = 00;
    							   -- t_in    t_data   t_error   test
                                   -- Sem erros
	constant tests: tests_array := (("0110111000", "011011", '0', "T1 "), --! pedra(01), papel(10), tesoura(11)
    								("1101100000", "110110", '0', "T2 "), --! tesoura(11), pedra(01), papel(10)
                                    ("1011011000", "101101", '0', "T3 "), --! papel(10), tesoura(11), pedra(01)
                                    ("0111101101", "011110", '0', "T4 "), --! pedra(01), tesoura(11), papel(10)
    								("1001111010", "100111", '0', "T5 "), --! papel(10), pedra(01), tesoura(11)
                                    ("1110010111", "111001", '0', "T6 "), --! tesoura(11), papel(10), pedra(01)
                                    
                                    
                                    -- Erros de 1 bit
                                   ("1110111000", "011011", '0', "T7 "), --! pedra(01), papel(10), tesoura(11)
    							   ("0101100000", "110110", '0', "T8 "), --! tesoura(11), pedra(01), papel(10)
                                   ("0011011000", "101101", '0', "T9 "), --! papel(10), tesoura(11), pedra(01)
                                   ("1111101101", "011110", '0', "T10"), --! pedra(01), tesoura(11), papel(10)
    							   ("0001111010", "100111", '0', "T11"), --! papel(10), pedra(01), tesoura(11)
                                   ("0110010111", "111001", '0', "T12"), --! tesoura(11), papel(10), pedra(01)
                                   
                                    -- erros de 2 bits
                                   ("1010111000", "011011", '1', "T13"), --! pedra(01), papel(10), tesoura(11)
    							   ("0001100000", "110110", '1', "T14"), --! tesoura(11), pedra(01), papel(10)
                                   ("0111011000", "101101", '1', "T15"), --! papel(10), tesoura(11), pedra(01)
                                   ("1011101101", "011110", '1', "T16"), --! pedra(01), tesoura(11), papel(10)
    							   ("0101111010", "100111", '1', "T17"), --! papel(10), pedra(01), tesoura(11)
                                   ("0010010111", "111001", '1', "T18"), --! tesoura(11), papel(10), pedra(01)
                                                                      
                                   ("0010010111", "111001", '1', "T19")); --! tesoura(11), papel(10), pedra(01)
    begin
     
      for k in tests' range loop -- dentro do process, após begin
        a_in <= tests(k).t_in; 
        
	    wait for 1 ns; -- espera estabilizar e verifica saída
        assert (erro_out = tests(k).t_error) report "Fail:" & tests(k).str severity error;
      end loop;    
      
        a_in <= "0000000000";-- Limpa entradas (opcional)
        
        assert false report "Test done." severity note; 
        
        wait; -- Interrompe execução
        end process;
end tb;