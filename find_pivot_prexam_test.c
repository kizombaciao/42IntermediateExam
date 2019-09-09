#include <stdio.h>

int tot(int *arr, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}


int	find_pivot(int *arr, int n)
{
	int a = 0;
	int b = 0;

	int nn = tot(arr, n);

	for (int i = 0; i < n; i++)
	{
		a += arr[i];
		if (nn - a == b)
		{
			return i;
		}
		b += arr[i];
	}
	return -1;
}


int 		main(int argc, const char *argv[])
{
 	int arr[] = { 1, 2, 3, 4, 0, 6 };
 	int na = 6;
 	printf("pivot a: %d\n", find_pivot(arr, na));

}

