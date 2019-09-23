// http://ruslanledesma.com/2016/06/17/why-does-heap-work.html
// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
// C++ program to print all permutations using 
// Heap's algorithm 

#include <stdio.h>
void printArr(int a[],int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf(" %d ", a[i]); 
	printf("\n"); 
} 

// IMPORTANT:  why does this way of using pointers work ???
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

// Generating permutation using Heap Algorithm 
void heapPermutation(int a[], int size, int n) 
{ 
	// if size becomes 1 then prints the obtained permutation 
	if (size == 1) 
	{ 
		printArr(a, n); 
		return; 
	} 
	for (int i = 0; i < size; i++) 
	{ 
		heapPermutation(a, size - 1, n); 

		// if size is odd, swap first and last element 
		if (size % 2 == 1) 
			swap(&a[0], &a[size - 1]); 

		// If size is even, swap ith and last element 
		else
			swap(&a[i], &a[size - 1]); 
	} 
} 

int main() 
{ 
	int a[] = {1, 2, 3}; 
	int n = sizeof a / sizeof a[0]; 
	heapPermutation(a, n, n); 
	return 0; 
} 
