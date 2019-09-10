// TEST AGAIN BECAUSE YOU HAVE A NEW TYPE OF PRINT
// PASSED !!!
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
	w[nw] = 0;  // law row of word table!

	i = 0;
	k = 0;

	while (i < nw)
	{
		j = 0;
		while (isb(s[k]) && s[k])
		{
			k++;
		}
		if (!isb(s[k]) && s[k]) // this if not necessary !
		{
			len = wlen(&s[k]);
			w[i] = (char *)malloc(sizeof(char) * (len + 1)); 
			// malloc error check !!!
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
/*
void p(char **w)
{
	int i = 0;
	int len;
	int last_len = -1;

	while (w[i] != 0)
	{
		len = wlen(w[i]);
		if (len == last_len)
			write(1, " ", 1);
		else if (last_len != -1)
			write(1, "\n", 1);
		write(1, w[i], len);
		last_len = len;
		i++;
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
		if (i == 0) // when i == 0
		{
			lastlen = cl;
			ft_putstr(w[i]);
		}
		else if (lastlen == cl) // when i != 0 && lastlen == c
		{
			ft_putchar(' ');
			ft_putstr(w[i]);
			lastlen = cl;
		}
		else if (lastlen != cl) // when i != 0 && lastlen != c
		{
			ft_putchar('\n');
			ft_putstr(w[i]);	
			lastlen = cl;
		}
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
	while (low(a[i]) == low(b[i])) // remember low()!!!
	{
		i++;
	}
	return (low(a[i]) - low(b[i])); // don't forget low !!!
}

void ftswap(char **w, int i, int j)
{
	char *t;

	t = w[i];
	w[i] = w[j];
	w[j] = t;
}

void sortabc(char **w) // void function !
{
	int i, j;

	for (i = 0; w[i] != 0; i++)
	{
		for (j = i + 1; w[j] != 0; j++) // don't forget j = i + 1 !!! NOT j = 1 !!!
		{
			if (abc(w[i], w[j]) < 0)
			{
				ftswap(w, i, j);
			}
		}
	}
}

// must use l1 and l2!!! investigate why ???
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
				ftswap(w, i, j);
				l1 = wlen(w[i]); // DON'T FORGET !!! Is necessary ???
			}
		}
	}
}

// DELETE
/*
void pr(char **w)
{
	for (int i = 0; w[i]; i++)
	{
		printf("%s\n", w[i]);
	}
	printf("\n");
}
*/
void ord(char *s)
{
	char **w;

	if (!s)
		return;

	w = split(s);
	//pr(w);
	sortabc(w);
	//pr(w);
	sortlen(w);
	//pr(w);
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


