/* */
#include<stdio.h>
int main()
{
    double n,soma,eps;
    int k;
    k=1;
    n=1.0;
    soma=0.0;
    eps=0.00000001;
    /* soma= 1-1/2+1/3-... */
    /* Calculemos primeiro a soma dos termos da esquerda para a direita*/
    while(n>=eps||-n>=eps){
    n= double/k;
    soma= -1*(k-1)*n;
    k++;
    }
    printf("%.16f",soma);
    return 0;

}
