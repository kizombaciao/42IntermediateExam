/*
** Get the total sum of all the values in an int array.
*/
static int	get_sum(int *arr, int n)
{
	int		sum;

	sum = 0;
	for (int i = 0; i < n; i += 1)
		sum += arr[i];
	return (sum);
}
/*
** Return the pivot index of an array, where the sum of the values on the
** left is equal to the sum on the right.
*/
int			find_pivot(int *arr, int n)
{
	int		count = 0;
	int 	pivot = -1;
	int		sum = get_sum(arr, n);

	for (int i = 0; (pivot == -1 && i < n); i += 1)
	{
		sum -= arr[i];
		pivot = (count == sum) ? i : -1;
		// alternative, immediately return i
		count += arr[i]; // count is added afterwards, so that pivot is never counted
	}
	return (pivot);
}
#include <stdio.h>
#include <stdlib.h>
int 		main(int argc, const char *argv[])
{
	int		*arr;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	for (int i = 0; (argc - 1) > i;  i += 1)
		arr[i] = atoi(argv[i + 1]); // no need for atoi in exam
	return (printf("Pivot: %d\n", find_pivot(arr, argc - 1)));
}