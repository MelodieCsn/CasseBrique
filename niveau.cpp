#include "niveau.h"
#include <iostream>
using namespace std;

Niveau::Niveau(int i) : lvl(i){}

int Niveau::getLvl() const { return lvl; }
void Niveau::setLvl(int n){ lvl=n; }
TableauBrique& Niveau::getT(){ return T; }

void Niveau::addBrique(Brique& br){

  for(int i=0;i<T.getN();i++){
    if( T.at(i).getX()==br.getX() && T.at(i).getY()==br.getY() ){
      cerr<<"Brique déjà présente en ("<<br.getX()<<","<<br.getY()<<"). Arrêt."<<endl;
      terminate();
    }
  }
  T.push_back(br);

}

void Niveau::addBrique(int X, int Y, int HP){

  for(int i=0;i<T.getN();i++){
    if( T.at(i).getX()==X && T.at(i).getY()==Y ){
      cerr<<"Brique déjà présente en ("<<X<<","<<Y<<"). Arrêt."<<endl;
      terminate();
    }
  }
  Brique br(X,Y,HP);
  T.push_back(br);

}
