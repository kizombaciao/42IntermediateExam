//#include <stdio.h>

int	is_anagram(char *a, char *b)
{
	int vf[127] = {0};

	for (int i = 0; a[i]; i++)
	{
		vf[(int)a[i]]++;
	}
	for (int i = 0; b[i]; i++)
	{
		vf[(int)b[i]]--;
	}
	for (int i = 0; i < 127; i++)
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
	printf("%d\n", is_anagram("ab c", "abc"));	
	
}
*/