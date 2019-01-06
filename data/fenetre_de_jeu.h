#ifndef FENETRE_DE_JEU_H
#define FENETRE_DE_JEU_H

#include "terrain.h"
#include "message.h"
#include "niveau.h"

class FenetreDeJeu{
  
 private:

  Terrain plateau;
  Message titre;
  Message infos;
  Message help;
  Message levelup;
  Message gameover;

 public:

  FenetreDeJeu(); // Crée toute la fenêtre de jeu ( plateau et messages )

  void chargerNiveau(Niveau n); // Charge un niveau, l'affiche et affiche son numéro dans infos
  
  Terrain& getPlateau();  // Renvoie le plateau (modifiable)
  Message& getTitre();    // Renvoie le titre (modifiable)
  Message& getInfos();    // Renvoie les infos (modifiable)
  Message& getHelp();     // Renvoie l'aide  (modifiable)
  Message& getLevelup();  // Renvoie le "level up" (modifiable)
  Message& getGameover(); // Renvoie le "game over" (modifiable)

  void start();  // Permet de "lancer le cycle" du jeu, en lançant la balle
  void aide();   // Affiche l'aide puis après avoir appuyé sur 'h', la désafiche
  void moveG5(); // Permet de bouger la raquette ( et la balle si start=false ) de 5 cases à gauche
  void moveG1(); // Permet de bouger la raquette ( et la balle si start=false ) de 1 case à gauche
  void moveD1(); // Permet de bouger la raquette ( et la balle si start=false ) de 1 case à droite
  void moveD5(); // Permet de bouger la raquette ( et la balle si start=false ) de 5 cases à droite

  void update();
  // Utilise plateau.update() puis affiche les nouveaux plateau, score et balles
  void nouveauNiveau(Niveau n);
  // Fait clignoter levelup et charge un nouveau niveau en actualisant son numéro et les balles
};

#endif
