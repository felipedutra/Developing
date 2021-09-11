#include <stdio.h>
#define MAX 1000
/*
Faça um programa que leia um inteiro 0 < k <= 1000,
e os k+1 coeficientes reais de um polinômio p de grau k e
três reais x0, x1 e x2 e imprima p(x0), p'(x1) e p''(x2)
*/
double potencia(double x,int k,double a );
double avalia (double p[MAX], int k, double x);
void deriva (double p[MAX], int *k);
void deriva (double p[MAX], int *k){
    int i;
    for(i=0;i<*k+1;i++)
    {
        p[i]=i*p[i];
    }
    for(i=0;i<*k;i++)
    {
        p[i]=p[i+1];
    }
    *k-=1;

}
double potencia(double x,int k,double a ){
    double f;
    f=a;
    while(k){
        f*=x;
        k--;
    }
    return(f);
}
double avalia (double p[MAX], int k, double x)
{
    int i;
    double f,num=0.0;
    for(i=0;i<k+1;i++){
        f=p[i];
        num+=potencia(x,i,f);
    }
    return(num);

}

int main()
{
        double f,y;
        double p[MAX],pr[MAX],x[MAX];
        int i,k;
        printf("Digite o valor do grau do polinomio :\n");
        scanf("%d",&k);
        printf("Digite os coeficientes do polinomio:\n");
        for(i=0;i<k+1;i++)
        {
            scanf("%lf",&p[i]);
        }
        printf("Digite tres valores:\n");
        for(i=0;i<2;i++){
        scanf("%lf ",&x[i]);
        }
        for(i=0;i<3;i++){
        f=x[i];
        deriva(p,&k);
        f=avalia(p,k,f);
        printf("%g ",f);


        }
        return 0;
 }
