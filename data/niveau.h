#ifndef NIVEAU_H
#define NIVEAU_H

#include "brique.h"
#include "tableau_brique.h"

class Niveau{
  
 private :

  int lvl;
  TableauBrique T;

 public :

  Niveau(int i); // Crée un niveau vide dont le numéro est i;

  int getLvl() const;    // Renvoie le numéro du niveau
  TableauBrique& getT(); // Renvoie le tableau de briques du niveau (modifiable)

  void addBrique(Brique& br);           // Ajoute br à T si pas déjà présente
  void addBrique(int X, int Y, int HP); // Ajoute Brique(X,Y,HP) à T si pas déjà présente
    
};

#endif
