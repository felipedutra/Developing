#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
	Pedido(int id);
	virtual ~Pedido();

	int getId();
private:
	int id;
};

#endif // PEDIDO_H
