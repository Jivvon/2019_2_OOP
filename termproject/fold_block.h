#ifndef FOLDBLOCK_H
#define FOLDBLOCK_H

#include "big_block.h"
using namespace std;

class fold_block : big_block
{
private:
    // int initwidth;
public:
    explicit fold_block(int c1, int c2, int c3);
    void rotate();
    // int getinitw();
};

#endif //FOLDBLOCK_H
