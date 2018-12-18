#ifndef _RAQUETTE_H
#define _RAQUETTE_H
using namespace std;

class raquette {

 private :
 	int X ;
 	int Y ;
 	int lenght;	

 public:

 	raquette(int x, int y, int l); 

 	int getX() const;
 	int getY() const;
 	int getLenght() const;

 	void setX(unsigned int x);
	void setY(unsigned int y);

};

#endif
