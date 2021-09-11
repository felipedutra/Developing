#include <iostream>
#include <string.h>
#ifndef EQUIPE_H
#define EQUIPE_H

using namespace std;

class Equipe {
protected:
    string nome;
    int membros;
public:
    Equipe(string nome, int membros);
    virtual ~Equipe();

    string getNome();
    int getMembros();

    void imprimir();
};

#endif
