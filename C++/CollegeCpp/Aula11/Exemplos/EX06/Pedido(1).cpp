#include "Pedido.h"

Pedido::Pedido (int id) : id(id){
}

Pedido::~Pedido() {
}

int Pedido::getId() {
	return id;
}
