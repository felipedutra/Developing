#include "Equipe.h"

using namespace std;

string Equipe::getNome() {
    return this->nome;
}

int Equipe::getMembros() {
    return this->membros;
}

void Equipe::imprimir() {
    cout << "Equipe " << this->nome << endl;
}
