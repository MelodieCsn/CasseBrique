#ifndef SCORE_H
#define SCORE_H

class Score{
  
 private:

  int val;

 public:

  Score(); // Crée un score de 0

  int getVal() const; // Renvoie la valeur du score
  void upVal(int s);  // Augmente la valeur du score de s

};

#endif
