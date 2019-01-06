#ifndef BRIQUE_H
#define BRIQUE_H

class Brique{
  
 private:
  
  int x;
  int y;
  int pv;
  
 public:
  
  Brique();
  // Construit une brique de -1 PV, en (-1,-1)
  Brique(int X, int Y, int hp);
  // Construit une brique de hp PV en (X,Y)

  int getX() const;  // Renvoie l'abscisse de la brique
  int getY() const;  // Renvoie l'ordonnée de la brique
  int getPv() const; // Renvoie le nombre de PVs de la brique

  void setX(int X);   // Modifie l'abscisse de la brique
  void setY(int Y);   // Modifie l'ordonnée de la brique
  void setPv(int hp); // Modifie le nombre de PVs de la brique

};

bool identique(const Brique& b1, const Brique& b2);
// Renvoie true si deux briques ont les 3 mêmes paramètres, false sinon

#endif
