#include <stdio.h>

void pd(int *a, int na, int *b, int nb)
{
	int ia = 0, ib = 0;

	while (ia < na && ib < nb)
	{
		if (a[ia] == b[ib])
		{
			printf("%d ", a[ia]);
			ia++;
			ib++;
		} else {
			if (a[ia] > b[ib])
				ib++;
			else
				ia++;
			}	
		}
		
}

int main()
{
	int a[] = {1, 2, 3, 10, 15, 21};
	int na = 6;
	int b[] = {2, 3, 20, 21, 40, 70};
	int nb = 6;

	pd(a, na, b, nb);
}