#ifndef __MESSAGE_H
#define __MESSAGE_H
#include "terrain.h"
#include "window.h"

class Message{
 private :

  Window win;
  Color col;
  
 public :
  
  Message(Terrain& p, string nom);
  
  void write(int X, int Y, char c);
  void write(int X, int Y, string m);
  void afficher(bool b);
  void clignoter(Color c);
};

char* itoa(int val);

#endif
