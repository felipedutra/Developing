#include <stdio.h>

#define NMAX 160000
#define NARQ 200

int main()
{
  char texto[NMAX + 1];
  char nome[NARQ];
  FILE *fp;
  int i;

  scanf("%199s", nome); /* 199 = NARQ - 1 */
  if (!(fp = fopen(nome, "r"))) {
    printf("Erro ao abrir o arquivo %s\n", nome);
    return 1;
  }

  i = 0;
  while (i < NMAX && fscanf(fp, "%c", &texto[i]) > 0)
    i++;

  texto[i] = '\0';

  printf("Texto (%d caracteres): '%s'\n", i, texto);

  fclose(fp);
  return 0;
}
