#include <stdlib.h>
#include <stdio.h>
#define MAX 4

void pr(int **mine, int n)
{
	printf("333a %d \n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("222a %d ", mine[i][j]);
		}
		printf("\n");
	}
	printf("\n");
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

	mine = (int **)malloc(sizeof(int *) * MAX);
	for (int r = 0; r < MAX; r++)
	{
		mine[r] = (int *)malloc(sizeof(int) * MAX);
		for (int c = 0; c < MAX; c++)
		{
			mine[r][c] = 1;
		}
	}
	pr(mine, MAX);
	//res = gg(mine, MAX);
	//printf(" %d", res);
}