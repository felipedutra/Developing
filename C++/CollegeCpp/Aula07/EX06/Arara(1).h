#ifndef ARARA_H
#define ARARA_H
#include <iostream>
#include "Passaro.h"

using namespace std;

class Arara: public Passaro {
public:
  Arara();
  virtual ~Arara();
  void canta ();
};

#endif // ARARA_H
