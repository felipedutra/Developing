#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define true 1
#define false 0
int acha (int v[MAX], int n, int x);
int acha (int v[MAX], int n, int x)
{
    int i,posi=-1,num,existe=false;
    for(i=0;i<n;i++){
        num=v[i];
        if(num==x){
            posi=i+1;
            printf("A posicao de %d e' %d \n",x,posi);
            existe=true;
        }
    }
    if(!existe){
        printf("-1");
    }
   return (posi);


}



int main()
{
    int i, n, posi,x;
    int v[MAX];
    printf("Digite a quantidade de elementos do vetor:%d \n %d \n",103%8,((256-7)%8)*8);
    scanf("%d",&n);
    printf("Digite os elementos do vetor%\n");

        for(i=0;i<n;i++){
            scanf("%d",&v[i]);
        }
    printf("Digite o elemento que voce deseja descobrir a posicao do vetor:\n");
    scanf("%d",&x);
    posi=acha(v,n,x);


    return 0;
}
