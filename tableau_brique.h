#ifndef __TABLEAU_BRIQUE_H
#define __TABLEAU_BRIQUE_H

#include "brique.h"

class TableauBrique{

 private :
  
  Brique* data;
  int n;
  int alloc;

 public :

  TableauBrique();
  TableauBrique(const TableauBrique& T);
  ~TableauBrique();

  TableauBrique& operator=(const TableauBrique& T);

  Brique& at(int i);
  const Brique& at(int i) const;

  int getN() const;

  int find(const Brique& br) const;
  void push_back(const Brique& br);
  void erase(int id);

  bool estVide();
  void abimer(int id);

};

#endif
