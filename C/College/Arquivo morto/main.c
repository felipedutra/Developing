#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main()
{
     char c;
     int b,B=1,x, pik, pib ;
     int num,i,proximos,cont;

        printf("Digite b ,pik,pib e c\n");
        scanf("%d %d %d %c",&b,&pik,&pib,&c);
        num=c;
        c='p';
        printf("%d\n",num);
        for(i=0;i<pib;i++)
        {
            num/=2;
        }
        pib+=b;
        if(pib>7){
            pib=0;
            pik+=1;
        }
        B=1;
        proximos=num%(2*b);
        for(i=0;i<b;i++)
        {
         B=2*B;
        }
        x=proximos+256;
        x=x%B;
        printf("x=%d B=%d\n",x,B);


        c=x;

        printf("pik pib proximos\n %d   %d  %d\nValor original %c",pik,pib,x,c);

/*int num,i,proximos,erro;

        num=T[*pik-1];
        if(b==8&&(*pik)){
            proximos=T[*pik-1];
            erro=true;
        }

        for(i=0;i<*pib;i++)
        {
            num/=2;
        }
        *pib+=b;
        if(*pib>7){
            *pib=0;
            *pik+=1;
        }
        if(!erro)
        proximos=num%(2*b);


        return(proximos); */


    return 0;
}
