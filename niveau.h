#ifndef __NIVEAU_H
#define __NIVEAU_H

#include "brique.h"
#include "tableau_brique.h"

class Niveau{
 private :

  int lvl;
  TableauBrique T;

 public :

  Niveau(int i);
  Niveau(char* file);

  int getLvl() const;
  void setLvl(int i);
  TableauBrique& getT();

  void addBrique(Brique& br);
  void addBrique(int X, int Y, int HP);
    
};

#endif
