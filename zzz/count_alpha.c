#include <stdio.h>
#include <unistd.h>

int isabc(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));

}

int lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	else
		return (c);
}

void ca2(char *s)
{
	int i = 0;
	int j = 1;
	char c;

	c = lower(s[i]);
	i++;
	while (s[i])
	{
		if (c == lower(s[i]))
		{
			s[i] = ' ';
			j++;
		}
		i++;
	}
	printf("%d%c", j, lower(c));
}

void ca(char *s)
{
	int sum = 0;
	int i = 0;
	int flag = 1;

	while (s[i])
	{
		if(isabc(s[i]))
		{
			if (flag == 0)
				printf(", ");
			ca2(&s[i]);
			flag = 0;
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
	write(1, "\n", 1);
}

// lower capital
// isabc