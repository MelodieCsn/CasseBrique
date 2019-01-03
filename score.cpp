#include "score.h"

Score::Score() : score(0) {}

int Score::getScore() const { return score; }
void Score::upScore(int s){ score+=s; }
