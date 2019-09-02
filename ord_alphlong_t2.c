// practice exam, make into template for studying !!!

#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

int numw(char *s)
{
	int i = 0;
	int flag = 1;
	int nw = 0;

	while (s[i])
	{
		if (isb(s[i]))
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			nw++;
			flag = 0;
		}
		i++;
	}
	return (nw);
}

int wlen(char *s)
{
	int i = 0;
	while (!isb(s[i]) && s[i])
	{
		i++;
	}
	return (i);
}

char **ftsplit(char *s)
{
	int i; // word
	int j; // string
	int k; // s
	int nw;
	char **w;
	int wl;

	if (!s)
		return NULL;
	nw = numw(s);
	w = (char **)malloc(sizeof(char *) * (nw + 1));

	i = 0;
	k = 0; // NOTE!!! this k is outside of the first while loop !!!
	while (i < nw)
	{
		j = 0;
		while (s[k] && isb(s[k]))
			k++;
		wl = wlen(&s[k]);
		w[i] = (char *)malloc(sizeof(char) * (wl + 1)); // remember !
		while (!isb(s[k]) && s[k])
		{
			w[i][j] = s[k];
			j++;
			k++;
		}
		w[i][j] = '\0';
		i++;
	}
	w[i] = 0;
	return (w);
}

char up(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

// note!!! double pointer w !!!
void ftswap(char **w, int i, int j)
{
	char *tmp;

	tmp = w[i];
	w[i] = w[j];
	w[j] = tmp;	
}

int abc(char *w1, char *w2)
{
	char t1;
	char t2;
	int i = 0;

	while (w1[i])
	{
		t1 = up(w1[i]);
		t2 = up(w2[i]);
		if (t1 != t2)
			return (t1 - t2);
		i++;
	}
	return (0);
}

void sortabc(char **w)
{
	int i = 0;
	int j;
	char *p;

	while (w[i])
	{
		j = i + 1; // note !!!
		while (w[j])
		{
			if (abc(w[i], w[j]) < 0)
			{
				ftswap(w, i, j);
			}
			j++;
		}
		i++;
	}
}

void sortlen(char **w)
{
	int i = 0;
	int j;
	int l1, l2;

	while (w[i])
	{
		l1 = wlen(w[i]);
		j = i;
		while (w[j])
		{
			l2 = wlen(w[j]);
			if (l1 >= l2)
			{
				ftswap(w, i, j);
				l1 = wlen(w[i]); // update l1 afte swap. // DON'T FORGET !!!
			}
			j++;
		}
		i++;
	}
}

void pr(char **w)
{
	int i = 0;
	int tmp;
	int last_len = -1;

	while (w[i])
	{
		if (tmp == last_len)
			write(1, " ", 1);
		else if (last_len != -1)
			write(1, "\n", 1);
		write(1, w[i], tmp);
		last_len = tmp;
		i++;
	}
}

int main(int ac, char **av)
{
	char **w;

	if (ac == 2)
	{
		w = ftsplit(av[1]);
		sortabc(w);
		sortlen(w);
		pr(w);
	}
	write(1, "\n", 1);
	return (0);
}
