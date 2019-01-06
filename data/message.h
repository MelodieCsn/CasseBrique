#ifndef MESSAGE_H
#define MESSAGE_H

#include "window.h"
#include "terrain.h"

class Message{
  
 private :

  Window win;
  Color col;

 public :

  Message(Terrain& p, string nom);
  // Crée un message autour de p, en fonction de son nom, définissant toutes ses caractéristiques
  // N'ayant pas réussi à faire des setPos() dans Window, j'implore votre indulgence par rapport
  // à la tête de ce constructeur ...
  
  void write(int X, int Y, string m); // Ecris m à la position (X,Y) dans le message
  void afficher(bool b);              // Si b=true, affiche le message, sinon le désafiche
  void clignoter(Color c);            // Fait clignoter le message entre sa couleur et c
  
};

char* itoa(int val); // Renvoie la version char* de l'entier val

#endif
