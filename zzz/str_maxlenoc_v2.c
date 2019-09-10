#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int wlen(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
	{
		;
	}
	return i;
}

char *ft_strdup(char *s)
{
	int i;
	char *p;

	int len = wlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	for (i = 0; s[i]; i++)
	{
		p[i] = s[i];
	}
	p[i] = '\0';
	return p;
}

char *ft_strsub(char *s, int st, int len)
{
	int i;
	char *p;

	if (!s)
		return (NULL); // remember !!!
	p = (char *)malloc(sizeof(char) * (len + 1));

	// chance of overflow ???
	for (i = 0; i < len && s[i]; i++) 
	{
		p[i] = s[i + st];
	}
	p[i] = '\0';
	return p;
}

int ft_strstr(char *n, char *h)
{
	int i = 0;
	int j;

	if (!*n)
		return(0);

	while (h[i])
	{
		j = 0;
		while (n[j] == h[i + j])
		{
			j++;
			if (!n[j])
				return 1;
		}
		i++;
	}
	return 0;
}

char *ft_strcpy(char *dst, char *s)
{
	int i;
	char *d = dst;
	for (i = 0; s[i]; i++)
	{
		d[i] = s[i];
	}
	d[i] = '\0';
	return d;
}

void sm(int n, char **s)
{
	char *stem;
	char *p = ft_strdup(s[0]);
	int len = wlen(p);
	char *res = (char *)malloc(sizeof(char) * (len + 1));
	int k;

	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			stem = ft_strsub(p, i, j);
			//printf("222a %s\n", stem);
			for (k = 1; k < n; k++)
			{
				if (ft_strstr(stem, s[k]) == 0)
				{
					break; // means no all match with current candidate stem!
				}
			}
			if (k == n)
			{
				//printf("222b %s /s %s\n", res, stem);
				if (wlen(res) < wlen(stem))
				{
					ft_strcpy(res, stem);
				}
			}
		}
	}
	printf("111a %s\n", res);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		sm(ac - 1, &av[1]);
	}
	ft_putchar('\n');
}







