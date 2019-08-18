// can see ord_alphlong directory for compiled and executable.
// https://github.com/Julow/exam-00/blob/master/ex03/ft_sort.c

#include <unistd.h>
#include <stdio.h> // delete

int			main(int argc, char **argv)
{
	char		**words;

	if (argc == 2)
	{
		words = ft_splitword(argv[1]);
		ft_sortalph(words);
		ft_sortlen(words);
		print_words(words);
		free(words);
	}
	write(1, "\n", 1);
	return (0);
}

// USE THIS ONE !!!

// https://github.com/Julow/exam-00/tree/master/ex03

/* TO SHOW THAT INCREMENTING WORDS VARIABLE BY 1 MOVES TO THE NEXT WORD

        while (*words)
        {
            printf("111a %s\n", *words);
            words++;
        }
*/


// ft_sort.c
////////////////////////////////////////////////
void		ft_strsswap(char **strs, int i1, int i2)
{
	char		*tmp;

	tmp = strs[i1];
	strs[i1] = strs[i2];
	strs[i2] = tmp;
}

char		ft_upper(char c)
{
	return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

int			ft_stralphcmp(char *s1, char *s2)
{
	char		tmp1;
	char		tmp2;
	int			i;

	i = -1;
	while (s1[++i] != '\0')
	{
		tmp1 = ft_upper(s1[i]);
		tmp2 = ft_upper(s2[i]);
		if (tmp1 != tmp2)
			return (tmp1 - tmp2);
	}
	return (0);
}

void		ft_sortalph(char **strs) // !!!
{
	int			i;
	int			j;

	i = -1;
	while (strs[++i] != NULL)
	{
		j = i;
		while (strs[++j] != NULL)
		{
			if (ft_stralphcmp(strs[i], strs[j]) < 0)
				ft_strsswap(strs, i, j);
		}
	}
}

void		ft_sortlen(char **strs)
{
	int			i;
	int			j;
	int			tmp;

	i = -1;
	while (strs[++i] != NULL)
	{
		tmp = ft_strlen(strs[i]);
		//printf("\n222a %d %d", tmp, i);
		j = i;
		while (strs[++j] != NULL)
		{
			if (tmp >= ft_strlen(strs[j]))
			{
				ft_strsswap(strs, i, j);
				tmp = ft_strlen(strs[i]); // because we swappd words in strs!!!
				//printf("\n222b %d %d", tmp, i);
			}
		}
	}
}


// ft_splitword()
///////////////////////////////////
int			ft_isspace(char c)
{
	return ((c == ' ' || c == '\t') ? 1 : 0);
}

int			skip_spaces(char *str)
{
	int			i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

int			skip_word(char *str, char **word)
{
	int			i;
	int			len;
	char		*tmp;

    // first, get word length
	i = 0;
	while (str[i] != '\0' && !ft_isspace(str[i]))
		i++;
	len = i;
    // 2nd, malloc
	tmp = (char*)malloc(sizeof(char) * (i + 1));
	tmp[i] = '\0';
    // 3rd, copy word into word 2d array
	while (--i >= 0)
		tmp[i] = str[i];
	(*word) = tmp; // note, only one asterisk!!!
	return (len);
}

int			count_words(char *str)
{
	int			words;
	int			i;

	words = 0;
	i = skip_spaces(str);
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			words++;
			i += skip_spaces(str + i);
		}
		i++;
	}
	if (i > 0)
		words++;
	return (words);
}

char		**ft_splitword(char *str)
{
	char		**words;
	int			i;
	int			len;

	words = (char**)malloc(sizeof(char*) * (count_words(str) + 1));
	i = skip_spaces(str);
	len = 0;
	while (str[i] != '\0')
	{
		i += skip_word(str + i, words + len);
		len++;
		i += skip_spaces(str + i);
	}
	words[len] = NULL;
	return (words);
}

// ft_print_words.c
////////////////////////////////

int			ft_strlen(char *str)
{
	int			len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void		print_words(char **words)
{
	int			i;
	int			tmp;
	int			last_len;

	i = -1;
	last_len = -1;
	while (words[++i] != NULL)
	{
		tmp = ft_strlen(words[i]);
		if (tmp == last_len)
			write(1, " ", 1);
		else if (last_len != -1)
			write(1, "\n", 1);
		write(1, words[i], tmp);
		last_len = tmp;
		free(words[i]);
	}
	// also, free words ???
}


// ord_alphlong.h
//////////////////////////////
#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

# include <stdlib.h>

int			ft_isspace(char c);
int			skip_spaces(char *str);
int			skip_word(char *str, char **word);
int			count_words(char *str);
char		**ft_splitword(char *str);

int			ft_strlen(char *str);
void		print_words(char **words);

void		ft_strsswap(char **strs, int i1, int i2);
char		ft_upper(char c);
int			ft_stralphcmp(char *s1, char *s2);
void		ft_sortalph(char **strs);
void		ft_sortlen(char **strs);

#endif

