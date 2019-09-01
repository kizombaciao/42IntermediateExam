#include <stdio.h>

void equation(int n)
{
	int a, b, c;

	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				if ((a * 10 + b) + (c * 10 + a) == n)
				{
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				}
			}
		}
	}
}
/*
int main()
{
	equation(42);
	printf("\n");
	equation(111);
	printf("\n");
	equation(0);
}
*/
