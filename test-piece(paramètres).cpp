#include "window.h"
#include "balle.h"
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

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

/*bool bord(int x, int y, Window& p){
  
  bool res = false;
  if(x>=p.getX() && x<=p.getX()+p.getLargeur()){
    if(y==p.getY() || y==p.getY()+p.getHauteur())
      res = true;
  }
  if(y>p.getY() && y<p.getY()+p.getHauteur()){
    if(x==p.getX() || x==p.getX()+p.getLargeur())
      res = true;    
  }
  return res;
  }*/

bool bord(int x, int y, Window& p){
  
  bool res = false;
  if(x>=-1 && x<=p.getLargeur()){
    if(y==-1 || y==p.getHauteur())
      res = true;
  }
  if(y>=-1 && y<=p.getHauteur()){
    if(x==-1 || x==p.getLargeur())
      res = true;    
  }
  return res;
  }

void coin2(int k, int i, int j, balle& ball){

  switch(k){
  case 1:
    
    if(i==1)
      if(j==1)
	ball.setDir(1);
      else
	ball.setDir(4);
    else
      if(j==1)
	ball.setDir(3);
      else
	ball.setDir(6);
    
    break;
  case 2:

    if(i==1)
      if(j==1)
	ball.setDir(3);
      else
	ball.setDir(6);
    else
      if(j==1)
	ball.setDir(1);
      else
	ball.setDir(4);

    break;
  case 3:

    if(i==1)
      if(j==1)
	ball.setDir(4);
      else
	ball.setDir(1);
    else
      if(j==1)
	ball.setDir(6);
      else
	ball.setDir(3);

    break;
  }
  
}


void coin(int i, int j, balle& ball, Window& p){
  
  int x=ball.getX(), y=ball.getY();
  if((bord(x+i,y,p) && bord(x,y+j,p)) || (bord(x+i,y+j,p) && !bord(x,y+j,p) && !bord(x+i,y,p)))
    coin2(1,i,j,ball);
  else if(bord(x,y+j,p))
    coin2(2,i,j,ball);    
  else if(bord(x+i,y,p))
    coin2(3,i,j,ball);
    
}
 
void rebond(balle& ball, Window& p){
  
  switch(ball.getDir()){
  case 1:
    coin(-1,-1,ball,p);
    break;
  case 2:
    if(bord(ball.getX(),ball.getY()-1,p))
      ball.setDir(5);
    break;
  case 3:
    coin(1,-1,ball,p);
    break;
  case 4:
    coin(-1,1,ball,p);
    break;
  case 5:
    if(bord(ball.getX(),ball.getY()+1,p))
      ball.setDir(2);
    break;
  case 6:
    coin(1,1,ball,p);
    break;

   }
}


/* 

xx ox xo
x  x  o

xx ox
o  o

xo oo
x  x

oo
o

*/


