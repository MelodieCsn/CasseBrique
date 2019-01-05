#ifndef __MENU_H
#define __MENU_H
#include "window.h"
#include "title.h"

class Menu{
 private :

  Window win;
  Title title;
  int x;
  int y;
  char place;
  bool b;

 public :

  Menu();

  Window& getWin();

  int getX() const;
  int getY() const;
  char getPlace() const;
  bool getB() const;
  void setY(int Y);

  void down();
  void up();
  void choose();

  void disappear();

  

};

#endif
