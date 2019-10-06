//#include <stdio.h>

int c2(int n)
{
	int tot = 0;

	while (n > 0)
	{
		if (n % 10 == 2)
			tot++;
		n /= 10;
	}
	return tot;
}

int    count_of_2(int n)
{
	int sum = 0;

	for (int i = 2; i <= n; i++)
	{
		sum += c2(i);
	}
	return sum;
}

/*
int main()
{
	printf("%d\n", count_of_2(25));
}
*/