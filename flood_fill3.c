#include "flood_fill.h"

void    flood_fill(char **tab, t_point size, t_point begin)
{
    char replace;
    t_point    new;
    if (begin.x < size.x && begin.y < size.y)
        replace = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    //TOP
    if (begin.y)
    {
        new = begin;
        new.y = begin.y - 1;
        if (tab[new.y][new.x] == replace)
            flood_fill(tab, size, new);
    }
    //BOTTOM
    if (begin.y < (size.y - 1))
    {
        new = begin;
        new.y = begin.y + 1;
        if (tab[new.y][new.x] == replace)
            flood_fill(tab, size, new);
    }
    //LEFT
    if (begin.x)
    {
        new = begin;
        new.x = begin.x - 1;
        if (tab[new.y][new.x] == replace)
            flood_fill(tab, size, new);
    }
    //RIGHT
    if (begin.x < (size.x - 1))
    {
        new = begin;
        new.x = begin.x + 1;
        if (tab[new.y][new.x] == replace)
            flood_fill(tab, size, new);
    }
}
/*
Maybe I'm misunderstanding, but why ever use more than a single function? Here's what I did (can easily be reduced, but I wrote it verbosely for clarity):
 */