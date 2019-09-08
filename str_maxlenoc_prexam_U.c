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

int ft_len(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	int i = 0;
	char *p;
	int len;

	len = ft_len(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *ft_strsub(char *s, int st, int len)
{
	int i = 0;
	char *p;

	if (!s)
		return (NULL); // remember !!!

	p = (char *)malloc(sizeof(char) * (len + 1));
	while (len-- && s[i])
	{
		p[i++] = s[st++];
	}
	p[i] = '\0';
	return (p);
}

char *ft_strstr(char *h, char *n)
{
	int i = 0;
	int j = 0;

	if (!*n)
		return(h);

	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j]) // remember trick !!!
		{
			j++;
			if (!n[j]) // we are at the end of stem !
				return (&h[i]);
		}
	}
	return (NULL);
}

char *ft_strcpy(char *dest, char *src)
{
	int i = 0;
	char *p;

	p = dest;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// for i and for j is to get the start and length for strsub()
// for k is to cycle through the words
char *fs(int n, char **arr)
{
	int i, j, k;
	char *s;
	int len;
	char *stem;
	char *res;

	s = ft_strdup(arr[0]);
	len = ft_len(s);
	res = (char *)malloc(sizeof(char) * (len + 1));

	for (i = 0; i < len; i++) // i = start of strsub
	{
		// note equality j <= len - i !!!
		for (j = 1; j <= len - i; j++) // j = len of strsub
		{
			stem = ft_strsub(s, i, j);
			for (k = 1; k < n; k++) // k = num of words
			{
				if (ft_strstr(arr[k], stem) == NULL)
					break;

			}
			if (k == n && ft_len(res) < ft_len(stem))
				ft_strcpy(res, stem);
			free(stem); 
			// examshell doesn't penalize you if excluded free
		}
	}
	free(s);
	return (res);
}

// strdup w[0] s
// strlen s
// malloc res
// 3 nest for loops
// remember j = 1; j <= len - i
// strsub
// strstr and break
// if k == n and max res, stem, then strcpy

int main(int ac, char **av)
{
	char *p;
	if (ac >= 2)
	{
		p = fs(ac - 1, &av[1]);
		ft_putstr(p);
	}
	ft_putchar('\n');
}

