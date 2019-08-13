#define max(a, b, c) (a > b && a > c ? a : b > c ? b : c)

int	gold_gain(int **mine, int n)
{
	int ret = 0;
	for (int col = 1, a = 0, b = 0, c = 0; col < n; col++){
		for (int row = 0; row < n; row++){
			a = b = c = 0;
			if (row > 0)
				a = mine[row - 1][col - 1];
			b = mine[row][col - 1];
			if (row + 1 < n )
				c = mine[row + 1][col - 1];
			mine[row][col] += max(a, b, c);
			if (col == n - 1 && ret < mine[row][col])
					ret = mine[row][col];
		}

	}
	return ret;
}

/*
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
*/

// https://github.com/sayakura/42__Exams--intermidiate/blob/master/3_gold_gain.c

