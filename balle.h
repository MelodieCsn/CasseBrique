#ifndef __BALLE_H
#define __BALLE_H

class Balle{
 private :
  int x;
  int y;
  int dir;
  int nb;

 public :
  Balle(int X, int Y, int d, int n);
  
  int getX() const;
  int getY() const;
  int getDir() const;
  int getNb() const;

  void setX(int X);
  void setY(int Y);
  void setDir(int d);
  void setNb(int n);

  void update();

};

#endif
