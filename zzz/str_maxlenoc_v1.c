#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int wlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char *ftstrdup(char *s)
{
	char *p;
	int len;
	int i = 0;

	len = wlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
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
	char *p;
	int i;

	if (!s)
		return NULL;

	p = (char *)malloc(sizeof(char) * (len + 1));
	// better to use while and check for s[i] equal to NULL !!!
	for (i = 0; i < len; i++)
	{
		p[i] = s[st + i];
	}
	p[len] = '\0';
	return p;
}

int ftstrstr(char *h, char *s)
{
	int i = 0, j;

	if (!*s)
		return 0;

	while (h[i])
	{
		j = 0;
		while (h[i + j] == s[j])
		{
			j++;
			if (!s[j])
				return (1);
		}
		i++;
	}
	return 0;
}

void ftstrcpy(char *d, char *s)
{
	int i = 0;

	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}

char *sm(int nw, char **w)
{
	char *s;
	int len;
	char *res;
	char *stem;

	int i, j, k;


	s = ftstrdup(w[0]);
	len = wlen(s);
	res = (char *)malloc(sizeof(char) *(len + 1));
	//stem[len] = '\0'; // <<<

	for (i = 0; i < len; i++)
	{
		for (j = 0; j <= len - i; j++)
		{
			stem = ftstrsub(s, i, j);
			
			for (k = 1; k < nw; k++)
			{
				if (ftstrstr(w[k], stem) == 0)
				{
					break;
				}
			}
			if (k == nw)
			{
				if (wlen(res) < wlen(stem))
					ftstrcpy(res, stem);
			}
		}
	}
	return res;
}

int main(int ac, char **av)
{
	char *p;
	
	if (ac >= 2)
	{
		p = sm(ac - 1, &av[1]);
		printf("%s\n", p);

	}
	write(1, "\n", 1);
}

// strdup
// strlen
// malloc
// strsub, i, j
// strstr