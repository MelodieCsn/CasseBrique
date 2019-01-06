#include "fenetre_de_jeu.h"
#include <unistd.h>

FenetreDeJeu::FenetreDeJeu() : titre(plateau,"titre"), infos(plateau,"infos"), help(plateau,"help"), levelup(plateau,"levelup"), gameover(plateau,"gameover"){
}

void FenetreDeJeu::chargerNiveau(Niveau n){

  plateau.chargerNiveau(n);
  infos.write(9,0,itoa(plateau.getLvl()));
  plateau.print();
  titre.afficher(true);
  infos.afficher(true);

}

Terrain& FenetreDeJeu::getPlateau(){ return plateau; }
Message& FenetreDeJeu::getTitre(){ return titre; }
Message& FenetreDeJeu::getInfos(){ return infos; }
Message& FenetreDeJeu::getHelp(){ return help; }
Message& FenetreDeJeu::getLevelup(){ return levelup; }
Message& FenetreDeJeu::getGameover(){ return gameover; }

void FenetreDeJeu::start(){
  plateau.setStart(true);
}

void FenetreDeJeu::aide(){
  help.afficher(true);
  int ch;
  while((ch = getch()) != 'h'){}
  help.afficher(false);
}

void FenetreDeJeu::moveG5(){
  if(plateau.getRaq().getX()>4){
    if(!plateau.getStart())
      plateau.slideBall(-5);
    plateau.slideRaq(-5);
  }
}

void FenetreDeJeu::moveG1(){
  if(plateau.getRaq().getX()>0){
    if(!plateau.getStart())
      plateau.slideBall(-1);
    plateau.slideRaq(-1);
  }
}

void FenetreDeJeu::moveD1(){
  if(plateau.getRaq().getX()+plateau.getRaq().getLength()<plateau.getWin().getWidth()){
    if(!plateau.getStart())
      plateau.slideBall(1);
    plateau.slideRaq(1);
  }
}

void FenetreDeJeu::moveD5(){
  if(plateau.getRaq().getX()+plateau.getRaq().getLength()+4<plateau.getWin().getWidth()){
    if(!plateau.getStart())
      plateau.slideBall(5);
    plateau.slideRaq(5);
  }
}

void FenetreDeJeu::update(){
  usleep(50000);
  plateau.update();
  plateau.print();
  infos.write(8,1,itoa(plateau.getScore().getVal()));
  infos.write(11,2,itoa(plateau.getBall().getNb()));
}

void FenetreDeJeu::nouveauNiveau(Niveau n){
  levelup.clignoter(WRED);
  levelup.afficher(false);
  chargerNiveau(n);
  plateau.getBall().setNb(plateau.getBall().getNb()+1);
  infos.write(11,2,itoa(plateau.getBall().getNb()));
  plateau.reset();
  plateau.print();
}
