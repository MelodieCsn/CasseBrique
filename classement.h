#ifndef __TABSCORE_H
#define __TABSCORE_H
#include "window.h"
#include "score.h"

class Classement{
 private:
  Window win;
  string T[10];

 public:

  Classement();
  
  Window& getWin();

  void catchFile();
  
  void save(Score s);
  void print(bool b);
  void rewrite();
  bool alphabet(char c);
  
};

#endif
