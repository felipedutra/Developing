#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void contagem(int v[MAX],int*m);
void contagem(int v[MAX],int *m){
    int i,j,num;
    for(i=0;i<*m;i++){
        num=v[i];
        for(j=0;j<*m;j++){
            if(num==v[j]&&j!=i){
                v[j]=v[*m-1];
                *m-=1;
            }
        }
    }
}
int main()
{
    int i, m;
    int v[MAX];
    printf("Digite a quantidade de elementos do vetor:\n");
    scanf("%d",&m);
    printf("Digite os elementos do vetor:\n");

        for(i=0;i<m;i++){
            scanf("%d",&v[i]);
        }
        contagem(v,&m);
        for(i=0;i<m;i++){
            printf("%d "
                   ,v[i]);
        }
        return 0;
}
