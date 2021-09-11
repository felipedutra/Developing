#include "Aluno.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

Aluno::Aluno (string nome, double notaP1, double notaP2,
              double notaP3, int faltas) {
  this->nome = nome;
  this->notaP1 = notaP1;
  this->notaP2 = notaP2;
  this->notaP3 = notaP3;
  this->faltas = faltas;
}

Aluno::~Aluno() {
}

double Aluno::getNotaP3() {
  return notaP3;
}

double Aluno::getNotaP2() {
  return notaP2;
}

double Aluno::getNotaP1() {
  return notaP1;
}

string Aluno::getNome() {
  return nome;
}

void Aluno::imprimir() {
  cout << nome << " P1: " << notaP1 << " P2: " << notaP2 <<
       " P3: " << notaP3 << " faltas: " << faltas << endl;
}


