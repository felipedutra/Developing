#include <iostream>

using namespace std;

int main() {
    int i=5;
  int *p1; // endereço indefinido
        p1=NULL;
  cout << *p1 << endl; // Ops... Problema!

  int *p2; // endereço indefinido
  p2 = NULL; // nenhum valor

  if (p2 == NULL) { // é possível testar
    cout << "Null" << endl;
  }

  return 0;
}
