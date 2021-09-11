#ifndef PILHA_H
#define PILHA_H

template <class T> class Pilha {
public:
	void push(T valor);
	T pop();
private:
	T valores[10];
	int topo = 0;
};

template <class T>
void Pilha<T>::push(T valor) {
	topo++;
	valores[topo] = valor;
}

template <class T>
T Pilha<T>::pop() {
	topo--;
	return valores[topo];
}

#endif // PILHA_H
