#include <iostream>

using namespace std;

#include "Janela.h"
using namespace casa;

int main() {
	casa::Janela *j1 = new casa::Janela();
	j1->fechar();

	cout << (j1->estaAberta() ? "Aberta" : "Fechada") << endl;

	Janela *j2 = new Janela();
	j2->abrir();

	cout << (j2->estaAberta() ? "Aberta" : "Fechada") << endl;

	return 0;
}
