#include <stdio.h>
#include <stdlib.h>
#define MAX 102
int moldurador(int A[MAX][MAX], int *m, int *n);
int moldurador(int A[MAX][MAX], int *m, int *n){
    int i,j;
    /*transladando a coluna para a direita*/
    for(i=0;i<(*n);i++){
        for(j=0;j<(*n)+1;j++){
            A[i][*m-j+1]=A[i][*m-j];

        }

    }
    for(j=0;j<(*n)+1;j++){
        for(i=0;i<(*m)+1;i++){
            A[*n-i+1][j]=A[*n-i][j];
        }
    }
    *m=*m+2;
    *n=*n+2;
    for(i=0;i<(*n)+1;i++)
    {
    A[i][0]=-2;
    A[i][(*m-1)]=-2;
    }
    for(j=0;j<(*m);j++)
    {
    A[0][j]=-2;
    A[(*n-1)][j]=-2;
    }





}

int conta_minas (int A[MAX][MAX], int m, int n, int i, int j);
int conta_minas (int A[MAX][MAX], int m, int n, int i, int j)
{
    int k,l,contador=0;
    for(k=(i-1);k<(i+2);k++){
        for(l=(j-1);l<(j+2);l++){
            if(A[k][l]==-1){
                contador ++;
            }
        }
    }

    return(contador);
}

int main()
{
    int A[MAX][MAX];
    int i,j; /*Indices de matrizes*/
    int n,m,contado; /*Valores das quantidades de linhas e colunas*/
    printf("Digite a quantidade de linhas e colunas da matriz (nxm):\n");
    scanf("%d %d",&n,&m);
    printf("Digite a matriz:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }
       printf("\n");

    moldurador(A,&m,&n);
     for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
        A[i][j]=conta_minas(A,m,n,i,j);


        }

    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%3d ",A[i][j]);
        }
               printf("\n");

    }

    conta_minas(A,m+2,n+2,i,j);
    return 0;

}
