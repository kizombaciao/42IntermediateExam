#include <stdio.h>

/*
** Count the numbers of two (2) that appears in the number n passed as argument.
** Second argument keeps track of the current count state.
** If a number has 2 or more digits, we have to split it into smaller digits.
** We do this by using recursion.
** If it's a single digit, we can check really quick because 2 == n. ;)
*/

static void	count_number(int n, int *count)
{
	if (n >= 10)
	{
		count_number(n / 10, count);
		count_number(n % 10, count);
		//printf("\neee %d, %d", n, *count);
	}
	if (n == 2)
	{
		//printf("\nbbb %d, %d", n, *count);
		*count += 1;
	}
	return ;
}

/*
** Counts, for a given integer n, the number of two (2) that appear in all
** the numbers between 0 and n (inclusive).
*/

int			count_of_2(int n)
{
	int		i = 1;
	int		count = 0;

	while (++i <= n)
		count_number(i, &count);
	return (count);
}

/*
** Main function. Uncomment to test this file!
*/

#include <stdio.h>
#include <stdlib.h>
int			main(int argc, char *argv[])
{
	if (argc == 2)
		printf("\naaa %i\n", count_of_2(atoi(argv[1])));
	return (0);
}
