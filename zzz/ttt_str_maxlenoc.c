




char *ft_strdup(char *s)
{
	char *p;

	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	int i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return p;
}

char *ft_strsub(char *s, int st, int len)
{
	char *p;
	int i = 0;

	while (i < len)
	{
		p[i] = s[i + st];
		i++;
	}
	p[i] = '\0';
	return p;
}


int ft_strstr(char *h, char *n)
{
	int i = 0;
	while (h[i])
	{
		j = 0;
		while (h[i + j] = n[j])
		{
			j++;
			if (!n[j])
				return (1);
		}
		i++;
	}
	return 0;
}

char *fs(int n, char **arr)
{
	char *s = ft_strdup(arr[0]);
	int len = ft_strlen(arr[0]);
	char *res = (char *)malloc(sizeof(char) * (len + 1));

	for (i = 0; i < len; i++)
	{
		for (j = 0; j <= len - i; j++)
		{
			stem =ft_strsub(s, i, j);
			for (k = 1; k < n; k++)
			{
				if (ft_strstr(arr[k], stem) == NULL)
					break;
			}
			if (k == n)
			{
				if (ft_strlen(stem) > ft_strlen(res))
				{
					ft_strcpy(res,stem);
				}
				free(stem);
			}
		}
	}
	free(s);
	return (res);
}

// ft_strdup
// ft_strsub
// ft_strstr
// ft_strcpy