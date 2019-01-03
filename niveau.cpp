#include "niveau.h"
#include <iostream>

Niveau::Niveau(): nbBriques(3), nbLignes(3), espaceBrique(1) {}
Niveau::Niveau(unsigned int nbB, unsigned int nbL, unsigned int espB) : nbBriques(nbB), nbLignes(nbL), espaceBrique(espB) {}

unsigned int Niveau::getNbBriques() const {return nbBriques ;}
unsigned int Niveau::getNbLignes() const {return nbLignes;}
unsigned int Niveau::getEspaceBrique() const {return espaceBrique;}

void Niveau::setNbBriques(unsigned int nbB) {this->nbBriques=nbB;}
void Niveau::setNbLignes(unsigned int nbL){this->nbLignes=nbL;}
void Niveau::setEspaceBrique(unsigned int espB) {this->espaceBrique=espB;}
