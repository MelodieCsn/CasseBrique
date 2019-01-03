#ifndef __TERRAIN_H
#define __TERRAIN_H

#include "window.h"
#include "niveau.h"
#include "score.h"
#include "raquette.h"
#include "balle.h"
#include "tableau_brique.h"
#include "brique.h"

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

  Window& getWin();
  Raquette& getRaq();
  Balle& getBall();
  Score& getScore();
  TableauBrique& getT();
  int getLvl() const;
  bool getStart() const;
  void setStart(bool b);

  void chargerNiveau(Niveau& lvl);
  
  void addBrique(Brique& br);
  void addBrique(int X, int Y, int HP);

  void slideRaq(int i);
  void slideBall(int i);

  void print() const;
  void reset();

  bool bord(int X, int Y);

  int brique(int X, int Y);
  void contactBrique(int X, int Y);
  
  bool palette(int X, int Y);
  bool bordPaletteG(int X, int Y);
  bool bordPaletteD(int X, int Y);

  bool bloc(int X, int Y);

  void coin2(int k, int i, int j);
  void coin(int i, int j);

  void rebond();
};

#endif
