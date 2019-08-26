#include <stdio.h>

int abc(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return(c + ('a' - 'A'));
	}
	return (c);
}

int ca(char *s)
{
	char c;
	int i = 1;

	c = lower(*s);		
	s++;
	while (*s)
	{
		if (c == lower(*s))
		{
			*s = ' ';
			i++;
		}
		s++;
	}
	return (i);
}

void count_alpha(char *s)
{
	int d;
	char c;
	int flag = 1;

	while (*s)
	{
		if (abc(*s))
		{		
			c = lower(*s);
			d = ca(s);
			if (flag == 1) // another way to use flag !!!
			{
				printf("%d%c", d, c);
				flag = 0;
			}
			else
			{
				printf(", %d%c", d, c);
			}
		}
		s++;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	count_alpha(av[1]);
	return (0);
}
