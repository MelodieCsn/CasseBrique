#include "terrain.h"
using namespace std;

Terrain::Terrain() : win(21,41,1,4,' '), raq(0,win.getHeight()-2,5), ball(0,raq.getY()-1,2,3), lvl(0), start(false){
  raq.setX((win.getWidth()/2)-(raq.getLength()/2));
  ball.setX(raq.getX()+raq.getLength()/2);}

Window& Terrain::getWin() { return win; }
Raquette& Terrain::getRaq() { return raq; }
Balle& Terrain::getBall() { return ball; }
Score& Terrain::getScore() { return score; }
TableauBrique& Terrain::getT() { return T; }
int Terrain::getLvl() const { return lvl; }
bool Terrain::getStart() const { return start; }
void Terrain::setStart(bool b){ start=b; }

void Terrain::chargerNiveau(Niveau& level){

  T=level.getT();
  lvl=level.getLvl();

}

void Terrain::addBrique(Brique& br){

  T.push_back(br);

}

void Terrain::addBrique(int X, int Y, int HP){

  Brique br(X,Y,HP);
  T.push_back(br);

}

void Terrain::slideRaq(int i){

  if(i<0)
    for(int j=1;j<=-i;j++)
      win.print(raq.getX()+raq.getLength()-j,raq.getY(),' ');
  else
    for(int k=0;k<i;k++)
      win.print(raq.getX()+k,raq.getY(),' ');
  raq.setX(raq.getX()+i);
  win.print(raq);
  
}

void Terrain::slideBall(int i){

  win.print(ball.getX(),ball.getY(),' ');
  ball.setX(ball.getX()+i);
  win.print(ball);
  
}

void Terrain::print() const{

  win.print(raq);
  win.print(ball);
  for(int i=0;i<T.getN();i++)
    win.print(T.at(i));

}


void Terrain::reset(){

  win.print(raq.getX(),raq.getY(),"     ");
  raq.setX((win.getWidth()/2)-(raq.getLength()/2));

  win.print(ball.getX(),ball.getY(),' ');
  ball.setX(raq.getX()+raq.getLength()/2);
  ball.setY(raq.getY()-1);
  ball.setDir(2);
	
}


bool Terrain::bord(int X, int Y){
  
  bool res = false;
  if(X>=-1 && X<=win.getWidth()){
    if(Y==-1 || Y==win.getHeight())
      res = true;
  }
  if(Y>=-1 && Y<=win.getHeight()){
    if(X==-1 || X==win.getWidth())
      res = true;    
  }
  return res;
  
}

bool Terrain::bordBas(int X, int Y){
  
  if(X>=-1 && X<=win.getWidth() && Y==win.getHeight())
      return true;
  return false;
  
}

int Terrain::brique(int X, int Y){

  for(int i=0;i<T.getN();i++)
    if(X==T.at(i).getX() && Y==T.at(i).getY())
      return i;
  return -1;
  
}

void Terrain::contactBrique(int X, int Y){
  
  if(brique(X,Y)>=0){

    if(T.at(brique(X,Y)).getPv()==1)
      win.print(X,Y,' ');
    T.abimer(brique(X,Y));
    score.upScore(1);

  }
  
}

bool Terrain::palette(int X, int Y){
  return (Y==raq.getY() && X>=raq.getX() && X<=raq.getX()+raq.getLength()-1);
}
  
bool Terrain::bordPaletteG(int X, int Y){
  return (Y==raq.getY() && X==raq.getX());
}
  
bool Terrain::bordPaletteD(int X, int Y){
  return (Y==raq.getY() && X==raq.getX()+raq.getLength()-1);
}
  
bool Terrain::bloc(int X, int Y){
  return (bord(X,Y) || palette(X,Y) || brique(X,Y)>-1);
}

void Terrain::direction(int k, int i, int j){

  switch(k){
  case 1:
    
    if(i==1)
      if(j==1)
	ball.setDir(1);
      else
	ball.setDir(4);
    else
      if(j==1)
	ball.setDir(3);
      else
	ball.setDir(6);
    
    break;
  case 2:

    if(i==1)
      if(j==1)
	ball.setDir(3);
      else
	ball.setDir(6);
    else
      if(j==1)
	ball.setDir(1);
      else
	ball.setDir(4);

    break;
  case 3:

    if(i==1)
      if(j==1)
	ball.setDir(4);
      else
	ball.setDir(1);
    else
      if(j==1)
	ball.setDir(6);
      else
	ball.setDir(3);

    break;
  }
  
}
  
void Terrain::rebond(int i, int j){
  
  int X=ball.getX(), Y=ball.getY();
  if((bloc(X+i,Y) && bloc(X,Y+j)) || (bloc(X+i,Y+j) && !bloc(X,Y+j) && !bloc(X+i,Y))){
    
    contactBrique(X+i,Y);
    contactBrique(X+i,Y+j);
    contactBrique(X,Y+j);
    
    direction(1,i,j);
  }
  else if(bloc(X,Y+j)){
    contactBrique(X,Y+j);
    direction(2,i,j);
  }
  else if(bloc(X+i,Y)){
    contactBrique(X+i,Y);
    direction(3,i,j);
  }
}
  
void Terrain::update(){
  
  switch(ball.getDir()){
  case 1:
    rebond(-1,-1);
    break;
  case 2:
    if(bloc(ball.getX(),ball.getY()-1)){
      contactBrique(ball.getX(),ball.getY()-1);
      ball.setDir(5);
    }
    break;
  case 3:
    rebond(1,-1);
    break;
  case 4:
    if(bordPaletteD(ball.getX(),ball.getY()+1))
      ball.setDir(2);
    else if(bordBas(ball.getX(),ball.getY()+1)){
      reset();
      ball.setNb(ball.getNb()-1);
      start=false;
    }else
      rebond(-1,1);
    break;
  case 5:
    if(bloc(ball.getX(),ball.getY()+1)){
      
      if(bordPaletteG(ball.getX(),ball.getY()+1)){
	
	if(bord(ball.getX()-1,ball.getY()))
	  ball.setDir(3);
	else
	  ball.setDir(1);

      }
      
      else if(bordPaletteD(ball.getX(),ball.getY()+1)){
	
	if(bord(ball.getX()+1,ball.getY()))
	  ball.setDir(1);
	else
	  ball.setDir(3);
	
      }
      else if(bordBas(ball.getX(),ball.getY()+1)){
	reset();
	ball.setNb(ball.getNb()-1);
	start=false;
      }else{
        contactBrique(ball.getX(),ball.getY()+1);
	ball.setDir(2);
      }
    }
    break;
  case 6:
    if(bordPaletteG(ball.getX(),ball.getY()+1))
      ball.setDir(2);
    else if(bordBas(ball.getX(),ball.getY()+1)){
      reset();
      ball.setNb(ball.getNb()-1);
      start=false;
    }else
      rebond(1,1);
    break;

  }
  if(start){
    win.print(ball.getX(),ball.getY(),' ');
    ball.update();    
  }
}

/* 

xx ox xo
x  x  o

xx ox
o  o

xo oo
x  x

oo
o

*/
