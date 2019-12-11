#ifndef BIGBLOCK_H
#define BIGBLOCK_H

#include <vector>
#include "block.h"
#include "arr2d.h"
using namespace std;

class big_block
{
protected:
    int min_x, min_y, max_x, max_y;
    vector<block *> v;

public:
    virtual ~big_block(); // 상속 관계에서 소멸자는 virtual 키워드 필수
    virtual void rotate() = 0;
    virtual bool can_rotate() = 0;
    virtual int type() = 0;
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
