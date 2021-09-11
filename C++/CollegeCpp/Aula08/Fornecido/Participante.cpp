#include "Participante.h"


Participante::Participante(string nome) {
    this->nome = nome;

}
Participante::~Participante() {
    //dtor
}
/* Implemente a classe aqui */
void Participante::imprimir() {
    cout << nome << endl;

 }
