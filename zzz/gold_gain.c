#include <stdio.h>

void pr(int mine[][4], int n)
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

// careful!!! check if == versus =
int gg(int m[][4], int n)
{
	int r;
	int c;
	int ru, ri, rd;

	pr(m, n);

	for (c = n - 1; c >= 0; c--)
	{
		for (r = 0; r < n; r++)
		{
			ri = (c == n - 1) ? 0 : m[r][c + 1];

			ru = ((c == n - 1) || (r == 0)) ? 0 : m[r - 1][c + 1];
			rd = ((c == n - 1) || (r == n - 1)) ? 0 : m[r + 1][c + 1];
			m[r][c] = m[r][c] + max(max(ru, rd), ri);

			printf("%d %d %d   %d %d %d %d\n", r, c, n, ru, ri, rd, m[r][c]);
		}
	}

	int res = m[0][0];
	for (r = 0; r < n; r++)
	{
		res = max(res, m[r][0]);
		printf("%d\n", res);
	}
	return res;
}

int		main(void)
{
	int mine[4][4] = {
		{ 1, 3, 1, 5 },
	  	{ 2, 2, 4, 1 },
 		{ 5, 0, 2, 3 },
		{ 0, 6, 1, 2 }
	};
	printf("%d\n", gg(mine, 4));
	return (0);
}