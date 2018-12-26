#ifndef __TERRAIN_H
#define __TERRAIN_H

#include "window.h"
#include "raquette.h"
#include "balle.h"
#include "tableau_brique.h"
#include "brique.h"

class Terrain{

 private:

  Window win;
  Raquette raq;
  Balle ball;
  
  int n;
  TableauBrique T;

 public:

  Terrain();

  Window& getWin();
  Raquette& getRaq();
  Balle& getBall();
  TableauBrique& getT();

  int getN() const;
  void upN();

  void addBrique(Brique& br);
  void addBrique(int X, int Y, int HP);

  void print() const;

  bool bord(int X, int Y);

  int brique(int X, int Y);
  
  bool palette(int X, int Y);
  bool bordPaletteG(int X, int Y);
  bool bordPaletteD(int X, int Y);

  bool bloc(int X, int Y);

  void coin2(int k, int i, int j);
  void coin(int i, int j);

  void rebond();
};

#endif
