#include "raquette.h"
#include <iostream>
#include <string>
using namespace std;

raquette::raquette(int x, int y, int l) : X(x), Y(y), lenght(l){}

int raquette::getX() const { return X; }
int raquette::getY() const { return Y; }
int raquette::getLenght() const { return lenght; }

void raquette::setX(unsigned int x) { X=x; }
void raquette::setY(unsigned int y) { Y=y; }
