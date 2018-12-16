#include "window.h"
#include "brique.h"
#include "stdlib.h"
#include "balle.h"

void myprogram(){
  int ch;
  int h=10,w=10;
 
  Window menu(3,30,1,0);
  Window plateau(h,w,1,6);
  Window infos(7,14,17,8);
  Window aide(50,50,0,0);

  Brique b(1,1,1,1,VERT);
  plateau.print(b);

  Balle ba(10,10);
  plateau.print(ba);

  
  menu.setCouleurBordure(BRED);
  plateau.setCouleurBordure(BBLUE);
  infos.setCouleurBordure(BMAGENTA);
  infos.setCouleurFenetre(BMAGENTA);

  menu.print(4,1,"Casse Briques",WRED);
  infos.print(1,0,"Niveau : ",WMAGENTA);
  infos.print(1,1,"Score : ",WMAGENTA);
  infos.print(1,2,"Balle(s) : ",WMAGENTA);
  infos.print(1,3,"Aide : 'H'",WMAGENTA);
  infos.print(1,4,"Quitter : 'Q'",WMAGENTA);

  int x=w/2,y=h/2;
  char p='X';
  Color col=WBLUE;
  plateau.print(x,y,p,col);
  
  while((ch = getch()) != 'q')
    {
      switch (ch) {
      case '1':
	col=BMAGENTA;
	break;
      case '2':
	col=WCYAN;
	break;
      case 'c':
	plateau.clear();
	break;
      case KEY_UP:
	plateau.print(x,y,' ');
	plateau.print(x,--y,p,col);
	break;
      case KEY_DOWN:
	plateau.print(x,y,' ');
	plateau.print(x,++y,p,col);
	break;
      case KEY_LEFT:
	plateau.print(x,y,' ');
	plateau.print(--x,y,p,col);
	break;
      case KEY_RIGHT:
	plateau.print(x,y,' ');
	plateau.print(++x,y,p,col);
	break;
      case '\n':
	x=w/2,y=h/2;
	plateau.print(x,y,p,col);
	break;
      case 'h':
      aide.setCouleurBordure(BGREEN);
      aide.setCouleurFenetre(BGREEN);
      aide.print(1,1,"règles du jeu");
      break;
      case '\t':
	Color tmp= menu.getCouleurBordure();
	menu.setCouleurBordure(plateau.getCouleurBordure());
	plateau.setCouleurBordure(tmp);
	break;
      }
    }
}

int main(){
  startProgramX();
  myprogram();
  stopProgramX();
  return 0;
}
