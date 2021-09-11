#include "PilhaDeString.h"

void PilhaDeString::push(string valor) {
	valores[topo] = valor;
	topo++;
}

string PilhaDeString::pop() {
	topo--;
	return valores[topo];
}
