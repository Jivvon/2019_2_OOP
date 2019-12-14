#include "arr2d.h"
#include "block.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
#include <unistd.h>
#include <iostream>

using namespace std;

block *arr2d::board[MAP_WIDTH][MAP_HEIGHT] = {};
set<color_block *> arr2d::explosion_s;
int arr2d::score = 0;
arr2d::arr2d()
{
    score = 0;
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            board[i][j] = new block(0);
            board[i][j]->set_location(i, j);
        }
    }
}

bool arr2d::can_make(int type)
{
    if (type == FOLD)
    {
        if ((get_block(0, 0)->get_color() == 0) &&
            (get_block(2, 1)->get_color() == 0) &&
            (get_block(3, 1)->get_color() == 0))
            return true;
    }
    else if (type == TREE)
    {
        if ((get_block(2, 0)->get_color() == 0) &&
            (get_block(2, 1)->get_color() == 0) &&
            (get_block(2, 2)->get_color() == 0))
            return true;
    }
    else if (type == CROSS)
    {
        if ((get_block(2, 0)->get_color() == 0) &&
            (get_block(2, 1)->get_color() == 0) &&
            (get_block(2, 2)->get_color() == 0) &&
            (get_block(1, 1)->get_color() == 0) &&
            (get_block(3, 1)->get_color() == 0))
            return true;
    }

    char *type_str;
    if (type == FOLD)
        type_str = "FOLD";
    else if (type == TREE)
        type_str = "TREE";
    else if (type == CROSS)
        type_str = "CROSS";

    cout << "can't make " << type_str << " block" << endl;
    return false;
}

void arr2d::delete_block(int x, int y)
{
    // cout << "call delete_block" << endl;
    delete get_block(x, y);
    board[x][y] = nullptr;
}

void arr2d::insert(vector<block *> v)
{
    for (vector<block *>::iterator it = v.begin(); it != v.end(); ++it)
    {
        block *thisbl = *it;
        insert(thisbl->get_x(), thisbl->get_y(), thisbl);
    }
}

void arr2d::insert(int x, int y, block *b)
{
    board[x][y] = b;
}

block *arr2d::get_block(int x, int y)
{
    return board[x][y];
}

bool arr2d::can_move(int x, int y)
{
    if ((x == 0 || arr2d::get_block(x - 1, y)->get_color() != 0) &&             // left
        (x == MAP_WIDTH - 1 || arr2d::get_block(x + 1, y)->get_color() != 0) && // right
        (y == MAP_HEIGHT - 1 || arr2d::get_block(x, y + 1)->get_color() != 0)   // down
    )
        return false;
    return true;
}
void arr2d::print()
{
    cout << "201502119 정지원 뿌요뿌요" << endl;
    cout << "score : " << get_score() << endl;
    for (int j = 0; j < MAP_HEIGHT; j++)
    {
        for (int i = 0; i < MAP_WIDTH; i++)
        {
            cout << get_block(i, j)->get_color() << "  ";
        }
        cout << endl;
    }
}

void arr2d::insert_explosion(color_block *group)
{
    explosion_s.insert(group);
}

void arr2d::remove_explosion(color_block *group)
{
    if (explosion_s.find(group) != explosion_s.end())
    {
        // cout << "explosions_s에서 " << group << "찾았다!!" << endl;
        explosion_s.erase(group);
    }
}

bool arr2d::can_explosion()
{
    color_block *this_cb;
    // cout << "explosion_s size : " << explosion_s.size() << endl;
    for (set<color_block *>::iterator it = explosion_s.begin(); it != explosion_s.end(); ++it)
    {
        this_cb = *it;
        // cout << "this set size : " << this_cb->get_set_size() << endl;
        if (this_cb->get_set_size() >= 4)
            return true;
    }
    return false;
}

void arr2d::explosion()
{
    /*
        여기서 can_explosion 하면서 while 처리해줘야 콤보 가능
    */
    color_block *this_cb;
    int combo = 1;

    while (can_explosion()) // explosion_s에 4개 이상인 color_block이 있다면
    {
        // cout << "@@@@@@@@@ go explosion @@@@@@@@@" << endl;
        for (set<color_block *>::iterator it = explosion_s.begin(); it != explosion_s.end();)
        {
            this_cb = *it;
            if (this_cb->get_set_size() >= 4)
            {
                this_cb->explosion();
                ++it; // remove_explosion(this_cb)하고 iterator를 다음으로 이동시키려면 segmentation falut 발생.
                remove_explosion(this_cb);
            }
            else
                ++it;
        }
        // 밑에서부터 한 행씩 down_all해준다.
        block *blk;
        for (int j = MAP_HEIGHT - 1; j >= 0; j--)
        {
            // cout << j;

            for (int i = 0; i < MAP_WIDTH; i++)
            {
                // cout << "*";
                blk = get_block(i, j);
                // if (blk->get_color() != 0 && blk->get_color() != GREY && blk->can_down())
                if (blk->get_color() != 0 && blk->can_down())
                {
                    // cout << "/";
                    blk->down_all();
                    blk->find_merge();
                }
            }
            // cout << endl;
        }
        system("clear");
        print();
        cout << combo << " combo !! " << endl;
        usleep(1000000);
        score += combo++;
    }
}

void arr2d::swap_block(int x1, int y1, int x2, int y2)
{
    // block 안의 좌표도 바꿔줘야한다
    block *tmp1, *tmp2;
    tmp1 = get_block(x1, y1);
    tmp2 = get_block(x2, y2);
    insert(x1, y1, tmp2);
    insert(x2, y2, tmp1);
    tmp1->set_location(x2, y2);
    tmp2->set_location(x1, y1);
}

int arr2d::get_score()
{
    return score;
}