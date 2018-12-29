#include "message.h"

#include <string>
using namespace std;

Message::Message(Terrain p, string nom) : /*win(height,width,x,y,' ')*/ {
    
  switch(nom){

  case "titre":
    height=1;
    width=12;
    x=((p.getWin().getWidth()+13+9)/2)-7;
    y=0;
    msg="Casse-Brique";
    Color=WRED;
    break;
    
  case "infos":
    height=6;
    width=13;
    x=p.getWin().getWidth()+7;
    y=5;
    msg="Niveau :\n\
Score :\n\
Balle(s) :\n\n\
Aide : 'H'\n\
Quitter : 'Q'";
    Color=WMAGENTA;
    break;
    
  case "help":
    height=10;
    width=60;
    x=1;
    y=max(4+p.getWin().getHeight()+3,14);
    msg="Bienvenue dans l'aide ! Appuyez sur 'H' pour revenir au jeu.\n\
But du jeu : Casser toutes les briques a l'aide de la balle.\
             Vous perdez une vie quand la balle touche le\n\
             bord inferieur, en dessous de 0, c'est fini !\n\n\
Commandes : < : Deplacer la palette d'une case a gauche.\n\
            > : Deplacer la palette d'une case a gauche.\n\
            SPACE : Tirer la balle au debut du niveau\n\
                    ou apres avoir perdu une vie.";
    Color=BYELLOW;
    break;
    
  case "levelup":
    height=2;
    width=13;
    x=p.getWin().getWidth()+7;
    y=14;
    msg="Niveau fini !\
 + 1 balle ! ";
    Color=BYELLOW;
    break;
    
  case"gameover":
    height=1;
    width=11;
    x=(p.getWin().getWidth()/2)-4;
    y=4+p.getWin().getHeight()/2;
    msg="GAME OVER !";
    Color=BYELLOW;
    break;
  }
}
