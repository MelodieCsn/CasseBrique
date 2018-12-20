#ifndef __JOUEUR_H
#define __JOUEUR_H

#include <string>

class Joueur {
 public:
  
  enum Couleur{
    BLEU, 
    ROUGE,
    NOIR, //derniere vie:GameOver
    NB_COULEURS 
  };

 private:
 
  size_t nom;
  unsigned int x, y;
  Couleur couleur;

 public:
  Joueur();
  Joueur(bool etat, unsigned int x, unsigned int y);

  // Accesseurs en lecture
  bool getNbDeVies() const;
  unsigned int getX() const;
  unsigned int getY() const;
  Couleur getCouleur() const;

  // Accesseurs en �criture
  void setX(unsigned int x);
  void setY(unsigned int y);
  void setNbDeVies(bool etat);

  // affiche le joueur
  void print() const;

  // sp�cifie que le joueur doit mourir au prochain tour du jeu (-> changement de couleur)
  void vaMourir();

};


// Renvoie vrai si le joueur est de la couleur pass�e en param�tre, faux sinon.
bool JoueurEstDeLaCouleur(const Joueur &joueur, Joueur::Couleur couleur);

// Retourne la cha�ne correspondant � la couleur pass�e en param�tre
std::string Couleur2String(Joueur::Couleur c);

#endif
