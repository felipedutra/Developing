#include "CompeticaoImprimivel.h"

CompeticaoImprimivel::CompeticaoImprimivel(string nome, int maximoValor):
        Competicao(nome, maximoValor){

}

CompeticaoImprimivel::~CompeticaoImprimivel() {

}
void CompeticaoImprimivel::imprimir() {
    cout <<"FUDEU" <<endl;
    this->imprimir();
    for (int i = 0; i < getQuantidadeDeEquipes() ; i++) {
        cout <<"/t";
                getEquipes()[i]->imprimir();

    }
}
