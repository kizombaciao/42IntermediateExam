// DID NOT PASS! investigate why it seg defaulted???
/*
= Test 2 ===================================================
$> ./tjqlcuowyiz5k0skirtwtkry test2
Command './tjqlcuowyiz5k0skirtwtkry test2' got killed by a Segmentation fault (Signal\
 -11)
Grade: 0

= Final grade: 0 ===============================================================
 */

//#include <stdlib.h> // del
//#include <stdio.h> // del
#include "flood_fill.h"

void ff(char **tab, t_point size, int y, int x, char c)
{
    // error! missing the case if tab[y][x] != c !!!
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
		return;

	if (tab[y][x] == c)
	{
		tab[y][x] = 'F';
		ff(tab, size, y - 1, x, c);
		ff(tab, size, y, x - 1, c);
		ff(tab, size, y + 1, x, c);
		ff(tab, size, y, x + 1, c);
	}
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	int y, x;
	char c;

	y = begin.y - 1;
	x = begin.x - 1;
	c = tab[y][x];
	ff(tab, size, y, x, c);
}



/*
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
*/
