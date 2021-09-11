-- Testbench for 4-bit half-adder

entity testbench is
-- empty
end entity testbench;

architecture tb of testbench is

  component jokempotriplo is
    port (
        a1, a2, a3:  in bit_vector(1 downto 0);
        b1 , b2, b3: in bit_vector(1 downto 0);
        z:           out bit_vector(1 downto 0)
       );


  end component;

signal a1, a2, a3: in bit_vector(1 downto 0) := (others=>'0');
signal b1 , b2, b3: in bit_vector(1 downto 0):= (others=>'0');
signal z_out: out bit_vector(1 downto 0):= (others=>'0');

begin
  tb: jokempotriplo port map(r1_in,r2_in,r3_in,z_out);
  stim: process is
    begin


      report "BOT";

      r1_in <= "00";
      r2_in <= "00";
      r3_in <= "00";
      wait for 1 ns;
      assert (y_out = "00") report "Fail 00 00 00";


      r1_in <= "01";
      r2_in <= "01";
      r3_in <= "01";
      wait for 1 ns;
      assert (y_out = "01") report "Fail 00 00 00";

      r1_in <= "10";
      r2_in <= "10";
      r3_in <= "10";
      wait for 1 ns;
      assert (y_out = "10") report "Fail 00 00 00";

      r1_in <= "10";
      r2_in <= "01";
      r3_in <= "10";
      wait for 1 ns;
      assert (y_out = "10") report "Fail 00 00 00";


      report "EOT";
      wait;
    end process;
  end tb;
