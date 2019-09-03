#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

int cw(char *s)
{
	int i = 0;
	int flag = 1;
	int nw = 0;

	while (s[i])
	{
		if (isb(s[i]))
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			nw++;
		}
		i++;
	}
	return nw;
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

// count words
char **split(char *s)
{
	int nw;
	char **w;
	int len;
	int i = 0;
	int j, k;

	nw = cw(s);
//	printf("%d\n", nw);

	w = (char **)malloc(sizeof(char *) * (nw + 1));
	w[nw] = 0;

	k = 0;
	while (i < nw)
	{
		j = 0; // inside the outer while loop !!!

		while (isb(s[k]) && s[k])
		{
			k++;
		}
		if (!isb(s[k]) && s[k])
		{
			len = wlen(&s[k]);
		}
		w[i] = (char *)malloc(sizeof(char) * (len + 1));
		w[i][len] = '\0';
		while (!isb(s[k]))
		{
			w[i][j] = s[k];
			j++;
			k++;
		}		
		i++;
	}
	return w;
}

void p(char **w)
{
	int i = 0, j = 0;

	while (w[i])
	{

		/*
		while (w[i][j])
		{
			printf("%c", w[i][j]);
			j++;
		}
		*/
		printf("%s\n", w[i]);
		i++;
	}
	printf("\n");
}

char low(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return c;
}
void ftswap(char **w, int i, int j)
{
	char *tmp;

	tmp = w[i];
	w[i] = w[j];
	w[j] = tmp;
}

int cmpabc(char *a, char *b)
{
	int i = 0;

	while (low(a[i]) == low(b[i]))
	{
		i++;
	}
	//printf("222a %d\n", i);
	return (low(a[i]) - low(b[i]));
}

// j index starts from where ???
// ftswap(char **w, int i, int j)
// lower case !!!
// ftsplit(), the j index needs to be inside the outer while loop
void sortabc(char **w)
{
	int i = 0, j;

	while (w[i] != 0)
	{
		j = i + 1;
		while (w[j] != 0)
		{
			//printf("333a %s %s\n", w[i], w[j]);
			if (cmpabc(w[i], w[j]) < 0)
			{
				//printf("hey\n");
				ftswap(w, i, j);
			}
			j++;
		}
		i++;
	}
}

void sortlen(char **w)
{
	int i = 0, j;
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
				l1 = wlen(w[i]);
			}
			j++;
		}
		i++;
	}
}
void pr(char **w)
{
	int i = 0;
	int lastlen = -1;
	int len;

	while (w[i] != 0)
	{
		len = wlen(w[i]);
//		printf("555a %d %d\n", len, lastlen);
		if (len == lastlen)
			write(1, " ", 1);
		else if (lastlen != -1)
			write(1, "\n", 1);
		write(1, w[i], len);
		lastlen = len;
		i++;
	}
}
/*
void pr(char **w)
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

int main(int ac, char **av)
{
	char **w;

	if (ac == 2)
	{
		w = split(av[1]);
		//p(w);
		sortabc(w);
		//p(w);
		sortlen(w);
		pr(w);
	}
	write(1, "\n", 1);
	return 0;
}