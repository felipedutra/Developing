/*
  Dados dois números positivos 0 < m < 1000 e 0 < n < 1000
 e duas sequências crescentes com m e n números inteiros,
 obter uma única sequência crescente contendo todos os
  elementos das sequências originais.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int main()
{
    int m,n,k;
    int i,j,num=MAX,numant1=-MAX,numant2=-MAX;
    int vetor1[MAX], vetor2[MAX];
        printf("Digite quantos elementos ha na sequencia 1:\n");
        scanf("%d",&m);
        printf("Digite a sequencia:\n");
            for(i=0;i<m;i++)
            {
                scanf("%d",&vetor1[i]);
            }
        printf("Digite quantos elementos ha na sequencia 2:\n");
        scanf("%d",&n);
        printf("Digite a sequencia:\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&vetor2[i]);
            }
            k=m+n;
            for(j=0;j<k;j++){
                for(i=0;i<n;i++){
                    if(vetor1[i]<num&&vetor1[i]>numant1){
                            numant1=num;
                        num=vetor1[i];
                    }
                }
                for(i=0;i<n;i++){
                    if(vetor2[i]<num&&vetor2[i]>numant2){
                            numant2=num;
                        num=vetor2[i];
                    }
                }
                if(num!=MAX){
                printf("%d ",num);
                }
                num=MAX;
            }




    return 0;
}
