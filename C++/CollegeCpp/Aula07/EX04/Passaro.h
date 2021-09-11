#ifndef PASSARO_H
#define PASSARO_H

#include <iostream>
#include <string>

using namespace std;
class Passaro {
protected:
  bool emExtincao;
  string corPredominante;
public:
  Passaro();
  ~Passaro();
  void canta();
  bool getEmExtincao();
  string getCorPredominante();
};

#endif // PASSARO_H
