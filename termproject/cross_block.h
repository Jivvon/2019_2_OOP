#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include "big_block.h"
using namespace std;

class cross_block : public big_block
{
public:
    explicit cross_block(int c1, int c2, int c3, int c4, int c5);
    void rotate();
    bool can_rotate();
    int type();
};

#endif //CROSSBLOCK_H
