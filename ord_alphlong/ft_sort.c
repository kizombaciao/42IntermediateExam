#include "ord_alphlong.h"
#include <stdio.h> // delete


void		ft_strsswap(char **strs, int i1, int i2)
{
	char		*tmp;

	tmp = strs[i1];
	strs[i1] = strs[i2];
	strs[i2] = tmp;
}

char		ft_upper(char c)
{
	return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

int			ft_stralphcmp(char *s1, char *s2)
{
	char		tmp1;
	char		tmp2;
	int			i;

	i = -1;
	while (s1[++i] != '\0')
	{
		tmp1 = ft_upper(s1[i]);
		tmp2 = ft_upper(s2[i]);
		if (tmp1 != tmp2)
			return (tmp1 - tmp2);
	}
	return (0);
}

// sorts in reverse alphabetical order but why???
void		ft_sortalph(char **strs)
{
	int			i;
	int			j;

	i = -1;
	while (strs[++i] != NULL)
	{
		j = i;
		while (strs[++j] != NULL)
		{
			printf("444a %s %s\n", strs[i], strs[j]);
			if (ft_stralphcmp(strs[i], strs[j]) < 0)
				ft_strsswap(strs, i, j);
		}
	}
}

void		ft_sortlen(char **strs)
{
	int			i;
	int			j;
	int			tmp;
	int			tmp2;

	i = -1;
	while (strs[++i] != NULL)
	{
		tmp = ft_strlen(strs[i]);
		//printf("\n222a %d %d", tmp, i);
		j = i;
		while (strs[++j] != NULL)
		{
			tmp2 = ft_strlen(strs[j]);
//			printf("777a %d %d\n", tmp, tmp2);
			printf("888a %d %d %s\n", i, tmp, strs[j]);
			if (tmp >= ft_strlen(strs[j]))
			{
				ft_strsswap(strs, i, j);
				tmp = ft_strlen(strs[i]); 
				// because tmp gets recalculated here!!!
				// that's how it gets updated!!!
				//printf("\n222b %d %d", tmp, i);
			}
		}
	}
}

// https://github.com/Julow/exam-00/blob/master/ex03/ft_sort.c
