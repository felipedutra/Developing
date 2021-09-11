#include <iostream>
using namespace std;

// Faca os includes necessarios

class Equipe {
public:
    string nome;
    int numeroDeMembros = 0;

    int getMaximoDeTorcedores();
    void imprimir();
};

/** Implementar metodos da classe Equipe **/

class Modalidade {
public:
    string nome;
    Equipe* e1 = NULL;
    Equipe* e2 = NULL;

    Equipe* getMaiorTorcida();
    bool adicionar(Equipe *e);

    void imprimir();
};


int main() {
  cout << "BUsted"<<endl;
  return (0);

}
//g++ aula03.cpp  -std=c++11
