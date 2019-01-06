#include "menu.h"
#include "classement.h"
#include "niveau.h"
#include "fenetre_de_jeu.h"
#include <iostream>
using namespace std;

void parametres(int argc, char** argv){
  for (int i=1;i<argc;i++){
    string h="--help";
    string v="--version";
    string a="--auteurs";
    if(argv[i]==h)
      cout<<"\nVous arrivez premièrement dans un menu où vous pouvez lancer un certain niveau, regarder les meilleurs scores, quitter, ou faire clignoter le titre ( pas utile, mais joli ! )\n\n\
Vous pouvez naviguer dans ce menu avec la FLECHE DU HAUT, la FLECHE DU BAS et ENTER.\n\n\n\
Si vous lancez une partie, le but est simple, vous devez casser toutes les briques à l'aide de la balle située au début sur la raquette. Il vous suffit de la lancer pour commencer.\n\
Il faut en revanche déplacer la raquette car si la balle touche la partie basse du terrain, vous perdez une vie, et après 0 c'est le Game Over ( Mais vous gagnez 1 vie à chaque niveau ! ).\n\
Les moyens de terminer le jeu sont la touche 'q', perdre le jeu, ou gagner le jeu ( on ne parlera pas de CTRL+C hein ... ).\n\n\
Les touches sont : SPACE : lance la balle au début ou après être mort, FLECHE DE GAUCHE : déplace la palette d'une case à gauche, FLECHE DE DROITE : déplace la palette d'une case à droite,\n\
                   'a' : déplace la palette de 5 cases à gauche, 'e' : déplace la palette de 5 cases à droite.\n"<<endl;
    else if(argv[i]==v)
      cout<<"\nLa version du jeu est V1.12.\n"<<endl;
    else if(argv[i]==a)
      cout<<"\nLes auteurs du jeu sont : Ahamed Eliza, Cassan Mélodie, Galinier Lisa et Wyszynski Anthony.\n"<<endl;
    else
      cerr<<"\nLes paramètres disponibles sont --help, --version, et --auteurs.\n"<<endl;
  }
}

void myprogram(){
  int ch;

  Menu menu;
  
  do{
    ch = getch();
    switch (ch) {
    case KEY_UP:
      menu.up();
      break;
    case KEY_DOWN:
      menu.down();
      break;
    case '\n':
      menu.choose();
      break;
    }
  }while(menu.getB());

  if(menu.getY()!=7 || menu.getPlace()!='m'){

    FenetreDeJeu game;

    Niveau lvlone(1);
    Niveau lvlthree(3);
    Niveau error(5);

    if(menu.getY()==1 || menu.getY()==3){
      int k;
      for(int x=6;x<game.getPlateau().getWin().getWidth()-6;x+=8){
	k=4;
	for(int y=1;y<15;y+=4){
	  for(int i=0;i<5;i++)
	    lvlone.addBrique(x+i,y,k);
	  k--;
	}
      }
      if(menu.getY()==1)
	game.chargerNiveau(lvlone);
      else{
	Brique b31(3,4,1);
	Brique b32(7,4,2);
	Brique b33(6,4,3);
	Brique b34(6,5,4);
	Brique b35(20,13,5);
	lvlthree.addBrique(b31);
	lvlthree.addBrique(b32);
	lvlthree.addBrique(b33);
	lvlthree.addBrique(b34);
	lvlthree.addBrique(b35);
	game.chargerNiveau(lvlthree);
      }      
    }
    else{
      Brique b51(7,5,1);
      Brique b52(7,5,2);
      error.addBrique(b51);
      error.addBrique(b52);
      game.chargerNiveau(error);
    }
  
    do{
      ch = getch();
      switch (ch) {
      case ' ':
	game.start();
	break;
      case 'h':
	game.aide();
	break;
      case KEY_LEFT:
	game.moveG1();
	break;
      case KEY_RIGHT:
        game.moveD1();
	break;
      case 'a':
        game.moveG5();
	break;
      case 'e':
        game.moveD5();
	break;
      }
      if(game.getPlateau().getStart()){
        game.update();
	if(game.getPlateau().getT().estVide()){
	  if(game.getPlateau().getLvl()==3)
	    game.nouveauNiveau(lvlone);
	  else
	    ch='q';
	}	  
	if(game.getPlateau().getBall().getNb()<0)
	  ch='q';
      }
    }while(ch != 'q');
    
    game.getGameover().clignoter(WRED);
    menu.getCls().save(game.getPlateau().getScore());
  }
}

int main(int argc, char** argv){
  if(argc!=1){
    parametres(argc,argv);
  }else{
    startProgramX();
    myprogram();
    stopProgramX();
  }
  return 0;
}
