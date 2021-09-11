#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <string>
#include <iostream>
using namespace std;

class Participante {
public:
    Participante(string nome);
    virtual ~Participante();

    virtual void imprimir();
    virtual string getNome() = 0;
    /* Crie os atributos necessarios */
protected:
    string nome;

};

#endif // PARTICIPANTE_H
