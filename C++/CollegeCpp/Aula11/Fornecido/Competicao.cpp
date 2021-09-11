#include "Competicao.h"
#include <stdexcept>

// Implemente as alteracoes

Competicao::Competicao(string nome, int maxValor) :
nome(nome), maxValor(maxValor) {
   // equipes = new Equipe*[maxValor];
   equipes = new vector <Equipe*> ();

    modalidades = new list <Modalidade*> ();
    //cout << "Criou " <<endl;
}

Competicao::~Competicao() {
	delete[] equipes;
	while (!equipes->empty()) {
        Equipe * ultimo = equipes->back();
        equipes->pop_back();
        delete ultimo;
	}
	delete equipes;
	delete[] modalidades;
}



vector<Equipe*>* Competicao::getEquipes() {
    return equipes;
}
list<Modalidade*>* Competicao::getModalidades() {
    return modalidades;
}


void Competicao::adicionar(Equipe* e) {
    unsigned int tamanhoAtual = equipes->size();
    if (tamanhoAtual >= maxValor) throw new overflow_error ("Overflow");
    for(unsigned int i = 0; i < equipes->size(); i++) {
        if(equipes->at(i) == e) throw new invalid_argument("Equipe ja adicionada");
    }
    equipes->push_back ( e );
   // cout << "Adicionou" <<endl;
}

void Competicao::adicionar(Modalidade* m) {
    //unsigned int tamanhoAtual = modalidades->size();
    //if (tamanhoAtual >= maxValor) throw new overflow_error ("Modalidades esta cheio");

    list<Modalidade*>::iterator i = modalidades->begin();
    while (i != modalidades->end()) {
        if((*i) == m) throw new invalid_argument ("Modalidade ja adicionada");
        i++;
    }



    modalidades->push_back (m);
      //  cout << "Adicionou" <<endl;

}
