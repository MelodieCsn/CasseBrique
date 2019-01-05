#ifndef __CONFIG_H
#define __CONFIG_H
using namespace std;
#include "tableau_niveau.h"
#include <string>

class Config{
    private:
    
    public:
    TableauNiveau tabNiv;
    Config(); 
    //TableauNiveau& const getTableauNiveau();
    void loadConfig(string file);
    void nettoie(string &s);
    bool findCleVal(string &s, string &s1, string &s2);
    void TraiteOption(const string &cle, const string &valeur, size_t num_ligne);

};
#endif
