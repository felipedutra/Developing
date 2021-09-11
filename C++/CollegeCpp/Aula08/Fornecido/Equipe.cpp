#include "Equipe.h"

Equipe::Equipe(string nome, int maxValor) : Participante(nome),
nome(nome), maxValor(maxValor) {
    nusps = new int[maxValor];
    pessoas = new Pessoa*[maxValor];
}

Equipe::~Equipe() {
	delete[] nusps;
}
/*
bool Equipe::adicionar(int nusp) {
    if(quantidade >= maxValor) return false;
    for(int i = 0; i < quantidade; i++) {
        if(nusps[i] == nusp) return false;
    }
    nusps[quantidade] = nusp;
    quantidade++;
    return true;
}
*/
Pessoa** Equipe::getPessoas() {
    return pessoas;
}
bool Equipe::adicionar(Pessoa* p) {
    if(quantidade < maxValor) {
        for(int i = 0; i < quantidade; i++) {
            if(pessoas[i] == p) return false;
        }
        pessoas[quantidade] = p;
        quantidade++;
        return true;
    }else return false;

}
string Equipe::getNome() {
    return nome;

}
