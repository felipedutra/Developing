#include <iostream>
#include <stdexcept>
#include "Disciplina.h"
#include "Aluno.h"

using namespace std;

int main() {
  try {
    Disciplina *d = new Disciplina();
    d->adicionarAluno ("Ana", 10, 10, 10, -1);
    d->adicionarAluno ("Joao", 5, 5, 5, 3);

    d->imprimir();
  } catch (invalid_argument *e) {
    cout << "Erro: " << e->what();
    delete e; // limpando!
  }

  return 0;
}
