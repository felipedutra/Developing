#include "Modalidade.h"
#include "Equipe.h"
#include "Competicao.h"

#include <iostream>

using namespace std;


int main() {



        Equipe *e1 = new Equipe("Poli",10);
        Equipe *e2 = new Equipe("FEA",11);
        Equipe *e3 = new Equipe("EACH",12);
        Equipe *e4 = new Equipe("FFLCH",13);

        Modalidade *m1 = new Modalidade("Futebol",10);
        m1-> adicionar(e1);
        m1-> adicionar(e2);

        Modalidade *m2 = new Modalidade("Volei",10);


        Competicao *c1 = new Competicao("Copa",4);
        c1->adicionar(e1);
        c1->adicionar(e2);
        c1->adicionar(e3);
        c1->adicionar(e4);

        c1->adicionar (m1);
        c1->adicionar (m2);














    return 0;

}
