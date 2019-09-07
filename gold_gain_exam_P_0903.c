//#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int gold_gain(int **mine, int n)
{
	int ri, ru, rd;
	int res;

	if (!mine)
		return 0;

	for (int c = n - 1; c >= 0; c--)
	{
		for (int r = 0; r < n; r++)
		{
			if (c == n - 1 || r == 0)
				ru = 0;
			else
				ru = mine[r - 1][c + 1];

			if (c == n - 1 || r == n - 1)
				rd = 0;
			else
				rd = mine[r + 1][c + 1];

			if (c == n - 1)
				ri = 0;
			else
				ri = mine[r][c + 1];

			mine[r][c] = mine[r][c] + max(max(ru, rd), ri);
		}
	}

	res = mine[0][0];
	for (int r = 1; r < n; r++)
	{
		res = max(res, mine[r][0]);
	}
	return res;
}

/*
int main()
{
	int **m;
	int n;

	n = 4;
	m = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		m[i] = (int *)malloc(sizeof(int) * n);
	}

	m[0][0] = 1;
	m[0][1] = 3;
	m[0][2] = 1;
	m[0][3] = 5;

	m[1][0] = 2;
	m[1][1] = 2;
	m[1][2] = 4;
	m[1][3] = 1;

	m[2][0] = 5;
	m[2][1] = 0;
	m[2][2] = 2;
	m[2][3] = 3;

	m[3][0] = 0;
	m[3][1] = 6;
	m[3][2] = 1;
	m[3][3] = 2;

	printf("%d\n", gold_gain(m, n));
}
*/

