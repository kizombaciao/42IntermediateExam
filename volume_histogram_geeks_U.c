// https://www.geeksforgeeks.org/trapping-rain-water/
// https://codepumpkin.com/trapping-rain-water-algorithm-problem/
// C++ program to find maximum amount of water 
// that can be trapped within given set of bars. 
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);	
}

int min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);	
}

int findWater(int arr[], int n) 
{ 
	// left[i] contains height of tallest bar to the left of i'th bar 
	// including itself 
	int left[n]; 
	// Right [i] contains height of tallest bar to the right of ith bar 
	// including itself 
	int right[n]; 
	// Initialize result 
	int water = 0; 

	// Fill left array 
	left[0] = arr[0]; 
	for (int i = 1; i < n; i++) 
	    left[i] = max(left[i - 1], arr[i]); 

	// Fill right array 
	right[n - 1] = arr[n - 1]; 
	for (int i = n - 2; i >= 0; i--) 
	    right[i] = max(right[i + 1], arr[i]); 

	// Calculate the accumulated water element by element 
	// consider the amount of water on i'th bar, the 
	// amount of water accumulated on this particular 
	// bar will be equal to min(left[i], right[i]) - arr[i] . 
	for (int i = 0; i < n; i++) 
	    water += min(left[i],right[i]) - arr[i]; 
		// need to deduct index height, arr[i]

	return water; 
} 
int main() 
{ 
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("Maximum water that can be accumulated is %d", findWater(arr, n)); 
	return 0; 
}
// Maximum water that can be accumulated is 6

