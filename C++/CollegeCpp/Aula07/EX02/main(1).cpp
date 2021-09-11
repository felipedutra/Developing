#include <iostream>
#include "Relogio.h"

using namespace std;

int main() {
  Relogio *r1 = new Relogio (1);
  Relogio *r2 = new Relogio (1, 30);
  Relogio *r3 = new Relogio (1, 30, 45);
  r1->imprimir();
  r2->imprimir();
  r3->imprimir();
}
