#ifndef CROSSBLOCK_H
#define CROSSBLOCK_H

#include "big_block.h"
using namespace std;

class cross_block : big_block
{
public:
    explicit cross_block(int c1, int c2, int c3, int c4, int c5);
    void rotate();
};

#endif //CROSSBLOCK_H
