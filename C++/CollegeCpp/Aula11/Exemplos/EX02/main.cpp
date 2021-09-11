#include <iostream>

#include "Pilha.h"
#include "PilhaDePedido.h"
#include "PilhaDeString.h"

using namespace std;

int main() {
	Pilha* p1 = new Pilha();
	PilhaDePedido* p2 = new PilhaDePedido();
	PilhaDeString* p3 = new PilhaDeString();

	p1->push(10);
	p2->push(new Pedido(1));
	p3->push("Texto");

	cout << "int: " << p1->pop() << endl;
	cout << "Pedido: " << p2->pop()->getId() << endl;
	cout << "string: " << p3->pop() << endl;

	return 0;
}
