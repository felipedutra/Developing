#ifndef RELOGIO_H
#define RELOGIO_H


class Relogio {
public:
  Relogio (int hora);
  Relogio (int hora, int minuto);
  Relogio (int hora, int minuto, int segundo);
  void imprimir ();
  virtual ~Relogio();
protected:
  int hora;
  int minuto;
  int segundo;
};

#endif // RELOGIO_H
