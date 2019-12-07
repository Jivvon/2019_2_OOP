#ifndef BIGBLOCK_H
#define BIGBLOCK_H

#include <vector>
#include "block.h"
using namespace std;

class big_block
{
protected:
    int min_x, min_y, max_x, max_y;
    static vector<block *> v;

public:
    ~big_block();
    virtual void rotate() = 0;
    bool can_left();
    bool can_right();
    bool can_down();
    void left();
    void right();
    bool down();
    bool down_all();
    bool move(int input);
};

#endif //BIGBLOCK_H
