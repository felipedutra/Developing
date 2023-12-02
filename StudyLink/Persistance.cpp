#include "Persistance.h"
#include <fstream>
#include <iostream>
#define MAXVAL 1000
Persistance::Persistance(string name) {
    this->fname = name;

    ifstream input(fname, ios::in); //Open the file
    if (input.fail() ) {
    
        input.close();

        ofstream output; //Make a file with this name
        output.open(fname, ios::app);
        output.close();
    }

    for (string line; getline(input,line);) {
      cout <<line <<endl;

    }



}

Persistance::~Persistance() {
    //dtor
}
void Persistance::record(Users* u,Books* b) {
    ofstream output; //Make a file with this name
    output.open(fname, ios::app);
    //output << "Text" << endl;
    output.close();

}
