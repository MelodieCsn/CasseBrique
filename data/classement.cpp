#include "classement.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

Classement::Classement() : win(14,20,termSize(true)/2-10,termSize(false)-17,' '){
  catchFile();
  win.print(1,1,"Tableau des Scores");
  win.print(1,2,"   Quitter : 'q'  ");
  rewrite();
  win.setCouleurBordure(BBLACK);
  win.setCouleurFenetre(BBLACK);
}

void Classement::catchFile(){
  ifstream filein("data/classement.txt");
  string line;
  int i=0;
  while(getline(filein,line,';')){
    T[i]=line;
    i++;
  }
  filein.close();
}

void Classement::save(Score s){
  if(s.getVal()>stoi(T[0])){
    int k=1;
    while(k<5 && s.getVal()>stoi(T[k])){
      T[k-1]=T[k]; T[k+4]=T[k+5];
      k++;
    }
    T[k+4]="___";
    T[k-1]=to_string(s.getVal());
    rewrite();
    
    win.print(1,1," Entrez votre nom ");
    win.print(1,2," ( en 3 lettres ) ");
    print(true);
    int i=0;
    char str;
    stringstream ss;
    while(i<3){
      str=' ';
      while(!alphabet(str))
	str = getch();
      ss << char(toupper(str));
      T[k+4]=ss.str();
      rewrite();
      i++;
      
    }
    win.print(1,1,"  Félicitations ! ");
    win.print(1,2,"   Quitter : 'q'  ");
    while((str=getch())!='q'){}
  }
  
  ofstream fileout("data/classement.txt");
  for(int i=0;i<9;i++){
    fileout<<T[i]<<";";
  }
  fileout<<T[9];
  fileout.close();
}

void Classement::print(bool b){
  if(b){
    win.setCouleurBordure(WWHITE);
    win.setCouleurFenetre(WBLACK);
  }
  else{
    win.setCouleurBordure(BBLACK);
    win.setCouleurFenetre(BBLACK);
  }
}

void Classement::rewrite(){
  int y=4;
  for(int i=4;i>=0;i--){
    win.print(6,y,T[i+5]);
    win.print(12,y,T[i]);
    y+=2;
  }
}

bool Classement::alphabet(char c){
  return ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' );
}
