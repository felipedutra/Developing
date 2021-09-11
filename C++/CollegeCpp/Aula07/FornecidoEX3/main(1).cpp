#include "Competicao.h"
#include "Modalidade.h"
#include "Equipe.h"
#include "CompeticaoImprimivel.h"
#include "Historico.h"
#include <iostream>

using namespace std;

/**
  * Teste as classes!!!
  **/
int main() {
    int tamanho = 0;

    Equipe *e1 = new Equipe("Poli",10);
    Equipe *e2 = new Equipe("FEA",11);
    Equipe *e3 = new Equipe("PEA",12);
    Equipe *e4 = new Equipe("FFLCH",14);

    Modalidade *m1 = new Modalidade("InterUSP",10);
    m1-> adicionar(e1);
    m1-> adicionar(e2);
    m1-> adicionar(e3);
    m1-> adicionar(e4);



    Competicao *c1 = new Competicao("Copa",10);
    CompeticaoImprimivel *c2 = new CompeticaoImprimivel("Olimpiada",10);
    c1->adicionar(e1);
    c1->adicionar(e2);
    c1->adicionar(e3);
    c1->adicionar(e4);
    c2->adicionar(e1);
    c2->adicionar(e2);
    c2->adicionar(e3);
    c2->adicionar(e4);

    c1->adicionar (m1);
    c2->adicionar (m1);

    c1->imprimir();
    c2->imprimir();
    Historico *h1 = new Historico(2);
    h1->adicionar(c1);
   // h1->adicionar(c2);
    cout << h1->getCompeticoesImprimiveis(tamanho) <<endl;
    cout << tamanho <<endl;





    return 0;
}
