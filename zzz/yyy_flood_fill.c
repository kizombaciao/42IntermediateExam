#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

///////////////////////////////////////////////

/*

#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

#endif

 */

void ff(char **tab, int y, int x, char c, t_point size)
{
    if (y < 0 || x < 0 || y >= size.y || x >= size.x || tab[y][x] != c)
    {
        return ;
    }
    tab[y][x] = 'F';
    ff(tab, y - 1, x, c, size);
    ff(tab, y + 1, x, c, size);
    ff(tab, y, x - 1, c, size);
    ff(tab, y, x + 1, c, size);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    if (!tab)
        return ;

    int y = begin.y - 1;
    int x = begin.x - 1;

    char c = tab[y][x];
    ff(tab, y, x, c, size);
}

///////////////////////////////////////////////


char** make_area(char** zone, t_point size)
{
        char** new;

        new = malloc(sizeof(char*) * size.y);
        for (int i = 0; i < size.y; ++i)
        {
                new[i] = malloc(size.x + 1);
                for (int j = 0; j < size.x; ++j)
                        new[i][j] = zone[i][j];
                new[i][size.x] = '\0';
        }

        return new;
}

int main(void)
{
        t_point size = {8, 5};
        char *zone[] = {
                "11111111",
                "10001001",
                "10010001",
                "10110001",
                "11100001",
        };

        char**  area = make_area(zone, size);
        
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        printf("\n");

        t_point begin = {8, 5};
        
        flood_fill(area, size, begin);

        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}