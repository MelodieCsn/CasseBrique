#ifndef __TABLEAU_NIVEAU_H
#define __TABLEAU_NIVEAU_H

#include "niveau.h"

class TableauNiveau{
    private:
    Niveau* data;
    int n;
    int alloc;

    public:
    TableauNiveau();
    TableauNiveau(const TableauNiveau& T);
    ~TableauNiveau();

    Niveau& at(int i);
    const Niveau& at(int i) const;

    int getN()const;
    void erase(int id);

};

#endif
