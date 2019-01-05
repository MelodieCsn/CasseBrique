#include "niveau.h"
#include <iostream>

Niveau::Niveau(): pvBriques(3), nbLignes(3), espaceBrique(1) {}
Niveau::Niveau(unsigned int nbB, unsigned int nbL, unsigned int espB) : pvBriques(nbB), nbLignes(nbL), espaceBrique(espB) {}

unsigned int Niveau::getpvBriques() const {return pvBriques ;}
unsigned int Niveau::getNbLignes() const {return nbLignes;}
unsigned int Niveau::getEspaceBriques() const {return espaceBrique;}

void Niveau::setPvBriques(unsigned int nbB) {this->pvBriques=nbB;}
void Niveau::setNbLignes(unsigned int nbL){this->nbLignes=nbL;}
void Niveau::setEspaceBriques(unsigned int espB) {this->espaceBrique=espB;}
