#ifndef __MESSAGE_H
#define __MESSAGE_H
#include "terrain.h"
#include "window.h"

#include <string>
using namespace std;

class Message{
 private :

  Window& win;
  string msg;
  Color col;
  
 public :
  
  Message(Terrain p, string nom);
  
  void write(int Y, int X, char c);
  void write(int Y, int X, string m);
  void afficher(bool i);
  void clignoter(Color c);

};

#endif
