-- Testbench for 4-bit half-adder

entity testbench is
-- empty
end entity testbench;

architecture tb of testbench is

-- DUT component
component jokempo is


port (
    a: in bit_vector(1 downto 0);
    b: in bit_vector(1 downto 0);
    y: out bit_vector(1 downto 0)
    );
end component;

signal a_in: in bit_vector(1 downto 0) := (others=>'0');
signal b_in: in bit_vector(1 downto 0):= (others=>'0');
signal y_out: out bit_vector(1 downto 0):= (others=>'0');

begin

tb: jokempo port map(a_in, b_in, y_out);

  stim: process is
  begin


    report "BOT";

    a_in <= "00";
    b_in <= "00";
    wait for 1 ns;
    assert (y_out = "00") report "Fail 00 00";

    a_in <= "01"; --pedra
    b_in <= "10"; --papel
    wait for 1 ns;
    assert(y_out = "01") report "Fail 00 00";

    a_in <= "10"; --papel
    b_in <= "01"; --pedra
    wait for 1 ns;
    assert(y_out = "10") report "Fail 00 00";




    report "EOT";
    wait;
  end process;
end tb;
