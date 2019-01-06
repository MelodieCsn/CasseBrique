#ifndef TITLE_H
#define TITLE_H

#include "window.h"
#include "lettre.h"

class Title{
 private :

  Window win;
  Lettre data[12];

 public :

  Title(int X, int Y); // Crée un titre "CASSE-BRIQUE" en (X,Y)

  void fade(bool b) const;
  // Si b=false, fait lentement apparaitre le titre, sinon le fait lentement disparaitre
  void clignoter() const;
  // Fait clignoter le titre de toutes les couleurs ( ou presque )
};

#endif
