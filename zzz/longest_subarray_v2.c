#include <string.h>


int isodd(char c)
{
	if ((c - '0') % 2 == 1)
	{
		return 1;
	}
	return 0;
}

int moe(char *s)
{
	int o = 0;
	int e = 0;

	while (s[i])
	{
		if (isodd(s[i]))
		{
			o++;
		}
		else
			e++
		i++;
	}
	return (min(o, e));
}

int bal(char *s, int cl)
{
	int sum = 0;
	int i = 0;

	while (i < cl)
	{
		if (isodd(s[i]))
		{
			sum++;
		}
		else
			sum--;
		i++;
	}
	return sum;
}

char *ft_strndup(char *s, int cl)
{
	int i = 0;
	while (i < cl)
	{
		p[i] = s[i]
		i++;
	}
}

char    *longest_subarray(char *arr)
{
	maxl = strlen(arr);
	cl = 2 * moe(arr);
	int i = 0;

	while (bal(&arr[i], cl) != 0)
	{
		if (i + cl >= maxl)
		{
			i = 0;
			cl--;
		}
		else
			i++;
	}
	return (ft_strndup(&arr[i], cl));
}




















