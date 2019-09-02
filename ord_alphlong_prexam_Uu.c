// TEST THIS CODE ???

//#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

int isb(char c)
{
	return (c == ' ' || c == '\t');
}



int nwords(char *s)
{
	int flag = 0;
	int i = 0;
	int nw = 0;

	while (s[i])
	{
		if (isb(s[i]))
		{
			flag = 0;
		}
		else if (!isb(s[i]) && flag == 0)
		{
			flag = 1;
			nw++;
		}
		i++;
	}
	return nw;
}

int wlen(char *s)
{
	int i = 0;

	while (!isb(s[i]) && s[i])
	{
		i++;
	}
	return i;
}

char **split(char *s)
{
	int nw;
	int i, j, k;
	char **w;
	int len;


	nw = nwords(s);
	//printf("%d\n", nw);
	w = (char **)malloc(sizeof(char *) * (nw + 1));
	w[nw] = 0;  // ?????????

	i = 0;
	k = 0;

	while (i < nw)
	{
		j = 0;
		while (isb(s[k]) && s[k])
		{
			k++;
		}
		if (!isb(s[k]) && s[k])
		{
			len = wlen(&s[k]);
			w[i] = (char *)malloc(sizeof(char) * (len + 1));
	//		printf("%d\n", len);
		}
		while (!isb(s[k]) && s[k])
		{
			w[i][j] = s[k];
			j++;
			k++;
		}
		w[i][j] = '\0';
		i++;
	}
	return w;
}

void p(char **w)
{
	int i = 0;
	int tmp;
	int last_len = -1;

	while (w[i] != 0)
	{
		tmp = wlen(w[i]);
		if (tmp == last_len)
			write(1, " ", 1);
		else if (last_len != -1)
			write(1, "\n", 1);
		write(1, w[i], tmp);
		last_len = tmp;
		i++;
	}
}

char low(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return c;
}

int abc(char *a, char *b)
{
	int i = 0;
	while (low(a[i]) == low(b[i]))
	{
		i++;
	}
	return (low(a[i]) - low(b[i]));
}

void ftswap(char **w, int i, int j)
{
	char *t;

	t = w[i];
	w[i] = w[j];
	w[j] = t;
}

void sortabc(char **w)
{
	int i, j;

	for (i = 0; w[i] != 0; i++)
	{

		for (j = i + 1; w[j] != 0; j++)
		{
			if (abc(w[i], w[j]) < 0)
			{
				ftswap(w, i, j);
			}
		}
	}
}

void sortlen(char **w)
{
	int i, j;
	int l1, l2;

	for (i = 0; w[i] != 0; i++)
	{
		l1 = wlen(w[i]);
		for (j = i; w[j] != 0; j++) // NOTE J = I HERE !!!
		{
			l2 = wlen(w[j]);
			if (l1 >= l2)
			{
				ftswap(w, i, j);
				l1 = wlen(w[i]); // DON'T FORGET !!!
			}
		}
	}
}

void ord(char *s)
{
	char **w;

	if (!s)
		return;

	w = split(s);
	//p(w);

	sortabc(w);
	//p(w);
	sortlen(w);
	p(w);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ord(av[1]);

	}
	write(1, "\n", 1);
}

/*
= Test 1 ===================================================
$> ./eo8pjmy0o82n9cm5s1ns1wjh "lorem ipsum dolor sit amet consectetur adipiscing elit curabitu\
r sollicitudin pretium nibh"
$> diff -U 3 user_output_test1 test1.output | cat -e
--- user_output_test1   2019-09-01 19:38:00.000000000 -0700$
+++ test1.output        2019-09-01 19:38:00.000000000 -0700$
@@ -1,6 +1,6 @@$
 sit$
-nibh elit amet$
-lorem dolor ipsum$
+amet elit nibh$
+dolor ipsum lorem$
 pretium$
 curabitur$
 adipiscing$

Diff KO :(
Grade: 0

*/


