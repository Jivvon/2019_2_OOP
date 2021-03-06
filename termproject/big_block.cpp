#include "big_block.h"
#include "arr2d.h"
#include <iostream>

/*
    작은 블록들 중 큰 블록 내부의 이유로 이동이 불가능한 경우

              left    right   down
    fold        1       1       1
    tree        2       2       2
    cross       2       2       2
*/

big_block::~big_block()
{
    // std::cout << "call ~big in big_block" << std::endl;

    /*
        1. color_block 합쳐질 수 있는지 확인 : 블록이 붙어있어야 하고 && 색깔이 같아야 한다
    */
    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        blk->set_group(new color_block(*it));          // 일단 넣어야 find_merge 안의 can_merge 가능
        if (blk->get_color() != GREY)                  // 회색이 아닐 경우
            arr2d::insert_explosion(blk->get_group()); // explosion_s에 넣는다
    }

    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        blk->find_merge(); // 합칠 수 있으면 합친다.
        // cout << "size :   " << blk->get_group()->get_set_size() << endl;
    }

    v.clear();
}
bool big_block::can_left()
{
    int cnt;
    if (this->type() == FOLD)
        cnt = 1;
    else if (this->type() == TREE || this->type() == CROSS)
        cnt = 2;

    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        if (!blk->can_left()) // 불가능하면 count--
            cnt--;
    }

    if (cnt < 0)
        return false;
    else
        return true;
}
bool big_block::can_right()
{
    int cnt;
    if (this->type() == FOLD)
        cnt = 1;
    else if (this->type() == TREE || this->type() == CROSS)
        cnt = 2;

    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        if (!blk->can_right()) // 불가능하면 count--
            cnt--;
    }

    if (cnt < 0)
        return false;
    else
        return true;
}
bool big_block::can_down()
{
    int cnt;
    if (this->type() == FOLD)
        cnt = 1;
    else if (this->type() == TREE || this->type() == CROSS)
        cnt = 2;

    for (vector<block *>::iterator it = v.begin(); it != v.end(); it++)
    {
        block *blk = *it;
        if (!blk->can_down()) // 불가능하면 count--
            cnt--;
    }

    if (cnt < 0)
        return false;
    else
        return true;
}
void big_block::left()
{
    if (!can_left())
        return;
    int cnt = v.size();       // 현재 big_block에 포함된 작은 블록의 개수
    vector<int> tmp(cnt, -1); // 성공할 때마다 인덱스로 바꿀 예정 기본값은 -1
    while (cnt > 0)           // 모든 블록이 성공할 때까지
    {
        int idx = 0;
        for (vector<block *>::iterator it = v.begin(); it != v.end(); it++, idx++)
        {
            block *blk = *it;
            if (blk->can_left() && tmp[idx] == -1)
            {
                blk->left();
                tmp[idx] = idx;
                cnt--;
            }
        }
    }
    min_x--; // 작은 블록들 전부 왼쪽으로 1만큼 이동함
    max_x--;
}
void big_block::right()
{
    if (!can_right())
        return;
    int cnt = v.size();       // 현재 big_block에 포함된 작은 블록의 개수
    vector<int> tmp(cnt, -1); // 성공할 때마다 인덱스로 하나씩 추가할거야 기본값은 -1
    while (cnt > 0)           // 모든 블록이 성공할 때까지
    {
        int idx = 0;
        for (vector<block *>::iterator it = v.begin(); it != v.end(); it++, idx++)
        {
            block *blk = *it;
            if (blk->can_right() && tmp[idx] == -1)
            {
                blk->right();
                tmp[idx] = idx;
                cnt--;
            }
        }
    }
    min_x++;
    max_x++;
}
bool big_block::down()
{
    if (!can_down())
        return false;
    int cnt = v.size();       // 현재 big_block에 포함된 작은 블록의 개수
    vector<int> tmp(cnt, -1); // 성공할 때마다 인덱스로 하나씩 추가할거야 기본값은 -1
    while (cnt > 0)           // 모든 블록이 성공할 때까지
    {
        int idx = 0;
        for (vector<block *>::iterator it = v.begin(); it != v.end(); it++, idx++)
        {
            block *blk = *it;
            if (blk->can_down() && tmp[idx] == -1)
            {
                blk->down();
                tmp[idx] = idx;
                cnt--;
            }
        }
    }
    min_y++;
    max_y++;
    return true;
}
bool big_block::down_all()
{
    /*
        작은 블록 중 내려갈 수 있는 블록도 있고
        못 내려가는 블록도 있다
    */
    // cout << "down_all at big_block" << endl;
    int cnt = max_y - min_y + 1;
    while (cnt > 0)
    {
        int idx = 0;
        for (vector<block *>::iterator it = v.begin(); it != v.end(); it++, idx++)
        {
            block *blk = *it;
            if (blk->can_down())
            {
                blk->down_all();
            }
        }
        cnt--;
    }
    return true;
}
bool big_block::move(int input)
{
    switch (input)
    {
    case LEFT_KEY: // left
        if (can_left())
        {
            left();
            return true;
        }
        break;
    case RIGHT_KEY: // right
        if (can_right())
        {
            right();
            return true;
        }
        break;
    case DOWN_KEY: // down
        if (can_down())
        {
            down();
            return true;
        }
        break;
    case ALL_DOWN_KEY: // down_all
        return down_all();
        break;
    case ROTATE_KEY: // rotate
        if (can_rotate())
        {
            rotate();
            return true;
        }
        return false;
        break;

    default:
        return false;
    }

    return true;
}