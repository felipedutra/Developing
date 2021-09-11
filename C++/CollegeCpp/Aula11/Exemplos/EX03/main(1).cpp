#include <iostream>

#include "Pilha.h"
#include "Pedido.h"
#include <string>

using namespace std;

int main() {
	Pilha<string>* p1 = new Pilha<string>();
	p1->push("a");
	p1->push("b");
	cout << p1->pop() << endl;

	Pilha<Pedido*>* p2 = new Pilha<Pedido*>();
	p2->push (new Pedido(1));
	p2->push (new Pedido(2));
	cout << p2->pop()->getId() << endl;

	return 0;
}
