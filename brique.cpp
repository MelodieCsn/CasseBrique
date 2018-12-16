#include "brique.h"
#include <iostream>
extern "C" {
#include <curses.h>
}
Brique::Brique(): height(1), width(1), x(0), y(0), c(VERT){}
Brique::Brique(unsigned int h,unsigned int w,unsigned int x,unsigned int y,Couleur c) : height(h), width(w), x(x), y(y), c(c){}

unsigned int Brique::getX() const {return x;}
unsigned int Brique::getY() const {return y;}
Couleur Brique::getCouleur() const {return c;}
unsigned int Brique::getPv() const {return pv;}
  
void Brique::setX(unsigned int x) {this->x=x;}
void Brique::setY(unsigned int y){this->y=y;}
void Brique::setPv(unsigned int pv) {
	this->pv=pv;

  if(pv==3)
		this->c=VERT;
	else if(pv==2)
		this->c=JAUNE;
	else
		this->c=ROUGE;
}
void Brique::setCouleur(Couleur c){this->c=c;}


string Brique::Couleur2String(Couleur c) {
  string res;
  switch (c) {
  case Couleur::VERT:
    res = "\033[1;32mX\033[0m";//"verte";
    break;
  case Couleur::ROUGE:
    res = "\033[1;31mX\033[0m";//"rouge";
    break;
  case Couleur::JAUNE:
    res = "\033[1;33mX\033[0m";//"jaune";
    break;
    return res;
    
    }
}


