#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_point
{
	int x; // cols
	int y; // rows
}	t_point;


char **make_area(char **zone, t_point size)
{
	char **p;
	int i, j;

	p = (char **)malloc(sizeof(char *) * size.y);
	for (i = 0; i < size.y; i++)
	{
		p[i] = (char *)malloc(sizeof(char) * size.x);
	}

	for (i = 0; i < size.y; i++)
	{
		for (j = 0; j < size.x; j++)
		{
			p[i][j] = zone[i][j];
		}
	}
	return (p);
}

void print_table(char **area, t_point size)
{
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			printf("%c ", area[i][j]);
		}
		printf("\n");
	}

}

void ff(char **area, t_point size, int y, int x)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
		return;

	if (area[y][x] == '0')
	{
		area[y][x] = 'F';
		ff(area, size, y - 1, x);
		ff(area, size, y, x - 1);
		ff(area, size, y + 1, x);
		ff(area, size, y, x + 1);
	}
}

void flood_fill(char **area, t_point size, t_point begin)
{
	t_point cur;

	if (area == NULL)
		return;

	cur.y = begin.y--;
	cur.x = begin.x--;

	ff(area, size, cur.y, cur.x);	
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
	};

	area = make_area(zone, size);
	print_table(area, size);
	flood_fill(area, size, begin);
	write(1, "\n", 1);
	print_table(area, size);
	return (0);
}