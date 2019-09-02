// pass practice exam

#include <stdio.h>

void print_doublon(int *a, int na, int *b, int nb)
{
	int flag = 0;
	int i = 0, j = 0;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (flag == 0)
			{
				printf("%d", a[i]);
				flag = 1;
			}	
			else
				printf(" %d", a[i]);

			i++;
			j++;
		}
		else if (a[i] < b[j])
		{
			i++;
		} 
		else if (a[i] > b[j])
		{
			j++;
		}
	}
	printf("\n");
}

/*
int main()
{
	int a[] = {1, 200, 300};
	int na = 3;
	int b[] = {1, 2, 3, 4};
	int nb = 4;


//	int a[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
//	int b[] = {2,  4,  5,  6,  7, 10,  40,  70};
//	int na = 11;
//	int nb = 8;

	print_doublon(a, na, b, nb);
}
*/