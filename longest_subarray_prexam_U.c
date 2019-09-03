// PASS!!!

#include <stdlib.h>
#include <stdio.h>

int ftstrlen(char *s)
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
	int n;

	n = c - '0';
	if (n % 2 == 1)
		return 1;
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
	int i = 0;

	while (s[i])
	{
		if (isodd(s[i]))
		{
			o++;
		}
		else
		{
			e++;
		}
		i++;
	}
	return (min(o, e));
}

int bal(char *s, int cl)
{
	int sum = 0;
	int i = 0;

	while(i < cl)
	{
		if (isodd(s[i]))
		{
			sum++;
		}
		else
			sum--;
		i++;
	}
	return sum;
}

char *ft_strndup(char *s, int len)
{
	int i = 0;
	char *p;

	p = (char *)malloc(sizeof(char) * (len + 1));
	p[len] = '\0';
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	return p;
}

// find max len
// find min odd even len
char    *longest_subarray(char *arr)
{
	int ml;
	int cl;
	int i = 0;

	ml = ftstrlen(arr);
	cl = 2 * moe(arr); // REMEMBER !!! 2 X

	while (bal(&arr[i], cl) != 0)
	{
		if (i + cl >= ml) // why equality ???
		{
			i = 0;
			cl--;
		}
		else
			i++; // way to find max within cl limit
	}
	return (ft_strndup(&arr[i], cl));
}
/*
int main()
{
	//char s1[] = "12435";
	//printf("%s\n", longest_subarray(s1));
	char str1[] = "1357913579024680213579";
	printf("79135790246802\n%s\n", longest_subarray(str1));
	char str2[] = "134";
	printf("\n34\n%s\n", longest_subarray(str2));
	char str3[] = "454";
	printf("\n45\n%s\n", longest_subarray(str3));
	char str4[] = "2010102";
	printf("\n0101\n%s\n", longest_subarray(str4));
	char str5[] = "2";
	printf("\n[blank]\n%s\n", longest_subarray(str5));
	char str6[] = "";
	printf("\n[blank]\n%s\n", longest_subarray(str6));
	//Moulinette test 6
	//char str7[] = "222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222202222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222223222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222122222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222220222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222253222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222322222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222292222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222022222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";
	//printf("\n2253\n%s\n", longest_subarray(str7));
}
*/
