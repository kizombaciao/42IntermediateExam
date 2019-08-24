#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

static size_t ft_count_words(char const *s, int (*func)(char))
{
	size_t i;
	size_t w;
	size_t flag;

	flag = 0;
	w = 0;
	i = 0;
	while (s[i])
	{
		if (is_blank(s[i]))
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
		i++;
	}
	return (w);
}

static size_t ft_word_len(char const *s, int (*func)(char))
{
	size_t l;

	l = 0;
	while (!is_blank(*s) && *s++)
		l++;
	return (l);
}

char **ft_strsplit(char const *s, int (*func)(char))
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	if (!(p = (char **)malloc(sizeof(char *) * (ft_count_words(s, func) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_count_words(s, func))
	{
		j = 0;
		while (is_blank(s[k]) && s[k])
			k++;
		if (!(p[i] = (char *)malloc(ft_word_len(&s[k], func) + 1)))
			return (NULL);
		while (!is_blank(s[k]) && s[k])
			p[i][j++] = s[k++];
		p[i++][j] = '\0';
	}
	p[i] = 0;
	return (p);
}

////////////////////////////////////
void print_words(char **words, int (*func)(char))
{
	int i = -1;
	int tmp;
	int last_len = -1;

	while (words[++i])
	{
		tmp = ft_word_len(words[i], func);
		if (tmp == last_len)
			write(1, " ", 1);
		else if (last_len != -1)
			write(1, "\n", 1);
		write(1, words[i], tmp);
		last_len = tmp;
		free(words[i]);
	}
}

// sort
void ft_swap(char **words, int i, int j)
{
	char *tmp;

	tmp = words[i];
	words[i] = words[j];
	words[j] = tmp;
}

char ft_upper(char c)
{
	return ((c >= 'A' && c <= 'Z') ? c : c - ('a' - 'A'));
}

int ft_cmpalph(char *s1, char *s2)
{
	char t1;
	char t2;
	int i = -1;

	while (s1[++i])
	{
		t1 = ft_upper(s1[i]);
		t2 = ft_upper(s2[i]);
		if (t1 != t2)
			return (t1 - t2);
	}
	return (0);
}

void ft_sortalph(char **words)
{
	int i = -1;
	int j;

	while (words[++i])
	{
		j = i;
		while (words[++j])
		{
			if (ft_cmpalph(words[i], words[j]) < 0)
				ft_swap(words, i, j);
		}
	}
}

void ft_sortlen(char **words, int (* func)(char))
{
	int i = -1;
	int j;
	int tmp;

	while (words[++i])
	{
		tmp = ft_word_len(words[i], func);
		j = i;
		while (words[++j])
		{
			if (tmp >= ft_word_len(words[j], func))
			{
				ft_swap(words, i, j);
				tmp = ft_word_len(words[i], func);
			}
		}
	}
}

///////////////////////////
void ord_alphlong(char *s)
{
	char **words;

	// NOTE, &is_blank also works !!!
	words = ft_strsplit(s, is_blank);
//	print_words(words);
	ft_sortalph(words);
//	print_words(words);
	ft_sortlen(words, is_blank);
	print_words(words, is_blank);

}

//////////////////////////////
int main(int ac, char **av)
{
	if (ac == 2)
	{
		ord_alphlong(av[1]);
	}
	write(1, "\n", 1);
}
