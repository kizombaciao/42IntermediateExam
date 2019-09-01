#include <stdio.h>

char low(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + (32));
	}
	return (c);
}

int isabc(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ca(char *s)
{
	int i = 0;
	char c;
	int num = 1;


	c = low(s[i]);
	i++;
	while (s[i])
	{
		if (c == low(s[i]))
		{
			s[i] = ' ';
			num++;
		}
		i++;
	}
	return (num);
}

void count_alpha(char *s)
{
	int i = 0;
	int num;
	int flag = -1;

	while (s[i])
	{
		if (isabc(s[i]))
		{
			num = ca(&s[i]);
			if (flag == -1)
			{
				printf("%d%c", num, low(s[i]));
				flag = 1;
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
		count_alpha(av[1]);
	}
	printf("\n");
	return (0);
}
