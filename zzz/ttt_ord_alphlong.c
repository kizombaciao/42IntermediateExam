



// num of words
int ft_wlen(char *s)
{
	int ii = 0;
	flag = 0;

	while (s[i])
	{
		if (isb(s[i]))
		{
			flag = 1;
		} 
		else if (flag == 1)
		{
			ii++;
			flag = 0;
		}
		i++;
	}
	return i;
}


char **ft_split(char *s)
{
	wl = ft_wlen(s);
	char **w = (char **)malloc(sizeof(char *) * (len + 1));
	w[len] = 0;
	int k = 0;
	int i = 0;
	while (i < wl)
	{
		while (isb(s[k]) && s[k])
		{
			k++;
		}
		len = ft_strlen(&s[k]);
		w[i] = (char *)malloc(sizeof(char) * (len + 1));
		w[i][len] = '\0';

		j = 0;
		while (isb(s[k]) && s[k])
		{
			w[i][j] = s[k];
			j++;
			k++;
		}
		i++;
	}
	return w;
}

void ft_swap(char **w, int i, int j)
{
	char *tmp;

	tmp = w[i]
	w[i] = w[j]
	w[j] = tmp
}


void sortabc(char **w)
{
	int i, j;

	for (i = 0; w[i] != 0; i++)
	{
		for (j = i + 1; w[j] != 0; j++)
		{
			if (cmp(w[i], w[j]) < 0)
				ft_swap(w, i, j);
		}
	}
}

void sortlen(char **w)
{
	int i, j;

	for (i = 0; w[i] != 0; i++)
	{
		l1 = ft_strlen(w[i]);
		for (j = i; w[j] != 0; j++)
		{
			l2 = ft_strlen(w[j]);
			if (l1 >= l2)
			{
				ft_swap(w, i, j);
				l1 = ft_strlen(w[i]);
			}

		}
	}
}

void pr(char **w)
{
	int lastlen;
	int curlen;

	while (w[i])
	{
		curlen = strlen(w[i]);
		if (i == 0)
		{
			lastlen = cl;
			//
		}
		else if (lastlen == curlen)
		{
			// p " "
		}
		else if (lastlen != curlen)
		{
			// p "\n"
			lastlen = curlen;
		}
		i++;
	}
}

void oa(char *s)
{
	char **w = ft_split(s);

	sortabc(w);
	sortlen(w);
	pr();


}

// lower case !!!

int main(int ac, char **av)
{
	oa(av[1]);

}