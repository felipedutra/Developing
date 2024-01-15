library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity multiplicador_modificado is
    port (
        Clock : in bit;
        Reset : in bit;
        Start : in bit;
        Va, Vb : in bit_vector(3 downto 0);
        Vresult : out bit_vector(7 downto 0);
        Ready : out bit
    );
end entity multiplicador_modificado;

architecture Behavioral of multiplicador_modificado is
    signal produto_parcial : bit_vector(7 downto 0) := (others => '0');
    signal vai_um : bit := '0';
    signal multiplicando : bit_vector(3 downto 0) := (others => '0');
    signal multiplicador : bit_vector(3 downto 0) := (others => '0');
    signal result_temp : bit_vector(7 downto 0) := (others => '0');
    signal counter : integer := 0;
    signal done : boolean := false;

begin
    process(Clock, Reset)
    begin
        if Reset = '1' then
            counter <= 0;
            multiplicando <= (others => '0');
            multiplicador <= (others => '0');
            produto_parcial <= (others => '0');
            vai_um <= '0';
            done <= false;
            Ready <= '0';
        elsif rising_edge(Clock) then
            if Start = '1' then
                multiplicando <= Va;
                multiplicador <= Vb;
                counter <= 0;
                produto_parcial <= (others => '0');
                vai_um <= '0';
                done <= false;
                Ready <= '1';
            elsif counter < 4 then
                if multiplicador(0) = '1' then
                    result_temp <= (others => '0');
                    result_temp <= result_temp + multiplicando;
                end if;
                counter <= counter + 1;
                multiplicador <= multiplicador(2 downto 0) & '0';
                multiplicando <= '0' & multiplicando(3 downto 1);
                produto_parcial <= produto_parcial(6 downto 0) & vai_um;
                vai_um <= result_temp(7);
                result_temp <= result_temp(6 downto 0) & '0';
            else
                Vresult <= produto_parcial;
                done <= true;
                Ready <= '0';
            end if;
        end if;
    end process;
end Behavioral;
