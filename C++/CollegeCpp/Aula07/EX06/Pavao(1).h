#ifndef PAVAO_H
#define PAVAO_H

#include "Passaro.h"

class Pavao : public Passaro {
public:
  Pavao();
  virtual ~Pavao();
  void canta();
  string getCorDaCauda();
private:
  string corDaCauda;
};

#endif // PAVAO_H
