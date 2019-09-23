// PASS !!!
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
	//int h[] = {1, 0, 2, 0, 2};
	int h[] = {2, 0, 0, 5, 6, 6, 5, 0, 0, 8, 9, 0, 5, 0, 0, 4, 0, 7, 0, 8, 0, 9, 0, 3, 0, 1, 0, 5, 0, 5, 0, 6, 0, 4, 0, 6, 0, 7, 0, 5, 5, 6, 5, 4, 7, 0, 8, 0, 5, 0, 0, 0};
	int size = 52;

	printf("%d\n", volume_histogram(h, size));
}
*/