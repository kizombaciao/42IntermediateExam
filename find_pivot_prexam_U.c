// PASS!!!
//#include <stdio.h>
//#include <stdlib.h>

int sss(int *a, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int	find_pivot(int *arr, int n)
{
	int sum;
	int bal = 0;

	sum = sss(arr, n);

	for (int i = 0; i < n; i++)
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
int 		main(int argc, const char *argv[])
{
 	int arra[] = { 1, 2, 3, 4, 0, 6 };
 	int na = 6;
 	printf("pivot a: %d\n", find_pivot(arra, na));

}
*/
