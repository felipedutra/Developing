#include "Arara.h"

Arara::Arara() : Passaro() {
  this->emExtincao = true;
  this->corPredominante = "azul";
}

Arara::~Arara() {
}

void Arara::canta() {
  cout << "A-RA-RA --- A-RA-RA" << endl;
}
