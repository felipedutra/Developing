// Adicione aqui as diretivas de compilacao necessarias

#ifndef EQUIPECOMCAPITAO_H
#define EQUIPECOMCAPITAO_H
#include <string>
#include <iostream>
#include "Equipe.h"

using namespace std;

class EquipeComCapitao : public Equipe {
private:
    // Adicione aqui os atributos necessarios
    string nomeCapitao;
    string nome;
    int membros;
public:
    EquipeComCapitao(string nome, int membros, string nomeCapitao);
    ~EquipeComCapitao();

    string getNomeCapitao();
};

#endif // EQUIPECOMCAPITAO_H
