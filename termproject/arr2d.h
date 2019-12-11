#ifndef MAP_H
#define MAP_H

#include <vector>
#include <set>
#include "block.h"
#include "color_block.h"
using namespace std;

#define MAP_WIDTH 5
#define MAP_HEIGHT 12
#define COUNT_OF_BRICK 2
#define BRICK_COUNT_OF_CLEAR 4
#define NUM_OF_DIRECTION_TO_CHECK 4

class arr2d
{
protected:
    static block *board[MAP_WIDTH][MAP_HEIGHT];
    static set<color_block *> explosion_s;
    static int score;

public:
    arr2d();

    static bool can_make(int type);
    static void delete_block(int x, int y);
    static void insert(vector<block *> v);
    static void insert(int x, int y, block *b);
    static block *get_block(int x, int y);
    static bool can_move(int x, int y);
    static void print();
    static void insert_explosion(color_block *group);
    static void remove_explosion(color_block *group);
    static bool can_explosion();
    static void explosion();
    static void swap_block(int x1, int y1, int x2, int y2);
    static int get_score();
};

#endif //MAP_H
