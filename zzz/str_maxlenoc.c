#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}
char *ft_strdup(char *s)
{
	int i = 0;
	int len;
	char *d;

	len = ft_strlen(s);

	//printf("444a %d\n", len);
	d = (char *)malloc(sizeof(char) * (len + 1));

	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);

}

char *ft_strsub(char *s, int i, int len)
{
	int k = 0;
	char *p;

	if (!s)
		return NULL;

	p = (char *)malloc(sizeof(char) * (len + 1));

	while (len-- && s[k])
	{
		p[k] = s[i++];
		k++;
	}
	p[k] = '\0';
	return (p);
}

char *ft_strstr(char *hay, char *needle)
{
	int i;
	int j;

	if (!*needle)
		return (hay);
	i = 0;
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return NULL;
}

char *ft_strcpy(char *d, char *s)
{
	char *p;

	printf("555b %s\n", s);

	p = d;
	while ((*p++ = *s++))
		;
	*(--p) = '\0';
	printf("555a %s\n", d);
	return (d);
}

char *fs(int n, char **arr)
{
	int k; // index for num of words
	char *s; // first word
	int len; // length of first word
	char *res; // returned result
	char *stem;

	//printf("HI %s\n", arr[0]);
	s = ft_strdup(arr[0]);
	//printf("333a %s", s);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		// note, j is for length
		for (int j = 1; j <= len - i; j++)
		{
			stem = ft_strsub(s, i, j);
			//printf("222a %s %d %d\n", stem, i, j);
			for (k = 1; k < n; k++)
			{
				if (ft_strstr(arr[k], stem) == NULL)
					break;
					// why break when it is NULL?
					// b/c needle is not within hay!
			}

			// n is index for number of words
			// b/c we want the largest of the potential matches!!!
			if (k == n && ft_strlen(res) < ft_strlen(stem))
				ft_strcpy(res, stem);
			free(stem);
		}
	}
	free(s);
	return res;
}
///////////////////////////////////////////
int main(int ac, char **av)
{
	char *p;
	if (ac >= 2)
	{
		p = fs(ac - 1, &av[1]);
		ft_putstr(p);
	}

}