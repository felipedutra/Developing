#include "Modalidade.h"
#include "EquipeRepetida.h"


Modalidade::Modalidade(string nome, int maximoEquipes) :
        nome(nome), maximoEquipes(maximoEquipes) {

    quantidade = 0;

    if (maximoEquipes <= 1 || nome.empty()) {
        throw new invalid_argument ("Nome vazio");
    }

    equipes = new Equipe*[maximoEquipes];
}

Modalidade::~Modalidade() {
    delete[] equipes;
}

void Modalidade::adicionar(Equipe* e) {
    if(quantidade >= maximoEquipes)
        throw new overflow_error ("Overflow");

    for (int i = 0; i < quantidade; i++) {
        if (equipes[i] == e)
            throw new EquipeRepetida("Equipe ja adicionada");
    }

    equipes[quantidade] = e;
    quantidade++;

}


string Modalidade::getNome() {
    return nome;
}

int Modalidade::getQuantidade() {
    return quantidade;
}

void Modalidade::imprimir() {
    for(int i = 0; i < quantidade; i++) {
        equipes[i]->imprimir();
    }
}
