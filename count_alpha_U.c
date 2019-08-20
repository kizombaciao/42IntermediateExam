// Passed Moulinette 2019.05.19

#include <stdio.h>
#define TO_LOWER(c) (((c) >= 'a') ? (c) : (c) + ('a' - 'A'))

int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// a local copy of str (from the implicit index)
void	print_count(char *str)
{
	int count = 0;
	char c;

	c = TO_LOWER(*str);
	while (*str)
	{
		if (TO_LOWER(*str) == c)
		{
			*str = ' ';
			count++;
		}
		str++;
	}
	printf("%d%c", count, c);
}

void count_alpha(char *str)
{
	int first = 1;	
	while (*str)
	{
		if (is_alpha(*str))
		{
			if (first == 0)
				printf(", "); // trick:  put it before!!!
			print_count(str); // note, passing string, str is not at index = 0 !!!
			first = 0;
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
}