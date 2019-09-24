#include <stdio.h> // del

#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

int nwords(char *s)
{
	int i = 0;
	int nw = 0;
	int flag = 0;

	while (s[i])
	{
		if (isb(s[i]))
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			flag = 1;
			nw++;
		}
		i++;
	}
	return nw;
}

int ft_strlen(char *s)
{
	int i = 0;
	
	while (s[i] && !isb(s[i]))
	{
		i++;
	}
	return i;
}


char **split(char *s)
{
	int i, j, k;
	int len;
	int nw = nwords(s);
	printf("222a %d\n", nw);
	char **w;

	w = (char **)malloc(sizeof(char *) * (nw + 1));
	w[nw] = 0; // ???

	k = 0;
	for (i = 0; i < nw; i++)
	{
		while (s[k] && isb(s[k]))
		{
			k++;
		}
		if (!isb(s[k]) && s[k])
		{
			len = ft_strlen(&s[k]);
			w[i] = (char *)malloc(sizeof(char) * (len + 1));
			w[i][len] = '\0'; // char or string ???
			printf("222b %d\n", len);
		}
		j = 0;
		while (s[k] && !isb(s[k]))
		{
			w[i][j] = s[k];
			j++;
			k++;
		}
		printf("222c %s\n", w[i]);
	}
	//w[i] = 0;
	return NULL;
}

void ft_swap(char **w, int i, int j)
{
	char *tmp;

	tmp = w[i];
	w[i] = w[j];
	w[j] = tmp;
}

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 32;
	}
	return c;
}

// lower !!!
int ft_strcmp(char *a, char *b)
{
	int i = 0;
	while (lower(a[i]) == lower(b[i]))
	{
		i++;
	}
	return (lower(a[i]) - lower(b[i]));
}

void sortabc(char **w)
{
	for (int i = 0; w[i] != 0; i++)
	{
		for (int j = i + 1; w[i] != 0; j++)
		{
			if (ft_strcmp(w[i], w[j]) < 0)
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
		for (int j = i; w[i] != 0; j++)
		{
			l2 = ft_strlen(w[j]);
			if (l1 > l2)
			{
				ft_swap(w, i, j);
				l1 = ft_strlen(w[i]);
			}
		}
	}
}

void ft_putstr(char *s)
{
	int i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void pr(char **w)
{
	int i = 0;
	int lastlen = 0;
	int cl;

	while (w[i] != 0)
	{
		cl = ft_strlen(w[i]);
		if (lastlen == 0)
		{
			lastlen = cl;
			ft_putstr(w[i]);
		}
		else if (lastlen != cl)
		{
			ft_putchar('\n');
			ft_putstr(w[i]);
		}
		else if (lastlen == cl)
		{
			ft_putchar(' ');
			ft_putstr(w[i]);
		}
	}
}

// delete
void pt(char **w)
{
	for (int i = 0; w[i] != 0; i++)
	{
		printf("333a  %s\n", w[i]);
	}
	printf("\n");
}

void oa(char *s)
{
	char **w;
	printf("hey");

	w = split(s);
//	pt(w);
	sortabc(w);
//	pt(w);
//	sortlen(w);
//	pt(w);
//	pr(w);
}

// IMPORTANT --- LOWER !!!

int main(int ac, char **av)
{
	if (ac == 2)
	{
		oa(av[1]);
	}
	ft_putchar('\n');
	return 0;
}
