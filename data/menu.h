#ifndef MENU_H
#define MENU_H

#include "window.h"
#include "title.h"
#include "classement.h"

class Menu{
  
 private :

  Window win;
  Title title;
  Classement cls;
  int x;
  int y;
  char place;
  bool b;

 public :

  Menu();
  // Crée un menu au milieu de l'écran avec juste au-dessus le titre et dessous le classement

  Classement& getCls();  // Renvoie le classement (modifiable)

  int getY() const;      // Renvoie l'ordonnée du curseur du menu
  char getPlace() const; // Renvoie le caractère de la catégorie du menu ( m=menu, n=niveaux )
  bool getB() const;     // Renvoie le booléen décrivant si true : on utilise encore le menu ou non
  
  void setY(int Y);      // Modifie l'ordonnée du curseur du menu

  void down();
  // Descend le curseur d'une case si possible, et change l'affichage en fonction de son Y et de place
  void up();
  // Monte le curseur d'une case si possible, et change l'affichage en fonction de son Y et de place
  void choose();
  // "Utilise le bouton" devant lequel est placé le curseur, en fonction de son Y et de place

  void disappear();
  // Appelle fade(true) de title et fait disparaitre le menu avant de mettre b sur false
  // Puis de lancer la suite, ou de quitter

};

#endif
