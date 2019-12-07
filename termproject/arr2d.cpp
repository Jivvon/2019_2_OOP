#include "arr2d.h"
#include "block.h"
#include <iostream>
#include <ctime>

using namespace std;

arr2d::arr2d()
{
    this->score = 0;
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            this->board[i][j] = new block(0);
            this->board[i][j]->set_location(i, j);
        }
    }
}

bool arr2d::can_make(int type)
{
    if (board[3][0] != 0)
    {
        return true;
    }
    return false;
}

void arr2d::delete_block(int x, int y)
{
    // 호출한 곳에서 블록 정해주자
    // delete get_block(x, y);
    // board[x][y] = nullptr;

    // insert(x, y, new block(0));
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
    if (board[x][y] != nullptr && board[x][y]->get_color() != 0)
        delete_block(x, y);
    board[x][y] = b;
}

block *arr2d::get_block(int x, int y)
{
    return board[x][y];
}

bool arr2d::can_move(int x, int y)
{
    return false;
}
void arr2d::print()
{
    cout << get_score() << endl;
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            cout << get_block(i, j)->get_color() << "\t";
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
    explosion_s.erase(group);
}

bool arr2d::can_explosion()
{
    color_block *this_cb;
    for (set<color_block *>::iterator it = explosion_s.begin(); it != explosion_s.end(); ++it)
    {
        this_cb = *it;
        if (this_cb->get_set_size() >= 4)
        {
            return true;
        }
    }
    return false;
}

void arr2d::explosion()
{
    color_block *this_cb;
    for (set<color_block *>::iterator it = explosion_s.begin(); it != explosion_s.end(); ++it)
    {
        this_cb = *it;
        if (this_cb->get_set_size() >= 4)
        {
            //
        }
        remove_explosion(this_cb);
    }
}

int arr2d::get_score()
{
    return this->score;
}