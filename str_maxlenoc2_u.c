#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0); // recursively
}

/*
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
Compare two blocks of memory:
Compares the first num bytes of the block of memory pointed 
by ptr1 to the first num bytes pointed by ptr2, 
returning zero if they all match or a value different 
from zero representing which is greater if they do not.
Notice that, unlike strcmp, 
the function does not stop comparing after finding a null character.
*/
int		ft_memcmp(void *s1, void *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((char *)s1)[i] - ((char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
const char * strstr ( const char * str1, const char * str2 );
char * strstr (       char * str1, const char * str2 );
Locate substring:
Returns a pointer to the first occurrence of str2 in str1, 
or a null pointer if str2 is not part of str1.
The matching process does not include the terminating null-characters, 
but it stops there.
*/
char	*ft_strstr(char *s1, char *s2)
{
    printf("555a %s  %s\n", s1, s2);
	while (*s1)
	{
        // if there is a match of s2 to s1, upto length of s2
		if (ft_memcmp(s1, s2, ft_strlen(s2)) == 0)
			return (s1);
		s1++;
	}
	return (0);
}

void	ft_strcpy(char *s1, char *s2)
{
	while ((*s1++ = *s2++))
		;
}

char	*ft_strdup(char *s)
{
	char *d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(d, s);
	return (d);
}

char 	*match_from_end(char *match, char *s)
{
	char *cpy;

	cpy = ft_strdup(match);
	while (*cpy)
	{
		printf("cpy: %s\n", cpy); // PRINT!
		if (ft_strstr(s, cpy))
        {
            printf("444a  %s  %s\n", s,  cpy);
			return (cpy);
        }
		cpy[ft_strlen(cpy) - 1] = 0; // Null is same as zero ???
	}
	return (cpy);
}

char	*match(char *match, char *s)
{
	char *max;
	char *cur_match;

	max = ft_strdup(""); // to malloc the string argument
	while (*match)
	{
        //printf("222a %s\n", match);
		cur_match = match_from_end(match, s);
        printf("\n333a  %s\n", cur_match);
		if (ft_strlen(cur_match) > ft_strlen(max))
			max = cur_match;
		match++;
        //printf("222b %s\n", match);
	}
	return (max);
}

void	maxlenoc(char **ss)
{
	char *cur_match;

	cur_match = ss[0];
    //printf("111a %s\n", ss[0]);
	ss++;
    //printf("111a %s\n", *ss);
	while (*ss)
	{
		cur_match = match(cur_match, *ss);
		ss++;
	}
	write(1, cur_match, ft_strlen(cur_match));
}

int		main(int ac, char **av)
{
	if (ac > 1)
		maxlenoc(++av);
	write(1, "\n", 1);
	return (0);
}

// https://github.com/yyang42/ft_exam_guide/blob/master/exercices/difficile/str_maxlenoc/v1/str_maxlenoc.c
