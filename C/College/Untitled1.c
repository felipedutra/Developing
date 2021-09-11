#include<stdio.h>
int main()
{
   double x,soma,termo;
   int n, k;
   printf("Digite um termo 0<x<6.28 e um termo de precisão n ");
   scanf("%lf %d", &x,&n);
   soma=0.0;
   termo=x;
   k=0;
   while(k<n)
   {
       soma+=termo;
       k++;
       termo*= -x*x;
       termo/=(2*k)*(2*k+1);
   }
   printf("%.16f\n",soma);
   return 0;
}
