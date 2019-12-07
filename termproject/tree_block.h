#ifndef TREEBLOCK_H
#define TREEBLOCK_H

#include "big_block.h"
using namespace std;

class tree_block : big_block
{
public:
    explicit tree_block(int c1, int c2, int c3);
    void rotate();
};

#endif //TREEBLOCK_H
