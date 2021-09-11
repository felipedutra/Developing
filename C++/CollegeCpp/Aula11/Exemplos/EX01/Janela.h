#ifndef JANELA_H
#define JANELA_H

namespace casa {

class Janela {
public:
	Janela();
	virtual ~Janela();

	void abrir();
	void fechar();
	bool estaAberta();
private:
	bool aberta;
};

}

#endif // JANELA_H
