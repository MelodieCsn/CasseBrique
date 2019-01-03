#include "message.h"
#include <unistd.h>

Message::Message(Terrain& p, string nom) : win(
					      (nom=="titre"?1:(nom=="infos"?6:(nom=="help"?12:(nom=="levelup"?2:1)))),
					      (nom=="titre"?12:(nom=="infos"?13:(nom=="help"?60:(nom=="levelup"?13:11)))),
					      (nom=="titre"?((p.getWin().getWidth()+13+9)/2)-7:(nom=="infos"?p.getWin().getWidth()+7:(nom=="help"?1:(nom=="levelup"?p.getWin().getWidth()+7:(p.getWin().getWidth()/2)-4)))),
					      (nom=="titre"?0:(nom=="infos"?5:(nom=="help"?max(4+p.getWin().getHeight()+3,14):(nom=="levelup"?14:4+p.getWin().getHeight()/2)))),
					      ' ')
{
    
  if(nom=="titre"){
    /*height=1;
    width=12;
    x=((p.getWin().getWidth()+13+9)/2)-7;
    y=0;*/
    col=WRED;
    win.print(0,0,"Casse-Brique");

  }else if(nom=="infos"){
    /*height=6;
    width=13;
    x=p.getWin().getWidth()+7;
    y=5;*/
    col=WMAGENTA;
    win.print(0,0,"Niveau :\n\
Score :\n\
Balle(s) :\n\n\
Aide : 'H'\n\
Quitter : 'Q'");
    win.print(9,0,itoa(p.getLvl()));
    win.print(8,1,itoa(p.getScore().getScore()));
    win.print(11,2,itoa(p.getBall().getNb()));
    
  }else if(nom=="help"){
    /*height=12;
    width=60;
    x=1;
    y=max(4+p.getWin().getHeight()+3,14);*/
    col=BYELLOW;
    win.print(0,0,"Bienvenue dans l'aide ! Appuyez sur 'H' pour revenir au jeu.\n\
But du jeu : Casser toutes les briques a l'aide de la balle.\
             Vous perdez une vie quand la balle touche le\n\
             bord inferieur, en dessous de 0, c'est fini !\n\n\
Commandes : < : Deplacer la palette d'une case a gauche.\n\
            > : Deplacer la palette d'une case a droite.\n\
            a : Deplacer la palette de 5 cases a gauche.\n\
            e : Deplacer la palette de 5 cases a droite.\n\
            SPACE : Tirer la balle au debut du niveau\n\
                    ou apres avoir perdu une vie.");
    
  }else if(nom=="levelup"){
    /*height=2;
    width=13;
    x=p.getWin().getWidth()+7;
    y=14;*/
    col=BYELLOW;
    win.print(0,0,"Niveau fini !\
 + 1 balle ! ");
    
  }else{
    /*height=1;
    width=11;
    x=(p.getWin().getWidth()/2)-4;
    y=4+p.getWin().getHeight()/2;*/
    col=BYELLOW;
     win.print(0,0,"GAME OVER !");
  }
  
  win.setCouleurBordure(BBLACK);
  win.setCouleurFenetre(BBLACK);
}

void Message::write(int X, int Y, char c){ win.print(X,Y,c); }
void Message::write(int X, int Y, string m){ win.print(X,Y,m); }
void Message::afficher(bool b){
  if(b){
    win.setCouleurBordure(col);
    win.setCouleurFenetre(col);
  }
  else{
    win.setCouleurBordure(BBLACK);
    win.setCouleurFenetre(BBLACK);
  }
}
void Message::clignoter(Color c){
  for(int i=0;i<3;i++){
	win.setCouleurFenetre(c);
	win.setCouleurBordure(c);
	usleep(500000);
	win.setCouleurFenetre(col);
	win.setCouleurBordure(col);
	usleep(500000);
      }
}

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
