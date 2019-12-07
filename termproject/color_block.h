#ifndef COLORBLOCK_H
#define COLORBLOCK_H

#include <set>
// #include "block.h"
using namespace std;

class block;

class color_block
{
private:
    set<block *> s;

public:
    explicit color_block(block *b);
    void inset(set<block *> s);
    set<block *> get_set();
    int get_set_size();
    void explosion();
};

#endif //COLORBLOCK_H
