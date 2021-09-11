#include "PersistenciaEquipe.h"
#include <fstream>
#include <stdexcept>
using namespace std;
 PersistenciaEquipe::PersistenciaEquipe(string arquivo) {

     this->arquivo = arquivo;
}
PersistenciaEquipe::~PersistenciaEquipe() {

}

void PersistenciaEquipe::inserir(Equipe *e) {



    ofstream output;
    output.open(arquivo, ios::app);
    output << e->getNome()  <<endl;
    output << e->getMembros() <<endl;
    output.close();


}
Equipe** PersistenciaEquipe::obter(int* quantidade) {
    equipes = new Equipe*[10];
    *quantidade = 0;
    string linha;
    int numero;

    for (int i = 0; i < 10; i++) {
        equipes[i] = NULL;
    }


    ifstream input(arquivo, ios::in);
    if (input.fail() ) {
        input.close();
        throw invalid_argument("Arquivo nao encontrado");
        return NULL;
    }

    //LENDO O ARQUIVO
    for(int i = 0; input; i++) {
        string nome;

            if(i%2 == 0){
                getline(input,linha);
                if(linha != ""){
                *quantidade = *quantidade + 1;
                }
            }else {
            input >> numero;
            cout << linha <<" "<<numero <<endl;
            nome = linha;
            getline(input,linha);


            }
            if (*quantidade){
            Equipe *e = new Equipe(nome,numero);

            equipes[*quantidade-1] = e;
            }



    }
    if (quantidade == 0)  {
        cout << "Arquivo vazio" << endl;
        input.close();
        return NULL;
    }
    return equipes;
    //*quantidade = (*quantidade - 1)/2;
}
