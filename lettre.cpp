#include "lettre.h"

Lettre::Lettre() : height(0), width(0), x(0), y(0), forme(0) {}
Lettre::Lettre(int X, int Y, char ch) : height(ch=='-'?1:5), width(ch=='i'?1:(ch=='-'?2:3)), x(X), y(Y){
  
  switch(ch){
  case 'c':
    forme=111001001001111;
    break;
    case 'a':
    forme=101101111101111;
    break;
  case 's':
    forme=111100111001111;
    break;
  case 'e':
    forme=111001011001111;
    break;
  case '-':
    forme=11;
    break;
  case 'b':
    forme=11101011101011;
    break;
  case 'r':
    forme=101101011101111;
    break;
  case 'i':
    forme=11101;
    break;
  case 'q':
    forme=100011101101111;
    break;
  case 'u':
    forme=111101101101101;
    break;
  }
}

int Lettre::getHeight() const { return height; }
int Lettre::getWidth() const { return width; }
int Lettre::getX() const { return x; }
int Lettre::getY() const { return y; }
unsigned long long int Lettre::getForme() const{ return forme; }
