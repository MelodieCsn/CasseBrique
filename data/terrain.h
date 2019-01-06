#ifndef TERRAIN_H
#define TERRAIN_H

#include "window.h"
#include "raquette.h"
#include "balle.h"
#include "score.h"
#include "brique.h"
#include "tableau_brique.h"
#include "niveau.h"

class Terrain{

 private:

  Window win;
  Raquette raq;
  Balle ball;
  Score score;
  TableauBrique T;

  int lvl;
  bool start;

 public:

  Terrain();
  // Crée un fenêtre fixée dans le cpp, avec sa raquette, sa balle et son score en position initiale
  // Ainsi qu'avec un niveau de numéro 0 et avec start=false;

  Window& getWin();      // Renvoie la fenêtre du terrain (modifiable)
  Raquette& getRaq();    // Renvoie la raquette du terrain (modifiable)
  Balle& getBall();      // Renvoie la balle du terrain (modifiable)
  Score& getScore();     // Renvoie le score du terrain (modifiable)
  TableauBrique& getT(); // Renvoie le tableau de briques du terrain (modifiable)
  int getLvl() const;    // Renvoie la numéro du niveau du terrain
  bool getStart() const; // Renvoie true si la balle est lancée, false sinon
  
  void setStart(bool b); // Modifie la valeur de start

  void chargerNiveau(Niveau& lvl); // Modifie T en copiant le tableau de briques de lvl
  
  void slideRaq(int i);  // Fait glisser la raquette à l'horizontale de i cases
  void slideBall(int i); // Fait glisser la balle à l'horizontale de i cases

  void print() const; // Affiche la raquette, la balle et toutes les briques
  void reset();       // Met la balle et la raquette à leur position initiale, et met start à false

  bool bord(int X, int Y);
  // Renvoie true si (X,Y) sont des coordonnées de bord de terrain, false sinon
  bool bordBas(int X, int Y);
  // Renvoie true si (X,Y) sont des coordonnées de bord bas de terrain, false sinon

  int brique(int X, int Y);
  // Renvoie le numéro dans T de la brique en (X,Y), si elle n'en fait pas partie, renvoie -1 
  void contactBrique(int X, int Y);
  // Si (X,Y) définit la position d'une brique, baisse sa vie, la fait disparaitre si nécessaire
  // Et augmente le score de 1
  
  bool palette(int X, int Y);
  // Renvoie true si (X,Y) fait partie de la palette, false sinon
  bool bordPaletteG(int X, int Y);
  // Renvoie true si (X,Y) est le bord gauche de la palette, false sinon
  bool bordPaletteD(int X, int Y);
  // Renvoie true si (X,Y) est le bord droit de la palette, false sinon

  bool bloc(int X, int Y);
  // Renvoie true si (X,Y) est un bord, la palette ou une brique, false sinon

  void direction(int k, int i, int j);
  // Modifie la direction de la balle en fonction de quelle surface k la balle touche :
  // 1="coin", 2="sol/plafond", 3="mur" et en fonction de (i,j), direction "angulaire" de la balle :
  // (-1,-1)=haut gauche ,(-1,1)=bas gauche ,(1,1)=bas droite ,(1,-1)=haut droite
  void rebond(int i, int j);
  // En fonction des même (i,j), appelle contactBrique() et direction() selon si la balle touche
  // un coin, un plafond, ou un mur, sinon ne fait rien

  void update();
  // Selon la direction de la balle, appelle rebond quand cette dernière est vers un angle
  // Sinon appelle contactBrique() et change directement la direction de la balle
  // Gère plusieurs cas exceptionels : si la balle touche le bord bas, appelle reset() et enleve 1 vie
  // Si la balle touche un bord de palette spécifique à son angle, la direction est différente
  // de celles plus haut, et plus avancé, si la balle va frapper un coin formé par le mur du terrain
  // et par un bout de palette
  // Enfin, appelle ball.update() afin de chnager ses coordonnées
};

#endif
