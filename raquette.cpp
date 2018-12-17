#include "raquette.h"
#include <iostream>
#include <string>
extern "C" {
#include <curses.h>
}

using namespace std;

Raquette::Raquette(unsigned int x, unsigned int y, size_t h, size_t w, unsigned int n) : x(x),y(y),height(h),width(w),n(n) {
  if(n==1){
    this->colin=NOIR;
    this->colout=BLEU;
  }
  if(n==2){
    this->colin=NOIR;
    this->colout=VERT;
  }
}


unsigned int Raquette::getX() const {return x;}
unsigned int Raquette::getY() const {return y;}
size_t Raquette::getHeight() const {return height;}
size_t Raquette::getWidth() const {return width;}
Couleur Raquette::getColIn() {return colin;}
Couleur Raquette::getColOut() {return colout;}


void Raquette::setX(unsigned int x) {this->x=x;}
void Raquette::setY(unsigned int y) {this->y=y;}

string Raquette::Couleur2String(Couleur c) {
  string res;
  switch (c) {
  case Couleur::NOIR:
    res = "\033[1;30mX\033[0m"; //"noire";
    break;
  case Couleur::BLEU:
    res = "\033[1;34mX\033[0m";//"bleue";
    break;
  case Couleur::VERT:
    res = "\033[1;32mX\033[0m";//"verte";
    break;
  case Couleur::ROUGE:
    res = "\033[1;31mX\033[0m";//"rouge";
    break;
  case Couleur::JAUNE:
    res = "\033[1;33mX\033[0m";//"jaune";
    break;
  }
  return res;}


