#include <stdio.h>
#define MAX 100
#define true 1
#define false 0

int main()
{
    int i,j,m=1,n,simetrica=true,nula;
    int M[MAX][MAX];
    printf("Digite a ordem da matriz(0<n<100): \n");
    scanf("%d",&n);
    printf("Digite a matriz:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&M[i][j]);
        }
    }
    /*Verificando se a matriz e' simetrica*/
    for(i=0;i<n;i++){
        for(j=m;j<n;j++){
            if(M[i][j]!=M[j][i]){
                simetrica=false;
            }

        }
        m++;
    }
    if(simetrica){
        printf("A matriz e' simetrica.\n");
    }else {
        printf("A matriz nao e' simetrica.\n");
    }
    /*Verificando se ha uma linha nula*/
     for(i=0;i<n;i++){
        nula=true;
        for(j=0;j<n;j++){
            if(M[i][j]){
                nula=false;
            }
        }
            if(nula){
                printf("A linha  %d e' nula.\n",i+1);
            }

     }
    /*Verificando se ha uma linha nula*/
     for(j=0;j<n;j++){
        nula=true;
        for(i=0;i<n;i++){
            if(M[i][j]){
                nula=false;
            }
        }
            if(nula){
                printf("A coluna %d e' nula.\n",j+1);
            }

     }
     /*Verificando se a diagonal principal e' nula*/
     nula=true;
     for(i=0;i<n;i++){
        if(M[i][i]!=0){
            nula=false;
        }
     }
     if(nula){
     printf("A diagonal principal e' nula\n");
     }
    /*Verificando se a diagonal secundaria e' nula*/
     nula=true;
     for(i=0;i<n;i++){
        if(M[i][n-1-i]!=0){
            nula=false;
        }
     }
     if(nula){
     printf("A diagonal secundaria e' nula\n");
     }








    return 0;

}
