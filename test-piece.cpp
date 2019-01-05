#include "window.h"
#include "fenetre_de_jeu.h"
#include "menu.h"
#include "title.h"
#include "message.h"
#include "terrain.h"
#include "niveau.h"
#include "score.h"
#include "tableau_brique.h"
#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include <cstring>
#include <unistd.h>
#include "lettre.h"

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

  if(menu.getY()!=5 || menu.getPlace()!='m'){

    Niveau lvlone(1);

    Brique b11(3,5,1);
    Brique b12(7,4,2);
    Brique b13(6,4,3);
    Brique b14(6,5,4);
    Brique b15(20,5,5);

    lvlone.addBrique(b11);
    lvlone.addBrique(b12);
    lvlone.addBrique(b13);
    lvlone.addBrique(b14);
    lvlone.addBrique(b15);

    Niveau lvlthree(3);

    Brique b31(7,5,1);
    Brique b32(7,3,2);
    Brique b33(6,18,3);
    Brique b34(0,5,4);
    Brique b35(21,5,5);

    lvlthree.addBrique(b31);
    lvlthree.addBrique(b32);
    lvlthree.addBrique(b33);
    lvlthree.addBrique(b34);
    lvlthree.addBrique(b35);

    Niveau error(5);

    Brique b51(7,5,1);
    Brique b52(7,5,2);

    error.addBrique(b51);
    error.addBrique(b52);

    FenetreDeJeu game(lvlone);
  
    do{
      ch = getch();
      switch (ch) {
      case ' ':
	game.getPlateau().setStart(true);
	break;
      case 'h':
	game.getHelp().afficher(true);
	while((ch = getch()) != 'h'){}
	game.getHelp().afficher(false);
	break;
      case KEY_LEFT:
	if(game.getPlateau().getRaq().getX()>0){
	  if(!game.getPlateau().getStart())
	    game.getPlateau().slideBall(-1);
	  game.getPlateau().slideRaq(-1);
	}
	break;
      case KEY_RIGHT:
	if(game.getPlateau().getRaq().getX()+game.getPlateau().getRaq().getLength()<game.getPlateau().getWin().getWidth()){
	  if(!game.getPlateau().getStart())
	    game.getPlateau().slideBall(1);
	  game.getPlateau().slideRaq(1);
	}
	break;
      case 'a':
	if(game.getPlateau().getRaq().getX()>4){
	  if(!game.getPlateau().getStart())
	    game.getPlateau().slideBall(-5);
	  game.getPlateau().slideRaq(-5);
	}
	break;
      case 'e':
	if(game.getPlateau().getRaq().getX()+game.getPlateau().getRaq().getLength()+4<game.getPlateau().getWin().getWidth()){
	  if(!game.getPlateau().getStart())
	    game.getPlateau().slideBall(5);
	  game.getPlateau().slideRaq(5);
	}
	break;
      }
      if(game.getPlateau().getStart()){
	usleep(50000);
	game.getPlateau().update();
	game.getPlateau().print();
	game.getInfos().write(8,1,itoa(game.getPlateau().getScore().getScore()));
	game.getInfos().write(11,2,itoa(game.getPlateau().getBall().getNb()));
	if(game.getPlateau().getT().estVide()){
	  game.getLevelup().clignoter(WMAGENTA);
	  game.getLevelup().afficher(false);
	  if(game.getPlateau().getLvl()==1)
	    game.getPlateau().chargerNiveau(lvlthree);
	  else
	    game.getPlateau().chargerNiveau(lvlone);
	  
	  game.getInfos().write(9,0,itoa(game.getPlateau().getLvl()));
	  game.getPlateau().getBall().setNb(game.getPlateau().getBall().getNb()+1);
	  game.getInfos().write(11,2,itoa(game.getPlateau().getBall().getNb()));
	  
	  game.getPlateau().reset();
	  game.getPlateau().print();
	  
	  game.getPlateau().setStart(false);
	}	  
	if(game.getPlateau().getBall().getNb()<0)
	  ch='q';
      }
    }while(ch != 'q');
  
    if(game.getPlateau().getBall().getNb()<0)
      game.getGameover().clignoter(WMAGENTA);
  }
}

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
