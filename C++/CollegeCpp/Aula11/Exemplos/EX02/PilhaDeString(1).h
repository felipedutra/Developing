#ifndef PILHADESTRING_H
#define PILHADESTRING_H

#include <string>

using namespace std;

class PilhaDeString {
public:
	void push(string valor);
	string pop();
private:
	string valores[10];
	int topo = 0;
};

#endif // PILHADESTRING_H
