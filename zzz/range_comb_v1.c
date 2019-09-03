
int fact(int n)
{
	int res = 1;

	for (int i = 1; i <= n; i++)
	{
		res *= i;
	}
	return res;
}

char *cts(int n)
{
	char *s;

	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';
	for (int i = 0; i < n; i++)
	{
		s[i] = i + '0';
	}
	return s;
}

permute(char *s, int **t, int n, int st, int end)
{
	static int idx = 0;

	if (st == end)
	{
		for (int j = 0; j < n; j++)
		{
			t[idx][j] = s[j] - '0';
		}
		idx++;
	}
	else
	{
		for (int i = st; i <= end; i++) // remember !!!
		{
			swap(&s[st], &s[i]);
			permute(s, t, n, st + 1, end);
			swap(&s[st], &s[i]);
		}
	}
}

int **rc(int n)
{
	char *s;
	int **t;

	if (n <= 0)
		return NULL;

	f = fact(n);
	t = (int **)malloc(sizeof(int *) * f);
	for (int i = 0; i < f; i++)
	{
		t[i] = (int *)malloc(sizeof(int) * n);
	}
	s = cts(n);
	t = permute(s, t, n, 0, n - 1);
	return t;
}

int main()
{
	char **t;

	t = rc(n);
}

// what does permute return? returns int **t


// factorial
// convert to string
