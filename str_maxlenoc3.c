#include <unistd.h>

size_t	ft_maxlen(char *ref, char *ptr)
{
	size_t	maxlen;

	maxlen = 0;
	while (*ref++ == *ptr++)
		maxlen++;
	return (maxlen);
}

size_t	maxlen_forstring(char *ref, char *str)
{
	size_t	maxlen;
	size_t	tmp;

	maxlen = 0;
	while (*str != '\0')
	{
		tmp = ft_maxlen(ref, str);
		if (tmp > maxlen)
			maxlen = tmp;
		str++;
	}
	return (maxlen);
}

size_t	maxlen_forallstrings(char *ref, int ac, char *av[])
{
	size_t	maxlen;
	size_t	tmp;
	int		i;

	maxlen = -1;
	i = 1;
	while (++i < ac)
	{
		tmp = maxlen_forstring(ref, av[i]);
		if (tmp < maxlen)
			maxlen = tmp;
	}
	return (maxlen);
}

int		main(int ac, char *av[])
{
	size_t	maxlen;
	size_t	tmp;
	char	*ptr;

	if (ac > 1)
	{
		maxlen = 0;
		ptr = av[1];
		while (*av[1] != '\0')
		{
			tmp = maxlen_forallstrings(av[1], ac, av);
			if (tmp > maxlen)
			{
				ptr = av[1];
				maxlen = tmp;
			}
			av[1]++;
		}
		write(1, ptr, maxlen);
	}
	write(1, "\n", 1);
	return (0);
}

// https://github.com/Ngoguey42/c_exams/blob/master/c_exam03/ex04/str_maxlenoc.c
