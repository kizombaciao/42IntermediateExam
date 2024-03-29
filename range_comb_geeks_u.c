// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// https://www.geeksforgeeks.org/c-program-to-print-all-permutations-of-a-given-string/

// https://www.youtube.com/watch?time_continue=2&v=AfxHGNRtFac
// https://www.youtube.com/watch?v=78t_yHuGg-0

/*
Time Complexity: O(n*n!) 
Note that there are n! permutations 
and it requires O(n) time to print a a permutation.
*/

// ALSO USING RECURSION
// C program to print all permutations with duplicates allowed 
#include <stdio.h> 
#include <string.h> 

/* Function to swap values at two pointers */
void swap(char *x, char *y) // we are passing by reference address
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 
/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char *a, int l, int r) 
{ 
    int i; 
    if (l == r) 
    	printf("%s\n", a); // note, b/c of recur 'a' keeps changing
    else
    { 
    	for (i = l; i <= r; i++) 
    	{ 
    		swap((a + l), (a + i)); 
    		permute(a, l + 1, r); 
    		swap((a + l), (a + i)); //backtrack 
    	} 
    } 
} 
int main() 
{ 
	char str[] = "012"; 
	int n = strlen(str); 
	permute(str, 0, n-1); 
	return 0; 
} 

