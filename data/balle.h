#ifndef BALLE_H
#define BALLE_H

class Balle{
 private :
  int x;
  int y;
  int dir;
  int nb;

 public :
  Balle(int X, int Y, int d, int n);
  // Construit une balle à la position (X,Y)
  // Avec une direction d et n autres balles en stock

  // Directions : 1 en haut à gauche, 2 en haut, 3 en haut à droite
  //              4 en bas à gauche, 5 en bas, 6 en bas à droite
  
  int getX() const;   // Renvoie l'abscisse de la balle
  int getY() const;   // Renvoie l'ordonnée de la balle
  int getDir() const; // Renvoie la direction de la balle
  int getNb() const;  // Renvoie le nombre de balles restantes

  void setX(int X);   // Modifie l'abscisse de la balle
  void setY(int Y);   // Modifie l'ordonnée de la balle
  void setDir(int d); // Modifie la direction de la balle
  void setNb(int n);  // Modifie le nombre de balles restantes

  void update(); // Change les coordonnées en fonction de la direction

};

#endif
