// actual queston is a square matrix n x n

https://github.com/evandjohnston/ft_alone_in_the_dark/tree/master/Tips/2019.02.25_limits.h

// https://www.geeksforgeeks.org/gold-mine-problem/
// C++ program to solve Gold Mine problem 
//#include<bits/stdc++.h> 
//using namespace std; 
#include <stdio.h>
const int MAX = 100; 

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

// https://www.geeksforgeeks.org/memset-c-example/
// memset function writes len bytes of value c (converted to an unsigned char) to the string b.
void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)b;
	while (d < (unsigned char *)b + n)
		*(d++) = (unsigned char)c;
	return (b);
}

// Returns maximum amount of gold that can be collected 
// when journey started from first column and moves 
// allowed are right, right-up and right-down 
int getMaxGold(int gold[][MAX], int m, int n) // is MAX necessary here ??? 
{ 
	// Create a table for storing intermediate results 
	// and initialize all cells to 0. The first row of 
	// goldMineTable gives the maximum gold that the miner 
	// can collect when starts that row 
	int goldTable[m][n]; 

	// CLEVER WAY TO INITIALIZE MATRIX TO ZERO !!!
	ft_memset(goldTable, 0, sizeof(goldTable)); // initialize goldTable to zero

	for (int col = n - 1; col >= 0; col--) 
	{ 
		for (int row = 0; row < m; row++) 
		{ 
			// Gold collected on going to the cell on the right(->) 
			// if last column, then no gold to the right
			int right = (col == n - 1) ? 0 : goldTable[row][col + 1]; 

			// Gold collected on going to the cell to right up (/) 
			// if first row, then no right_up
			// if last col, then no right_up
			int right_up = (row == 0 || col == n - 1) ? 0 : 
							goldTable[row - 1][col + 1]; 

			// Gold collected on going to the cell to right down (\) 
			// if last row, then no right_down
			// if last col, then no right_down
			int right_down = (row == m - 1 || col == n - 1) ? 0 : 
							goldTable[row + 1][col + 1]; 

			// Max gold collected from taking either of the 
			// above 3 paths 
			goldTable[row][col] = gold[row][col] + 
							max(right, max(right_up, right_down)); 													
		} 
	} 
	// The max amount of gold collected will be the max 
	// value in first column of all rows 
	int res = goldTable[0][0]; 
	for (int i = 1; i < m; i++) 
		res = max(res, goldTable[i][0]); 
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
	printf("\n%d\n", getMaxGold(gold, m, n)); 
	return 0; 
} 
/* 
memset() is used to fill a block of memory with a particular value.
// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting 
//         from ptr to be filled
void *memset(void *ptr, int x, size_t n);
*/
/*
#include <stdio.h>
#include <string.h>
int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7);
   puts(str);
   
   return(0);
}
Let us compile and run the above program that will produce the following result −
> This is string.h library function
> $$$$$$$ string.h library function
*/

/*
void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)b;
	while (d < (unsigned char *)b + n)
		*(d++) = (unsigned char)c;
	return (b);
}
*/
/*
** note, b+n is simply using pointer math, with contiguous addresses
** difference in address is the same as counter
**
** why replace while (n--) with below ???
** while (n--)
**
** https://www.geeksforgeeks.org/memset-c-example/
**
** memset function writes len bytes of value c
** (converted to an unsigned char) to the string b.
** This function returns it's first argument.
*/