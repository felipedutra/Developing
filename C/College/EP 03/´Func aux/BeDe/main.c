#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()

{
    int k,m, n,pb, pd;
    int b,d,erro;
    printf("Digite m,n e k:\n");
    scanf("%d %d %d",&m,&n,&k);
    /*Descobrindo o b*/
    b=1;
    erro=false;
    while(((m*n)-1)*b<(8*k)&&b<8){
        b=2*b;
    }
    if(b>8){
        /*A funcao deu ruim*/
        erro=true;
        printf("erro =%d",erro);

    }
    printf("b=%d\n",b);
    /*Descobrindo o d*/
    for(d=m*n;(m/d)*(n/d)*b<8*k+b;d--)
    {
        erro=true;
        if(d<m){
        erro=false;
    }
    }
    printf("d =%d\n",d);
    printf("erro =%d",erro);
    return (0);
}
