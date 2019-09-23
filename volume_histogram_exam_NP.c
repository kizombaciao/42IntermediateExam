#include <stdio.h> // del

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

int    volume_histogram(int *histogram, int size)
{
	int i;
	int le[size];
	int ri[size];
	int sum = 0;

	le[0] = histogram[0];
	for (i = 1; i < size; i++)
	{
		le[i] = max(le[i - 1], histogram[i]);
	}

	ri[size - 1] = histogram[size - 1];
	// the error was size - 1 instead of the correct size - 2 !!!
    for (i = size - 2; i >= 0; i--)
	{
		ri[i] = max(ri[i + 1], histogram[i]);
	}

	for (i = 0; i < size; i++)
	{
		sum += min(le[i], ri[i]) - histogram[i];
	}
	return sum;
}

int main()
{
    int h[] = {2, 0, 0, 5, 6, 6, 5, 0, 0, 8, 9, 0, 5, 0, 0, 4, 0, 7, 0, 8, 0, 9, 0, 3, 0, 1, 0, 5, 0, 5, 0, 6, 0, 4, 0, 6, 0, 7, 0, 5, 5, 6, 5, 4, 7, 0, 8, 0, 5, 0, 0, 0};
	int size = 52;

	printf("%d\n", volume_histogram(h, size));
/*
	int    histogram[] = {1, 0, 2, 0, 2};
	int    size = 5;

	printf("%d\n", volume_histogram(histogram, size));

	int    h[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int    s = 16;

	printf("%d\n", volume_histogram(h, s));
*/
}

