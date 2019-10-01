// PASS!
//#include <stdio.h>

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
	int ml[size];
	int mr[size];
	int sum = 0;


	ml[0] = histogram[0];
	for (int i = 1; i < size; i++)
	{
		ml[i] = max(ml[i - 1], histogram[i]);
	}

	mr[size - 1] = histogram[size - 1];
	for (int i = size - 2; i >= 0; i--)
	{
		mr[i] = max(mr[i + 1], histogram[i]);
	}

	for (int i = 0; i < size; i++)
	{
		sum += min(ml[i], mr[i]) - histogram[i];
	}
	return sum;
}

/*
int main()
{
	int    histogram[] = {1, 0, 2, 0, 2};
	int    size = 5;

	printf("%d\n", volume_histogram(histogram, size));

	int    histogram2[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	int    size2 = 16;

	printf("%d\n", volume_histogram(histogram2, size2));
}
*/
