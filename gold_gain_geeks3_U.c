#include <stdio.h>
const int MAX = 100; 

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

// modify to use **mine !!!
int getMaxGold(int gold[][MAX], int m, int n) // is MAX necessary here ??? 
{ 
	for (int col = n - 1; col >= 0; col--) 
	{ 
		for (int row = 0; row < m; row++) 
		{ 
			int right = (col == n - 1) ? 0 : gold[row][col + 1]; 

			int right_up = (row == 0 || col == n - 1) ? 0 : 
							gold[row - 1][col + 1]; 

			int right_down = (row == m - 1 || col == n - 1) ? 0 : 
							gold[row + 1][col + 1]; 

			gold[row][col] = gold[row][col] + 
							max(right, max(right_up, right_down)); 													
		} 
	} 
	int res = gold[0][0]; 
	for (int i = 1; i < m; i++) 
		res = max(res, gold[i][0]); 
	return res; 
} 

int getMaxGold2(int gold[][MAX], int m, int n) // is MAX necessary here ??? 
{ 
	for (int col = 0; col <= n - 1; col++) 
	{ 
		for (int row = 0; row < m; row++) 
		{ 
			int left = (col == 0) ? 0 : gold[row][col - 1]; 

			int left_up = (row == 0 || col == 0) ? 0 : 
							gold[row - 1][col - 1]; 

			int left_down = (row == m - 1 || col == 0) ? 0 : 
							gold[row + 1][col - 1]; 

			gold[row][col] = gold[row][col] + 
							max(left, max(left_up, left_down)); 													
		} 
	} 
	int res = gold[0][n - 1]; 
	for (int i = 1; i < m; i++) 
		res = max(res, gold[i][n - 1]); 
	return res; 
}

int main() 
{ 
	int gold[MAX][MAX]= { {1, 3, 1, 5}, 
		{2, 2, 4, 1}, 
		{5, 0, 2, 3}, 
		{0, 6, 1, 2} 
	}; 
	int m = 4, n = 4; 
	printf("\n%d\n", getMaxGold2(gold, m, n)); 
	return 0; 
} 
