#include <iostream>
#include "Passaro.h"
#include "Arara.h"

using namespace std;

int main() {
  Passaro *p = new Passaro ();
  cout << "Passaro " << p->getCorPredominante()
       << " em extincao? "
       << (p->getEmExtincao() ? "Sim" : "Nao") << endl;
  p->canta();

  Arara *a = new Arara ();
  cout << "Arara " << a->getCorPredominante()
       << " em extincao? "
       << (a->getEmExtincao() ? "Sim" : "Nao") << endl;

  a->canta();

  delete p;
  delete a;
  return 0;
}
