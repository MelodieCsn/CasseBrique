#include <iostream>
#include <string>
#include "score.h"

score::score(): val(0) {}
score::score(int n): val(n) {}

int score::getVal() const {return val;}
void score::setVal(int n) {val=n;}