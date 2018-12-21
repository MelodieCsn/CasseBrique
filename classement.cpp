#include "classement.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void classement::saveScore(score s, joueur j){ 

    ifstream fichier("classement.txt"); 
    string TS[5]; string TJ[5];
  
    if(fichier){
        string ligne;
        int i=0;
        while(getline(fichier,ligne,';')){
            if(i<5) {TS[i]=ligne;}
            if(i>=5) {TJ[i-5]=ligne;}
            i++;
            //on met les informations du fichier dans deux tableaux : TS pour les scores et TJ pour les joueurs
        } 
    }     
    int k=0;
    if(s.getVal()>stoi(TS[0])){
        while(k<5 && s.getVal()>stoi(TS[k])){
            TS[k]=TS[k+1]; TJ[k]=TJ[k+1];
            k++;
            //on compare notre score avec ceux du classement et tant qu'il est supérieur on décale tout vers le bas
        }
        j.askNom();
        TJ[k-1]=j.getNom();
        TS[k-1]=to_string(s.getVal());

    }
    fichier.close();
    ofstream fichierout("classement.txt"); //en l'ouvrant avec ofstream on écrase son contenu, et on réécrit les nouvelles données dans le fichier
    for(int i=0;i<5;i++){
        fichierout<<TS[i]<<";";
    }
    for(int i=0;i<5;i++){
        fichierout<<TJ[i]<<";";
    }
    fichierout.close();
}

void classement::print(){
    ifstream fichier("classement.txt");
    if(fichier){
        string ligne;
        while(getline(fichier,ligne,';')) {cout<<ligne<<endl;}
    }
    fichier.close();
}

int main(){
    score s(56); joueur j; saveScore(s,j);
    print();
}