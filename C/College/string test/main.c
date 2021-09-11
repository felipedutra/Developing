#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
Dada uma string (sequência de caracteres terminada por '\0'),
com no máximo 1000 caracteres, contar o número de ocorrências de cada letra do alfabeto.
a. Escreva uma função de protótipo
int ocorre (char u[MAX], char v[MAX], int i);
que recebe duas strings u e v, e um índice
 0 <= i < MAX, e devolve 1 se a string v aparece em u a partir da posição i,
  ou 0 caso contrário.
*/
int main()
{
    char u[MAX], v[MAX];
    int i,j=1;
    printf("Digite as letras dos vetores:\n");
    scanf("%[^\n]",u);
    for(i=0;u[i];i++){
        if(u[i]!=' '){
        u[i]=u[i]+j;
        }
        if(j>26)
            j=0;

    }
    printf("%s\n",u);


    return 0;
}
