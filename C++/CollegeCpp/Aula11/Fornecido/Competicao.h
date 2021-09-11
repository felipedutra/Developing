#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "Modalidade.h"
#include <vector>
#include <list>
// Faca os includes necessarios

using namespace std;

// Modifique SOMENTE a classe Competicao

class Competicao {
public:
    Competicao(string nome, int maxValor);
    virtual ~Competicao();

    vector<Equipe*>* getEquipes();
    list<Modalidade*>* getModalidades();

    void adicionar(Equipe* e);
    void adicionar(Modalidade* m);
protected:
    string nome;
    //int quantidadeDeModalidades;
    // int quantidadeDeEquipes;
    int maxValor;
    //  Equipe** equipes;
    vector <Equipe*>* equipes ;
    list <Modalidade*>* modalidades;
};

#endif // COMPETICAO_H
