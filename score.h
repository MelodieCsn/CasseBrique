#ifndef __SCORE_H
#define __SCORE_H

class Score{
 private:

  int score;

 public:

  Score();

  int getScore() const;
  void upScore(int s);

};

#endif
