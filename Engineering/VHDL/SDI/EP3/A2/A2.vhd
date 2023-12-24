entity bass_hero_versus is
port (clk, reset: in bit;
target: in bit_vector (3 downto 0);
played: in bit_vector (3 downto 0);
jam: in bit;
score: out bit_vector (2 downto 0);
cheers: out bit );
end entity;


architecture bhs of bass_hero_versus is
	-- tipo: enumere aqui seus estados
	type state_type is (A,B,C,D,E,F);
	signal state, next_state: state_type;
begin
  --bloco sequencial: estado atual
	ESTADO_ATUAL: process (reset, clk) 	-- bloco de memória
	begin		 				    -- sensível a clock e reset
		if reset = '1' and clk'event and clk='1' then
			state <= C;      -- estado inicial (reset assíncrono)
		elsif clk'event and clk='1' then -- borda subida
			state <= next_state;
		end if;
	end process;

--bloco sequencial: proximo estado
	PROX_ESTADO: process (state, played,jam) 	-- bloco de prox. estado
	begin			      -- sensível a estado e entradas apenas!
        case state is
					when A =>
							if played=target and jam = '0' then next_state <= B; elsif played/=target and jam = '0' then next_state<= A; else next_state <= A;  end if;
					when B =>
							if played=target and jam = '0' then next_state <= C; elsif played/=target and jam = '0' then next_state<= A; else next_state <= A;  end if;
					when C =>
							if played=target and jam = '0' then next_state <= D; elsif played/=target and jam = '0' then next_state<= B; else next_state <= A;  end if;
					when D =>
							if played=target and jam = '0' then next_state <= E; elsif played/=target and jam = '0' then next_state<= C; else next_state <= B;  end if;
					when E =>
							if played=target and jam = '0' then next_state <= F; elsif played/=target and jam = '0' then next_state<= D; else next_state <= C;  end if;
					when F =>
							if played=target and jam = '0' then next_state <= F; elsif played/=target and jam = '0' then next_state<= D; else next_state <= C;  end if;



		   end case;

 	end process;



with state select   -- bloco de saída score
      score <=  "110" when A,
                "111" when B,
                "000" when C,
                "001" when D,
                "010" when E,
                "010" when F, --catch all
                "000" when others;




cheers <= '1' when state = F  else       -- bloco de saída cheers
     '0';

end bhs;
