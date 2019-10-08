//#include <stdio.h> // del

#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

// special strlen !!!
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i] && !isb(s[i]))
	{
		i++;
	}
	return i;
}

int cw(char *s)
{
	int i = -1;
	int flag = 0;
	int c = 0;

	while (s[++i])
	{
		if (isb(s[i]))
			flag = 0;
		else if (flag == 0)
		{
			c++;
			flag = 1;
		}
	}
	return c;
}

char **ft_split(char *s)
{
	int slen;
	int i, j, k;
	int len = cw(s);
	//printf("333a %d\n", len);
	char **w;

	w = (char **)malloc(sizeof(char *) * (len + 1));
	w[len] = 0;

	k = 0;
	for (i = 0; i < len; i++)
	{
		j = 0;
		while (s[k] && isb(s[k])) // VERY IMPORTANT isb() !!!
		{
			k++;
		}
		if (s[k])
		{
			slen = ft_strlen(&s[k]);
			//printf("333b %d\n", slen);
			w[i] = (char *)malloc(sizeof(char) * (slen + 1));
			w[i][slen] = 0;
		}
		while (s[k] && !isb(s[k]))
		{
			w[i][j] = s[k];
			k++;
			j++;
		}
	}
	return w;
}

int lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return c;
}

int ft_strcmp(char *a, char *b)
{
	int i = 0;
//	printf("444a %d  %d\n", ft_strlen(a), ft_strlen(b));

	while (lower(a[i]) == lower(b[i]) && a[i] && b[i]) // NOTE!!!
	{
//		printf("222a %d %c %c\n", i, a[i], b[i]);
		i++;
	}
//	if (!a[i] && !b[i])
//		return -1;
	return (lower(a[i]) - lower(b[i]));
}

void ft_swap(char **w, int i, int j)
{
	char *tmp = w[i];
	w[i] = w[j];
	w[j] = tmp;
}

void sortabc(char **w)
{
	for (int i = 0; w[i] != 0; i++)
	{
		for (int j = i + 1; w[j] != 0; j++) // don't forget i + 1 !!!
		{
			if (ft_strcmp(w[i], w[j]) <= 0)
			{
				ft_swap(w, i, j);
			}
		}
	}
}

void sortlen(char **w)
{
	int l1, l2;

	for (int i = 0; w[i] != 0; i++)
	{
		l1 = ft_strlen(w[i]);
		for (int j = i; w[j] != 0; j++)
		{
			l2 = ft_strlen(w[j]);
			if (l1 >= l2) // NOTE!!! EQUALITY !!!
			{
				ft_swap(w, i, j);
				l1 = ft_strlen(w[i]);
			}
		}
	}
}

void pr(char **w)
{
	int cl;
	int lastlen = 0;

	for (int i = 0; w[i] != 0; i++)
	{
		cl = ft_strlen(w[i]);
		if (lastlen == 0)
		{
			lastlen = cl;
			ft_putstr(w[i]);
		}
		else if (lastlen == cl)
		{
			ft_putchar(' ');
			ft_putstr(w[i]);
			lastlen = cl;
		}
		else if (lastlen != cl)
		{
			ft_putchar('\n');
			ft_putstr(w[i]);
			lastlen = cl;
		}
	}
}
/*
void p2(char **w)
{
	for (int i = 0; w[i] != 0; i++)
	{
		printf("%s\n", w[i]);
	}

}
*/
void oa(char *s)
{
	char **w;

	w = ft_split(s);
	sortabc(w);
	//p2(w);
	//printf("\n");
	sortlen(w);
	//p2(w);
	//printf("\n");
	pr(w);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		oa(av[1]);
	}
	ft_putchar('\n');
	return 0;
}

// VERY IMPORTANT !!! NOTE !!! test aA Aa"

