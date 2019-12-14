#include "color_block.h"
#include "arr2d.h"
#include "block.h"
#include <iostream>
using namespace std;

color_block::color_block(block *b)
{
    this->s.insert(b);
}
void color_block::inset(set<block *> s)
{
    this->s.insert(s.begin(), s.end());
    /* 내 set에 s를 넣는거 */
}
set<block *> color_block::get_set()
{
    return this->s;
}
int color_block::get_set_size()
{
    return this->s.size();
}
void color_block::explosion()
{
    /* block들의 주위에 같이 터질 수 있는 회색 있는지 보고 있다면 터뜨리자 */

    block *thisbl;
    for (set<block *>::iterator it = s.begin(); it != s.end(); ++it)
    {
        thisbl = *it;
        int x = thisbl->get_x(),
            y = thisbl->get_y();

        // cout << x << ", " << y << " : " << thisbl->get_color() << "   :   " << thisbl << endl;
        // 왼쪽
        if (x != 0 && thisbl->can_explosion(arr2d::get_block(x - 1, y)))
        {
            delete arr2d::get_block(x - 1, y);
            arr2d::insert(x - 1, y, new block(0));
        }
        // 오른쪽
        if (x != MAP_WIDTH - 1 && thisbl->can_explosion(arr2d::get_block(x + 1, y)))
        {
            delete arr2d::get_block(x + 1, y);
            arr2d::insert(x + 1, y, new block(0));
        }
        // 아래쪽
        if (y != MAP_HEIGHT - 1 && thisbl->can_explosion(arr2d::get_block(x, y + 1)))
        {
            delete arr2d::get_block(x, y + 1);
            arr2d::insert(x, y + 1, new block(0));
        }
        // 위쪽
        if (y != 0 && thisbl->can_explosion(arr2d::get_block(x, y - 1)))
        {
            delete arr2d::get_block(x, y - 1);
            arr2d::insert(x, y - 1, new block(0));
        }
        delete (*it); // 작은 블록 delete
        arr2d::insert(x, y, new block(0));
    }
}