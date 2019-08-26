// NOT PASSED !!!

#include <stdio.h> // del
#include <stdlib.h>

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int gold_gain(int **mine, int n)
{
	int t[n][n];
	int r, c, ri, ru, rd;
	int res;

	for (r = 0; r < n; r++)
	{
		for (c = 0; c < n; c++)
		{
			t[r][c] = 0;
		}
	}

	for (c = n - 1; c >= 0; c--)
	{
		for (r = 0; r <= n - 1; r++) // note! equality
		{
			if (c == n - 1)
				ri = 0;
			else
				ri = t[r][c + 1];

			if (r == 0 || c == n - 1)
				ru = 0;
			else
				ru = t[r - 1][c + 1];

			if (r == n - 1 || c == n - 1)
				rd = 0;
			else
				rd = t[r + 1][c + 1];

			t[r][c] = mine[r][c] + max(ri, max(ru, rd));
		}
	}
	res = t[0][0];
	for (r = 1; r <= n - 1; r++) // error, need equality!!!
	{
		res = max(res, t[r][0]);
	}
	return (res);
}

int main()
{
	int i;
	int n = 4;
	int res;
//	int mine[4][4] = { {1, 3, 1, 5},
//					   {2, 2, 4, 1},
//					   {5, 0, 2, 3},
//					   {0, 6, 1, 2} };

//	printf("%d", mine[2][2]);

	int **p;

	p = (int **)malloc(sizeof(int *) * 4);
	for (i = 0; i < 4; i++)
	{
		p[i] = (int *)malloc(sizeof(int) * 4);
	}
	p[0][0] = 1;
	p[0][1] = 3;
	p[0][2] = 1;
	p[0][3] = 5;

	p[1][0] = 2;
	p[1][1] = 2;
	p[1][2] = 4;
	p[1][3] = 1;

	p[2][0] = 5;
	p[2][1] = 0;
	p[2][2] = 2;
	p[2][3] = 3;

	p[3][0] = 0;
	p[3][1] = 6;
	p[3][2] = 1;
	p[3][3] = 2;

	res = gold_gain(p, n);
	printf("%d\n", res);
}
/*
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			p[i][j] = 1;
		}
	}
*/
