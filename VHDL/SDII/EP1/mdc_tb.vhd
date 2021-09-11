library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_bit.all;

entity testbench is
end testbench;

architecture arch_tb_MDC6 of testbench is

	-- Declara o componente do DUT
    component MDC6 is
      port(
      -- Entrada de controle global
      clock, reset: in bit; 
      -- Entrada de controle
      iniciar: in bit;      
      -- Entrada de dados
      a_en, b_en: in bit_vector(5 downto 0); 
      -- Saida de controle
      fim: out bit;  
      -- Saida de dados
      mdc: out bit_vector(5 downto 0)       
      );
	end component;
    
    signal a_in, b_in, mdc_out: bit_vector(5 downto 0);
    signal iniciar_in, fim_out: bit;
    signal reset_in: bit;
    
    constant clockPeriod : time := 2 ns; -- periodo do clock
    signal clock_in: bit := '0';
    signal simulando: bit := '0';
    
begin

	DUT: MDC6 
    port map (clock_in, reset_in, iniciar_in, a_in, b_in, fim_out, mdc_out);
    
	-- Clock
    clock_in <= (simulando and (not clock_in)) after clockPeriod/2;

    stimulus: process is -- Processo de testes
        -- Estrutura de dados com testes
		type test_record is record
			reset: bit; 
			a, b: bit_vector(5 downto 0);
			iniciar: bit;
            fim: bit;
            mdc: bit_vector(5 downto 0);
			str : string(1 to 5); -- comment
		end record;

        -- Vetor com testes
		type tests_array is array (natural range <>) of test_record;
		constant tests : tests_array :=
         -- reset    a        b       iniciar   fim      mdc      str
		  (('1', "000000", "000000",   '1',     '1',  "000000", "00/00"),
       	   ('0', "000100", "000110",   '1',     '1',  "000010", "04/06"), -- mdc = 2
           ('0', "010000", "011000",   '1',     '1',  "001000", "16/24"), -- mdc = 8
           ('0', "011000", "010010",   '1',     '1',  "000110", "24/18")  -- mdc = 6
           );
           
		begin -- Conteudo dos testes
			assert false report "Test start." severity note;
			simulando <= '1'; -- Habilita clock
    
		for k in tests'range loop
            
			reset_in <= tests(k).reset;
			a_in <= tests(k).a;
            b_in <= tests(k).b;
            iniciar_in <= tests(k).iniciar;
            
            reset_in <= '1';
            wait for 5 ns;
            reset_in <= '0';
            wait for 5 ns;
            
            wait for 50 ns; -- tempo para execucao do algoritmo
            
            assert (tests(k).fim = fim_out)
                report "Fail:fim" & tests(k).str severity error;
            assert (tests(k).mdc = mdc_out)
                report "Fail:mdc" & tests(k).str severity error;
            
            
		end loop;

        -- Final do teste
		assert false report "Test done." severity note;
		simulando <= '0'; -- Desabilita clock
		wait; -- Fim da execucao
	end process;
end architecture;
    