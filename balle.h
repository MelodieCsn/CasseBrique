#ifndef __BALLE_H
#define __BALLE_H

class Balle{
 private :
  int x;
  int y;
  int dir;

 public :
  Balle(int X, int Y, int d);
  
  int getX() const;
  int getY() const;
  int getDir() const;

  void setX(int X);
  void setY(int Y);
  void setDir(int d);

  void update();

};

#endif
