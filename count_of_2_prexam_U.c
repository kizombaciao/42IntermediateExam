#include <stdio.h>

int c(int n)
{
	int i = 0;

	while (n > 0) // remember !!!
	{
		if (n % 10 == 2)
		{
			i++;
		}
		n /= 10;
	}
	return i;
}

int count_of_2(int n)
{
	int i;
	int sum = 0;

	for (i = 2; i <= n; i++)
	{
		sum += c(i);
	}
	return sum;
}

/*
int main()
{
	printf("%d\n", count_of_2(25));
}
*/
