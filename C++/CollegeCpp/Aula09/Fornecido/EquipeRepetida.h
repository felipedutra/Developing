#ifndef EQUIPEREPETIDA_H
#define EQUIPEREPETIDA_H
#include <stdexcept>
#include <string>
using namespace std;


class EquipeRepetida: public invalid_argument {
    public:
        EquipeRepetida(const string &mensagem);
        ~EquipeRepetida();



};

#endif // EQUIPEREPETIDA_H
