#include "Disciplina.h"
#include <stdexcept>
#include <string>

using namespace std;

Disciplina::Disciplina() {
  this->numeroDeAlunos = 0;
}

void Disciplina::adicionarAluno (string nome, double notaP1,
                                 double notaP2,
                                 double notaP3, int faltas) {
  if (nome.empty() ) throw new invalid_argument ("Nome vazio");
  else if (notaP1 < 0 || notaP1 > 10 || notaP2 < 0
           || notaP2 > 10 ||
           notaP3 < 0 || notaP3 > 10)
    throw new invalid_argument ("Nota invalida");
  else if (faltas < 0)
		throw new invalid_argument ("Falta negativa");

  this->alunos[numeroDeAlunos++] = new Aluno (nome, notaP1,
      notaP2,
      notaP3, faltas);
}

void Disciplina::imprimir() {
  for (int i = 0; i < numeroDeAlunos; i++) {
    alunos[i]->imprimir();
  }
}

Disciplina::~Disciplina() {
  for (int i = 0; i < numeroDeAlunos; i++) {
    delete this->alunos[i];
  }
}
