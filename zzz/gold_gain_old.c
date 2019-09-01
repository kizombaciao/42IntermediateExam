#include <stdio.h>
#define MAX 4

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

void pr(int **mine, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf(" %d ", mine[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void *ft_memset(void *b, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)b;
	while (d < (unsigned char *)b + n)
		*(d++) = (unsigned char)c;
	return (b);
}

int gg(int **m, int n)
{
	int t[n][n];
	int ri, ru, rd;
	int res = 0;

	ft_memset(t, 0, sizeof(t));

/*
	for (int i; i < n; i++)
	{
		for (int j; j < n; j++)
		{
			t[i][j] = 0;
		}
	}
*/
	// i col, j row
	for (int c = n - 1; c >= 0; c--)
	{
		for (int r = 0; r <= n - 1; r++)
		{
			if (c == n - 1)
				ri = 0;
			else
				ri = t[r][c + 1];
			if (c == n - 1 || r == 0)
				ru = 0;
			else
				ru = t[r - 1][c + 1];
			if (c == n - 1 || r == n - 1)
				rd = 0;
			else
				rd = t[r + 1][c + 1];

			t[r][c] = m[r][c] + max(max(ru, ri), rd);
		}
	}

	res = t[0][0];
	for (int r = 1; r < n; r++)
	{
		res = max(res, t[r][0]);
	}
	//pr(t, n);

	return (res);
}

int main()
{
	int res;
	int m[MAX][MAX]= 	{ 	{1, 3, 1, 5}, 
							{2, 2, 4, 1}, 
							{5, 0, 2, 3}, 
							{0, 6, 1, 2} 
						};  
	int **mine;

	for (int r = 0; r < MAX; r++)
	{
		mine[r] = m[r];
	}
	pr(mine, MAX);
	res = gg(mine, MAX);
	printf("RES: %d\n", res);
}


// memset