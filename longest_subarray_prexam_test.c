// lots of compiling errors, below

#include <stdlib.h>

int slen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return i;
}

int isodd(char c)
{
	if ((c - '0') % 2 == 1)
	{
		return 1;
	}
	return 0;
}

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

int moe(char *s)
{
	int o = 0;
	int e = 0;

	for (int i = 0; s[i]; i++)
	{
		if (isodd(s[i]))
			o++;
		else
			e++;
	}
	return(min(e, o));
}

int bal(char *s, int len)
{
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		if (isodd(s[i]))
			sum++;
		else
			sum--;
	}
	return sum
}

char *ft_strndup(char *s, int len)
{
	char *p = (char *)malloc(sizeof(char) * (len + 1));
	p[len] = '\0';

	for (int i = 0; i < len; i++)
	{
		p[i] = s[i];
	}
	return p;
}

char    *longest_subarray(char *arr)
{
	int maxlen = slen(arr);
	int cl = 2 * moe(arr);

	int st = 0;
	while (bal(arr[st], cl) != 0)
	{

		if (st + cl >= maxlen)
		{
			st = 0;
			cl--;
		}
		else
		{
			cl++;
		}
	}
	return(ft_strndup(arr[st], cl));
}

int main()
{
	printf("%s\n", longest_subarray("134"));
}

/*
= longest_sequence =============================================================
$> gcc -Wextra -Wall -Werror main.c longest_sequence.c -o user_exe
longest_sequence.c:53:12: error: expected ';' after return statement
        return sum
                  ^
                  ;
longest_sequence.c:74:13: error: incompatible integer to pointer conversion passing '\
char' to parameter of type 'char *'; take the address with & [-Werror,-Wint-conversio\
n]
        while (bal(arr[st], cl) != 0)
                   ^~~~~~~
                   &
longest_sequence.c:42:15: note: passing argument to parameter 's' here
int bal(char *s, int len)
              ^
longest_sequence.c:87:20: error: incompatible integer to pointer conversion passing '\
char' to parameter of type 'char *'; take the address with & [-Werror,-Wint-conversio\
n]
        return(ft_strndup(arr[st], cl));
                          ^~~~~~~
                          &
longest_sequence.c:56:24: note: passing argument to parameter 's' here
char *ft_strndup(char *s, int len)
                       ^
3 errors generated.

Could not compile 'user_exe'
Grade: 0

*/