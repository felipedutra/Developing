#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 400
#define MAX2 160000
#define FNMAX 200
#define true 1
#define false 0
int LeDesenho( char nomearq[FNMAX], int M[MAX][MAX],int *pm, int *pn, int *pmax );
int LeTexto( char nomearq[FNMAX], char T[MAX2], int *pk );
int BeDe( int k, int m, int n, int *pb, int *pd );
int ProximosBBits( char T[MAX2], int b, int *pik, int *pib );
void Codifica( int D[MAX][MAX], int m, int n, char T[MAX2], int k,
int Dl[MAX][MAX], int b, int d, int modo );
int Maximo( int D[MAX][MAX], int m, int n );
int EscreveDesenho( char nomearq[FNMAX], int M[MAX][MAX],
int m, int n, int max );
void DeBeDe( int D[MAX][MAX], int Dl[MAX][MAX],
int m, int n, int *pb, int *pd );
int DeCodifica( int D[MAX][MAX], int Dl[MAX][MAX], int m, int n,
int b, int d, char T[MAX2], int modo );
int EscreveTexto( char nomearq[FNMAX], char T[MAX2], int k );

int EscreveTexto( char nomearq[FNMAX], char T[MAX2], int k )
{

     FILE *fp;
    int i,erro;
        if (!(fp = fopen(nomearq, "w"))) {
            printf("Erro ao abrir o arquivo %s\n", nomearq);
            erro=true;
            /* mais comandos para lidar com o erro na abertura do arquivo */
        }
        for(i=0;i<k-2;i++)
    {
        fprintf(fp,"%c",T[i]);
    }
    fclose(fp);
    return(erro);
}
int DeCodifica( int D[MAX][MAX], int Dl[MAX][MAX], int m, int n,
int b, int d, char T[MAX2], int modo ){
    int i,dig,j,B,pik,pib=0,k=0;
    int m2,n2,x,y,z,multi=1,num=0;
    int V[MAX],erro=false;
    m2=m/d;
    m2*=d;
    n2=n/d;
    n2*=d;
    B=1;
    pik=0;
            for(i=0;i<b;i++)
            {
                B*=2;
            }
        for(i=d-1;i<=m2-1;i=i+d){                           /*VERIFICAR SE O <= ATRAPALHA*/
                for(j=d-1;j<=n2-1;j=j+d){
                    if(!(i==d-1&&j==d-1)){
                        z=Dl[i][j];
                        x=D[i][j];
                        y=(z-x+256)%B;
                        V[k]=y;
                        k++;
                    }
                    }

            }
        for(i=0;i<k;i++)
        {
            printf("%d ",V[i]);
        }

        j=0;
        for(i=0;i<k;i++)
        {
                    y=V[i];
                    /*Converte V[i]*/
                    dig=y%B;
                    y=V[i];
                    printf("dig=%d multi=%d\n",dig,multi);

                    num=num+multi*dig;
                    multi=multi*B;


               if((i+1)%B==0){
                    multi=1;
                    printf("num= %d\n",num);
                    T[j]=num;
                    j++;
                    num=0;
               }


        }
        printf("%s\n k=%d",T,k/7+2);




  return(k);
}
void DeBeDe( int D[MAX][MAX], int Dl[MAX][MAX],
int m, int n, int *pb, int *pd ){
    int i,j;
    int acha=0;

    /*achando o d*/
    for(i=0;i<m&&!acha;i++){
        for(j=0;j<n&&!acha;j++){
        acha=Dl[i][j]-D[i][j];   /*ACHA RECEBEU Z-X  */


            if(acha){
                (*pd)=i+1;
                (*pb)=(acha+256)%acha;
                        V[k]=y;  /*Valor somado a posicao d-1 d-1 com o valor de b*/
            }
            }
    }


   return;


}
int EscreveDesenho( char nomearq[FNMAX], int M[MAX][MAX],
int m, int n, int max ){
    int erro=false;
    int i,j;
    FILE *fp;
    if (!(fp = fopen(nomearq, "w"))) {
        printf("Erro ao abrir o arquivo %s\n", nomearq);
        erro=true;
        /* mais comandos para lidar com o erro na abertura do arquivo */
        }
    fprintf(fp, "P2\n%d %d\n%d\n", n,m,max);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                fprintf(fp, "%03d ", M[i][j]);
            }
            fprintf(fp, "\n");
        }
    printf("ERRO=%d",erro);
    fclose(fp);
    return(erro);
}
int Maximo( int D[MAX][MAX], int m, int n )
{
    int i,j,maximus;
    maximus=D[0][0];
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(D[i][j]>=maximus)
            {
                maximus=D[i][j];
            }
        }

    }
    return(maximus);
}
void Codifica( int D[MAX][MAX], int m, int n, char T[MAX2], int k,
int Dl[MAX][MAX], int b, int d, int modo )
{

    int i,j,x,y,z,B;
    int m2, n2; /* valores maximos de d x==d/m, y==d/n*/
    int pik=0,pib=0;  /*pik==Valores da posição e pib==Quantos bits menos significativos ignorados */
    int erro=false;
    printf("Iniciando a codificacao\n");
        m2=m/d;
        m2*=d;
        n2=n/d;
        n2*=d;
      for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                    Dl[i][j]=D[i][j];

            }
        }

        if(!erro){
            B=1;
            for(i=0;i<b;i++)
            {
                B*=2;
            }
            printf("(%d,%d)\n",pik,y);

    for(i=d-1;i<=m2-1;i=i+d){                           /*VERIFICAR SE O <= ATRAPALHA*/
                for(j=d-1;j<=n2-1;j=j+d){
                        x=D[i][j];
                        z=x/B;
                        z=z*B;
                        y=ProximosBBits(T,b,&pik,&pib);
                        z+=(x+y)%B;
                        Dl[i][j]=z;
                        printf("(%d,%d)\n",pik,y);

        }

    }
    /*FIM Alterando as posicoes de D1*/

    }

}
int ProximosBBits( char T[MAX2], int b, int *pik, int *pib )
{
     int num,i,B=1;
        if(*pik==0){
            num=b;
            }else{
                num=T[*pik-1];
            }
        /* REMOVENDO OS BITS ANTERIORES*/
        for(i=0;i<*pib;i++)
        {
            num/=2;
        }

       /*ACHANDO OS PROXIMOS b BITS*/
        for(i=0;i<b;i++){
            B*=2;
        }
        num=num%B;
        *pib+=b;

        if((*pib)>7){
            *pib=0;
            *pik+=1;
        }

       if((*pik)==0)
        {
            (*pik)+=1;
            (*pib)=0;

        }






        printf("y=%d pib=%d  pik=%d B=%d\n",num,*pib,*pik,B);
        return(num);

}
int BeDe( int k, int m, int n, int *pb, int *pd )
   {
    int b,d,erro;
    /*Descobrindo o b*/
    b=1;
    erro=false;
    while(((m*n)-1)*b<(8*k)&&b<8){
        b=2*b;
    }
    if(b>8){
        /*A funcao deu ruim*/
        erro=true;
        printf("erro =%d\n",erro);

    }
    printf("b=%d\n",b);
    /*Descobrindo o d*/
    if(!erro){
            erro=true;
    for(d=m*n;((m/d)*(n/d)*b<8*k+b)&&d>1;d--)
    {

        if(d<m&&d<n){
        erro=false;
    }
    if(d<1)
    {
        erro=true;
    }
    }
    }
	*pb=b;
	*pd=d;
    printf("d=%d\n",d);
    printf("erro =%d\n",erro);
    return (erro);
}
int LeDesenho( char nomearq[FNMAX], int M[MAX][MAX],int *pm, int *pn, int *pmax )
{
    FILE *fp;
    int erro;
    int i,j;   /*Indices da matriz M*/
    char c;
    if (!(fp = fopen(nomearq, "r"))) {
    printf("Erro ao abrir o arquivo %s\n", nomearq);
    erro=true;
/* mais comandos para lidar com o erro na abertura do arquivo */
    }else{
    erro=false;
    }
    if(!erro){
        fscanf(fp,"%c %d",&c,&j);
        fscanf(fp, "%d %d %d ", &(*pn),&(*pm),&(*pmax));
        printf("%d %d %d\n",*pn,*pm,*pmax );

        if((*pn)>MAX||(*pm)>MAX||(*pmax)>255){
            erro=true;
        }
        }
        if(!erro){
        for(i=0;i<*pm;i++){
            for(j=0;j<*pn;j++){
                fscanf(fp," %d ",&M[i][j]);
            }
        }


        }

    fclose(fp);



    return(erro);


}

