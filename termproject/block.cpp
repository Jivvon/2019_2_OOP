#include "block.h"
#include "color_block.h"
#include "arr2d.h"

using namespace std;

block::block(int color)
{
    this->color = color;
}
block::block(int color, int x, int y)
{
    this->color = color;
    this->x = x;
    this->y = y;
}
block::~block()
{
    this->color = 0;
    group = nullptr;
}
int block::get_color()
{
    return this->color;
}
int block::get_x()
{
    return x;
}
int block::get_y()
{
    return y;
}
void block::set_group(color_block *group)
{
    this->group = group;
}
color_block *block::get_group()
{
    return this->group;
}
void block::set_location(int x, int y)
{
    this->x = x;
    this->y = y;
}
bool block::can_left()
{
    if (x == 0 || arr2d::get_block(x - 1, y) != 0)
    {
        return false;
    }
    return true;
}
bool block::can_right()
{
    if (x == MAP_WIDTH - 1 || arr2d::get_block(x + 1, y) != 0)
    {
        return false;
    }
    return true;
}
bool block::can_down()
{
    if (y == MAP_HEIGHT || arr2d::get_block(x, y + 1) != 0)
    {
        return false;
    }
    return true;
}
void block::left()
{
    /*
        색깔만 바꿀 수 없다. setcolor가 없어.
        그니까 블록 자체를 바꿔야 함.
        1. 보드에서 옮길 곳의 블록을 delete하고
        2. 현재 블록의 좌표를 이동시킨다.
        3. 보드에서 insert.
        4. 이동한 자리는 delete하고
        5. 이동한 자리는 빈 블록으로 채우자.
    */

    // arr2d::delete_block(x - 1, y);
    // x--;
    // arr2d::insert(x, y, this);
    // // arr2d::delete_block(x + 1, y);
    // arr2d::insert(x + 1, y, new block(0, x + 1, y));
}
void block::right()
{
    arr2d::delete_block(x + 1, y);
    x++;
    arr2d::insert(x, y, this);
    arr2d::insert(x - 1, y, new block(0, x - 1, y));
}
void block::down()
{
    // arr2d::delete_block(x, y+1);
    // y++;
    // arr2d::insert(x, y, this);
    // arr2d::insert(x - 1, y, new block(0, x - 1, y));
}
void block::down_all()
{
    return;
}
bool block::can_merge(block *b)
{
    return false;
}
bool block::can_explosion(block *b)
{
    return false;
}
void block::merge(block *b)
{
    return;
}
void block::find_merge()
{
    return;
}