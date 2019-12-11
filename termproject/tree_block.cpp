#include "tree_block.h"
// #include "arr2d.cpp"
using namespace std;

tree_block::tree_block(int c1, int c2, int c3)
{
    block *bl1 = new block(c1);
    block *bl2 = new block(c2);
    block *bl3 = new block(c3);

    bl1->set_location(2, 0);
    bl2->set_location(2, 1);
    bl3->set_location(2, 2);

    min_x = 2;
    min_y = 0;
    max_x = 2;
    max_y = 2;

    v.push_back(bl1);
    v.push_back(bl2);
    v.push_back(bl3);

    arr2d::insert(bl1->get_x(), bl1->get_y(), bl1);
    arr2d::insert(bl2->get_x(), bl2->get_y(), bl2);
    arr2d::insert(bl3->get_x(), bl3->get_y(), bl3);
}

void tree_block::rotate()
{
    // can_rotate는 rotate 호출할 때 해준다
    if (!can_rotate()) // 돌릴 수 없으면 끝
        return;

    /*
        1*3 or 3*1
                    1                   3
        1 2 3 ->    2   ->  3 2 1 ->    2
                    3                   1
    */

    if (min_x == max_x) // 세로로 3개일 경우 가로로 돌려준다
    {
        int y_avg = (max_y + min_y) / 2;
        arr2d::swap_block(min_x, min_y, max_x + 1, y_avg);
        arr2d::swap_block(max_x, max_y, min_x - 1, y_avg);
        min_x--;
        max_x++;
        min_y = max_y = y_avg;
    }
    else if (min_y == max_y) // 가로로 3개일 경우 세로로 돌려준다
    {
        int x_avg = (max_x + min_x) / 2;
        arr2d::swap_block(min_x, min_y, x_avg, min_y - 1);
        arr2d::swap_block(max_x, max_y, x_avg, max_y + 1);
        min_x = max_x = x_avg;
        min_y--;
        max_y++;
    }
}

bool tree_block::can_rotate()
{
    /*
        블록이 이동할 부분만 체크해준다
        돌아가면서 걸리는 부분은.....
        보통 테트리스에서는 체크 안 하는거 같아서 pass
    */
    // int x_avg = (max_x + min_x) / 2,
    //     y_avg = (max_y + min_y) / 2;

    if (min_x == max_x) // 세로로 3개일 경우
    {
        int y_avg = (max_y + min_y) / 2;
        if (arr2d::get_block(min_x - 1, y_avg)->get_color() != 0 ||
            arr2d::get_block(min_x + 1, y_avg)->get_color() != 0)
            return false;
    }
    else if (min_y == max_y) // 가로로 3개일 경우
    {
        int x_avg = (max_x + min_x) / 2;
        if (arr2d::get_block(x_avg, min_y - 1)->get_color() != 0 ||
            arr2d::get_block(x_avg, min_y + 1)->get_color() != 0)
            return false;
    }
    return true;
}

int tree_block::type()
{
    return TREE;
}