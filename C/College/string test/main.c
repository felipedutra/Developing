#include <stdio.h>
#include <stdlib.h>
#define MAX 100
/*
Dada uma string (sequ?ncia de caracteres terminada por '\0'),
com no m?ximo 1000 caracteres, contar o n?mero de ocorr?ncias de cada letra do alfabeto.
a. Escreva uma fun??o de prot?tipo
int ocorre (char u[MAX], char v[MAX], int i);
que recebe duas strings u e v, e um ?ndice
 0 <= i < MAX, e devolve 1 se a string v aparece em u a partir da posi??o i,
  ou 0 caso contr?rio.
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
