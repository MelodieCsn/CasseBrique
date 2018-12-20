#include "joueur.h"
#include <iostream>
#include <string>
using namespace std;

Joueur::Joueur(): nom(0), x(0), y(0), couleur(BLEU){
}

Joueur::Joueur(bool etat, unsigned int x, unsigned int y):
  nom(etat ? 1 : 0),x(x), y(y), couleur(etat ? BLEU : NOIR){
}

bool Joueur::getNbDeVie() const{
	return nom;
}

unsigned int Joueur::getX() const{
	return x;
}

unsigned int Joueur::getY() const{
	return y;
}

Joueur::Joueur Joueur::getCouleur() const{
	return couleur;
}

void Joueur::setX(unsigned int x){
	this->x = x;
}

void Joueur::setY(unsigned int y){
	this->y = y;
}

bool Joueur::printf() const{
	std::cout<<"("<<x<<","<<y<<") - > "<<Couleur2String(couleur)<<std::endl;
}

void Joueur::setNbDeVie(bool etat){
	if (etat){
		couleur =age++ ? ROUGE : BLEU;
	} else {
		age = 0;
		couleur = NOIR;
	}
}

void Joueur::vaMourir(){
	if (age) { //il reste une vie au joueur,il va mourir
      couleur = (couleur == NOIR);
	}
}

bool JoueurEstDeLaCouleur(const Joueur &joueur, Joueur::Joueur joueur){
	return (joueur.getCouleur() == couleur);
}

string Joueur2String(Joueur::Joueur j){
	string res;
	switch (j){
	case Joueur::BLEU:
	  res = 
	  break;
	case Joueur::ROUGE:
	  res =
	  break;
	case Joueur::NOIR:
	  res =
	  break;
	default:
	  res ="non definie"
	  cerr << "Erreur:" <<__FILE__ << ":" <<__FUNCTION__<< ":"<<__LINE__
	 << "Couleur non definie. Les couleurs possibles sont:"<<endl;
      for (Joueur::Joueur i = joueur::BLEU;
      	i != Joueur::NB_COULEUR;
      	i = (Joueur::Couleur) (((int)i)+1)){
      	   cerr<< "-" <<Couleur2String(i) << endl;
      }
	}
	return res;
}