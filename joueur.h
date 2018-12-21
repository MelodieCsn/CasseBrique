#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <iostream>
#include <string>
using namespace std;

class joueur {

    private:
    string nom;

    public:
    joueur();
    joueur(string s);

    string getNom() const;
    void setNom(string s);
    void askNom();
};

#endif