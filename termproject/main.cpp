#include <iostream>
#include <cstdio>
#include <ctime>
#include "arr2d.h"
#include "big_block.h"
#include "fold_block.h"
#include "cross_block.h"
#include "tree_block.h"

int main()
{
    arr2d *game = new arr2d();
    char ch;
    while (true) // 블록 생성
    {
        srand((unsigned int)time(0));
        int block_type = rand() % 3 + 1;

        if (!game->can_make(block_type)) // 생성 불가면 출력하고 종료
        {
            cout << "score : " << game->get_score() << endl;
            std::cout << "GAME OVER" << std::endl;
            break;
        }

        big_block *input_block;
        int c[5];

        for (int i = 0; i < 5; i++)
        {
            c[i] = rand() % 4 + 1;
        }
        if (block_type == FOLD)
            input_block = dynamic_cast<big_block *>(new fold_block(c[1], c[2], c[3]));
        else if (block_type == TREE)
            input_block = dynamic_cast<big_block *>(new tree_block(c[1], c[2], c[3]));
        else if (block_type == CROSS)
            input_block = dynamic_cast<big_block *>(new cross_block(c[1], c[2], c[3], c[4], c[0]));

        // 유저 입력
        while (input_block->can_down())
        {
            std::system("clear");
            game->print();
            ch = getchar();
            input_block->move(ch);
        }
        input_block->down_all(); // 정리하고
        delete input_block;
        // game->print();

        // 블록 결합 및 검사
        game->explosion(); // 여기서 while 돌면서 계속 처리해줘야 콤보 가능

        std::system("clear");
        game->print();
    }
}