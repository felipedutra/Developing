#include "Competicao.h"
#include "Modalidade.h"
#include "Equipe.h"


#include <iostream>

using namespace std;

/**
  * Teste as classes!!!
  **/
int main() {

    Equipe *e1 = new Equipe("Poli",10);
    Equipe *e2 = new Equipe("FEA",11);
    e1->imprimir();
    e2->imprimir();

    Modalidade *m1 = new Modalidade("InterUSP",10);
    m1-> adicionar(e1);
    m1-> adicionar(e2);
    m1->imprimir();

    Competicao *c1 = new Competicao("Copa",10);
    c1->adicionar(e1);
    c1->adicionar(e2);
    c1->adicionar (m1);





    return 0;
}
