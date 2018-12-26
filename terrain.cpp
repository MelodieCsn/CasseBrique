#include "terrain.h"
using namespace std;

Terrain::Terrain() : win(21,41,1,4,' '), raq(0,win.getHeight()-2,5), ball(0,raq.getY()-1,2), n(0){
  raq.setX((win.getWidth()/2)-(raq.getLength()/2));
  ball.setX(raq.getX()+raq.getLength()/2);}

Window& Terrain::getWin() { return win; }
Raquette& Terrain::getRaq() { return raq; }
Balle& Terrain::getBall() { return ball; }
TableauBrique& Terrain::getT() { return T; }

int Terrain::getN() const { return n; }
void Terrain::upN() { n++; }

void Terrain::addBrique(Brique& br){

  T.push_back(br);
  upN();

}

void Terrain::addBrique(int X, int Y, int HP){

  Brique br(X,Y,HP);
  T.push_back(br);
  upN();

}

void Terrain::print() const{

  win.print(raq);
  win.print(ball);
  for(int i=0;i<n;i++)
    win.print(T.at(i));

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

int Terrain::brique(int X, int Y){

  for(int i=0;i<n;i++)
    if(X==T.at(i).getX() && Y==T.at(i).getY())
      return i;
  return -1;
  
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

void Terrain::coin2(int k, int i, int j){

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
  
void Terrain::coin(int i, int j){
  
  int X=ball.getX(), Y=ball.getY();
  if((bloc(X+i,Y) && bloc(X,Y+j)) || (bloc(X+i,Y+j) && !bloc(X,Y+j) && !bloc(X+i,Y))){
    
    if(T.at(brique(X+i,Y)).getPv()==1)
      win.print(X+i,Y,' ');
    T.abimer(brique(X+i,Y));
    
    if(T.at(brique(X+i,Y+j)).getPv()==1)
      win.print(X+i,Y+j,' ');
    T.abimer(brique(X+i,Y+j));
    
    if(T.at(brique(X,Y+j)).getPv()==1)
      win.print(X,Y+j,' ');
    T.abimer(brique(X,Y+j));
    
    coin2(1,i,j);
  }
  else if(bloc(X,Y+j)){
    if(T.at(brique(X,Y+j)).getPv()==1)
      win.print(X,Y+j,' ');
    T.abimer(brique(X,Y+j));
    coin2(2,i,j);
  }
  else if(bloc(X+i,Y)){
    if(T.at(brique(X+i,Y)).getPv()==1)
      win.print(X+i,Y,' ');
    T.abimer(brique(X+i,Y));
    coin2(3,i,j);
  }
}
  
void Terrain::rebond(){
  
  switch(ball.getDir()){
  case 1:
    coin(-1,-1);
    break;
  case 2:
    if(bloc(ball.getX(),ball.getY()-1)){
      if(T.at(brique(ball.getX(),ball.getY()-1)).getPv()==1)
	win.print(ball.getX(),ball.getY()-1,' ');
      T.abimer(brique(ball.getX(),ball.getY()-1));
      ball.setDir(5);
    }
    break;
  case 3:
    coin(1,-1);
    break;
  case 4:
    if(bordPaletteD(ball.getX(),ball.getY()+1))
      ball.setDir(2);
    else
      coin(-1,1);
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
      else{
	if(T.at(brique(ball.getX(),ball.getY()+1)).getPv()==1)
	win.print(ball.getX(),ball.getY()+1,' ');
	T.abimer(brique(ball.getX(),ball.getY()+1));
	ball.setDir(2);
      }
    }
    break;
  case 6:
    if(bordPaletteG(ball.getX(),ball.getY()+1))
      ball.setDir(2);
    else
      coin(1,1);
    break;

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
