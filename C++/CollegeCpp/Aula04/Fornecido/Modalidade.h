#ifndef MODALIDADE_H
#define MODALIDADE_H
#include <string>
#define NUMERO_MAXIMO_VALORES 10
#include "Equipe.h"
 #include <iostream>

 using namespace std;
/*
 * Use as diretivas adequadas e inclua os arquivos e/ou bibliotecas
 * necessarios para a classe.

 */



class Modalidade {
/*  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
 */
 private:
    string nome;
    Equipe *Equipes[NUMERO_MAXIMO_VALORES];
    int quantidade=10;




/*
 * Os metodos podem ser acessados de fora do escopo da classe
 */public:
    int calculaTotalTorcida();
    bool adicionar(Equipe* e);

    string getNome();
    int getQuantidade();
    void setNome(string nome);

    void imprimir();
};
 #endif // MODALIDADE_H
