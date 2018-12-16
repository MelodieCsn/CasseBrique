#include "balle.h"
#include "terrain"

Balle::Balle(int x, int y):x(x),y(y) {}

unsigned int Balle::getX() const {return x;};
unsigned int Balle::getY() const {return y;};

void Balle::setX(unsigned int x){this->x=x;}
void Balle::setY(unsigned int y){this->y=y;}