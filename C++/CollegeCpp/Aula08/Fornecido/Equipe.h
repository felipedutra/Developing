#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include "Participante.h"
#include "Pessoa.h"

#include <iostream>

using namespace std;

class Equipe : public Participante {
public:
    Equipe(string nome, int maxValor);
    virtual ~Equipe();

    virtual bool adicionar(Pessoa* p);
    virtual Pessoa** getPessoas();
    virtual string getNome();
private:
    string nome;
    int maxValor;
    Pessoa ** pessoas;
    int quantidade;
    int* nusps;
};

#endif // EQUIPE_H
