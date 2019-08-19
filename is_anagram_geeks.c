// https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/

// NOT FINISHED!!!
// NEED TO CODE UP MY OWN SORT FUNCTION !!!

/*
Method 1 (Use Sorting)
    Sort both strings = USING QSORT()
    Compare the sorted strings
*/
// C++ program to check whether two strings are anagrams 
// of each other 
//#include <bits/stdc++.h> 
//using namespace std; 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#define MAX 100   
void sortStrings(char arr[][MAX], int n) 
{ 
    char temp[MAX];   
    // Sorting strings using bubble sort 
    for (int j=0; j<n-1; j++) 
    { 
        for (int i=j+1; i<n; i++) 
        { 
            if (strcmp(arr[j], arr[i]) > 0) 
            { 
                strcpy(temp, arr[j]); 
                strcpy(arr[j], arr[i]); 
                strcpy(arr[i], temp); 
            } 
        } 
    } 
} 
*/

/* function to check whether two strings are anagram of 
each other */
int areAnagram(char *str1, char *str2) 
{ 
	// Get lengths of both strings 
	int n1 = strlen(str1); 
	int n2 = strlen(str2); 

	// If length of both strings is not same, then they 
	// cannot be anagram 
	if (n1 != n2) 
		return 0; 

    // ???
	// Sort both the strings 
	//sort(str1.begin(), str1.end()); 
	//sort(str2.begin(), str2.end()); 

    sortStrings(str1, n1, sizeof(char), cmpfunc);
    sortStrings(str2, n2, sizeof(char), cmpfunc);

	// Compare sorted strings 
	for (int i = 0; i < n1; i++) 
		if (str1[i] != str2[i]) 
			return 0; 

	return 1; 
} 
int main() 
{ 
	char str1[] = "test"; 
	char str2[] = "ttes"; 
	if (areAnagram(str1, str2)) 
		printf("The two strings are anagram of each other"); 
	else
		printf("The two strings are not anagram of each other"); 
	return 0; 
} 

// Sort Strings using Bubble Sort
// https://www.geeksforgeeks.org/sorting-strings-using-bubble-sort-2/

// C Program to Sort an array of names or strings
// https://www.geeksforgeeks.org/c-program-sort-array-names-strings/

// https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
// https://www.geeksforgeeks.org/c-qsort-vs-c-sort/
