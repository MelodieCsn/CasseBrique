#include "menu.h"
#include <string>

Menu::Menu() : win(9,26,termSize(true)/2-13,termSize(false)/2-4,' '), title(win.getX()-9,win.getY()-7), x(1), y(1), place('m'), b(true){
  win.setCouleurBordure(BBLACK);
  title.fade(false);
  win.setCouleurBordure(WWHITE);
  win.print(x,y,'x',WCYAN);
  win.print(3,1,"Nouvelle partie",BWHITE);
  win.print(3,3,"Tableau des Scores");
  win.print(3,5,"Titre clignotant");
  win.print(3,7,"Quitter");
}

Classement& Menu::getCls(){ return cls; }

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
      win.print(3,3,"Tableau des Scores",BWHITE);
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
      win.print(3,3,"Tableau des Scores");
      win.print(3,5,"Titre clignotant",BWHITE);
    }
    else{
      win.print(3,3,"Niveau 3 puis Niveau 1");
      win.print(3,5,"Niveau \"Erreur\"",BWHITE);
    }
    break;
    
    case 5:
      win.print(x,y,' ');
    y+=2;
    win.print(x,y,'x',WCYAN);
    if(place=='m'){
      win.print(3,5,"Titre clignotant");
      win.print(3,7,"Quitter ... ?",BWHITE);
    }
    else{
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
      win.print(3,3,"Tableau des Scores");
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
      win.print(3,3,"Tableau des Scores",BWHITE);
      win.print(3,5,"Titre clignotant");  
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
      if(place=='m'){
      win.print(3,5,"Titre clignotant",BWHITE);
      win.print(3,7,"Quitter      ");
    }
    else{
      win.print(3,5,"Niveau \"Erreur\"",BWHITE);
      win.print(3,7,"Retour");
    }
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
      win.print(3,5,"Niveau \"Erreur\" ");
      win.print(3,7,"Retour ");
    }
    else
      disappear();
    break;
    
  case 3:
    if(place=='m'){
      cls.print(true);
      int ch;
      while((ch=getch())!='q'){}
      cls.print(false);
      win.setCouleurBordure(WWHITE);
      win.print(x,y,'x',WCYAN);
      win.print(3,1,"Nouvelle partie");
      win.print(3,3,"Tableau des Scores",BWHITE);
      win.print(3,5,"Titre clignotant");
      win.print(3,7,"Quitter");
    }
    else
      disappear();
    break;
    
  case 5:
    if(place=='m')
      title.clignoter();
    else
      disappear();
    break;
    
  case 7:
    if(place=='m')
      disappear();
    else{
      place='m';
      win.print(x,y,' ');
      x=1;
      y=1;
      win.print(x,y,'x',WCYAN);
      win.print(3,1,"Nouvelle partie",BWHITE);
      win.print(3,3,"Tableau des Scores    ");
      win.print(3,5,"Titre clignotant");
      win.print(3,7,"Quitter");
    }
    break;
  }
}

void Menu::disappear(){
  b=false;
  win.clear();
  win.setCouleurBordure(BBLACK);
  title.fade(true);
}
