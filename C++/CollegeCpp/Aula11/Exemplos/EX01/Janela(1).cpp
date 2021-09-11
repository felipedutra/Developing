#include "Janela.h"

using namespace casa;

Janela::Janela() : aberta(false) {
}

Janela::~Janela() {
}

void Janela::abrir() {
	aberta = true;
}

void Janela::fechar() {
	aberta = false;
}

bool Janela::estaAberta() {
	return aberta;
}

