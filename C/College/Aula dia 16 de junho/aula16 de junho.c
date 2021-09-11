#include<stdio.h>
#define MAX2 1000
#define MAX 100

int main()
{
    int D[MAX][MAX], D1[MAX][MAX];
    int m, n,i,j;
    printf("Digite os indices da matriz:\n");
    scanf("%d %d",&m,&n);
     printf("Digite a matriz:\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&D[i][j]);
            }
        }
        printf("A matriz e':\n");

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d ",D[i][j]);
            }
            printf("\n");
        }
         for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(i==j)
                D1[i][j]=D[i][j];
            }
            printf("\n");
        }
        printf("\n");
         for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d ",D1[i][j]);
            }
            printf("\n");
        }



}
