#ifndef PERSISTENCIAEQUIPE_H
#define PERSISTENCIAEQUIPE_H
#include <string>
#include "Equipe.h"

// inclua aqui as diretivas de compilacao necessarias

using namespace std;

class PersistenciaEquipe {


    public:
        PersistenciaEquipe(string arquivo);
        virtual ~PersistenciaEquipe();
        Equipe** obter(int* quantidade);

        void inserir(Equipe *e);
    private:

        string arquivo;
        Equipe** equipes;
    //inclua aqui os atributos necessarios
};
#endif // PERSISTENCIAEQUIPE_H
