#include "Competicao.h"
#include "Equipe.h"
#include <string>
#include <iostream>
using namespace std;

// Implemente aqui os metodos necessarios
Competicao::Competicao(string nome, int maximoEquipes) {
    this->nome = nome;
    this->maximoEquipes = maximoEquipes;
    this->quantidade = 0;
    Equipe **participantes = new Equipe*[maximoEquipes];
    for (int i = 0; i < maximoEquipes; i++) {
            participantes[i] = NULL;
    }

}


Competicao::~Competicao() {
    cout << "Competicao destruida" <<endl;
    }
Equipe** Competicao::getEquipes() {
    return this->participantes;
    }
int Competicao::getQuantidade() {

    return quantidade;


}
bool Competicao::adicionar(Equipe* e) {

    for (int i = 0; i < this->maximoEquipes; i++) {
            if( this->participantes[i] == e){
                cout << "Equipe ja adicionada"<<endl;
                return false;

            }
           if ( this->participantes[i] == NULL) {
            participantes[i] = e;
            quantidade = quantidade + 1;
            return true;
           }
           if (i == maximoEquipes -1 ) {
                cout << "Overflow" <<endl;
                return false;


           }
    }
}

void Competicao::imprimir() {
    cout << "Competicao "<< nome << endl;
    cout << getQuantidade()<<endl;


    for (int i = 0; i < this->quantidade; i++) {
           if ( this->participantes[i] != NULL) {
                   cout << "Equipe "<< i+1 << " " << participantes[i]->getNome() << endl;
            }


    }
}
