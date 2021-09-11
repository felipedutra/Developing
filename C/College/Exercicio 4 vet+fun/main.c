#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
void interseccao(int A[MAX], int B[MAX], int C[MAX]);
void interseccao(int A[MAX], int B[MAX], int C[MAX]){
  int num,i,j,n;
  C[0]=0;



}
int main()
{
    int A[MAX], B[MAX], C[MAX];
    int i;
    printf("Digite a quantidade e os termos do conjunto A:\n");
    scanf("%d",&A[0]);
    for(i=1;i<A[0]+1;i++){
        scanf("%d",&A[i]);
    }
    printf("Digite a quantidade e os termos do conjunto B:\n");
    scanf("%d",&B[0]);
    for(i=1;i<B[0]+1;i++){
        scanf("%d",&B[i]);
    }
    printf("Digite a quantidade e os termos do conjunto C:\n");
    scanf("%d",&C[0]);
    for(i=1;i<C[0]+1;i++){
        scanf("%d",&C[i]);
    }
    interseccao(A,B,C);
    for(i=1;i<C[0];i++){
        printf("%d",A[i]);
    }
}
