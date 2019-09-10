#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

// note, -1 !!!
void ff(char **a, t_point size, int y, int x, char c)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x || a[y][x] != c)
	{
		return ;
	}
	if (a[y][x] == c)
	{
		a[y][x] = 'F';
		ff(a, size, y - 1, x, c);
		ff(a, size, y + 1, x, c);
		ff(a, size, y, x - 1, c);
		ff(a, size, y, x + 1, c);
	}
}

void flood_fill(char **a, t_point size, t_point begin)
{
	if (!a)
		return ;

	int y = begin.y--;
	int x = begin.x--;

	char c = a[y][x]; // ???

	ff(a, size, y, x, c);
}

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

        t_point begin = {2, 2};
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}
