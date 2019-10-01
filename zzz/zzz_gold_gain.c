#include <stdio.h>
#include <stdlib.h>

void pr(int **mine, int n)
{
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			printf("%d ", mine[r][c]);
		}
		printf("\n");
	}
}
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	gold_gain(int mine[][4], int n)
{
    int ru;
    int ri;
    int rd;


    for (int c = n - 1; c >= 0; c--)
    {
        for (int r = 0; r < n; r++)
        {
            ri = (c == n - 1) ? 0 : mine[r][c + 1];
            ru = ((c == n - 1) || (r == 0))  ? 0 : mine[r - 1][c + 1];
            rd = ((c == n - 1) || (r == n - 1)) ? 0 : mine[r + 1][c + 1];
            mine[r][c] = mine[r][c] + max(max(ru, rd), ri);
            printf("222a %d %d %d\n", r, c, mine[r][c]);
        }
    }

    int res = mine[0][0];
    for (int r = 0; r < n; r++)
    {
        res = max(res, mine[r][0]);
    }
    return res;
}
// how mine is initialized ...
// but you have to change to int mine[][4] above !
int		main(void)
{
	int mine[4][4] = {
		{ 1, 3, 1, 5 },
	  	{ 2, 2, 4, 1 },
 		{ 5, 0, 2, 3 },
		{ 0, 6, 1, 2 }
	};
	printf("%d\n", gold_gain(mine, 4));
	return (0);
}