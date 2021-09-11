#include "Pessoa.h"
int Pessoa::nuspAuto = 12345678;
Pessoa::Pessoa(string nome, int nusp): Participante(nome) {
    this->nusp = nusp;
}
Pessoa::Pessoa(string nome):Participante(nome) {
    nusp = getNuspAuto();
    nuspAuto = nuspAuto + 1;


}




Pessoa::~Pessoa() {
    //dtor
}
int Pessoa::getNusp() {
    return nusp;
}

string Pessoa::getNome() {
    return nome;
}
int Pessoa::getNuspAuto() {
    return nuspAuto;
}

