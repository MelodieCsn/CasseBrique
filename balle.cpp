#include "balle.h"
#include <iostream>
#include <string>
using namespace std;

Balle::Balle(int X, int Y, int d) : x(X), y(Y), dir(d){}

int Balle::getX() const{ return x; }
int Balle::getY() const{ return y; }
int Balle::getDir() const{ return dir; }

void Balle::setX(int X){ x=X; }
void Balle::setY(int Y){ y=Y; }
void Balle::setDir(int d){ dir=d; }
  
void Balle::update(){
  switch(dir){
  case 1:
    x--;
    y--;
    break;
  case 2:
    y--;
    break;
  case 3:
    x++;
    y--;
    break;
  case 4:
    x--;
    y++;
    break;
  case 5:
    y++;
    break;
  case 6:
    x++;
    y++;
    break;
  }
}
