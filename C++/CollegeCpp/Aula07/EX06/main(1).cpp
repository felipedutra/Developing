#include <iostream>
#include "Passaro.h"
#include "Arara.h"
#include "Pavao.h"

using namespace std;

int main() {
  Passaro *p1 = new Passaro();
  p1->canta();
  delete p1;

  p1 = new Pavao ();
  p1->canta();
  delete p1;

  Passaro *p2 = new Passaro();
  Pavao *v1 = static_cast<Pavao*>(p2);
  if (v1 != NULL) {
    cout << "E' um pavao" << endl;
    //cout << v1->getCorDaCauda();
  }
  delete p2;

  Passaro *p3 = new Pavao();

  Pavao *v2 = dynamic_cast<Pavao*>(p3);
  if (v2 != NULL) {
    cout << "E' um pavao" << endl;
	cout << v2->getCorDaCauda();
  }

  delete p2;
  return 0;
}

