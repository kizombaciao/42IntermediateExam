// https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
/*
To find intersection of 2 sorted arrays, follow the below approach :

1) Use two index variables i and j, initial values i = 0, j = 0
2) If arr1[i] is smaller than arr2[j] then increment i.
3) If arr1[i] is greater than arr2[j] then increment j.
4) If both are same then print any of them and increment both i and j.
*/
// C program to find intersection of 
// two sorted arrays 
#include<stdio.h> 

/* Function prints Intersection of arr1[] and arr2[] 
m is the number of elements in arr1[] 
n is the number of elements in arr2[] */
int printIntersection(int arr1[], int arr2[], int m, int n) 
{ 
    int i = 0, j = 0; 
    while (i < m && j < n) 
    { 
    	if (arr1[i] < arr2[j]) 
        	i++; 
    	else if (arr2[j] < arr1[i]) 
    	    j++; 
    	else /* if arr1[i] == arr2[j] */
    	{ 
    	    printf(" %d ", arr2[j++]); 
    	    i++; 
    	} 
    } 
} 

/* Driver program to test above function */
int main() 
{ 
    int arr1[] = {1, 2, 4, 5, 6}; 
    int arr2[] = {2, 3, 5, 7}; 
    int m = sizeof(arr1)/sizeof(arr1[0]); 
    int n = sizeof(arr2)/sizeof(arr2[0]); 
    printIntersection(arr1, arr2, m, n); 
    getchar(); // ???
    return 0; 
} 

