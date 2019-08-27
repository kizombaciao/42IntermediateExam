#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int bbb(char c)
{
	return (c == ' ' || c == '\t');
}

int len(char *s, int (*f)(char))
{
	int i = 0;

	while (!f(*s) && *s++)
		i++;
	return (i);
}

// count words
int cw(char *s, int (*f)(char))
{
	int i = 0, w = 0, flag = 0;

	while (s[i])
	{
		if (f(s[i]))
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
		i++;
	}
	return w;
}

char **ss(char *s, int (*f)(char))
{
	char **p;
	int i = 0, j, k = 0;


	if (!s)
		return (NULL);

	p = (char **)malloc(sizeof(char *) * (cw(s, f) + 1));
	if (p == NULL)
		return (NULL);

	i = 0;
	k = 0;
	while (i < cw(s, f))
	{
		j = 0;
		while (f(s[k]) && s[k])
			k++;
		p[i] = (char *)malloc(sizeof(char) * (len(&s[k], f) + 1));
		if (p[i] == NULL)
			return (NULL);
		while (!f(s[k]) && s[k])
			p[i][j++] = s[k++];
		p[i++][j] = '\0';
	}
	p[i] = 0;
	return (p);
}

char up(char c)
{
	return ((c >= 'A' && c <= 'Z') ? c : c - ('a' - 'A'));
}

int cmpabc(char *w1, char *w2)
{
	int i = -1;
	char t1, t2;

	while (w1[++i])
	{
		t1 = up(w1[i]);
		t2 = up(w2[i]);

		if (t1 != t2)
			return (t1 - t2);
	}
	return 0;
}

void sw(char **w, int i, int j)
{
	char *tmp;

	tmp = w[i];
	w[i] = w[j];
	w[j] = tmp;
}

void sortabc(char **w)
{
	int i = -1, j;

	while (w[++i])
	{
		j = i;
		while (w[++j])
		{
			if (cmpabc(w[i], w[j]) < 0)
				sw(w, i, j);
		}
	}
}

void sortlen(char **w, int (*f)(char))
{
	int i = -1;
	int l1, l2, j;

	while (w[++i])
	{
		l1 = len(w[i], f);
		j = i;
		while (w[++j])
		{
			l2 = len(w[j], f);
			if (l1 >= l2)
			{
				sw(w, i, j);
				l1 = len(w[i], f); // note!!!
			}
		}
	}
}

void pr(char **w, int (*f)(char))
{
	int i = -1;
	int tmp;
	int lastlen = -1;

	while (w[++i])
	{
		tmp = len(w[i], f);
		if (tmp == lastlen)
			write(1, " ", 1);
		else if (lastlen != -1)
			write(1, "\n", 1);
		write(1, w[i], tmp);
		lastlen = tmp;
		//free
	}
}

void oa(char *s)
{
	char **w;

	w = ss(s, bbb);
	//pr(w, bbb);
	sortabc(w);
	//pr(w, bbb);
	sortlen(w, bbb);
	pr(w, bbb);

}

int main(int ac, char **av)
{
	oa(av[1]);
}

// two sorts
// split words

