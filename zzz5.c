// volume_histogram.c
#include <stdio.h>

//#define max(a, b) (a > b) ? a : b
//#define min(a, b) (a < b) ? a : b

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
int vh(int *h, int n)
{
	int l[n];
	int r[n];
	int w = 0;

	l[0] = h[0];
	for (int i = 1; i < n; i++)
		l[i] = max(l[i - 1], h[i]);

	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--)
		r[i] = max(r[i + 1], h[i]);

	for (int i = 0; i < n; i++)
		w += min(l[i], r[i]) - h[i];

	return (w);
}

int main()
{
	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int size = sizeof(h) / sizeof(h[0]);

	printf("%d\n", vh(h, size));
}
