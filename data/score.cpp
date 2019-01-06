#include "score.h"

Score::Score() : val(0) {}

int Score::getVal() const { return val; }
void Score::upVal(int s){ val+=s; }
