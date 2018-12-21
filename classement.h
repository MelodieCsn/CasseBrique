#ifndef __TABSCORE_H__
#define __TABSCORE_H__

#include "joueur.h"
#include"score.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class classement{
    private:
    score s;
    joueur j;

    public:
    void saveScore(score s,joueur j);
    void print();

};

#endif