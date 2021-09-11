#include "PilhaDePedido.h"

void PilhaDePedido::push(Pedido* valor) {
	valores[topo] = valor;
	topo++;
}

Pedido* PilhaDePedido::pop() {
	topo--;
	return valores[topo];
}

