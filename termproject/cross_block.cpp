#include "cross_block.h"
#include "block.h"
#include "arr2d.cpp"
using namespace std;

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5)
{
    v.push_back(new block(c1));
    v.push_back(new block(c2));
    v.push_back(new block(c3));
    v.push_back(new block(c4));
    v.push_back(new block(c5));
}

void cross_block::rotate()
{
}