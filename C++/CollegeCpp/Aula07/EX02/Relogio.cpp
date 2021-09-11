#include "Relogio.h"
#include <iostream>

using namespace std;

Relogio::Relogio (int hora) {
  this->hora = hora;
  this->minuto = this->segundo = 0;
}

Relogio::Relogio (int hora, int minuto) {
  this->hora = hora;
  this->minuto = minuto;
  this->segundo = 0;
}

Relogio::Relogio (int hora, int minuto, int segundo) {
  this->hora = hora;
  this->minuto = minuto;
  this->segundo = segundo;
}

void Relogio::imprimir() {
  cout << hora << ":" << minuto << ":" << segundo << endl;
}

Relogio::~Relogio() {
}
