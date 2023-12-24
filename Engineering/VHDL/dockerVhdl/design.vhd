entity register8 is
    port(
        clock, reset: in  bit;
        load:         in  bit;
        parallel_in:  in  bit_vector(7 downto 0);
        parallel_out: out bit_vector(7 downto 0)
    );
end entity;

architecture arch_reg of register8 is
    signal internal: bit_vector(7 downto 0);
    begin
        process(clock, reset)
        begin
            if reset = '1' then -- reset assincrono
                internal <= (others => '0'); -- "000000"
            elsif (clock'event and clock = '1') then
                if load = '1' then
                    internal <= parallel_in;
                end if;
            end if;
        end process;
        parallel_out <= internal;
end architecture;


entity register16 is
    port(
        clock, reset: in  bit;
        load:         in  bit;
        parallel_in:  in  bit_vector(15 downto 0);
        parallel_out: out bit_vector(15 downto 0)
    );
end entity;

architecture arch_reg of register16 is
    signal internal: bit_vector(15 downto 0);
    begin
        process(clock, reset)
        begin
            if reset = '1' then -- reset assincrono
                internal <= (others => '0'); -- "000000"
            elsif (clock'event and clock = '1') then
                if load = '1' then
                    internal <= parallel_in;
                end if;
            end if;
        end process;
        parallel_out <= internal;
end architecture;

---------- Unidade de Controle ---------
entity UC is
    port(
        -- Sinais de controle global
        clock, reset: in bit;
        -- Entrada de controle
        inicia: in bit;
        -- Sinais de status
        diferente, maior: in bit;
        -- Sinais de controle
        h1, h2, s1, s2, x1: out bit;
        -- Saida de controle
        fim: out bit
    );
end entity;

architecture arch_UC of UC is
  type state is (espera, tes_a_b, a_igl_b, a_maior_b, a_menor_b);
  signal next_state, current_state: state;
begin
    process (reset,clock) is
    begin
      if (reset = '1') then
        current_state <= espera;

      elsif (clock'EVENT and clock='1') then
        current_state <= next_state;
      end if;
  end process;
  -- Logica de proximo estado
  next_state <= tes_a_b when (current_state = espera) and (inicia = '1') else
                espera when (current_state = espera) and (inicia = '0') else

                a_igl_b when (current_state = tes_a_b) and (diferente = '0') else
                a_maior_b when (current_state = tes_a_b) and (diferente = '1') and (maior = '1') else
                a_menor_b when (current_state = tes_a_b) and (diferente = '1') and (maior = '0') else

                tes_a_b when (current_state = a_maior_b) else
                tes_a_b when (current_state = a_menor_b);

  -- Decodifica o estado para gerar sinais de controle
  h1 <= '1' when (current_state = espera) or (current_state = a_maior_b) else '0';
  h2 <= '1' when (current_state = espera) or (current_state = a_menor_b) else '0';
  s1 <= '1' when (current_state = a_maior_b) else '0';
  s2 <= '1' when (current_state = a_menor_b) else '0';

  fim <= '1' when (current_state = a_igl_b) else '0';
  x1 <= '1' when (current_state = a_igl_b) else '0';

end architecture;


  ---------- Fluxo de Dados ------------
  library ieee;
  use ieee.numeric_bit.all;

  entity FD is
      port(
          -- Sinais de controle global
          clock: in bit;
          -- Sinais de controle da UC
          h1, h2, s1, s2, x1: in bit;
          -- Sinais de status
          diferente, maior: out bit;
          -- Entrada de dados
          A, B: in bit_vector(7 downto 0);
          -- Entrada de controle
          inicia: in bit;
          -- Saida de dados
          mmc: out bit_vector(15 downto 0)


      );
  end entity;

  architecture arch_FD of FD is
      component register16 is
          port(
              clock, reset: in  bit;
              load:         in  bit;
              parallel_in:  in  bit_vector(15 downto 0);
              parallel_out: out bit_vector(15 downto 0)
          );
      end component;
		component register8 is
          port(
              clock, reset: in  bit;
              load:         in  bit;
              parallel_in:  in  bit_vector(7 downto 0);
              parallel_out: out bit_vector(7 downto 0)
          );
      end component;
      signal a_out, b_out: bit_vector(15 downto 0);
      signal a_in, b_in: bit_vector(15 downto 0); -- Fio que liga o MUX ao REG
	  signal a0, b0: bit_vector(7 downto 0);
      begin

          regmA: register16
          port map (clock, '0', h1, a_in, a_out);

          regmB: register16
          port map (clock, '0', h2, b_in, b_out);

          regA: register8
          port map (clock, '0', inicia, A, a0);

          regB: register8
          port map (clock, '0', inicia, A, b0);

          regCMD: register16
          port map (clock, '0', x1, a_out, mmc);

          a_in <= a_out when (s2 = '0') else
                  bit_vector((unsigned(a0) + unsigned(a_out)));

          b_in <= b_out when (s1 = '0') else
                  bit_vector((unsigned(b0) + unsigned(b_out)));

          -- Sinais de condicao para UC
          diferente <= '1' when (a_out /= b_out) else '0';
          maior <= '1' when (a_out > b_out) else '0';
  end architecture;

  entity mmc is port(
        reset, clock:   in bit;  -- Sinais de controle global
        inicia:         in bit; -- passa do S0 para S1 -- Entrada de controle
        A,B:            in bit_vector(7 downto 0);  -- Entrada de dados
        fim:            out bit; -- Saida de controle
        nSomas:         out bit_vector(8 downto 0);
        MMC:            out bit_vector(15 downto 0)

        );
  end mmc;





  architecture arch_MMC16 of mmc is
      component UC is
          port(
              -- Sinais de controle global
              clock, reset: in bit;
              -- Sinais de status
              inicia, diferente, maior: in bit;
              -- Sinais de controle
              h1, h2, s1, s2, x1: out bit;
              -- Saida de controle
              fim: out bit
          );
      end component;

      component FD is
          port(
              -- Sinais de controle global
              clock: in bit;
              -- Sinais de controle da UC
              h1, h2, s1, s2, x1: in bit;
              -- Sinais de status
              diferente, maior: out bit;
              -- Entrada de dados
              A, B: in bit_vector(7 downto 0);
              -- Entrada de controle
              inicia: in bit;
              -- Saida de dados
              mmc: out bit_vector(15 downto 0)

          );
      end component;

      signal h1, h2, s1, s2, x1, diferente, maior: bit;
      signal clock_n: bit;

      begin
          clock_n <= not(clock);

          xUC: UC
          port map(clock, reset, inicia, diferente, maior, h1, h2, s1, s2, x1, fim);

          xFD: FD
          port map(clock_n, h1, h2, s1, s2, x1, diferente, maior, A, B, inicia, mmc);

  end architecture;
