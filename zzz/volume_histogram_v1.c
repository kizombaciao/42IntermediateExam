#include <stdio.h>

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

int    volume_histogram(int *h, int size)
{
	int maxl[size];
	int maxr[size];
	int v = 0;

	maxl[0] = h[0];
	for (int i = 1; i < size; i++)
	{
		maxl[i] = max(maxl[i - 1], h[i]);
	}

	maxr[size - 1] = h[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		maxr[i] = max(maxr[i + 1], h[i]);
	}

	for (int i = 0; i < size; i++)
	{
		v += (min(maxl[i], maxr[i])) - h[i];
	}

	return v;
}

int main()
{
	int    histogram[] = {1, 0, 2, 0, 2};
	int    size = 5;

	printf("%d\n", volume_histogram(histogram, size));
}

