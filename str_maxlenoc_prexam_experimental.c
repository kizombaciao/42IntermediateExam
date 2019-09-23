// PASS USING MODIFIED FT_STRSTR()!!!
// PASS!!!

//#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int wlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return i;
}
void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = '\0'; // review this type of notation ???
}
void	*ft_memalloc(size_t size)
{
	void *p;

	if (!(p = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
char	*ft_strnew(size_t size)
{
	// don't you need (char *) typecasting here ???
	// https://www.geeksforgeeks.org/type-conversion-c/
	return ((char *)ft_memalloc(size + 1)); 
}

char *ft_strdup(char *s)
{
	int wl = wlen(s);
	char *stem = (char *)ft_strnew(sizeof(char) * wl);
	int i = 0;
	while (s[i])
	{
		stem[i] = *(s + i);
		i++;
	}
	return stem;
}

char *ft_strsub(char *s, int i, int len)
{
	if (!*s)
		return NULL;

	char *stem = ft_strnew(sizeof(char) * len);

	for (int j = 0; j < len && s[j]; j++)
	{
		stem[j] = s[i + j]; // becareful, it should be stem[j] and NOT stem[i]!!!
	}
	return stem;
}

int ft_strstr(char *n, char *h)
{
	if (!*n)
		return 0;

	for (int i = 0; h[i]; i++)
	{
		int j = 0;
		while (h[i + j] == n[j])
		{
			j++;
			if (!n[j])
				return (1);
		}
		/*
		for (int j = 0; h[i + j] == n[j]; j++)
		{
			if (!n[j+1])
				return 1;
		}
		*/
	}
	return 0;
}

void ft_strcpy(char *d, char *s)
{
	for (int i = 0; s[i]; i++)
	{
		d[i] = s[i];
	}
}

void sm(int nw, char **s)
{
	int k;
	int wl = wlen(s[0]);
	char *res = ft_strnew(sizeof(char) * (wl));
	char *w = ft_strdup(s[0]);

	for (int i = 0; i < wl; i++)
	{
		for (int j = 1; j <= wl - i; j++) // length
		{
			char *stem = ft_strsub(w, i, j);
			for (k = 1; k < nw; k++)
			{
				if (ft_strstr(stem, s[k]) == 0)
				{
					break ;
				}	
			}
			if (k == nw)
			{
				if(wlen(res) < wlen(stem))
				{
					ft_strcpy(res, stem);
				}
			}
			free(stem);
		}
	}
	free(w);
	write(1, res, wlen(res));
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		sm(ac - 1, &av[1]);
	}
	ft_putchar('\n');
}



















