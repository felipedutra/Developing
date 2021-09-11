#include "Historico.h"

Historico::Historico(int maximoValor) :
maximoValor(maximoValor) {
    quantidade = 0;
    competicoes = new Competicao*[maximoValor];
}

Historico::~Historico() {
}

int Historico::getQuantidade() {
    return quantidade;
}

bool Historico::adicionar(Competicao* c) {
    if(quantidade >= maximoValor) return false;
    for(int i = 0; i < quantidade; i++)
        if(c == competicoes[i]) return false;
    competicoes[quantidade] = c;
    quantidade++;
    return true;
}

Competicao** Historico::getCompeticoes() {
    return competicoes;
}
