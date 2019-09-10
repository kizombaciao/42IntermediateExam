#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	for (int i = 0; s[i]; i++)
	{
		ft_putchar(s[i]);
	}
}

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

int cw(char *s)
{
	int flag = 0;
	int nw = 0;

	for (int i = 0; s[i]; i++)
	{
		if (isb(s[i]))
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			nw++;
		}
	}
	return nw;
}

int wlen(char *s)
{
	int i;
	/*
	while (s[i] && !isb(s[i]))
	{
		i++;
	}
	*/
	for (i = 0; !isb(s[i]) && s[i]; i++)
	{
		;
	}
	return i;
}

char **split(char *s)
{
	int i, j, k;
	int nw = cw(s);
	int wl;

	char **p = (char **)malloc(sizeof(char *) * (nw + 1));
	p[nw] = 0;

	i = 0;
	k = 0;
	for (i = 0; i < nw; i++)
	{
		j = 0;
		while (isb(s[k]) && s[k])
		{
			k++;
		}
		wl = wlen(&s[k]);
		p[i] = (char *)malloc(sizeof(char) * (wl + 1));
		p[i][wl] = '\0';
		while (!isb(s[k]) && s[k])
		{
			p[i][j] = s[k];
			j++;
			k++;
		}
	}
	return p;
}

void pr(char **w)
{
	for (int i = 0; w[i]; i++)
	{
		printf("%s\n", w[i]);
	}
	printf("\n");
}

void ft_swap(char **w, int i, int j)
{
	char *tmp;
	tmp = w[i];
	w[i] = w[j];
	w[j] = tmp;
}

int low(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return c;
}

int cmp(char *a, char *b)
{
	int i = 0;
	while (low(a[i]) == low(b[i]))
	{
		i++;
	}
	return (low(a[i]) - low(b[i]));
}

void sortabc(char **w)
{
	for (int i = 0; w[i] != 0; i++)
	{
		for (int j = i + 1; w[j] != 0; j++)
		{
			if (cmp(w[i], w[j]) < 0)
			{
				ft_swap(w, i, j); // char **ft_swap ???
			}
		}
	}
}
void sortlen(char **w) // void function !
{
	int i, j;
	int l1, l2;

	for (i = 0; w[i] != 0; i++)
	{
		l1 = wlen(w[i]);
		for (j = i; w[j] != 0; j++) // NOTE J = I HERE !!!
		{
			l2 = wlen(w[j]);
			if (l1 >= l2) // this needs to be equality!!!
			{
				ft_swap(w, i, j);
				l1 = wlen(w[i]); // DON'T FORGET !!! Is necessary ???
			}
		}
	}
}
/*
void sortlen(char **w)
{
	int l1, l2;

	for (int i = 0; w[i] != 0; i++)
	{
		for (int j = i + 1; w[j] != 0; j++)
		{

			if (wlen(w[i]) >= wlen(w[i])) // ???
			{
				ft_swap(w, i, j);
			}
		}
	}
}
*/

// THIS PRINT IS MUCH EASIER TO FOLLOW, SPLIT BY CASES!
void p(char **w)
{
	int lastlen;
	int cl;


	for (int i = 0; w[i]; i++)
	{
		cl = wlen(w[i]);
		if (i == 0)
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

void oa(char *s)
{
	char **w;

	if (!s)
		return ;

	w = split(s);
	//pr(w);

	sortabc(w);
	//pr(w);
	sortlen(w);
	p(w);

}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		oa(av[1]);
	}
	ft_putchar('\n');
}










