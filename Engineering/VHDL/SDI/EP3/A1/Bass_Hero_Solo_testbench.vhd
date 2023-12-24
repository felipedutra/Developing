library IEEE;
Use IEEE.numeric_bit.all;

entity testbench_bass_hero_solo is
end entity;

architecture tb of testbench_bass_hero_solo is

	component bass_hero_solo is
		port (clk, reset: in bit;
	    	  target: in bit_vector (3 downto 0);
	     	  played: in bit_vector (3 downto 0);
	     	  score: out bit_vector (2 downto 0);
	     	  cheers: out bit );
	end component;
	signal target_in, played_in : bit_vector (3 downto 0);
	signal score_out : bit_vector (2 downto 0);
	signal clk_in, reset_in, cheers_out : bit;
	signal keep_simulating : bit := '0';
	constant clock_period : time := 0.5 ns;
	
begin

	DUT: bass_hero_solo port map (clk_in, reset_in, target_in, played_in, score_out, cheers_out);
	clk_in <= (not clk_in) and keep_simulating after clock_period/2;
	testador : process is
		type i_o is record
			reset : bit;
			target, played : bit_vector (3 downto 0);
			score : bit_vector (2 downto 0);
			cheers : bit;
			mensagem : string (1 to 3);
        end record;
		type vetor_testes is array (natural range <>) of i_o;
			constant testes : vetor_testes := (('1', "0000", "0000", "000", '0', "INI"),
							   ('0', "0010", "0010", "001", '0', "1PA"),
							   ('0', "0100", "0100", "010", '0', "2PA"),
							   ('0', "0110", "0110", "010", '1', "CH1"),
							   ('0', "1101", "1101", "010", '1', "CH2"),
							   ('0', "0100", "0111", "001", '0', "1PE"),
							   ('0', "1100", "1111", "000", '0', "0PE"),
							   ('0', "1110", "1111", "111", '0', "-1E"),
							   ('0', "1100", "1010", "110", '0', "-2E"),
							   ('0', "1000", "1101", "110", '0', "-2M"),
						 	   ('0', "1101", "1101", "111", '0', "-1A"),
							   ('0', "1110", "1110", "000", '0', "0PA"),
							   ('0', "1111", "1111", "001", '0', "1P2"),
							   ('1', "1101", "1101", "000", '0', "RES"));
	begin
		keep_simulating <= '1';
		for k in testes'range loop
			reset_in <= testes(k).reset;
			target_in <= testes(k).target;
			played_in <= testes(k).played;
			wait until rising_edge (clk_in);
			wait for (clock_period/4);
			assert score_out = testes(k).score report "Erro:" & testes(k).mensagem severity error;
			assert cheers_out =  testes(k).cheers report "Erro:" & testes(k).mensagem severity error;
		end loop;
		wait until rising_edge (clk_in);
		reset_in <= '0';
		target_in <= "1110";
		played_in <= "1110";
		wait for (clock_period/4);
		assert (score_out = "000") report "Erro: Target e played sincronos" severity error;
		assert cheers_out =  '0' report "Erro: Target e played sincronos" severity error;

		wait until rising_edge (clk_in);
		reset_in <= '1';
		target_in <= "1110";
		played_in <= "1110";
		wait for (clock_period/4);
		assert (score_out = "001") report "Erro: Reset sincrono" severity error;
		assert cheers_out =  '0' report "Erro: Reset sincrono" severity error;

		assert false report "Test done" severity note;
		reset_in <= '1';
		keep_simulating <= '0';
		wait;
	end process;
end tb;
