#include "Pilha.h"

void Pilha::push(int valor) {
	valores[topo] = valor;
	topo++;
}

int Pilha::pop() {
	topo--;
	return valores[topo];
}

