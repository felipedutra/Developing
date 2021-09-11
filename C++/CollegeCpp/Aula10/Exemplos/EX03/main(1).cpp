#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream entrada;
  entrada.open ("exemplo.txt");

  if (entrada.fail() ) {
    cout << "Arquivo nao encontrado" << endl;
    entrada.close();
    return 1;
  }

  int a;
  string b = "123";
  entrada >> a; // ERRO
  if (entrada.fail())
    cout << "Erro: nao eh int" << endl;

  entrada >> b;
  if (entrada.fail())
    cout << "Erro: " << b << endl;

  entrada.close();
  return 0;
}
