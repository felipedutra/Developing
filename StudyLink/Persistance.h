#ifndef PERSISTANCE_H
#define PERSISTANCE_H
#include <iostream>
#include "Users.h"
#include "User.h"
#include "Book.h"
#include "Books.h"
using namespace std;

class Persistance {
    public:
        Persistance(string fname);
        virtual ~Persistance();
        void record(Users* u,Books* b);

    protected:

    private:
      string fname;

};

#endif // PERSISTANCE_H
//g++ main.cpp -Wall -pedantic -static -O3
//g++ main.cpp -Wall -pedantic -std=c17 -static-libgcc -static-libstdc++ -static -O3
//g++ -pedantic -Wall -std=gnu++17  -c
//-ftime-report -v
