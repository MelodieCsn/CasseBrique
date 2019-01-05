
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
#include "config.h"
#include "tableau_niveau.h"

Config::Config() : TableauNiveau(NULL,0) {}
//Config::Config( unsigned int nbB, unsigned int nbL, unsigned int espB) : pvBriques(nbB), nbLignes(nbL), espaceBrique(espB) {}

//TableauNiveau& Config::getTableauNiveau() const {return TabNiv;}

void Config::nettoie(std::string &s){
  size_t pos=s.find_first_of("#");
  s=s.substr(0,pos);  
  int beg=0,end=s.size()-1;
  while(beg<end+1 && (s[beg]==' ' || s[beg]=='\t' )) beg++;
  while(end>beg-1 && (s[end]==' ' || s[end]=='\t' )) end--;
  s=s.substr(beg,end-beg+1);
}

bool Config::findCleVal(std::string &s, std::string &s1,std::string &s2){
  nettoie(s);
  if (s==string("")) return false;
  size_t pos=s.find_first_of(":");
  if (pos==string::npos) {
    cerr << "Le fichier est mal formé" << endl;
    terminate();
  }
  s1=s.substr(0,pos);
  s2=s.substr(pos+1);
  nettoie(s1);
  nettoie(s2);
  //cout<<"Found cle/val -> "<< s1<< " and "<<s2<<endl;
  return true;
}
void Config::TraiteOption(const string &cle, const string &valeur, size_t num_ligne){
  if(cle == "niveau" && valeur == "1"){
    if (cle == "pvBriques1") {
    tabNiv.at(0).getPvBriques() = (atoi(valeur.c_str()));
  }
  if (cle == "nbLignes1") {
    tabNiv.at(0).getNbLignes() = (atoi(valeur.c_str()));    
  }
  if (cle == "espaceBriques1") {
    tabNiv.at(0).getEspaceBriques() = (atoi(valeur.c_str()));    
  }
}
  if(cle == "niveau" && valeur == "2"){
    if (cle == "pvBriques2") {
    tabNiv.at(1).getPvBriques() = (atoi(valeur.c_str()));
  }
  if (cle == "nbLignes2") {
    tabNiv.at(1).getNbLignes() = (atoi(valeur.c_str()));    
  }
  if (cle == "espaceBriques2") {
    tabNiv.at(1).getEspaceBriques() = (atoi(valeur.c_str()));    
  }
  }
}
void Config::loadConfig(std::string file){
  ifstream input(file.c_str());
  string cle, valeur;
  size_t num_ligne=0;

  if (!input.is_open()) {
    cerr << "Le fichier " << file << " n'a pas pu être ouvert." << endl;
    terminate();
  }

  string line;
  while (!input.eof()) {
    getline(input,line);
    //cout<<"reading line ("<<num_ligne<<") -> "<<line<<endl;
    if (!input.eof()) {
      if (findCleVal(line,cle,valeur)){
	    TraiteOption(cle,valeur,num_ligne);
     }
    num_ligne++;
  }
}
input.close();
}


