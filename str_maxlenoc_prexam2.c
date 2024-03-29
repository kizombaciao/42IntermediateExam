// PASS!

//#include <stdio.h> // d
#include <stdlib.h>
#include <unistd.h>

int ftstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ftstrdup(char *s)
{
	int i;
	int len;
	char *p;

	len = ftstrlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return p;
}

char *ftstrsub(char *s, int st, int len)
{
	int i;
	char *p;

	if (!*s)
		return NULL;
	p = (char *)malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len; i++)
	{
		p[i] = s[st + i];
	}
	p[i] = '\0';
	return p;
}

int ftstrstr(char *h, char *n)
{
	int i;
	int j;

	if (!*n)
		return 0;

	i = 0;
	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j])
		{
			j++;
			if (!n[j])
				return 1;
		}
		i++;
	}
	return 0;
}
void ftstrcpy(char *d, char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}

char *str_maxlenoc(int nw, char **w)
{
	int i;
	int j;
	int k;
	int len;
	char *s;
	char *stem;
	char *res;

	s = ftstrdup(w[0]);
	len = ftstrlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));

	for (i = 0; i < len; i++) // start
	{
		// j = 1 b/c minimum length of 1
		// index starts later means length has to be shorter
		for (j = 1; j <= len - i; j++) // len, hence why need equality
		{
			stem = ftstrsub(s, i, j);
			for (k = 1; k < nw; k++)
			{
				if (ftstrstr(w[k], stem) == 0)
					break;
			}
			if (k == nw)
			{
				if (ftstrlen(res) < ftstrlen(stem))
				{
					ftstrcpy(res, stem);
				}
			}
		}
	}
	return res;
}

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

int main(int ac, char **av)
{
	char *s;

	if (ac >= 2)
	{
		s = str_maxlenoc(ac - 1, &av[1]);
		ft_putstr(s);
	}
	ft_putchar('\n');

}

// s strdup
// slen strlen
// res malloc

// for st, < slen
// for len, <= slen - i
// stem = strsub
// for words
// strstr
// break
// k == n
// res = max(res, stem)
// strcpy
// free