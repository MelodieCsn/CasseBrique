#include "balle.h"
#include <iostream>
#include <string>
using namespace std;

balle::balle(int x, int y, int d, char* c) : X(x), Y(y), dir(d), ch(c){}

int balle::getX() const{ return X; }
int balle::getY() const{ return Y; }
int balle::getDir() const{ return dir; }
char* balle::getCh() const{ return ch; }

void balle::setX(int x){ X=x; }
void balle::setY(int y){ Y=y; }
void balle::setDir(int d){ dir=d; }
void balle::setCh(char* c){ ch=c; }

/*void balle::printBalle() const{
  cout<<"=============================="<<endl;
  for(int i=0;i<Y;i++)
    cout<<' '<<endl;
  for(int j=0;j<X;j++)
    cout<<' ';
  cout<<'@'<<endl;
  cout<<"=============================="<<endl;
  }*/
  
void balle::update(){
  switch(dir){
  case 1:
    X--;
    Y--;
    break;
  case 2:
    Y--;
    break;
  case 3:
    X++;
    Y--;
    break;
  case 4:
    X--;
    Y++;
    break;
  case 5:
    Y++;
    break;
  case 6:
    X++;
    Y++;
    break;
  }
}

/*int main(){
  balle b(0,0,6);
  b.printBalle();
  
  b.update();
  b.printBalle();
  b.update();
  b.printBalle();
  b.update();
  b.printBalle();
  
  b.changeDir(3);

  b.update();
  b.printBalle();
  b.update();
  b.printBalle();

  return 0;
  }*/
