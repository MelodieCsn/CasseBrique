#ifndef __SCORE_H__
#define __SCORE_H__


#include <iostream>

class score{
    private:
        int val;
    
    public:
        score();
        score(int n);

        int getVal() const;
        void setVal(int n);
};

#endif