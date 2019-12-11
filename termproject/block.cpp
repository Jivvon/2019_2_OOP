#include "block.h"
#include "color_block.h"
#include "arr2d.h"
#include <iostream>
// #include "arr2d.cpp"

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
    this->color = 99;
    this->group = nullptr;
}
int block::get_color()
{
    return this->color;
}
int block::get_x()
{
    return this->x;
}
int block::get_y()
{
    return this->y;
}
void block::set_group(color_block *group)
{
    this->group = group;
    // std::cout << group << std::endl;
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
    // std::cout << "call can_left in block" << std::endl;
    if (x == 0 || arr2d::get_block(x - 1, y)->get_color() != 0)
    {
        return false;
    }
    return true;
}
bool block::can_right()
{
    if (x == MAP_WIDTH - 1 || arr2d::get_block(x + 1, y)->get_color() != 0)
    {
        return false;
    }
    return true;
}
bool block::can_down()
{
    if (y == MAP_HEIGHT - 1 || arr2d::get_block(x, y + 1)->get_color() != 0)
    {
        return false;
    }
    return true;
}
void block::left()
{
    // std::cout << "call left in block" << std::endl;
    // if (can_left()) // 왼쪽이 빈 블록일 때만
    // {
    // }
    arr2d::insert(x, y, new block(0)); // 내 자리에 빈 블록 넣고
    x--;                               // 나 왼쪽으로 이동시켜서
    arr2d::delete_block(x, y);         // 왼쪽으로 이동시킨 지금 자리에 있는 블록 없애고
    arr2d::insert(x, y, this);         // 나 들어간다
}
void block::right()
{
    // if (can_right()) // 오른쪽이 빈 블록일 때만
    // {
    // }
    arr2d::insert(x, y, new block(0)); // 내 자리에 빈 블록 넣고
    x++;                               // 나 오른쪽으로 이동시켜서
    arr2d::delete_block(x, y);         // 오른쪽으로 이동시킨 지금 자리에 있는 블록 없애고
    arr2d::insert(x, y, this);         // 나 들어간다
}
void block::down()
{
    // if (can_down()) // 아래쪽이 빈 블록일 때만
    // {
    // }
    arr2d::insert(x, y, new block(0)); // 내 자리에 빈 블록 넣고
    y++;                               // 나 밑으로 이동시켜서
    arr2d::delete_block(x, y);         // 밑으로 이동시킨 지금 자리에 있는 블록 없애고
    arr2d::insert(x, y, this);         // 나 들어간다
}
void block::down_all()
{
    // cout << "down_all at block" << endl;
    while (can_down())
    {
        down();
    }
}

bool block::can_explosion(block *b)
{
    /*
        나는 터질 수 있을 때 b가 나와 같이 터질 수 있는가 !?
        어차피 같은 색의 블록은 검사할거라
        b가 회색블록이면 같이 터지자
    */

    if (b->get_color() == GREY)
        return true;
    return false;
}

bool block::can_merge(block *b)
{
    /*
        b와 색이 같고 다른 color_block에 속해있다면 true
    */

    if (b->get_color() == this->color)
    {
        // set<block *>::iterator it_this = this->get_group()->get_set().begin();
        // block *b1 = *it_this;
        // cout << x << ", " << y << "\t" << b1 << endl;
        // set<block *>::iterator it_b = b->get_group()->get_set().begin();
        // block *b2 = *it_b;

        // if (b1 != b2) // color_block의 첫 번째 요소가 다르다면
        // {
        //     return true;
        // }

        if (this->get_group() != b->get_group())
            return true;
    }
    return false;
}
void block::merge(block *b)
{
    /*
        나와 b의 group이 같아지도록 ! (같은 공간을 바라보고 있도록) 
        1. b의 color_block에 나의 color_block을 inset한다
        2. arr2d의 explosion_s에서 나의 color_block을 없앤다
        3. 내 color_block을 메모리 해제한 후
        4. 내 color_block이 b의 color_block을 가리키도록 한다
    */
    // cout << "call merge" << endl;

    // this->get_group()->inset(b->get_group()->get_set());
    // if (b->get_group() != this->get_group())
    // {
    //     arr2d::remove_explosion(b->get_group());
    // }
    // else // 얘 실행 안 됨
    // {
    //     cout << b->get_group() << "   vs   " << this->get_group() << endl;
    // }
    // this->group = b->get_group(); // 내 컬러블록을 b 컬러블록과 같게.
    // b->set_group(this->group);
    // b->set_group(this->group);

    b->get_group()->inset(this->group->get_set());
    arr2d::remove_explosion(this->group);
    this->set_group(b->get_group()); // 내 컬러블록을 b 컬러블록과 같게.
    b->set_group(this->get_group());
}
void block::find_merge()
{
    // 회색일 경우 합쳐질 필요 없으므로 pass
    if (this->color == GREY)
        return;
    /*
        내 주변에 있는 나와 같은 색의 블록들을 찾자 ! -> caller에서 합친다
    */
    // cout << "call find merge at " << this << endl;
    // 왼쪽
    if (x != 0 && can_merge(arr2d::get_block(x - 1, y)))
        merge(arr2d::get_block(x - 1, y));
    // 오른쪽
    if (x != MAP_WIDTH - 1 && can_merge(arr2d::get_block(x + 1, y)))
        merge(arr2d::get_block(x + 1, y));
    // 아래
    if (y != MAP_HEIGHT - 1 && can_merge(arr2d::get_block(x, y + 1)))
        merge(arr2d::get_block(x, y + 1));
    // 위
    if (y != 0 && can_merge(arr2d::get_block(x, y - 1)))
        merge(arr2d::get_block(x, y - 1));

    // 블록이 겹칠경우, explosion_s에 해당 color_block이 없게된다
    // 중복된다면 어차피 안 들어감. set
    arr2d::insert_explosion(this->get_group());
}