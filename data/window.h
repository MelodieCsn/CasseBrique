#ifndef WINDOW_H
#define WINDOW_H

extern "C" {
#include <curses.h>
}
#include <string>
#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include "lettre.h"
using namespace std;

// Ensemble de couleurs possibles (fond+texte)
enum Color {
  WBLACK,  // couleur fond = noir ,   couleur texte = blanc
  WCYAN,   // couleur fond = cyan,    couleur texte = blanc
  WBLUE,   // couleur fond = bleu,    couleur texte = blanc
  WYELLOW, // couleur fond = jaune,   couleur texte = blanc
  WGREEN,  // couleur fond = vert,    couleur texte = blanc
  WMAGENTA,// couleur fond = magenta, couleur texte = blanc
  WRED,	   // couleur fond = rouge,   couleur texte = blanc
  WWHITE,  // couleur fond = blanc,   couleur texte = blanc
  BCYAN,   // couleur fond = cyan,    couleur texte = noir
  BBLUE,   // couleur fond = bleu,    couleur texte = noir
  BYELLOW, // couleur fond = jaune,   couleur texte = noir
  BGREEN,  // couleur fond = vert,    couleur texte = noir 
  BMAGENTA,// couleur fond = magenta, couleur texte = noir
  BRED,    // couleur fond = rouge,   couleur texte = noir
  BBLACK,  // couleur fond = noir,    couleur texte = noir
  BWHITE,  // couleur fond = noir,    couleur texte = blanc
};

void startProgramX(); // Fonction pour démarrer le mode console graphique
void stopProgramX();  // Fonction pour arrêter le mode console graphique

class Window {
  
 private:
  
  int height, width, startx, starty;
  WINDOW* win, *frame;
  Color colorwin, colorframe;
  char bord;
  void update() const;

 public:

  // Constructeur d'une fenêtre de hauteur h, largeur w dont le coin superieur gauche
  // à pour coordonnée (x,y). Le caractère c est utilisé pour définir la bordure
  Window(int h,int w, int x, int y, char c='+');

  ~Window();

  // Fonction permettant d'afficher une variable s de type string ou char à la position (x,y) dans win.
  // Si une couleur est spécifié elle est utilisée, sinon la couleur de la fenêtre est utilisée
  void print(int x, int y, string s, Color c) const;
  void print(int x, int y, char s, Color c) const;
  void print(int x, int y, string s) const;
  void print(int x, int y, char s) const; 

  void print(Balle ball) const;             // Affiche la balle dans sa fenêtre
  void print(Raquette raq) const;           // Affiche la raquette dans sa fenêtre
  void print(Brique br) const;              // Affiche la brique dans sa fenêtre
  void print(Lettre lettre, Color c) const; // Affiche une lettre de couleur c dans sa fenêtre.
  
  int getX() const;                // Récupère l'abscisse du coin supérieur gauche de la fenêtre 
  int getY() const;                // Récupère l'ordonnée du coin supérieur gauche de la fenêtre 
  int getHeight() const ;          // Récupère la hauteur de la fenêtre
  int getWidth() const ;           // Récupère la largeur de la fenêtre
  Color getCouleurBordure() const; // Récupère la couleur de la bordure
  Color getCouleurFenetre() const; // Récupère la couleur de la fenêtre
  
  void setCouleurBordure(Color);   // Modifie la couleur de la bordure
  void setCouleurFenetre(Color);   // Modifie la couleur de la fenêtre

  void clear() const; // Enlève tout le contenu de la fenêtre

};

int termSize(bool b); // Si b=true : renvoie la longueur du terminal, sinon sa largeur

#endif
