#ifndef _RAQUETTE_H
#define _RAQUETTE_H
using namespace std;

class Raquette {

 private :
 	int x ;
 	int y ;
 	int length;	

 public:

 	Raquette(int X, int Y, int l); 

 	int getX() const;
 	int getY() const;
 	int getLength() const;

 	void setX(int X);

};

#endif
