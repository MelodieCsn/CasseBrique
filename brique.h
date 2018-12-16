#ifndef __BRIQUE_H
#define __BRIQUE_H
#include <string>
using namespace std;

enum Couleur {
  VERT,
  JAUNE,
  ROUGE,
};


class Brique{

 private:
 unsigned int height, width, x, y, pv;
 Couleur c;

  

 public:
  Brique();
  Brique(unsigned int h,unsigned int w,unsigned int x,unsigned int y, Couleur c);


  unsigned int getX() const;
  unsigned int getY() const;
  Couleur getCouleur() const;
  unsigned int getPv() const;
  
  void setX(unsigned int x);
  void setY(unsigned int y);
  void setCouleur(Couleur c);
  void setPv(unsigned int pv);
  
  string Couleur2String(Couleur c);
  

};
 

#endif