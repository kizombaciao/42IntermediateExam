// Print the longest common substring
// https://www.geeksforgeeks.org/print-longest-common-substring/
// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

// https://www.techiedelight.com/longest-common-substring-problem/
// Has a useful diagram that clarifies the approach.

// https://www.youtube.com/watch?v=BysNXJHzCEs
// https://www.youtube.com/watch?v=zqKlL3ZpTqs


// C++ implementation to print the longest common substring 
//#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>

//using namespace std; 

/* function to find and print the longest common 
substring of X[0..m-1] and Y[0..n-1] */
void printLCSubStr(char* X, char* Y, int m, int n) 
{ 
	// Create a table to store lengths of longest common 
	// suffixes of substrings. Note that LCSuff[i][j] 
	// contains length of longest common suffix of X[0..i-1] 
	// and Y[0..j-1]. The first row and first column entries 
	// have no logical meaning, they are used only for 
	// simplicity of program 
	int LCSuff[m + 1][n + 1]; 

	// To store length of the longest common substring 
	int len = 0; 

	// To store the index of the cell which contains the 
	// maximum value. This cell's index helps in building 
	// up the longest common substring from right to left. 
	int row, col; 

	/* Following steps build LCSuff[m+1][n+1] in bottom 
	up fashion. */
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			if (i == 0 || j == 0) 
				LCSuff[i][j] = 0; // 1st row and col are zeros

			else if (X[i - 1] == Y[j - 1]) { 
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1; 
                // because you want the maximum within the matrix
				if (len < LCSuff[i][j]) { 
					len = LCSuff[i][j]; 
					row = i; 
					col = j; 
				} 
			} 
			else
				LCSuff[i][j] = 0; 
		} 
	} 

	// if true, then no common substring exists 
	if (len == 0) { 
		printf("No Common Substring\n"); 
		return; 
	} 

	// allocate space for the longest common substring 
	char* resultStr = (char*)malloc((len + 1) * sizeof(char)); 

	// traverse up diagonally form the (row, col) cell 
	// until LCSuff[row][col] != 0 
	while (LCSuff[row][col] != 0) { 
		resultStr[--len] = X[row - 1]; // or Y[col-1] 

		// move diagonally up to previous cell 
		row--; 
		col--; 
	} 

	// required longest common substring 
	printf("%s\n", resultStr); 
} 

/* Driver program to test above function */
int main() 
{ 
	char X[] = "OldSite:GeeksforGeeks.org"; 
	char Y[] = "NewSite:GeeksQuiz.com"; 

	int m = strlen(X); 
	int n = strlen(Y); 

	printLCSubStr(X, Y, m, n); 
	return 0; 
} 

/*
 Dynamic Programming can be used to find 
 the longest common substring in O(m*n) time. 
 The idea is to find length of the longest common suffix 
 for all substrings of both strings and store these lengths in a table.
 */


