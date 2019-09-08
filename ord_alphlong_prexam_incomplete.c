// DID NOT PASS B/C I LEFT PRINTF INSIDE!!!

//#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

char low(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else
		return c;
}

int wlen2(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int wlen(char *s)
{
	int i = 0;
	int n = 0;
	int flag = 0;

	while (s[i])
	{
		if (isb(s[i]))
		{
			flag = 0;
		}
		else if (flag == 0)
		{
			flag = 1;
			n++;
		}
		i++;
	}
	return n;
}


char **split(char *s)
{
	int i = 0;
	int j, k;
	char **w;
	int wl, wl2;

	wl = wlen(s);
	w = (char **)malloc(sizeof(char *) * (wl + 1));
	w[wl] = 0; // ???

	k = 0;
	while (i < wl)
	{
		j = 0;
		while (isb(s[k]) && s[k])
		{
			k++;
		}
		// do i need an if condition here ???
		// better do if condition on malloc
		wl2 = wlen2(&s[k]);
		w[i] = (char *)malloc(sizeof(char) * (wl2 + 1));
		w[i][wl2] = '\0';

		while (!isb(s[k]) && s[k])
		{
			w[i][j] = s[k];
			j++;
			k++;
		}
		i++;
	}
	return w;
}

void pr(char **w)
{
	for (int i = 0; w[i]; i++)
	{
		printf("%s\n", w[i]); // be sure to remove printf even if not used !!!
	}
	printf("\n");
	//printf("\n");
}

int cmp(char *a, char *b)
{
	int i = 0;
	while ((low(a[i]) == low(b[i])) && a[i] && b[i])
	{
		i++;
	}
	return (low(a[i]) - low(b[i]));
}

void ft_swap(char **w, int i, int j)
{
	char *t;

	t = w[i];
	w[i] = w[j];
	w[j] = t;
}

void sortabc(char **w)
{
	for (int i = 0; w[i]; i++)
	{
		for (int j = i + 1; w[j]; j++)
		{
			if (cmp(w[i], w[j]) < 0)
			{
				ft_swap(w, i, j);
			}
		}
	}
}
/*
void sortlen(char **w)
{
	int l1, l2;

	for (int i = 0; w[i]; i++)
	{
		l1 = wlen2(w[i]);
		for (int j = i; w[j]; j++) // is it j = i ??? 
		{
			l2 = wlen2(w[j]);

			if (l1 >= l2)
			{
				ft_swap(w, i, j);
				l1 = wlen2(w[i]);
			}
		}
	}
}
*/

// BELOW ALSO WORKS, JUST MAKE SURE YOU HAVE THE RIGHT INDEX I AND J !!!
void sortlen(char **w)
{
	for (int i = 0; w[i]; i++)
	{
		for (int j = i; w[j]; j++) // is it j = i ??? 
		{

			if (wlen2(w[i]) >= wlen2(w[j]))
			{
				ft_swap(w, i, j);
			}
		}
	}
}
void p(char **w)
{
	int i = 0;
	int lastlen = -1;
	int curlen;
	//int flag = 0;

	while (w[i])
	{
		curlen = wlen2(w[i]);
	//	printf("222a  %s  %d  %d\n", w[i], curlen, lastlen);
		if (lastlen == curlen)
			{
				//printf("HEY\n");
				write(1, " ", 1);
			}
		else if (lastlen != -1)
			write(1, "\n", 1);
			
		write(1, w[i], wlen2(w[i]));
		lastlen = curlen;
		i++;
	}
}

void p2(char **words)
{
	int i = -1;
	int tmp;
	int last_len = -1; // trick used to keep same length words on same row!

	while (words[++i])
	{
		tmp = wlen2(words[i]);
		if (tmp == last_len)
			write(1, " ", 1);
		else if (last_len != -1)
			write(1, "\n", 1);
		write(1, words[i], tmp);
		last_len = tmp;
		//free(words[i]);
	}
}

void ord(char *s)
{
	char **w;

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
	return 0;
}

/*
= ord_alphlong =================================================================
$> gcc -Wextra -Wall -Werror ord_alphlong.c -o user_exe
ord_alphlong.c:91:3: error: implicitly declaring library function 'printf' with type 'int (co\
nst char *, ...)' [-Werror,-Wimplicit-function-declaration]
                printf("%s\n", w[i]);
                ^
ord_alphlong.c:91:3: note: include the header <stdio.h> or explicitly provide a declaration f\
or 'printf'
1 error generated.

Could not compile 'user_exe'
Grade: 0
*/