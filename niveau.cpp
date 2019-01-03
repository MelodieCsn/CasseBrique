#include "niveau.h"

Niveau::Niveau(int i) : lvl(i){}

int Niveau::getLvl() const { return lvl; }
void Niveau::setLvl(int n){ lvl=n; }
TableauBrique& Niveau::getT(){ return T; }

void Niveau::addBrique(Brique& br){

  T.push_back(br);

}

void Niveau::addBrique(int X, int Y, int HP){

  Brique br(X,Y,HP);
  T.push_back(br);

}
