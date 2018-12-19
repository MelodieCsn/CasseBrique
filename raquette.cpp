#include "raquette.h"
#include <iostream>
#include <string>
using namespace std;

raquette::raquette(int x, int y, int l) : X(x), Y(y), length(l){}

int raquette::getX() const { return X; }
int raquette::getY() const { return Y; }
int raquette::getLength() const { return length; }

void raquette::setX(unsigned int x) { X=x; }
void raquette::setY(unsigned int y) { Y=y; }
