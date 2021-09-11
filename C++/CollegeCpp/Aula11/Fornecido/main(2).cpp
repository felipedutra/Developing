#include <iostream>
#include "Equipe.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"
using namespace std;

// Faca os testes aqui
int main() {
        Equipe *e1 = new Equipe("Poli");
        Equipe *e2 = new Equipe("FEA");
        Equipe *e3 = new Equipe("EACH");
        Equipe *e4 = new Equipe("FFLCH");

        Modalidade *m1 = new Modalidade("Futebol",10);
        m1-> adicionar(e1);
        m1-> adicionar(e2);

        Modalidade *m2 = new Modalidade("Volei",10);
        Modalidade *m3 = new Modalidade("Volsei",10);
        Modalidade *m4 = new Modalidade("Volasei",10);
        Modalidade *m5 = new Modalidade("Volaei",10);
        Competicao *c1 = new Competicao("Copa",10);
        c1->adicionar(e1);
        c1->adicionar(e2);
        c1->adicionar(e3);
        c1->adicionar(e4);
      //  c1->adicionar(e4);
        cout << (*c1->getEquipes())[1]->getNome() <<endl;

        c1->adicionar (m1);
        c1->adicionar (m2);
        c1->adicionar (m3);
        c1->adicionar (m4);
        c1->adicionar (m5);
       // c1->adicionar (m5);


        list<Modalidade*>::iterator i = c1->getModalidades()->begin();
        for (int j = 0; j <10; j++) {
            cout << (*i)->getNome() <<endl;
            i++;
        }
        return 0;
}
