#include "tree_block.h"
#include "arr2d.cpp"
using namespace std;

tree_block::tree_block(int c1, int c2, int c3)
{
    v.push_back(new block(c1));
    v.push_back(new block(c2));
    v.push_back(new block(c3));
}

void tree_block::rotate()
{
}
