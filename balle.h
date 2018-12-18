#ifndef __BALLE_H
#define __BALLE_H

class balle{
 private :
  int X;
  int Y;
  int dir;
  char* ch;

 public :
  balle(int x, int y, int d, char* c);
  
  int getX() const;
  int getY() const;
  int getDir() const;
  char* getCh() const;

  void setX(int x);
  void setY(int y);
  void setDir(int d);
  void setCh(char* c);

  //void printBalle() const;
  void update();

};

#endif
