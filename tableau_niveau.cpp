#include "tableau_niveau.h"
#include <iostream>



TableauNiveau::TableauNiveau() : data(NULL), n(0), alloc() {}
TableauNiveau::TableauNiveau(const TableauNiveau& T) : data(new Niveau[T.n]), n(T.n), alloc(n) {
    for(int i=0;i<n;i++)
    data[i]=T.data[i];
}

TableauNiveau::~TableauNiveau(){ delete[] data; }

Niveau& TableauNiveau::at(int i){ return data[i]; }
const Niveau& TableauNiveau::at(int i) const { return data[i]; }

int TableauNiveau::getN() const {return n;}

void TableauNiveau::erase(int id){

  for(int i=id;i<n;i++)
    data[i]=data[i+1];
  n--;
  
}