#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

typedef struct s_point
{
	int x;
	int y;
} t_point;

void flood_fill(char **tab, t_point size, t_point begin);
void ff(char **tab, t_point size, int y, int x, char c);

#endif


void ff(char **tab, t_point size, int y, int x, char c)
{
    if (y < 0 || x < 0 || y >= size.y || x >= size.x)
        return ;
    if (tab[y][x] != c)
        return ;

    tab[y][x] = 'F';
    ff(tab, size, y - 1, x, c);
    ff(tab, size, y + 1, x, c);
    ff(tab, size, y, x - 1, c);
    ff(tab, size, y, x + 1, c);

}

void ff(char **tab, t_point size, t_point begin)
{

    if (!tab)
        return;

    int y = begin.y--;
    int x = begin.x--;
    char c = tab[y][x]; 
    ff(tab, size, y, x, c);
}