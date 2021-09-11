#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream entrada;
  entrada.open ("numeros.txt");

  if (entrada.fail() ) {
    cout << "Arquivo nao encontrado" << endl;
    entrada.close();
    return 1;
  }

  double x, total = 0;
  int quantidade = 0;

  entrada >> x;
  while (entrada) {
    total = total + x;
    quantidade++;
    entrada >> x;
  }

  if (!entrada.eof()){
    cout << "Erro de leitura" << endl;
    entrada.close();
    return 1;
  }

  if (quantidade == 0)  {
    cout << "Arquivo vazio" << endl;
    entrada.close();
    return 1;
  }

  double media = total / quantidade;
  entrada.close();

  ofstream saida;
  saida.open ("media.txt");

  if (saida.fail())
    cout << "Erro ao escrever" << endl;
  else
    saida << media;

  saida.close();

  return 0;
}
