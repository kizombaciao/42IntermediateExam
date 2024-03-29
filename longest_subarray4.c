#include <stdlib.h>
#include <string.h>

int findIt(char* arr) {
	
	int i = 0, odds = 0, evens = 0, len = 0;

	for (; i < (int)strlen(arr); i++) {
		if (arr[i] % 2)
			odds++;
		else
			evens++;
		len++;
	}
	i--;
	while (odds != evens && i >= 0) {
		if (arr[i] % 2)
			odds--;
		else
			evens--;
		i--;
		len--;
	}
	return len;
}

char* longest_subarray(char* arr) {

	int maxIdx = 0, maxLen = 0;

	for (int i = 0; i < (int)strlen(arr); i++) {
		int len = findIt(arr + i);
		if (maxLen < len) {
			maxLen = len;
			maxIdx = i;
		}
		if (maxLen > (int)strlen(arr) / 2)
			break;
	}
	char* ret = malloc(maxLen + 1);
	for (int i = 0; i < maxLen; i++)
		ret[i] = arr[i + maxIdx];
	ret[maxLen] = 0;
	return ret;
}

/************
  Test Main
************/

#include <stdio.h>
int main(int ac, char* av[]) {
	if (ac == 2)
		printf("%s\n", longest_subarray(av[1]));
	return 0;
}

/*
LONGEST_SUBARRAY
Assignment name  : longest_subarray
Expected files   : longest_subarray.c
Allowed functions: malloc free strlen
--------------------------------------------------------------------------------
Given a null-terminated array of digit characters, implement a function which
finds the longest subarray with an equal number of even and odd digits.
The function returns a null-terminated array.
Your function must be declared as follows:
char    *longest_subarray(char *arr);
Example 1:
input  = 134
output = 34
In the above example, 1 and 3 is odd and 4 is even,
the longest subarray with an equal number of odd and even digits is 34.
Example 2:
input  = 454
output = 45
Example 3:
input  = 1357913579024680213579
output = 79135790246802
Example 4:
input  = 2010102
output = 0101
Note:
- As a reminder, 0, 2, 4, 6, 8 are even digits and 1, 3, 5, 7, 9 are odd.
- In case of more than one subarray with the same length,
  the expected output is the first one.
*/

// https://github.com/kraxx/42_C_Exam_Intermediate/blob/master/4/longest_subarray.c
