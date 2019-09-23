// pass!
//#include <stdio.h> // del

int is_anagram(char *a, char *b)
{
	int i;
	int vf[127] = {0};

	i = 0;
	while (a[i])
	{
		vf[(int)a[i]]++;
		i++;
	}
	i = 0;
	while (b[i])
	{
		vf[(int)b[i]]--;
		i++;
	}
	for (i = 0; i < 127; i++)
	{
		if (vf[i] != 0)
		{
			return 0;
		}
	}
	return 1;
}

/*
int main()
{
	printf("%d\n", is_anagram(" abcdef", "d efabc"));
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram("%.123?.", "?321.."));
	printf("%d\n", is_anagram("abca", "bcab"));
}
*/
