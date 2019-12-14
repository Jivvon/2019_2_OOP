#include "cross_block.h"
using namespace std;

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5)
{
    block *bl1 = new block(c1);
    block *bl2 = new block(c2);
    block *bl3 = new block(c3);
    block *bl4 = new block(c4);
    block *bl5 = new block(c5);

    bl1->set_location(2, 0);
    bl2->set_location(2, 1);
    bl3->set_location(2, 2);
    bl4->set_location(1, 1);
    bl5->set_location(3, 1);

    min_x = 1;
    min_y = 0;
    max_x = 3;
    max_y = 2;

    v.push_back(bl1);
    v.push_back(bl2);
    v.push_back(bl3);
    v.push_back(bl4);
    v.push_back(bl5);

    arr2d::insert(bl1->get_x(), bl1->get_y(), bl1);
    arr2d::insert(bl2->get_x(), bl2->get_y(), bl2);
    arr2d::insert(bl3->get_x(), bl3->get_y(), bl3);
    arr2d::insert(bl4->get_x(), bl4->get_y(), bl4);
    arr2d::insert(bl5->get_x(), bl5->get_y(), bl5);
}

void cross_block::rotate()
{
    if (!can_rotate()) // 돌릴 수 없으면 끝
        return;

    /*
         1       4       3       2
        452 ->  351 ->  254 ->  153
         3       2       1       4      

         첫 번째 기준으로 swap(1,2) swap(1,3) swap(1,4) 하면 결과는 시계방향으로 돌아간다
    */
    int x_avg = (max_x + min_x) / 2;
    int y_avg = (max_y + min_y) / 2;
    arr2d::swap_block(x_avg, min_y, max_x, y_avg); // swap(1,2)
    arr2d::swap_block(x_avg, min_y, x_avg, max_y); // swap(1,3)
    arr2d::swap_block(x_avg, min_y, min_x, y_avg); // swap(1,4)
}

bool cross_block::can_rotate()
{
    return true;
}

int cross_block::type()
{
    return CROSS;
}