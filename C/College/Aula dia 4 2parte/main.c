#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 100
int perm(int V[MAX],int n);
int perm (int V[MAX], int n)
{
    int i,j,verdade=true,k=n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {


        if(i+1!=V[i])
        {
            k--;
        }
        }
        if(k==1){
            verdade=false;
        }
    }
    return (verdade);
}

int main()

{
    int M[MAX][MAX];
    int V[MAX];
    int m,n,i,j,k=0;
    int romana=true;
    printf("Digite o numero de linhas e colunas da matriz:\n");
    scanf("%d %d",&m,&n);
    printf("Digite a matriz:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++){
        scanf(" %d ",&M[i][j]);
        k++;
        }
    }
    while(k){
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++){
        V[j]=M[i][j];
        }
        romana= perm(V,n);
        if(!romana){
            printf("A matriz nao e romana");
        }
        k--;
    }
        for(j=0;j<n;j++){
            for(i=0;i<m;i++){
            V[i]=M[i][j];
        }
        romana = perm(V,m);
        if(!romana){
            printf("A matriz nao e romana");

        }
        k--;
    }

    }
    if(romana){
        printf("A matriz e romana");
    }


    return 0;
}
