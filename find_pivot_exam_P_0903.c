//#include <stdio.h> // del

int s(int *arr, int n)
{
	int i = 0;
	int sum = 0;

	while (i < n)
	{
		sum += arr[i];
		i++;
	}
	return sum;
}

int find_pivot(int *arr, int n)
{
	int sum = 0;
	int bal = 0;
	int i;

	sum = s(arr, n);

	for (i = 0; i < n; i++)
	{
		sum = sum - arr[i];
		
		if (sum == bal)
		{
			return i;
		}

		bal = bal + arr[i];
	}
	return -1;
}

/*
int main()
{
	int arr[] = {1, 2, 3, 4, 0, 6};
	int n = 6;

	int arr1[] = {-5, 10, 2, 5};
	int n1 = 4;

	int arr2[] = {1, 100, 0, 0, 1};
	int n2 = 5;

	int arr3[] = {7, 9, 8};
	int n3 = 3;

	int arr4[] = {1, 2};
	int n4 = 2;

	printf("%d\n", find_pivot(arr, n));
	printf("%d\n", find_pivot(arr1, n1));
	printf("%d\n", find_pivot(arr2, n2));
	printf("%d\n", find_pivot(arr3, n3));
	printf("%d\n", find_pivot(arr4, n4));
}
*/

