#include "Equipe.h"
#ifndef TABELA_H
#define TABELA_H

using namespace std;

class Tabela {
private:
    Equipe** participantes;
    int* pontos;
    int quantidade;

    int getIndice(Equipe* participante);
public:
	// Declare o construtor e o destrutor

    Equipe** getParticipantes() const;
    int getQuantidade();

    void pontuar(Equipe* participante, int pontos);
    int getPontos(Equipe* participante);

    void imprimir();

};
#endif // TABELA_H
