#include <iostream>
#include <stdexcept>
#include "Disciplina.h"
#include "Aluno.h"

using namespace std;

int main() {
  Disciplina *d = new Disciplina();
  d->adicionarAluno ("Ana", 10, 10, 10, -1);
  d->adicionarAluno ("Joao", 5, 5, 5, 3);

  d->imprimir();
  return 0;
}
