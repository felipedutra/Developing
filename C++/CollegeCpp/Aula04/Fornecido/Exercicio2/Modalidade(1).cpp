#include "Modalidade.h"
#include <string>
#include <iostream>

using namespace std;
/*
 * Faca os includes e coloque a implementacao dos metodos aqui!

 */
  string Modalidade::getNome() {
    return nome;
}

int Modalidade::getQuantidade(){
        return quantidade;
        }




    bool Modalidade::adicionar(Equipe* e) {
        bool adicionou = false;
                if(e&&quantidade<NUMERO_MAXIMO_VALORES){

                    Equipes[0+quantidade] = e;
                    adicionou = true;
                    quantidade=quantidade+1;
                }else
                cout<<"Erro"<<endl;

        return adicionou;
    }
    int Modalidade::calculaTotalTorcida() {
        int total=0;
        for (int i = 0; i < quantidade; i++) {
                    total= total+Equipes[i]->getMaximoDeTorcedores();

        } if(quantidade == 0 )
            total = -1;

        return total;



    }


    void Modalidade::setNome(string nome) {
    this->nome = nome;
}
    void Modalidade::imprimir(){

    cout << nome << " " << calculaTotalTorcida() << " torcedores no maximo " << endl;

    }

