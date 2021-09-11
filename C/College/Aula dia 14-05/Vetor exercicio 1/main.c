/*Dado um inteiro n > 0 e uma sequência
de n lançamentos de uma roleta (números inteiros no intervalo [0,36]),
calcular a frequência de cada número.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int main()
{
    int n, i,quantos=0.0;
    double vetor[MAX];
    double media=0.0;
    printf("digite quantas notas e as notas:");
    scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lf",&vetor[i]);
            media+=vetor[i];
            }
    media/=n;
        for(i=0;i<n;i++)
        {
            if(vetor[i]>=media){
                quantos++;
            }
        }
    printf("%d alunos tiveram nota maior que a media %.2f",quantos, media);
        return 0;

}
