
// i fixed sorted
// i fixed the case if input is 1, which should be zero and not 1.
// i fixed the case if input is -1.

// http://ruslanledesma.com/2016/06/17/why-does-heap-work.html
// https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
// all permutations using Heap's algorithm 

#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
{
	int num = 1;

	for (int i = 1; i <= n; i++)
		num *= i;
	return num;
}
// IMPORTANT:  why does this way of using pointers work ???
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void heapPermutation(int **t, int a[], int size, int n) 
{ 
    static int idx = 0;
	if (size == 1) 
	{ 
        for (int i = 0; i < n; i++)
        {
            t[idx][i] = a[i];
        }
        idx++;
		return; 
	} 
	for (int i = 0; i < size; i++) 
	{ 
		heapPermutation(t, a, size - 1, n); 

		// if size is odd, swap first and last element 
		if (size % 2 == 1) 
			swap(&a[0], &a[size - 1]); 

		// If size is even, swap ith and last element 
		else
			swap(&a[i], &a[size - 1]); 
	} 
} 

int ft_strcmp(char *a, char *b)
{
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return (a[i] - b[i]);
}

int intcmp(int *a, int *b, int n)
{
    int k = 0;

    while (a[k] == b[k] && k < n)
    {
        k++;
    }
    return (a[k] - b[k]);
}

void sort(int **t, int f, int n)
{
    for (int i = 0; i < f - 1; i++)
    {
        for (int j = i + 1; j < f; j++)
        {
            if (intcmp(t[i], t[j], n) > 0)
            {
                int *tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

int    **range_comb(int n)
{
    int **t;
    int f;
    int *a;

    if (n <= 0) // NOTE!!!
	    return NULL;

    f = factorial(n);
	t = (int **)malloc(sizeof(int *) * (f + 1));
	t[f] = 0; // Remember to NULL terminate!!!
	for (int i = 0; i < f; i++)
	{
		t[i] = (int *)malloc(sizeof(int) * n);
	}
/*
    if (n == 1)
    {
        t[0][0] = 0; // note! need to be zero!!!
        return t;
    }
*/
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        a[i] = i;
    heapPermutation(t, a, n, n);
    sort(t, f, n);
    return t;
}
////////////////////////////////////////////
void pr(int **t, int n)
{
    for (int r = 0; t[r] != 0; r++)
    {
        for (int c = 0; c < n; c++)
        {
            printf("%d", t[r][c]);
        }
        printf("\n");
    }
}
int main() 
{ 
    int **t;

    int n = 8; // TEST !!!
	t = range_comb(n);
    if (t != NULL)
        pr(t, n);
	return 0; 
} 
/*
= Test 5 ===================================================
$> ./hyeffl81vgh72eejn7qwaksk 3
$> diff -U 3 user_output_test5 test5.output | cat -e
--- user_output_test5   2019-09-23 09:07:36.000000000 -0700$
+++ test5.output        2019-09-23 09:07:35.000000000 -0700$
@@ -1,6 +1,6 @@$
 0 1 2$
-1 0 2$
-2 0 1$
 0 2 1$
+1 0 2$
 1 2 0$
+2 0 1$
 2 1 0$

Diff KO :(
Grade: 0
*/

/*
Diff OK :D
= Test 3 ===================================================
$> ./mxasv8um0vrbrba1vvwe6w2u 1
$> diff -U 3 user_output_test3 test3.output | cat -e
--- user_output_test3   2019-09-22 20:00:16.000000000 -0700$
+++ test3.output        2019-09-22 20:00:16.000000000 -0700$
@@ -1 +1 @@$
-1$
+0$

Diff KO :(
Grade: 0
 */