int LeTexto( char nomearq[FNMAX], char T[MAX2], int *pk )
{
    FILE *fp;
    int erro=false; /*De inicio a funcao nao tem erro*/
    int i;

    if (!(fp = fopen(nomearq, "r"))) {
    printf("Erro ao abrir o arquivo %s\n", nomearq);
    erro=true;
    /* mais comandos para lidar com o erro na abertura do arquivo */
    }
    if(!erro){
    for(i=0;fscanf(fp,"%c",&T[i])>0&&i<MAX2;i++)
    {
    *pk=i;
    }

    if(i>=MAX2){
        erro=true;
    }
    }

    fclose(fp);
    printf("ERRO= %d\n",erro);
    return (erro);
}

int main ()
{
    char nomearq[MAX];
    char T[MAX2];
    int D [MAX][MAX];
    int Dl[MAX][MAX];
    int M [MAX][MAX];
    int pb; /* Ponteiro de b*/
    int pd; /* Ponteiro de d*/
    int pk; /* numero de caracteres do texto*/
    int pm; /*numero de linhas */
    int pn; /* numero de colunas*/
    int pmax; /*valor maximo que codifica um tom de cinza*/
    int m,n,k,b,d;
    int i,j,erro,op,modo=0;
    int esc; /* O numero que o usuario escolheu*/



    printf("Digite o que voce quer:\n");

    do  {
    printf("1)codifica\n2)Decodifica\n");
    scanf(" %d",&esc);
    printf("%d\n",esc);

    if(esc==1){
            /*Codificando*/
        printf("Digite o nome do arquivo que contem o desenho original:\n");
        scanf(" %[^\n]", nomearq);
       erro= LeDesenho(nomearq,D,&pm,&pn,&pmax);
        if(!erro){
        for(i=0;i<pm;i++){
            for(j=0;j<pn;j++){
            printf("%03d ", D[i][j]);
            }
            printf(" \n");

        }
        }
            printf("\n\n");
        if(!erro){

        printf("Digite o nome do arquivo que contem o texto:\n");
        scanf(" %[^\n]", nomearq);
        erro= LeTexto(nomearq,T,&pk);
        }
         if(!erro){

            printf ( "O texto e:\n%s \nk=%d \n" , T,pk ) ;

        erro=BeDe(pk,pm,pn,&pb,&pd);
                printf("ERRO= %d\n",erro);
            }
                if(!erro){

        Codifica(D,pm,pn,T,pk,Dl,pb,pd,modo);
        printf("pm=%d pn=%d pk=%d pb=%d pd=%d \n",pm,pn,pk,pb,pd,modo);
        printf("Digite o nome em que sera gravado a imagem modificada:\n");
        scanf(" %[^\n]", nomearq);
                }
        if(!erro){
        pmax=Maximo(Dl,pm,pn);

         for(i=0;i<pm;i++){
            for(j=0;j<pn;j++){
            printf("%03d ", Dl[i][j]);
            }
            printf(" \n");

        }

        erro=EscreveDesenho(nomearq,Dl,pm,pn,pmax);
        printf("ERRO= %d\n",erro);

        }

    }


    /*PAREI NA FUNÇÃO CODIFICA
    */
    /*FUNCAO DECODIFICA*/
    if(esc==2)
        {

            printf("Digite o nome do arquivo que contem o desenho original:\n");
            scanf(" %[^\n]", nomearq);
            erro=LeDesenho(nomearq,D,&pm,&pn,&pmax);
            if(!erro)
            {
                m=pm;
                n=pn;
                printf("Digite o nome do arquivo que contem o desenho com esteganografia:\n");
                scanf(" %[^\n]", nomearq);
            }
            erro=LeDesenho(nomearq,Dl,&pm,&pn,&pmax);
            if(pm!=m||pn!=n){
                erro=true;
                printf("As imagens nao sao iguais.\n");
                }
            if(!erro){
                DeBeDe(D,Dl,m,n,&pb,&pd);
                printf("b=%d d=%d \n",pb,pd);

                k=DeCodifica(D,Dl,pm,pn,pb,pd,T,modo);
            }
            if(!erro){
                printf("Digite o nome do arquivo que deseja gravar a mensagem:\n");
                scanf(" %[^\n]", nomearq);
                EscreveTexto(nomearq,T,k);
                }




        }

    }while(esc);

    return (0);
}




