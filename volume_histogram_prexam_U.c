//#include <stdio.h> // del

int min(int a, int b)
{
	return ((a > b) ? b : a);
}

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int    volume_histogram(int *histogram, int size)
{
	int ml[size];
	int mr[size];
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			ml[i] = histogram[i];
		else
			ml[i] = max(ml[i - 1], histogram[i]);
	}
	for (int i = size-1; i >= 0; i--)
	{
		if (i == size-1)
			mr[i] = histogram[i];
		else
			mr[i] = max(mr[i + 1], histogram[i]);
	}
	for (int i = 0; i < size; i++)
	{
		sum += (min(ml[i], mr[i]) - histogram[i]);
	}
	return sum;
}
/*
int main()
{
	int h[] = {1, 0, 2, 0, 2};
	int size = 5;

	printf("%d\n", volume_histogram(h, size));
}
*/