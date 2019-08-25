// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	int i;
	int r = 1;

	for (i = 1; i <= n; i++)
	{
		r *= i;
	}
	return (r);
}
char *convert_string(n)
{
	int i;
	char *s;

	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';

	for (i = 0; i < n; i++)
	{
		s[i] = i + '0';
	}
	return (s);
}
void swap(char *x, char *y) // we are passing by reference address
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 
void permute(char *s, int **t, int n, int start, int end) 
{ 
	static int idx = 0;
    int i, j;

    if (start == end)
    {
    	for (j = 0; j < n; j++)
    	{
	    	t[idx][j] = s[j] - '0';
    	} 
    	idx++;
    } 
    else
    { 
    	for (i = start; i <= end; i++) 
    	{ 
    		swap((s + start), (s + i)); 
    		permute(s, t, n, start + 1, end); 
    		swap((s + start), (s + i)); //backtrack 
    	} 
    } 
} 

int **range_comb(int n)
{
	int i, j;
	char *s;
	int **t;
	int f;

	f = factorial(n);
	s = convert_string(n);

	t = (int **)malloc(sizeof(int *) * f);
	for (i = 0; i < f; i++)
	{
		t[i] = (int *)malloc(sizeof(int) * (n));
	}

	permute(s, t, n, 0, n - 1);
	return (t);
}

int main(void)
{
	int n;
	int **arr;
	int f;
	int i, j;

	n = 3;
	arr = range_comb(n);

	f = factorial(n);
	for (i = 0; i < f; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return (0);
}
