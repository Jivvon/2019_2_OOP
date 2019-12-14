#include <iostream>
#include "fold_block.h"
using namespace std;

fold_block::fold_block(int c1, int c2, int c3)
{
    block *bl1 = new block(c1);
    block *bl2 = new block(c2);
    block *bl3 = new block(c3);

    bl1->set_location(2, 0);
    bl2->set_location(2, 1);
    bl3->set_location(3, 1);

    min_x = 2;
    min_y = 0;
    max_x = 3;
    max_y = 1;

    v.push_back(bl1);
    v.push_back(bl2);
    v.push_back(bl3);

    arr2d::insert(bl1->get_x(), bl1->get_y(), bl1);
    arr2d::insert(bl2->get_x(), bl2->get_y(), bl2);
    arr2d::insert(bl3->get_x(), bl3->get_y(), bl3);
}

void fold_block::rotate()
{
    // can_rotate는 rotate 호출할 때 해준다
    if (!can_rotate()) // 돌릴 수 없으면 끝
        return;

    /*
        2*2이므로 모두 시계방향으로 돌려준다
        1 2
        3 4 일 때 순서대로 swap(1,2) swap(3,4) swap(1,4) 하면 결과는
            3 1
            4 2 로 시계방향으로 돌아간다
    */

    arr2d::swap_block(min_x, min_y, max_x, min_y); // swap(1,2)
    arr2d::swap_block(min_x, max_y, max_x, max_y); // swap(3,4)
    arr2d::swap_block(min_x, min_y, max_x, max_y); // swap(1,4)
}

bool fold_block::can_rotate()
{
    // 2*2 칸 중에 비어있는 칸은 한 칸
    // 비어있는 칸이 있으면 true
    for (int i = min_x; i <= max_x; i++)
    {
        for (int j = min_y; j <= max_y; j++)
        {
            if (arr2d::get_block(i, j)->get_color() == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int fold_block::type()
{
    return FOLD;
}
