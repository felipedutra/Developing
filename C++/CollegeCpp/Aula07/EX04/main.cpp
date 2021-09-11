#include <iostream>
#include "Passaro.h"
#include "Arara.h"

using namespace std;

int main() {
  Passaro *p [3];
  p[0] = new Passaro ();
  p[1] = new Arara ();
  p[2] = new Arara ();

  for (int i = 0; i < 3; i++) {
    p[i]->canta();
  }

  delete p[0];
  delete p[1];
  delete p[2];
  return 0;
}

