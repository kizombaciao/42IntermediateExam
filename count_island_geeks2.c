// https://www.geeksforgeeks.org/count-number-islands-every-island-separated-line/
// ignore this, doesn't use recursive backtracking!!!

/*  TO DO:
	> OPEN AND READ A FILE!!!
	> NUMBER THE ISLANDS
*/

// A C++ program to count the number of rectangular 
// islands where every island is separated by a line 
#include <stdio.h>
// Size of given matrix is M X N 
#define M 6 
#define N 3 

// This function takes a matrix of 'X' and 'O' 
// and returns the number of rectangular islands 
// of 'X' where no two islands are row-wise or 
// column-wise adjacent, the islands may be diagonaly 
// adjacent 
int countIslands(int mat[][N]) 
{ 
	int count = 0; // Initialize result 

	// Traverse the input matrix 
	for (int i = 0; i < M; i++) 
	{ 
		for (int j = 0; j < N; j++) 
		{ 
			// If current cell is 'X', then check 
			// whether this is top-leftmost of a 
			// rectangle. If yes, then increment count 
			if (mat[i][j] == 'X') 
			{ 
				if ((i == 0 || mat[i - 1][j] == 'O') && 
					(j == 0 || mat[i][j - 1] == 'O')) 
					count++; 
			} 
		} 
	} 

	return count; 
} 

int main() 
{ 
	int mat[M][N] = {{'O', 'O', 'O'}, 
					{'X', 'X', 'O'}, 
					{'X', 'X', 'O'}, 
					{'O', 'O', 'X'}, 
					{'O', 'O', 'X'}, 
					{'X', 'X', 'O'} 
					}; 
	printf("# of rect islands:  %d\n", countIslands(mat));
	return 0; 
}


