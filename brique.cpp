#include "brique.h"

Brique::Brique() : x(-1), y(-1), pv(-1){}
Brique::Brique(int X, int Y, int hp) : x(X), y(Y), pv(hp){}

int Brique::getX() const { return x; }
int Brique::getY() const { return y; }
int Brique::getPv() const { return pv; }

void Brique::setX(int X) { x=X; }
void Brique::setY(int Y) { y=Y; }
void Brique::setPv(int hp) { pv=hp; }

bool identique(const Brique& b1, const Brique& b2){

  return (b1.getX()==b2.getX()) && (b1.getY()==b2.getY()) && (b1.getPv()==b2.getPv());
  
}
