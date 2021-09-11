#include <stdio.h>
#include <stdlib.h>
#define MAX 37
int main()
{

    int vetor[MAX];
    int n,i,freq,num;
    printf("Digite quantos lancamentos ocorreram:\n");
    scanf("%d",&n);
    printf("Digite os resultados:\n");
    for(i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    for(num=0;num<36;num++){
        freq=0;
        for(i=0;i<n;i++){
            if(num==vetor[i]){
                freq++;
            }
        }
        if(freq){
        printf("%.2d aparece %.2d vezes \n",num, freq);
        }
    }
    return 0;
}
