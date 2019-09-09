#include <stdio.h>
#include <stdlib.h>

//#define max(a, b) (a > b) ? a : b

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

int	gold_gain(int **mine, int n)
{
	int r, c;
	int ri, ru, rd;

	//pr(mine, n);

	for (c = n - 1; c >= 0; c--)
	{
		for (r = 0; r < n; r++)
		{

			ri = (c == n - 1) ? 0 : mine[r][c + 1];

			ru = ((c == n - 1) || (r == 0)) ? 0 : mine[r - 1][c + 1];

			rd = ((c == n - 1) || (r == n - 1)) ? 0 : mine[r + 1][c + 1];

			mine[r][c] = mine[r][c] + max(max(ru, rd), ri); 
//			printf("%d %d %d %d\n", mine[r][c], ri, ru, rd);

		}
	}

	int gain = mine[0][0];
	for (r = 0; r < n; r++)
	{
		gain = max(mine[r][0], gain);
	}
	return gain;
}

//////////////////////////////////////////

int main()
{
	int n = 3;
	int **mine;

	mine = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		mine[i] = (int *)malloc(sizeof(int) * n);
	}
	mine[0][0] = 1;
	mine[0][1] = 0;
	mine[0][2] = 0;
	
	mine[1][0] = 0;
	mine[1][1] = 3;
	mine[1][2] = 4;
	
	mine[2][0] = 0;
	mine[2][1] = 0;
	mine[2][2] = 0;
	pr(mine, n);
	printf("%d\n", gold_gain(mine, n));
}