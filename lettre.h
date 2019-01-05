#ifndef __LETTRE_H
#define __LETTRE_H

class Lettre{
 private :
  int height;
  int width;
  int x;
  int y;
  unsigned long long int forme;

 public :

  Lettre();
  Lettre(int X, int Y, char ch);

  int getHeight() const;
  int getWidth() const;
  int getX() const;
  int getY() const;
  unsigned long long int getForme() const;

};

#endif
