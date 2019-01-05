#include "fenetre_de_jeu.h"

FenetreDeJeu::FenetreDeJeu(Niveau n) : titre(plateau,"titre"), infos(plateau,"infos"), help(plateau,"help"), levelup(plateau,"levelup"), gameover(plateau,"gameover"){
  plateau.chargerNiveau(n);
  infos.write(9,0,itoa(plateau.getLvl()));
  plateau.print();
  titre.afficher(true);
  infos.afficher(true);
}

Terrain& FenetreDeJeu::getPlateau(){ return plateau; }
Message& FenetreDeJeu::getTitre(){ return titre; }
Message& FenetreDeJeu::getInfos(){ return infos; }
Message& FenetreDeJeu::getHelp(){ return help; }
Message& FenetreDeJeu::getLevelup(){ return levelup; }
Message& FenetreDeJeu::getGameover(){ return gameover; }
