#ifndef __NIVEAU_H
#define __NIVEAU_H
#include <string>
using namespace std;

class Niveau {
    private:
    unsigned int nbBriques;
    unsigned int nbLignes;
    unsigned int espaceBrique;

    public:
    // constructeurs/destructeur
    Niveau();
    Niveau(unsigned int nbB, unsigned int nbL, unsigned int EspB);
    

    //accesseurs en ecriture
    unsigned int getNbBriques() const;
    unsigned int getNbLignes() const;
    unsigned int getEspaceBrique() const;

    // accesseurs en lecture
    void setNbBriques(unsigned int nbB);
    void setNbLignes(unsigned int nbL);
    void setEspaceBrique(unsigned int espB);


};
#endif