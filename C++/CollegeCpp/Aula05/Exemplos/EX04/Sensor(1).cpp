#include "Sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(int numero, Residencia *residencia) : numero(numero), residencia(residencia) {
}

Sensor::~Sensor() {
  cout << "Destruido" << endl;
}


int Sensor::getNumero() {
  return numero;
}

void Sensor::detectarAcao() {
  // Nao faz nada
}
