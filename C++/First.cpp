#include "First.h"


First::First(string nome,int count): nome(nome), count(count) {
}
First::~First() {

}

void First::imprimir () {
  cout << "Nome: " << nome << endl;
  cout << "Numero: " << count << endl;
}


//g++ main.cpp -Wall -pedantic -static -O3
//g++ main.cpp -Wall -pedantic -std=c17 -static-libgcc -static-libstdc++ -static -O3
//g++ -pedantic -Wall -std=gnu++17  -c
