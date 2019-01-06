#ifndef TABSCORE_H
#define TABSCORE_H

#include "window.h"
#include "score.h"

class Classement{
  
 private:
  
  Window win;
  string T[10];

 public:

  Classement(); // Appelle catchFile() pour créer le classement sans l'afficher

  void catchFile();
  // Modifie T selon "classement.txt", T[0-4]=scores croissants, T[5-9]=joueurs correspondants
  
  void save(Score s);
  // Si le score est supérieur à T[0], affiche le "nouveau classement temporaire" avec
  // le score au bon endroit, "___" devant et les autres scores bougés en fonction de ce dernier
  // puis demande d'entrer 3 lettres qui seront automatiquement mises en
  // majuscules. Toute autre touche n'étant pas pris en compte. Le nom s'affiche en même temps
  // qu'on le tape, puis une fois fini, il suffit d'appuyer sur 'q' pour quitter la partie
  // tandis que "classement.txt" est écrasé par le nouveau T
  
  void print(bool b); // Si b=true, affiche le classement, sinon le désafiche
  void rewrite(); // Ecrit le classement ( ou le "rafraichit" )
  bool alphabet(char c); // Renvoie true si c est entre a et z ou A et Z, false sinon
  
};

#endif
