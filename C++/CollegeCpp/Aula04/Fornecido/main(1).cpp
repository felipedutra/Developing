#include "Equipe.h"
#include "Modalidade.h"

#include <iostream>
using namespace std;


int main() {
    Equipe *e1 = new Equipe;
    Equipe *e2 = new Equipe;
    e1->setNome("Poli");
    e1-> setNumeroDeMembros(10);
    e1->getMaximoDeTorcedores();
    e1->imprimir();

    e2->setNome("FEA");
    e2->setNumeroDeMembros(11);
    e2->getMaximoDeTorcedores();
    e2->imprimir();


    Modalidade *m1 = new Modalidade;
    m1-> setNome("InterUSP");
    m1-> adicionar(e1);
    m1-> adicionar(e2);
    m1->imprimir();


    return 0;
}
