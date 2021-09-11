#ifndef CENTROACADEMICO_H
#define CENTROACADEMICO_H
#include "Pessoa.h"

#include <iostream>
using namespace std;
/* Faca os includes necessaios */

class CentroAcademico {
public:
    CentroAcademico(Pessoa* presidente, string sigla);
    virtual ~CentroAcademico();

    virtual string getSigla();
    virtual Pessoa* getPresidente();

    /* Crie os atributos necessarios */

private:
    Pessoa* presidente;
    string sigla;
};

#endif // CENTROACADEMICO_H
