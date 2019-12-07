#ifndef BLOCK_H
#define BLOCK_H

// #include "color_block.h"

// key
#define LEFT_KEY 97      // a
#define RIGHT_KEY 100    // d
#define DOWN_KEY 115     // s
#define ALL_DOWN_KEY 120 // x
#define ROTATE_KEY 101   // e : 시계방향으로 돌리자

// block type == 만들어질 때의 가로 길이와 같다
#define FOLD 1
#define TREE 2
#define CROSS 3

// block color
#define GREY 1
#define RED 2
#define GREEN 3
#define BLUE 4

class color_block;

class block
{
private:
    int color;
    static int x, y;
    color_block *group;

public:
    explicit block(int color);
    explicit block(int color, int x, int y);
    ~block();
    int get_color();
    static int get_x();
    static int get_y();
    void set_group(color_block *group);
    color_block *get_group();
    void set_location(int x, int y);
    bool can_left();
    bool can_right();
    bool can_down();
    void left();
    void right();
    void down();
    void down_all();
    bool can_merge(block *b);
    bool can_explosion(block *b);
    void merge(block *b);
    void find_merge();
};

#endif //BLOCK_H
