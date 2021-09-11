#include <iostream>
#include <stdexcept>

using namespace std;

int f2 (int a) {
  if (a == 0)
    throw new invalid_argument ("\"a\" nao e valido");

  return a + 1;
}

int f1 (int a) {
  return f2 (a) + 1;
}

int main (int argc, char **argv) {
  try {
    cout << "Resultado: " << f1 (0) << endl;
  } catch (invalid_argument *e) {
    cout << "Erro: " << e->what() << endl;
  }

  return 0;
}
