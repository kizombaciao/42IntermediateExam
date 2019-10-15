//#include <stdio.h> // del

int c2(int nb)
{
	int num = 0;

	while (nb > 0)
	{
		if ((nb % 10) == 2)
		{
			num++;
		}
		nb = nb / 10;
	}
	return num;
}

int count_of_2(int n)
{
	int tot = 0;

	for (int i = 2; i <= n; i++)
	{
		tot += c2(i);

	}
	return tot;
}

/*
int main()
{
	printf("%d\n", count_of_2(12));

}
*/