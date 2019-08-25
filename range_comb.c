// Passed Moulinette 2019.06.03
// This code was heavily influenced by dfonarev's solution (github.com/ruv1nce)

#include <stdlib.h>
#include <string.h>

int		factorial(int n)
{
	int out = n;
	while (--n > 1)
		out *= n;
	return (out);
}

void	permute(int **tab, int *avail, int *soln, int n, int cur, int *soln_i)
{
	int i = -1;
	if (cur == n)
		memcpy(tab[++(*soln_i)], soln, n * sizeof(int));
	else
	{
		while (++i < n)
		{
			if (avail[i] == 1)
			{
				soln[cur] = i;
				avail[i] = 0;
				permute(tab, avail, soln, n, cur + 1, soln_i);
				avail[i] = 1;
			}
		}
	}
}
int		**range_comb(int n)
{
	if (n <= 0)
		return (0);
	int i = -1;
	int soln[n];
	int permutations = factorial(n);
	int avail[n];
	int **tab;
	int soln_i;
	while (++i < n)
		avail[i] = 1;

	//tab = malloc(sizeof(*tab) * (permutations + 1)); // sizeof(*tab) ???
	tab = (int **)malloc(sizeof(int *) * (permutations + 1));
	tab[permutations] = 0;

	i = -1;
	while (++i < permutations)
		//tab[i] = malloc(sizeof(**tab) * n); // sizeof(**tab) ???
		tab[i] = (int *)malloc(sizeof(int) * n);

	soln_i = -1;
	permute(tab, avail, soln, n, 0, &soln_i);
	return (tab);
}

//-------------------------------------------
#include <stdio.h>
int	main(void)
{
	int n = 3;
	int **arr = range_comb(n);
	int i = -1;
	int j;
	int size = factorial(n);

	// i = num of permutations
	// j = the order of each of the n digits
	while (++i < size)
	{
		j = -1;
		while (++j < n)
			printf("%d, ", arr[i][j]);
		printf("\n");
	}
}