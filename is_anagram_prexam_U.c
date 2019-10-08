#include <stdio.h>

int is_anagram(char *a, char *b)
{
	int i;
	int vf[127] = {0}; // remember !!!

	i = 0;
	while (a[i]) // remember, you cycle through a and b, not vf[] with 127 elements.
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
	i = 0;
	while (i < 127)
	{
		if (vf[i] != 0)
			return (0);
		i++;
	}
	return 1;
}

int main()
{
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("abca", "bcab"));
}
