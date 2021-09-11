#include "Competicao.h"
#include "Modalidade.h"
#include "Equipe.h"
#include "CompeticaoImprimivel.h"

#include <iostream>

using namespace std;

/**
  * Teste as classes!!!
  **/
int main() {

    Equipe *e1 = new Equipe("Poli",10);
    Equipe *e2 = new Equipe("FEA",11);
    Equipe *e3 = new Equipe("PEA",12);
    Equipe *e4 = new Equipe("FFLCH",14);

    Modalidade *m1 = new Modalidade("InterUSP",10);
    m1-> adicionar(e1);
    m1-> adicionar(e2);
    m1-> adicionar(e3);
    m1-> adicionar(e4);

    m1->imprimir();

    Competicao *c2 = new Competicao("Copa",19);
    CompeticaoImprimivel *c1 = new CompeticaoImprimivel("Copa",10);
    c1->adicionar(e1);
    c1->adicionar(e2);
    c1->adicionar(e3);
    c1->adicionar(e4);

    c1->adicionar (m1);
    c1->imprimir();





    return 0;
}
