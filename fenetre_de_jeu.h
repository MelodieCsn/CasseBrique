#ifndef __FENETRE_DE_JEU_H
#define __FENETRE_DE_JEU_H

#include "terrain.h"
#include "message.h"
#include "niveau.h"

class FenetreDeJeu{
 private:

  Terrain plateau;
  Message titre;
  Message infos;
  Message help;
  Message levelup;
  Message gameover;

 public:

  FenetreDeJeu(Niveau n);
  
  Terrain& getPlateau();
  Message& getTitre();
  Message& getInfos();
  Message& getHelp();
  Message& getLevelup();
  Message& getGameover();

};

#endif
