#include "menu.h"

Menu::Menu() : win(20,30,1,15,' '), x(1), y(1), place('m'), b(true){
  title.fade(false);
  
  win.setCouleurBordure(WWHITE);
  
  win.print(x,y,'x',WCYAN);
  win.print(3,1,"Nouvelle partie",BWHITE);
  win.print(3,3,"Titre clignotant");
  win.print(3,5,"Quitter");

}

Window& Menu::getWin(){ return win; }

int Menu::getX() const { return x; }
int Menu::getY() const { return y; }
char Menu::getPlace() const { return place; }
bool Menu::getB() const { return b; }
void Menu::setY(int Y){ y=Y; }





void Menu::down(){
  switch(y){
  case 1:
    win.print(x,y,' ');
    y+=2;
    win.print(x,y,'x',WCYAN);
    if(place=='m'){
      win.print(3,1,"Nouvelle partie");
      win.print(3,3,"Titre clignotant",BWHITE);
    }
    else{
      win.print(3,1,"Niveau 1");
      win.print(3,3,"Niveau 3 puis Niveau 1",BWHITE);
    }
    break;
  case 3:
    win.print(x,y,' ');
    y+=2;
    win.print(x,y,'x',WCYAN);
    if(place=='m'){
      win.print(3,3,"Titre clignotant");
      win.print(3,5,"Quitter ... ?",BWHITE);
    }
    else{
      win.print(3,3,"Niveau 3 puis Niveau 1");
      win.print(3,5,"Niveau \"Erreur\"",BWHITE);
    }
    break;
    case 5:
    if(place=='n'){
      win.print(x,y,' ');
      y+=2;
      win.print(x,y,'x',WCYAN);
      win.print(3,5,"Niveau \"Erreur\"");
      win.print(3,7,"Retour",BWHITE);
    }
    break;
  }
}





void Menu::up(){
  switch(y){
  case 3:
    win.print(x,y,' ');
    y-=2;
    win.print(x,y,'x',WCYAN);
    if(place=='m'){
      win.print(3,1,"Nouvelle partie",BWHITE);
      win.print(3,3,"Titre clignotant");
    }
    else{
      win.print(3,1,"Niveau 1",BWHITE);
      win.print(3,3,"Niveau 3 puis Niveau 1");
    }
    break;
  case 5:
    win.print(x,y,' ');
    y-=2;
    win.print(x,y,'x',WCYAN);
    if(place=='m'){
      win.print(3,3,"Titre clignotant",BWHITE);
      win.print(3,5,"Quitter      ");
    }
    else{
      win.print(3,3,"Niveau 3 puis Niveau 1",BWHITE);
      win.print(3,5,"Niveau \"Erreur\"");
    }
    break;
  case 7:
      win.print(x,y,' ');
      y-=2;
      win.print(x,y,'x',WCYAN);
      win.print(3,5,"Niveau \"Erreur\"",BWHITE);
      win.print(3,7,"Retour");
      break;
  }
}





void Menu::choose(){
  switch(y){
  case 1:
    if(place=='m'){
      place='n';
      win.print(3,1,"               ");
      win.print(3,1,"Niveau 1",BWHITE);
      win.print(3,3,"Niveau 3 puis Niveau 1");
      win.print(3,5,"Niveau \"Erreur\"");
      win.print(3,7,"Retour");
    }
    else
      disappear();
    break;
  case 3:
    if(place=='m')
      title.clignoter();
    else
      disappear();
    break;
  case 5:
    disappear();
    break;
  case 7:
    place='m';
    win.print(x,y,' ');
    x=1;
    y=1;
    win.print(x,y,'x',WCYAN);
    win.print(3,1,"Nouvelle partie",BWHITE);
    win.print(3,3,"Titre clignotant      ");
    win.print(3,5,"Quitter        ");
    win.print(3,7,"      ");
    break;
  }
}

void Menu::disappear(){
  b=false;
  win.clear();
  win.setCouleurBordure(BBLACK);
  title.fade(true);
}
