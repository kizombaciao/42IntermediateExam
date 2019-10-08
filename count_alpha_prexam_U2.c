// i like this version

#include <stdio.h>
// low
// abc

int abc(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char low(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return c;
}

// how do i know that changes to s[] will be kept???
int ca2(char *s, char c)
{
	int i = 1;
	int d = 1;

	while (s[i])
	{
		if (c == low(s[i]))
		{
			s[i] = ' ';
			d++;
		}
		i++;
	}
	return d;
}

void ca(char *s)
{
	int i = 0;
	char c;
	int flag = 0;

	while (s[i])
	{
		if (abc(s[i]))
		{
			c = low(s[i]);
			int d = ca2(&s[i], c);
			if (flag == 0)
			{
				printf("%d%c", d, c);
				flag = 1;
			}		
			else
				printf(", %d%c", d, c);
		}
		i++;
	}
}

// ALWAYS REMEMBER LOWER !!!
int main(int ac, char **av)
{
	if (ac == 2)
	{
		ca(av[1]);
	}
	printf("\n");
	return 0;
}