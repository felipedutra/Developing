entity multiplicador_modificado is port (
Clock : in bit ;
Reset : in bit ;
Start : in bit ;
Va,Vb: in bit_vector (3 downto 0);
Vresult : out bit_vector (7 downto 0);
Ready : out bit
);
end entity ;


