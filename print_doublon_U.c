// Passed Moulinette 2019.05.14
#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int ia = 0;
	int ib = 0;
	int first = 1;

	while (ia < na && ib < nb) // note, && condition
	{
		if (a[ia] == b[ib])
		{
			if (first)
			{
				printf("%d", a[ia]);
				first = 0;
			}
			else
				// there is a space to account for subsequent entries
				printf(" %d", a[ia]); 
			ia++;
			ib++;
		}
		// LIKE A RACE: roll the index that is lagging, given sorted array
		else if (a[ia] < b[ib])
			ia++;
		else if (b[ib] < a[ia])
			ib++;
	}
	printf("\n");
}
//-----------------------------------------------------------
int	main(void)
{
	int a[] = { -5,  1, 3, 15, 50, 71, 100, 200, 300, 1200, 5000 }; int na = 11;
	int b[] = {  2,  3,  5,  6,  7, 15,  40,  1200 }                  ; int nb = 8;
	print_doublon(a, na, b, nb);
	return (0);
}