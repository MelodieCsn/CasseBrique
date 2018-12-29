#include "window.h"
#include "terrain.h"
#include "tableau_brique.h"
#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include <cstring>
#include <unistd.h>

char* itoa(int val){
  if(val==0){
    char *res=new char[1];
    res[0]='0';
    return res;
}
  else{
  int test=val, cpt=0;
    while(test>0){
      cpt+=1;
      test=test/10;
    }
    char *res=new char[cpt];
    while(cpt>0){
      res[--cpt]=(val%10)+'0';
      val=val/10;
    }
    return res;
  }
}

void myprogram(){
  int ch;
  int lvl=1;
  int score=0;
  
  Terrain plateau;

  Brique b1(3,5,1);
  Brique b2(4,5,2);
  Brique b3(5,5,3);
  Brique b4(6,5,4);
  Brique b5(20,5,5);

  plateau.addBrique(b1);
  plateau.addBrique(b2);
  plateau.addBrique(b3);
  plateau.addBrique(b4);
  plateau.addBrique(b5);

  plateau.print();
  
  Window infos(6,13,plateau.getWin().getWidth()+7,5,' ');
  Window titre(1,12,((plateau.getWin().getWidth()+13+9)/2)-7,0,' ');
  Window lvlup(2,13,infos.getX(),infos.getY()+infos.getHeight()+3,' ');
  Window aide(10,60,1,max(plateau.getWin().getY()+plateau.getWin().getHeight()+3,infos.getY()+infos.getHeight()+3),' ');

  /* aide.print(0,0,"Bienvenue dans l'aide ! Appuyez sur 'H' pour revenir au jeu.");
  aide.print(0,2,"But du jeu : Casser toutes les briques a l'aide de la balle.");
  aide.print(0,3,"             Vous perdez une vie quand la balle touche le");
  aide.print(0,4,"             bord inferieur, en dessous de 0, c'est fini !");
  aide.print(0,6,"Commandes : < : Deplacer la palette d'une case a gauche.");
  aide.print(0,7,"            > : Deplacer la palette d'une case a gauche.");
  aide.print(0,8,"            SPACE : Tirer la balle au debut du niveau");
  aide.print(0,9,"                    ou apres avoir perdu une vie.");*/

  aide.print(0,0,"Bienvenue dans l'aide ! Appuyez sur 'H' pour revenir au jeu.\n\
But du jeu : Casser toutes les briques a l'aide de la balle.\
             Vous perdez une vie quand la balle touche le\n\
             bord inferieur, en dessous de 0, c'est fini !\n\n\
Commandes : < : Deplacer la palette d'une case a gauche.\n\
            > : Deplacer la palette d'une case a gauche.\n\
            SPACE : Tirer la balle au debut du niveau\n\
                    ou apres avoir perdu une vie.");
  
  aide.setCouleurFenetre(BBLACK);
  aide.setCouleurBordure(BBLACK);

  lvlup.print(0,0,"Niveau fini !");
  lvlup.print(0,1," + 1 balle ! ");
  lvlup.setCouleurFenetre(BBLACK);
  lvlup.setCouleurBordure(BBLACK);
			 
  titre.setCouleurBordure(BRED);
  infos.setCouleurBordure(BMAGENTA);
  infos.setCouleurFenetre(WMAGENTA);
  
  titre.print(0,0,"Casse-Brique",WRED);

  infos.print(0,0,"Niveau : ");
  infos.print(9,0,itoa(lvl));
  infos.print(0,1,"Score : ");
  infos.print(8,1,itoa(score));
  infos.print(0,2,"Balle(s) : ");
  infos.print(11,2,itoa(plateau.getBall().getNb()));
  infos.print(0,4,"Aide : 'H'");
  infos.print(0,5,"Quitter : 'Q'");
  
  bool start=false;
  
  do{
    if(start){
    usleep(50000);
    plateau.getWin().print(plateau.getBall().getX(),plateau.getBall().getY(),' ');
    plateau.rebond();
    plateau.getBall().update();
    plateau.print();
    }
    ch = getch();
    switch (ch) {
    case ' ':
      start = true;
      break;
    case 'r':
      titre.setPos(5,5);
      break;
    case 'a':
      score+=1;
      infos.print(8,1,itoa(score));
      break;
    case 'z':
      if(start){
	plateau.getBall().setNb(plateau.getBall().getNb()-1);
	infos.print(11,2,itoa(plateau.getBall().getNb()));
	
	plateau.getWin().print(plateau.getRaq().getX(),plateau.getRaq().getY(),"     ");
	plateau.getWin().print(plateau.getBall().getX(),plateau.getBall().getY(),' ');

	plateau.getRaq().setX((plateau.getWin().getWidth()/2)-(plateau.getRaq().getLength()/2));
	plateau.getWin().print(plateau.getRaq());

	plateau.getBall().setX(plateau.getRaq().getX()+plateau.getRaq().getLength()/2);
	plateau.getBall().setY(plateau.getRaq().getY()-1);
	plateau.getBall().setDir(2);
	plateau.getWin().print(plateau.getBall());
	
	start = false;
      
      if(plateau.getBall().getNb()<0)
	ch='q';
      }
      break;
    case 's':
      for(int i=0;i<3;i++){
	lvlup.setCouleurFenetre(BYELLOW);
	lvlup.setCouleurBordure(BYELLOW);
	usleep(500000);
	lvlup.setCouleurFenetre(WMAGENTA);
	lvlup.setCouleurBordure(WMAGENTA);
	usleep(500000);
      }
      lvl+=1;
      infos.print(9,0,itoa(lvl));
      plateau.getBall().setNb(plateau.getBall().getNb()+1);
      infos.print(11,2,itoa(plateau.getBall().getNb()));
      lvlup.setCouleurFenetre(BBLACK);
      lvlup.setCouleurBordure(BBLACK);

      plateau.getWin().print(plateau.getRaq().getX(),plateau.getRaq().getY(),"     ");
      plateau.getWin().print(plateau.getBall().getX(),plateau.getBall().getY(),' ');
      
      plateau.getRaq().setX((plateau.getWin().getWidth()/2)-(plateau.getRaq().getLength()/2));
      plateau.getWin().print(plateau.getRaq());
      
      plateau.getBall().setX(plateau.getRaq().getX()+plateau.getRaq().getLength()/2);
      plateau.getBall().setY(plateau.getRaq().getY()-1);
      plateau.getBall().setDir(2);
      plateau.getWin().print(plateau.getBall());
      
      start = false;
	
      break;
    case 'h':
      aide.setCouleurFenetre(BYELLOW);
      aide.setCouleurBordure(BYELLOW);
      while((ch = getch()) != 'h'){}
      aide.setCouleurFenetre(BBLACK);
      aide.setCouleurBordure(BBLACK);
      break;
    case KEY_LEFT:
      if(plateau.getRaq().getX()>0){
	if(!start){
	  plateau.getWin().print(plateau.getBall().getX(),plateau.getBall().getY(),' ');
	  plateau.getBall().setX(plateau.getBall().getX()-1);
	  plateau.getWin().print(plateau.getBall());
	}
	plateau.getWin().print(plateau.getRaq().getX()+plateau.getRaq().getLength()-1,plateau.getRaq().getY(),' ');
	plateau.getRaq().setX(plateau.getRaq().getX()-1);
	plateau.getWin().print(plateau.getRaq());
      }
      break;
    case KEY_RIGHT:
      if(plateau.getRaq().getX()+plateau.getRaq().getLength()<plateau.getWin().getWidth()){
	if(!start){
	  plateau.getWin().print(plateau.getBall().getX(),plateau.getBall().getY(),' ');
	  plateau.getBall().setX(plateau.getBall().getX()+1);
	  plateau.getWin().print(plateau.getBall());
	}
	plateau.getWin().print(plateau.getRaq().getX(),plateau.getRaq().getY(),' ');
	plateau.getRaq().setX(plateau.getRaq().getX()+1);
	plateau.getWin().print(plateau.getRaq());
    }
      break;
    }
  }while(ch != 'q');
  
  if(plateau.getBall().getNb()<0){
    
    Window GO(1,11,plateau.getWin().getWidth()/2-4,4+plateau.getWin().getHeight()/2,' ');
      GO.setCouleurFenetre(BBLACK);
      GO.setCouleurBordure(BBLACK);
    GO.print(0,0,"GAME OVER !");
    for(int i=0;i<3;i++){
      GO.setCouleurFenetre(BYELLOW);
      GO.setCouleurBordure(BYELLOW);
      usleep(500000);
      GO.setCouleurFenetre(WMAGENTA);
      GO.setCouleurBordure(WMAGENTA);
      usleep(500000);
    }
      
    while((ch=getch())!='q'){}
  }
  
}

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
