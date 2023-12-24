entity turbo_ctrl is
port (clk,reset,B : in  bit;	-- entrada: B
	  Z			  : out bit);	-- saída: Z
end turbo_ctrl;

architecture arch2 of turbo_ctrl is
	-- tipo: enumere aqui seus estados
	type state_type is (Idle, Push, Hold, Turbo);
	signal state, next_s: state_type;
begin
	mem_proc: process (reset, clk) 	-- bloco de memória
	begin		 				    -- sensível a clock e reset
		if reset = '1' then
			state <= Idle;      -- estado inicial (reset assíncrono)
		elsif clk'event and clk='1' then -- borda subida
			state <= next_s;
		end if;
	end process;


	next_proc: process (state, B) 	-- bloco de prox. estado
	begin			      -- sensível a estado e entradas apenas!
  		case state is
   	       when Idle =>
   	          if B='0' then next_s <= Idle; else next_s <= Push; end if;
      	   when Push =>
   	          if B='0' then next_s <= Idle; else next_s <= Hold; end if;
   		   when Hold =>
   	          if B='0' then next_s <= Idle; else next_s <= Turbo; end if;
   		   when Turbo =>
   	          if B='0' then next_s <= Idle; else next_s <= Turbo; end if;
		   end case;
 	end process;

	with state select -- bloco de saída
   		Z <= '1' when Push | Turbo,
        	 '0' when others;

end arch2;
