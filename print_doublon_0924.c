// PASS
#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0;
	int j = 0;
	int flag = 0;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (flag == 0)
			{
				printf("%d" , a[i]);
				flag = 1;
			}
			else
			{
				printf(" %d" , a[i]);
			}
			i++;
			j++;
		}
		if (a[i] < b[j])
		{
			i++;
		}
		if (a[i] > b[j])
		{
			j++;
		}
	}
	printf("\n");
}
/*
int main()
{
	int a[4] = {1, 2, 10, 15};
	int b[4] = {2, 20, 40, 70};
	int na = 4;
	int nb = 4;
	print_doublon(a, na, b, nb);

	int a2[11] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int b2[8] = {2,  4,  5,  6,  7, 10,  40,  70};
	int na2 = 11;
	int nb2 = 8;
	print_doublon(a2, na2, b2, nb2);

	int a3[3] = {100, 200, 300};
	int b3[4] = {1, 2, 3, 4};
	int na3 = 3;
	int nb3 = 4;
	print_doublon(a3, na3, b3, nb3);
}
*/
