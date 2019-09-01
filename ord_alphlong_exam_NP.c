#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

int isb(char c)
{
	return (c == ' ' || c == '\t');
}

int countw(char *s)
{
	int i = 0;
	int num = 0;
	int flag = 0;

	while (s[i])
	{
		if (isb(s[i]) && s[i])
		{
			flag = 0;
			}
		if (!isb(s[i]) && flag == 0 && s[i])
		{
			flag = 1;
			num++;
		}
		i++;
	}
	return (num);
}

int wlen(char *s)
{
	int i = 0;

	while (!isb(s[i]))
	{
		i++;
	}
	return (i);
}

char **splitw(char *s)
{
	int i, j, k;
	int nw;
	int len;
	char **w;
	int flag = 0;

	nw = countw(s);
	//printf("222a %d\n", nw);
	w = (char **)malloc(sizeof(char *) * (nw + 1));
	w[nw] = 0;

	i = 0;
	while (s[i])
	{
		while (isb(s[i]) && s[i])
		{
			i++;
			flag = 0;
		}
		if (flag == 0 && !isb(s[i]) && s[i])
		{
			len = wlen(&s[i]);
			printf("444a  %d\n", len);
			flag = 1;
		}
		i++;
	}	

	return (NULL);
}


void ord_alphlong(char *s)
{
	char **w;

	w = splitw(s);



}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ord_alphlong(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
