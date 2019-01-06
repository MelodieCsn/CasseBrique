#ifndef LETTRE_H
#define LETTRE_H

class Lettre{
  
 private:
  
  int height;
  int width;
  int x;
  int y;
  unsigned long long int forme;

 public:

  Lettre();                       // Crée une lettre dont tous les attributs sont 0
  Lettre(int X, int Y, char ch);  // Crée une lettre fromant le caractère ch en (X,Y)

  int getHeight() const;                   // Renvoie la hauteur de la lettre
  int getWidth() const;                    // Renvoie la largeur de la lettre
  int getX() const;                        // Renvoie l'abscisse de la lettre
  int getY() const;                        // Renvoie l'ordonnée de la lettre
  unsigned long long int getForme() const; // Renvoie la forme de la lettre

};

#endif
