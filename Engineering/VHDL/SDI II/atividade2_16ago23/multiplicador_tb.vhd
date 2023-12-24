-------------------------------------------------------
--! @file multiplicador_tb.vhd
--! @brief testbench for synchronous multiplier
--! @author Edson Midorikawa (emidorik@usp.br)
--! @date 2020-06-15
-------------------------------------------------------

library ieee;
use ieee.numeric_bit.all;

entity multiplicador_tb is
end entity;

architecture tb of multiplicador_tb is
  
  -- Componente a ser testado (Device Under Test -- DUT)
  component multiplicador
    port (
      Clock:    in  bit;
      Reset:    in  bit;
      Start:    in  bit;
      Va,Vb:    in  bit_vector(3 downto 0);
      Vresult:  out bit_vector(7 downto 0);
      Ready:    out bit
    );
  end component;
  
  -- Declaração de sinais para conectar a componente
  signal clk_in: bit := '0';
  signal rst_in, start_in, ready_out: bit := '0';
  signal va_in, vb_in: bit_vector(3 downto 0);
  signal result_out: bit_vector(7 downto 0);

  -- Configurações do clock
  signal keep_simulating: bit := '0'; -- delimita o tempo de geração do clock
  constant clockPeriod : time := 1 ns;
  
begin
  -- Gerador de clock: executa enquanto 'keep_simulating = 1', com o período
  -- especificado. Quando keep_simulating=0, clock é interrompido, bem como a 
  -- simulação de eventos
  clk_in <= (not clk_in) and keep_simulating after clockPeriod/2;
  
  ---- O código abaixo, sem o "keep_simulating", faria com que o clock executasse
  ---- indefinidamente, de modo que a simulação teria que ser interrompida manualmente
  -- clk_in <= (not clk_in) after clockPeriod/2; 
  
  -- Conecta DUT (Device Under Test)
  dut: multiplicador
       port map(Clock=>   clk_in,
                Reset=>   rst_in,
                Start=>   start_in,
                Va=>      va_in,
                Vb=>      vb_in,
                Vresult=> result_out,
                Ready=>   ready_out
      );

  ---- Gera sinais de estímulo
  stimulus: process is
  type pattern_type is record
    m1: bit_vector(3 downto 0);
    m2: bit_vector(3 downto 0);
    resultado_esperado: bit_vector(7 downto 0);
  end record;

  type pattern_array is array (natural range <>) of pattern_type;
    constant patterns: pattern_array :=

    ( ("0001","0010","00000010"),
      ("0001","0001","00000000"),
      ("0001","0001","00000001"),
      ("0001","0001","00000001"));

  begin
  
    assert false report "simulation start" severity note;
    keep_simulating <= '1';
    for i in patterns'range loop 
    rst_in <= '1';
    rst_in <= '0';
    va_in<= patterns(i).m1;
    vb_in<= patterns(i).m2;
    start_in <= '1';
    wait for 10 ns;
    assert result_out = patterns(i).resultado_esperado report "Erro na multiplicação" severity error;

    wait;
  end loop;


    -- final do testbench
    assert false report "simulation end" severity note;
    keep_simulating <= '0';
    
    wait; -- fim da simulação: aguarda indefinidamente
  end process;


end architecture;


