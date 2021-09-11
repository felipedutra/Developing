#include <iostream>
#include "Participante.h"
#include "Equipe.h"
#include "Pessoa.h"
#include "CentroAcademico.h"
#include "EquipeDoCA.h"


using namespace std;

int main() {
    /* Faca os testes necessarios */
    Pessoa *p1 = new Pessoa("Felipe");
    cout<< p1->getNusp() <<endl;



    delete p1;


    return 0;
}
