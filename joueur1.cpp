#include "joueur.h"
#include <iostream>
#include <string>
using namespace std;

void NomJoueur(char );
bool nbDeVies(char);
bool GameOver(char );

int main(){
    int NomJoueur=Pierre;
    int nombreDeVie=3;

    char fenetre;

    for (int i(0); i <10; i++){
        for (int j(0); j<10; j++){
            fenetre[i][j]='..'
        }
    }
    do {
        system("cls"); //efface la fenetre
        nombreDeVie++;
        afficher(fentre);
        cout <<"Tour du joueur" <<NomJoueur <<":" <<endl;
        do{
            cout <<"Lancer la balle :";
            cin >> case;
        } while (!nombreDeVie(fenetre,nombreCase));
        NomJoueur= NomJoueur% 1;
    } while (!PartieGagne(fenetre)&& nombreDeVie !=0);
    system("cls");

    afficher(fenetre);

    NomJoueur = NomJoueur %1;
    if (PartieGagne(fenetre))
        cout <<"Le joueur" <<NomJoueur<<"a gagne la partie"<<endl<<endl;
    else
        cout<<"La partie est termine!"<<NomJoueur<<"Game Over"<<endl<<endl;

return 0;
}


