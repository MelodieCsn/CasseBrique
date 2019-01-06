#include "raquette.h"

Raquette::Raquette(int X, int Y, int l) : x(X), y(Y), length(l){}

int Raquette::getX() const { return x; }
int Raquette::getY() const { return y; }
int Raquette::getLength() const { return length; }

void Raquette::setX(int X) { x=X; }
