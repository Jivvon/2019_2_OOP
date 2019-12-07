#include "big_block.h"
#include "arr2d.h"
using namespace std;

big_block::~big_block()
{
    v.clear();
}
bool big_block::can_left()
{
    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        // int x = blk->get_x() - 1;
        int x = min_x;
        int y = blk->get_y();
        if (x < 0 || arr2d::get_block(x, y)->get_color() != 0)
        {
            return false;
        }
    }

    return true;
}
bool big_block::can_right()
{
    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        // int x = blk->get_x() + 1;
        int x = max_x;
        int y = blk->get_y();
        if (MAP_WIDTH - 1 < x || arr2d::get_block(x, y)->get_color() != 0)
        {
            return false;
        }
    }

    return true;
}
bool big_block::can_down()
{
    /*
        can_down은 작은 블록들 각각 생각해주어야 함.
        일단은 can_left/right와 똑같이 구현하고 
        마지막에 전부다 끌어내리는 걸로 하자.
    */

    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        int x = blk->get_x();
        int y = max_y;
        // int y = blk->get_y() + 1;
        if (MAP_HEIGHT - 1 < y || arr2d::get_block(x, y)->get_color() != 0)
        {
            return false;
        }
    }

    return true;
}
void big_block::left()
{
    return;
}
void big_block::right()
{
    return;
}
bool big_block::down()
{
    return false;
}
bool big_block::down_all()
{
    return false;
}
bool big_block::move(int input)
{
    return false;
}