void myprogram(){
  int ch;
  int lvl=1;
  int score=0;
  int balles=3;

  Window plateau(21,41,1,4,' ');
  Window infos(6,13,plateau.getLargeur()+7,5,' ');
  Window titre(1,12,((plateau.getLargeur()+infos.getLargeur()+9)/2)-7,0,' ');
  Window aide(10,60,1,(plateau.getHauteur()+titre.getHauteur()+6),' ');
  Window lvlup(2,13,infos.getX(),infos.getY()+infos.getHauteur()+3,' ');

  aide.print(0,0,"Bienvenue dans l'aide ! Appuyez sur 'H' pour revenir au jeu.");
  aide.print(0,2,"But du jeu : Casser toutes les briques a l'aide de la balle.");
  aide.print(0,3,"             Vous perdez une vie quand la balle touche le");
  aide.print(0,4,"             bord inferieur, en dessous de 0, c'est fini !");
  aide.print(0,6,"Commandes : < : Deplacer la palette d'une case a gauche.");
  aide.print(0,7,"            > : Deplacer la palette d'une case a gauche.");
  aide.print(0,8,"            SPACE : Tirer la balle au debut du niveau");
  aide.print(0,9,"                    ou apres avoir perdu une vie.");
  aide.setCouleurFenetre(BBLACK);
  aide.setCouleurBordure(BBLACK);

  lvlup.print(0,0,"Niveau fini !");
  lvlup.print(0,1," + 1 balle ! ");
  lvlup.setCouleurFenetre(BBLACK);
  lvlup.setCouleurBordure(BBLACK);
			 
  titre.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BGREEN);
  plateau.setCouleurFenetre(WBLUE);
  infos.setCouleurBordure(BMAGENTA);
  infos.setCouleurFenetre(WMAGENTA);
  
  titre.print(0,0,"Casse-Brique",WRED);
  
  infos.print(0,0,"Niveau : ");
  infos.print(9,0,itoa(lvl));
  infos.print(0,1,"Score : ");
  infos.print(8,1,itoa(score));
  infos.print(0,2,"Balle(s) : ");
  infos.print(11,2,itoa(balles));
  infos.print(0,4,"Aide : 'H'");
  infos.print(0,5,"Quitter : 'Q'");

  int x=plateau.getLargeur()/2,y=plateau.getHauteur()-2;
  char p=' ';
  Color col=WGREEN;
  plateau.print(x-2,y,p,WRED);
  plateau.print(x-1,y,p,col);
  plateau.print(x,y,p,col);
  plateau.print(x+1,y,p,col);
  plateau.print(x+2,y,p,WRED);

  balle ball(x,y-1,3,"@");
  plateau.print(ball);

  bool start=false;
  
  do{
    if(start){
    usleep(50000);
    plateau.print(ball.getX(),ball.getY(),' ');
    rebond(ball,plateau);
    ball.update();
    plateau.print(ball);
    }
    ch = getch();
    switch (ch) {
    case ' ':
      start = true;
      break;
    case 'r':
      infos.print(8,1,itoa(ball.getY()));
      break;
    case 'a':
      score+=1;
      infos.print(8,1,itoa(score));
      break;
    case 'z':
      balles-=1;
      infos.print(11,2,itoa(balles));
      start = false;
      ball.setDir(3);
      if(balles<0)
	ch='q';
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
      balles+=1;
      infos.print(11,2,itoa(balles));
      lvlup.setCouleurFenetre(BBLACK);
      lvlup.setCouleurBordure(BBLACK);
      break;
    case 'h':
      aide.setCouleurFenetre(BYELLOW);
      aide.setCouleurBordure(BYELLOW);
      while((ch = getch()) != 'h'){}
      aide.setCouleurFenetre(BBLACK);
      aide.setCouleurBordure(BBLACK);
      break;
    case KEY_LEFT:
      if(!start){
	plateau.print(x,y-1,' ');
	ball.setX(x-1);
	plateau.print(ball);
      }
      plateau.print(x+2,y,' ');
      plateau.print(--x,y,p,col);
      plateau.print(x-1,y,p,col);
      plateau.print(x-2,y,p,WRED);
      plateau.print(x+1,y,p,col);
      plateau.print(x+2,y,p,WRED);
      break;
    case KEY_RIGHT:
      if(!start){
	plateau.print(x,y-1,' ');
	ball.setX(x+1);
	plateau.print(ball);
      }
      plateau.print(x-2,y,' ');
      plateau.print(++x,y,p,col);
      plateau.print(x-1,y,p,col);
      plateau.print(x-2,y,p,WRED);
      plateau.print(x+1,y,p,col);
      plateau.print(x+2,y,p,WRED);
      break;
    }
  }while(ch != 'q');
  
  if(balles<0){
    
    Window GO(1,11,plateau.getLargeur()/2-4,4+plateau.getHauteur()/2,' ');
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

int main(int argc,char**argv){
  if(argc!=1){

    string s="--help";
    string t="--version";
    string u="--auteurs";
    for (int i=1;i<argc;i++){

      if(argv[i]==s){
        cout<<"But du jeu : Casser toutes les briques a l'aide de la balle."<<endl;
        cout<<"Vous perdez une vie quand la balle touche le bord inferieur, en dessous de 0, c\'est fini !"<<endl;
        cout<<"Commandes : < : Deplacer la palette d'une case a gauche."<<endl;
        cout<<"            > : Deplacer la palette d'une case a gauche."<<endl;
        cout<<"            SPACE : Tirer la balle au debut du niveau"<<endl;
        cout<<"                    ou apres avoir perdu une vie."<<endl;
      }
      if(argv[i]==t){
        cout<<"La version du jeu est V1.02"<<endl;
      }
      if(argv[i]==u){
        cout<<"Les auteurs du jeu sont : Ahamed Eliza, Cassan Mélody, Galinier Lisa et Wyszynski Anthony."<<endl;
      }
      if(argv[i]!=s && argv[i]!=t && argv[i]!=u){
        cerr<<"Les paramètres disponibles sont --help, --version, et --auteurs."<<endl;
      }
    }
    
  }
 
  else{
  startProgramX();
  myprogram();
  stopProgramX();
  
  }
  return 0;
}
