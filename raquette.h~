#ifndef _RAQUETTE_H
#define _RAQUETTE_H
#include <string>
using namespace std;

enum Couleur {
	NOIR,
	BLEU,
	VERT,
	ROUGE,
	JAUNE,
};

class Raquette {

 private :
 	unsigned int x ;
 	unsigned int y ;
 	size_t height;
 	size_t width;
 	Couleur colin;
 	Couleur colout;
	unsigned int n; //niveau

 public:

 	Raquette(unsigned int x, unsigned int y, size_t h, size_t w, unsigned int n); 

 	unsigned int getX() const;
 	unsigned int getY() const;
 	size_t getHeight() const;
 	size_t getWidth() const;
	Couleur getColIn();
	Couleur getColOut();

 	void setX(unsigned int x);
	void setY(unsigned int y);

	string Couleur2String(Couleur c);

};





#endif