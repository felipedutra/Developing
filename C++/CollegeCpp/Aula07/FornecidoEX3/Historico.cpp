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
Competicao** Historico::getCompeticoesImprimiveis(int& tamanho) {
    competicoesImprimiveis = new Competicao*[maximoValor];
    int quantidadeDeImprimiveis = 0;
//COMO FAZER A DISTINÇÃO DAS VARIÁVEIS DAS CLASSES BASE E DERIVADA
    for(int i = 0; i < getQuantidade(); i++) {
        CompeticaoImprimivel *cv = dynamic_cast<CompeticaoImprimivel*>(competicoes[i]);
        if(cv != NULL) {
            competicoesImprimiveis[quantidadeDeImprimiveis];
            quantidadeDeImprimiveis++;

        }



    }
    if (quantidadeDeImprimiveis == 0) {
        tamanho = 0;
        return NULL;
    }
    tamanho = quantidadeDeImprimiveis;
    return (competicoesImprimiveis);

}
