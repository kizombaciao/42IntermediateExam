// PASS!

//#include <stdio.h> // d
#include <stdlib.h>
#include <unistd.h>

// set up, strup, strlen
// strsub
// strstr

int ftstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

// don't forget to create malloc!!!
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
	// remember malloc!!!
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
	//printf("%s %d\n", p, len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len; i++) // start
	{
		//printf("222a %d %d\n", i, len);
		for (j = 1; j <= len - i; j++) // len, hence why need equality
		{
			stem = ftstrsub(s, i, j);
			//printf("%d %d %s\n", i, j, stem);
			for (k = 1; k < nw; k++)
			{
				if (ftstrstr(w[k], stem) == 0)
					break;
			}
			//printf("444a  %d %d\n", k, nw);
			if (k == nw)
			{
				if (ftstrlen(res) < ftstrlen(stem))
				{
					//printf("555a %s\n", stem);
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
		//printf("HI\n");
		s = str_maxlenoc(ac - 1, &av[1]);
//		printf("111a %s\n", s);
		ft_putstr(s);
	}
	ft_putchar('\n');

}