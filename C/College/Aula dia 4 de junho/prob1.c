/* 

(a) Escreva uma função de protótipo

int conta_minas (int A[MAX][MAX], int m, int n, int i, int j);

que recebe como parâmetros uma matriz inteira A_{n x m}, e 
uma posição (i,j) livre da matriz A (A[i][j] = 0), 
e devolve o número de posições ao redor da posição (i,j) que
contêm o valor -1, assumindo que a matriz tem uma moldura com -2.

(b) Escreva um programa que lê inteiros 0 < n, m <= 100, 
e uma matriz A_{n x m} de 0's (posições livres) e -1's (minas). 
Seu programa deverá fazer uma "moldura" de -2 ao redor dos 
elementos da matriz. Utilizando, então, a função do item anterior, 
o programa deve computar e imprimir a quantidade de minas 
ao redor de cada posição livre da matriz.

*/ 
#include <stdio.h> 
#define MAX 102

int conta_minas(int A[MAX][MAX], int m, int n, int i, int j); 


int conta_minas(int A[MAX][MAX], int m, int n, int i, int j)
{
  int conta = 0, k, l;
  for (k = i-1; k <= i+1; k++){
    for (l = j-1; l <= j+1; l++){
      if(A[k][l] == -1){
        conta++;
      }
    }
  }
  return conta; 
} 

int main()
{
  int n, m, A[MAX][MAX], i, j;

  printf("Digite 0 < n,m <= 100: "); 
  scanf("%d %d", &n, &m);

  for (j = 1; j <= m; j++){
    A[0][j] = -2; 
    A[n+1][j] = -2; 
  } 
  for (i = 0; i <= n+1; i++){
    A[i][0] = -2;
    A[i][m+1] = -2; 
  } 

  printf("Digite os elementos da matriz (0 livre, -1 mina): \n");
  for (i = 1; i <= n; i++){
    for (j = 1; j <= m; j++){
      scanf("%d", &A[i][j]);
    }
  }

  printf ("Matriz original: \n"); 
  for (i = 0; i <= n+1; i++){
    for (j = 0; j <= m+1; j++){
      printf("%3d ", A[i][j]); 
    } 
    printf("\n"); 
  } 
    
  for (i = 1; i <= n; i++){
    for (j = 1; j <= m; j++){
      if (A[i][j] == 0){
	A[i][j] = conta_minas(A, n, m, i, j); 
      }
    }
  }

  printf ("Matriz numerada: \n"); 
  for (i = 0; i <= n+1; i++){
    for (j = 0; j <= m+1; j++){
      printf("%3d ", A[i][j]); 
    } 
    printf("\n"); 
  } 
  return 0;
}
