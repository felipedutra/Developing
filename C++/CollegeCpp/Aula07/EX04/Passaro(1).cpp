#include "Passaro.h"

Passaro::Passaro() {
  this->emExtincao = false;
  this->corPredominante = "cinza";
}

Passaro::~Passaro() {}

void Passaro::canta()  {
  cout << "Piu Piu Piu" << endl;
}

bool Passaro::getEmExtincao () {
  return this->emExtincao;
}

string Passaro::getCorPredominante () {
  return this->corPredominante;
}
