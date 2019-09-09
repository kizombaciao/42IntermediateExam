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
