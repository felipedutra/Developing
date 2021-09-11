#ifndef PILHA_H
#define PILHA_H

class Pilha {
public:
	void push(int valor);
	int pop();
private:
	int valores[10];
	int topo = 0;
};

#endif // PILHA_H
