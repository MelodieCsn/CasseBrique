#ifndef __BALLE_H
#define __BALLE_H

class Balle {
 private:
  unsigned int x,y;
 public:
  Balle(int x, int y);
  unsigned int getX() const;
  unsigned int getY() const;

  void setX(unsigned int x);
  void setY(unsigned int y);
  
}