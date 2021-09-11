#include <iostream>
#include <string.h>
#ifndef EQUIPE_H
#define EQUIPE_H

using namespace std;

class Equipe {
private:
    string nome;
    int membros;
public:

    string getNome();
    int getMembros();

    void imprimir();
} ;

#endif
