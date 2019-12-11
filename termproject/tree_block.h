#ifndef TREEBLOCK_H
#define TREEBLOCK_H

#include "big_block.h"
using namespace std;

class tree_block : public big_block
{
public:
    explicit tree_block(int c1, int c2, int c3);
    void rotate();
    bool can_rotate();
    int type();
};

#endif //TREEBLOCK_H
