#include "Equipe.h"
#include "EquipeComCapitao.h"
#include "Competicao.h"
#include <iostream>

using namespace std;

int main() {
    //Teste aqui o seu codigo


    EquipeComCapitao *e1 = new EquipeComCapitao("Poli",10,"Felipe");
   EquipeComCapitao *e2 = new EquipeComCapitao("FEA",15,"Caio");
   //Equipe *e3 = new Equipe("FEAa",152);

    Competicao *c1 = new Competicao("Copinha",3);
    c1->adicionar(e1);
    c1->adicionar(e2);

   //c1->adicionar(e3);

    c1->imprimir();
    cout << c1->getQuantidade()<<endl;


    delete c1;
   // delete e1;
   //delete e2;



    return 0;
}


