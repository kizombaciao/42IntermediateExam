#include <stdlib.h>
#include <stdio.h> // del

int factorial(int n)
{
	int num = 1;

	for (int i = 1; i <= n; i++)
		num *= i;
	return num;
}

char *convert_string(int n)
{
	int i;
	char *s;

	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';
	for (i = 0; i < n; i++)
	{
		s[i] = i + '0';
	}
	return s;
}

void swap(char *x, char *y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
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
			/*
			swap((s + start), (s + i)); 
    		permute(s, t, n, start + 1, end); 
    		swap((s + start), (s + i)); //backtrack 
			*/
			swap(&s[start], &s[i]);
			permute(s, t, n, start + 1, end);
			swap(&s[start], &s[i]);
		}
	}
}

// find factorial f
// convert to string s
// malloc t
// permute
int    **range_comb(int n)
{
	int f;
	char *s;
	int **t;

	if (n <= 0) // NOTE!!!
		return NULL;

	f = factorial(n);
	s = convert_string(n);

	t = (int **)malloc(sizeof(int *) * f);
	for (int i = 0; i < f; i++)
	{
		t[i] = (int *)malloc(sizeof(int) * n);
	}
	permute(s, t, n, 0, n - 1);
	return t;
}

int main(void)
{
	int n;
	int **arr;
	int f;
	int i, j;

	n = 1;
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
