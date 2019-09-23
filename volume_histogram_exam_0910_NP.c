// not pass!!!
//#include <stdio.h> // del

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
	for (i = size - 1; i >= 0; i--) // error! start from i = size - 2 !!!
	{
		ri[i] = max(ri[i + 1], histogram[i]);
	}

	for (i = 0; i < size; i++)
	{
		sum += min(le[i], ri[i]) - histogram[i];
	}
	return sum;
}

/*
int main()
{
	int    h1[] = {2, 0, 1};
	int    s1 = 3;

	printf("%d\n", volume_histogram(h1, s1));

	int    histogram[] = {1, 0, 2, 0, 2};
	int    size = 5;

	printf("%d\n", volume_histogram(histogram, size));

	int    h[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int    s = 16;

	printf("%d\n", volume_histogram(h, s));
}
*/
