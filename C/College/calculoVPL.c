#include <stdio.h>
double potencia (double base, double expoente)
{
    double result=1;
    for(; expoente ; expoente--){
        result=result*base;
    }
    return result;
}
int main()
{
    double n=0.0, invest=0.0, consumoefic=0.0, consumoinef=0.0, vpl=0.0, frc=0.0, a=0.0;
    printf( "Cite, respectivamente, investimento com a troca em R$,\n vida util do equipamento em anos, consumo do equipamento eficiente \nem kWh/mes e consumo do equipamento ineficiente em kWh/mes:\n");
    scanf("%lf %lf %lf %lf", &invest, &n, &consumoefic, &consumoinef);
    frc=(0.1*potencia(1.1, n))/(potencia(1.1, n)-1.0);
    a=(consumoinef*12-consumoefic*12)*0.25;
    vpl=-invest+(a/frc);
    printf("A = R$%.2f\n", a);
    printf("FRC = %.5f\n", frc);
    printf("VPL = R$%.2f\n", vpl);
    return 0;
}

