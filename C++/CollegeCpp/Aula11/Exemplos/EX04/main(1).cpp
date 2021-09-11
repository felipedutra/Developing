#include <iostream>
#include <vector>
#include "Pedido.h"

using namespace std;

int main() {
	vector<Pedido*>* v = new vector<Pedido*>();
	v->push_back(new Pedido(1));
	cout << (*v)[0]->getId() << endl;
	Pedido *p = v->back();
	v->pop_back();
	delete p;
	delete v;

	vector<Pedido*>* pedidos = new vector<Pedido*>();
	pedidos->push_back(new Pedido(100));
	pedidos->push_back(new Pedido(101));

	for(unsigned int i = 0; i < pedidos->size(); i++) {
		cout << pedidos->at(i)->getId() << endl;
	}

	// Apagando
	while (!pedidos->empty()) {
		Pedido *ultimo = pedidos->back();
		pedidos->pop_back();
		delete ultimo;
	}
	delete pedidos;

	return 0;
}
