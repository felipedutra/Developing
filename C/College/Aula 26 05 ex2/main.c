#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void insere (int v[MAX], int *m, int x);
void insere (int v[MAX], int *m, int x)
{
    int i;
    *m+=1;
    i=*m-1;
    v[i]=x;
}
int main()
{
    int v[MAX],i,m,x=0;
    printf("Digite a quantidade de termos do vetor:\n");
    scanf("%d",&m);
    printf("Digite os termos do vetor:\n");
    for(i=0;i<m;i++){
        scanf("%d",&v[i]);
        x+=v[i];
    }/*
    for(i=0;i<m;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
*/
    insere(v,&m,x);

    for(i=0;i<m;i++){
        printf("%d ",v[i]);
    }
}
