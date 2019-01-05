#ifndef __TITLE_H
#define __TITLE_H

#include "lettre.h"
#include "window.h"
#include <unistd.h>

class Title{
 private :

  Window win;
  Lettre data[12];

 public :

  Title();

  void fade(bool b) const;
  void clignoter() const;
};

#endif
