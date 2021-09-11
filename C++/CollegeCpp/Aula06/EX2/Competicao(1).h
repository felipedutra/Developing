// Inclua aqui as diretivas de compilacao necessarias

#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "Equipe.h"
#include "EquipeComCapitao.h"
#include <string>

#include <iostream>

using namespace std;

class Competicao {
  private:
      // Inclua aqui os atributos necessarios
    Equipe** participantes;
    int quantidade;
    int maximoEquipes;
    string nome;
  public:
    Competicao(string nome, int maximoEquipes);
    ~Competicao();

    Equipe** getEquipes();
    int getQuantidade();
    bool adicionar(Equipe* e);

    void imprimir();
};

#endif // COMPETICAO_H
