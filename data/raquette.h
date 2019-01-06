#ifndef RAQUETTE_H
#define RAQUETTE_H

class Raquette {

 private :
  
  int x;
  int y;
  int length;	

 public:

  Raquette(int X, int Y, int l);
  // Crée une raquette de longueur l et son bout gauche étant en (X,Y)

  int getX() const;      // Renvoie l'abscisse du bout gauche de la raquette
  int getY() const;      // Renvoie l'ordonnée du bout gauche de la raquette
  int getLength() const; // Renvoie la longueur de la raquette

  void setX(int X); // Modifie l'abscisse du bout gauche de la raquette

};

#endif
