#ifndef __BRIQUE_H
#define __BRIQUE_H

class Brique{
  
 private:
  
  int x;
  int y;
  int pv;
  
 public:
  
  Brique();
  Brique(int X, int Y, int hp);

  int getX() const;
  int getY() const;
  int getPv() const;

  void setX(int X);
  void setY(int Y);
  void setPv(int hp);

};

  bool identique(const Brique& b1, const Brique& b2);

#endif
