#ifndef PILHADEPEDIDO_H
#define PILHADEPEDIDO_H

#include "Pedido.h"

class PilhaDePedido {
public:
	void push(Pedido* valor);
	Pedido* pop();
private:
	Pedido* valores[10];
	int topo = 0;
};

#endif // PILHADEPEDIDO_H
