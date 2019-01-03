#include "window.h"
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

void myprogram(){
  int ch;

  Niveau lvlone(1);
  Niveau lvlthree(3);
  Terrain plateau;

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

  Brique b21(7,5,1);
  Brique b22(7,3,2);
  Brique b23(6,18,3);
  Brique b24(0,5,4);
  Brique b25(21,5,5);

  lvlthree.addBrique(b21);
  lvlthree.addBrique(b22);
  lvlthree.addBrique(b23);
  lvlthree.addBrique(b24);
  lvlthree.addBrique(b25);

  plateau.chargerNiveau(lvlone);

  Message titre(plateau,"titre");
  Message infos(plateau,"infos");
  Message help(plateau,"help");
  Message levelup(plateau,"levelup");
  Message gameover(plateau,"gameover");

  plateau.print();

  titre.afficher(true);
  infos.afficher(true);
  
  do{
    if(plateau.getStart()){
    usleep(50000);
    plateau.getWin().print(plateau.getBall().getX(),plateau.getBall().getY(),' ');
    plateau.rebond();
    plateau.getBall().update();
    plateau.print();
    infos.write(8,1,itoa(plateau.getScore().getScore()));
    }
    ch = getch();
    switch (ch) {
    case ' ':
      plateau.setStart(true);
      break;
    case 'z':
      if(plateau.getStart()){
	plateau.getBall().setNb(plateau.getBall().getNb()-1);
	infos.write(11,2,itoa(plateau.getBall().getNb()));
	
	plateau.reset();
	plateau.print();
	
	plateau.setStart(false);
      
      if(plateau.getBall().getNb()<0)
	ch='q';
      }
      break;
    case 's':
      levelup.clignoter(WMAGENTA);
      levelup.afficher(false);
      if(plateau.getLvl()==1)
	plateau.chargerNiveau(lvlthree);
      else
	plateau.chargerNiveau(lvlone);
      
      infos.write(9,0,itoa(plateau.getLvl()));
      plateau.getBall().setNb(plateau.getBall().getNb()+1);
      infos.write(11,2,itoa(plateau.getBall().getNb()));

      plateau.reset();
      plateau.print();
      
      plateau.setStart(false);
	
      break;
    case 'h':
      help.afficher(true);
      while((ch = getch()) != 'h'){}
      help.afficher(false);
      break;
    case KEY_LEFT:
      if(plateau.getRaq().getX()>0){
	if(!plateau.getStart())
	  plateau.slideBall(-1);
        plateau.slideRaq(-1);
      }
      break;
    case KEY_RIGHT:
      if(plateau.getRaq().getX()+plateau.getRaq().getLength()<plateau.getWin().getWidth()){
	if(!plateau.getStart())
	  plateau.slideBall(1);
        plateau.slideRaq(1);
    }
      break;
      case 'a':
      if(plateau.getRaq().getX()>4){
	if(!plateau.getStart())
	  plateau.slideBall(-5);
        plateau.slideRaq(-5);
      }
      break;
      case 'e':
      if(plateau.getRaq().getX()+plateau.getRaq().getLength()+4<plateau.getWin().getWidth()){
	if(!plateau.getStart())
	  plateau.slideBall(5);
        plateau.slideRaq(5);
    }
      break;
    }
  }while(ch != 'q');
  
  if(plateau.getBall().getNb()<0){
    gameover.clignoter(WMAGENTA);      
    while((ch=getch())!='q'){}
  }
  
}

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
