#include "fold_block.h"
#include "arr2d.cpp"
using namespace std;

fold_block::fold_block(int c1, int c2, int c3)
{
    // block *blk1 = new block(c1);
    v.push_back(new block(c1));
    v.push_back(new block(c2));
    v.push_back(new block(c3));
}

void fold_block::rotate()
{
}
