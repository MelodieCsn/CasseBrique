#include "tableau_brique.h"
#include <iostream>

TableauBrique::TableauBrique() : data(NULL), n(0), alloc() {}
TableauBrique::TableauBrique(const TableauBrique& T) : data(new Brique[T.n]), n(T.n), alloc(n) {
  for(int i=0;i<n;i++)
    data[i]=T.data[i];
}

TableauBrique::~TableauBrique(){ delete[] data; }

TableauBrique& TableauBrique::operator=(const TableauBrique& T){
  if(this!=&T){
    delete[] data;
    data=new Brique[T.n];
    n=T.n;
    alloc=T.n;
    for(int i=0;i<n;i++)
      data[i]=T.data[i];
  }
  return *this;
}

Brique& TableauBrique::at(int i){ return data[i]; }
const Brique& TableauBrique::at(int i) const { return data[i]; }

int TableauBrique::getN() const { return n; }

int TableauBrique::find(const Brique& br) const {
  for(int i=0;i<n;i++)
    if(identique(br,data[i]))
      return i;
  return -1;
}

void TableauBrique::push_back(const Brique& br){
  if(n==alloc){
    alloc=2*n+1;
    Brique* tmp=new Brique[alloc];
    for(int i=0;i<n;i++)
      tmp[i]=data[i];
    delete[] data;
    data=tmp;
  }
  data[n]=br;
  n++;
}

bool TableauBrique::estVide(){
  if(n==0)
    return true;
  return false;
}

void TableauBrique::erase(int id){

  for(int i=id;i<n;i++)
    data[i]=data[i+1];
  n--;
  
}

void TableauBrique::abimer(int id){

  if(data[id].getPv()==1)
    erase(id);
  else
    data[id].setPv(data[id].getPv()-1);

}
