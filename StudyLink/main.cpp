#include "Persistance.h"
#include "User.h"
#include "Users.h"
#include "Login.h"
#include "Book.h"
#include "Books.h"
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    system("./open.sh");
    Persistance *p = new Persistance("./.json/.tempdata.txt");
    Users *u = new Users("Users");
    Books *b =  new Books("Books");


    cout << "What do you wish to do?" <<endl;


    User *u2 = new User("Felipe", "11974578070");

    u->addUser(u2);
    Book *b1 = new Book("12 Regras para a vida","Jordan Peterson");
    b->addBook(b1);
    //u2->print();
    //u2->sleepRecorder(12.3,3);
    //u2->print();
    p->record(u,b);

    delete u2;
    system("./.scripts/open.sh");


    return 0;
}
//g++ main.cpp User.cpp Users.cpp Persistance.cpp Login.cpp Book.cpp Books.cpp -Wall -ansi -O3
//g++ main.cpp -Wall -pedantic -static -O3
//g++ main.cpp -Wall -pedantic -std=c17 -static-libgcc -static-libstdc++ -static -O3
//g++ -pedantic -Wall -std=gnu++17  -c
//-ftime-report -v

//clang++ *.cpp -Wall -ansi -O3 -std=c++11  -o a | ./a
