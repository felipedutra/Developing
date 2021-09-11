#include "EquipeComCapitao.h"
#include "Equipe.h"

// Implemente aqui os metodos

    EquipeComCapitao::EquipeComCapitao(string nome, int membros, string nomeCapitao) : Equipe(nome, membros){
    this->nomeCapitao = nomeCapitao;
    }


    string EquipeComCapitao::getNomeCapitao() {
    return this->nomeCapitao;
    }
    EquipeComCapitao::~EquipeComCapitao() {
    cout << "Equipe com Capitao " << getNomeCapitao() << " destruida" <<endl;
    }

