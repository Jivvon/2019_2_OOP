#include "color_block.h"
#include "block.h"
using namespace std;

color_block::color_block(block *b)
{
    this->s.insert(b);
}
void color_block::inset(set<block *> s)
{
    for (set<block *>::iterator it = s.begin(); it != s.end(); ++it)
    {
        this->s.insert(*it);
    }
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
    for (set<block *>::iterator it = s.begin(); it != s.end(); ++it)
    {
        delete (*it);
    }
}