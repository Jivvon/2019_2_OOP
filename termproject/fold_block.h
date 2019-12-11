#ifndef FOLDBLOCK_H
#define FOLDBLOCK_H

#include "big_block.h"
using namespace std;

class fold_block : public big_block
{
private:
    // int initwidth;
public:
    explicit fold_block(int c1, int c2, int c3);
    void rotate();
    bool can_rotate();
    int type();
    // int getinitw();
};

#endif //FOLDBLOCK_H
