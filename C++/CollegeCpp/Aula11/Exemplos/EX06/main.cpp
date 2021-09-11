#include <iostream>
#include <list>
#include "Pedido.h"
using namespace std;

int main() {
	list<Pedido*>* pedidos = new list<Pedido*>();
	pedidos->push_back (new Pedido(1) );
	pedidos->push_back (new Pedido(2) );

	pedidos->push_front(new Pedido(3) );
	pedidos->push_front(new Pedido(4) );

	list<Pedido*>::iterator i = pedidos->begin();

	while (i != pedidos->end()) {
		cout << (*i)->getId() << " ";
		i++;
	}

	return 0;
}
