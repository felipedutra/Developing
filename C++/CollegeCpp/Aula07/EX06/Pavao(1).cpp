#include "Pavao.h"

Pavao::Pavao() : Passaro() {
  this->emExtincao = false;
  this->corPredominante = "azul";
  this->corDaCauda = "verde";
}

Pavao::~Pavao() {
}

string Pavao::getCorDaCauda() {
  return corDaCauda;
}

void Pavao::canta() {
  cout << "Gra ";
  Passaro::canta();
}
