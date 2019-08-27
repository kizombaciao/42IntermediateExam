#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
	int i;
	int res = 1;

	for (i = 1; i <= n; i++)
	{
		res *= i;
	}
	return (res);
}

char *cs(int n)
{
	int i;
	char *p;

	p = (char *)malloc(sizeof(char) * (n + 1));
	p[n] = '\0';

	for (i = 0; i < n; i++)
	{
		p[i] = i + '0';
	}
	return (p);
}

void swap(char *x, char *y)
{
	char tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void perm(char *s, int **t, int n, int start, int end)
{
	static int idx = 0; // remember!!!
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
			swap(&s[start], &s[i]);
			perm(s, t, n, start + 1, end);
			swap(&s[start], &s[i]);
		}
	}
}

int **rc(int n)
{
	int f;
	char *s;
	int **t;

	f = fact(n);
	s = cs(n);

	t = (int **)malloc(sizeof(int *) * f);
	for (int i = 0; i < f; i++)
	{
		t[i] = (int *)malloc(sizeof(int) * n);
	}

	perm(s, t, n, 0, n - 1);
	return (t);
}

int main()
{
	int n;
	int **arr;
	int f;
	int i, j;

	n = 3;
	arr = rc(n);
	f = fact(n);
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



