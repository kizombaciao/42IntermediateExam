// TEST AGAIN!!!

#include <stdio.h>

int isabc(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int low(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return c;
}

int ca2(char *s)
{
	int i = 0;
	char c;
	int num = 1;

	c = low(s[i]);
	i++;
	while (s[i])
	{
		if (low(s[i]) == c)
		{
			s[i] = ' ';
			num++;
		}
		i++;
	}
	return num;
}

void ca(char *s)
{
	int i = 0;
	int num;
	int flag = 1;

	while (s[i])
	{
		if (isabc(s[i]))
		{
			num = ca2(&s[i]);
			if (flag == 1)
			{
                // remember s[i] also needs to be low !!!
				printf("%d%c", num, low(s[i]));
				flag =0; // remember this !!!
			}
			else
				printf(", %d%c", num, low(s[i]));
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ca(av[1]);
	}
	printf("\n");
	return 0;
}

