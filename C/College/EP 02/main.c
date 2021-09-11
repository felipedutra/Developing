/***************************************************************/
/**                                                           **/
/** Felipe Dutra Teixeira  N Usp 11806851                     **/
/** Exercicio programa 02                                     **/
/** Professor: Marcel Kenji                                   **/
/** Turma: (02)                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BISSEC_TOL (1e-6)
/* #define RANDOM_SEED 1234 */
void ativa_sorteador();
double sorteia_real();

/* Funcoes implementadas */
int sorteia_voto_com_falha (double f);
double bissecta (int N, double a, int T, double tol);
double prob_erro (int N, double a, double f, int T);

/* "da a partida" no gerador de numeros aleatorios */
void ativa_sorteador()
{
#ifdef RANDOM_SEED
srand(RANDOM_SEED);
#else
srand(time(NULL));
#endif
}
/* devolve um real sorteado uniformemente no intervalo [0,1] */
double sorteia_real()
{
return (double) rand() / RAND_MAX;
}
/*Descricao das funcoes implementadas*/
int sorteia_voto_com_falha (double f)
{
    double sorteado;

    int n;
    sorteado=sorteia_real();


    if(sorteado-f<=BISSEC_TOL)             /*Voto falhou*/
    {
        n=1;
    }
    if(sorteado-f>BISSEC_TOL)            /*Voto nao falhou*/
    {
       n=0;
    }
    return(n);
}

double prob_erro (int N, double a, double f, int T)
{
    double A;              /*Numero de votos que o candidato A recebeu.         */
    double B;              /*Numero de votos que o candidato B recebeu.         */
    double VcFA;               /*Numero de votos COM FALHA DO CANDIDATO A.          */
    double VcFB;               /*Numero de votos COM FALHA DO CANDIDATO B.          */
    int i,n,w;                /*Contadores de passagem.                            */
    double ecF=0.0;                /*Numero de eleicoes com falha                       */
        A=a*N;
        B=N-A;
        for(i=T;i>0;i=i-1)
        {
            n=A;
            for(VcFA=0;n>0;n=n-1)
            {
                w=sorteia_voto_com_falha(f);
                if(w!=0)                    /*Calcula quantos votos de A falharam*/
                {
                    VcFA=VcFA+1;
                }
            }
                n=B;
            for(VcFB=0;n>0;n=n-1)
            {
                w=sorteia_voto_com_falha(f);
                if(w!=0)  /*Calcula quantos votos de A falharam*/
                {
                    VcFB=VcFB+1;
                }
            }
                A=A+VcFB-VcFA;           /*    Troca de votos errados A recebe B */
                B=B+VcFA-VcFB;           /*    Troca de votos errados B recebe A */
                if(A-B<=BISSEC_TOL)
                {
                    ecF=ecF+1;
                }
                A=N*a;
                B=N-A;

        }
        ecF=ecF/T;
        return (ecF);
}
double bissecta (int N, double a, int T, double tol)
{
    double fa=0.0;                      /* Probabilidade de erro nas urnas que A ganha*/
    double fb=1.0;                      /* Probabilidade de erro nas urnas que b 'ganha'*/
    double f;
    double P;                           /*Probabilidade de erro na eleicao*/
        while(fb-fa>=BISSEC_TOL)
        {
            f=(fa+fb)/2;
            P=prob_erro(N,a,f,T);         /*Chance de B ganhar           */

            if(P-tol<BISSEC_TOL)
            {
                fa=f;
            }
            else
            {
                fb=f;
            }
        }


        return(f);

}




int main()
{
    int N,T;
    double a,tol,f;
    ativa_sorteador();
    printf(" Digite o numero de votantes (0 < N <= 2x10^9):\n");
    scanf("%d",&N);
    printf("Digite a porcentagem de votos do candidato A (0.5 < a <= 1):\n");
    scanf("%lf",&a);
    printf("Digite o numero de simulacoes (0 < T <= 2x10^9):\n");
    scanf("%d",&T);
    printf("Digite a probabilidade toleravel de erros (0 <= tol <= 1):\n");
    scanf("%lf",&tol);
    f= bissecta (N,a,T,tol);


    printf("Maior falha das urnas toleravel: %g",f);
    return (0);
}
