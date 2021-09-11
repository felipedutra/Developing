#ifndef TELEVISAO_H
#define TELEVISAO_H

namespace casa {

class Televisao {
public:
	Televisao();
	virtual ~Televisao();

	void ligar();
	void desligar();
	bool estaLigada();
private:
	bool ligada;
};

}
#endif // TELEVISAO_H
