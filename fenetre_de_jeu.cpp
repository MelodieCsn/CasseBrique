#include "fenetre_de_jeu.h"

FenetreDeJeu::FenetreDeJeu() : titre(plateau,"titre"), infos(plateau,"infos"), help(plateau,"help"), levelup(plateau,"levelup"), gameover(plateau,"gameover"){
  titre.afficher(true);
  infos.afficher(true);
  plateau.print()
}
