// https://www.geeksforgeeks.org/longest-common-substring-array-strings/

// C++ program to find the stem of given list of 
// words 
//#include <bits/stdc++.h> 
//using namespace std; 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strcpy(char *dst, const char *src)
{
	char *p;

	p = dst;
	while ((*p++ = *src++))
		;
	*(--p) = '\0';
	return (dst);
}
char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*d;

	len = ft_strlen(s);
	if (!(d = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[i])
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
char *ft_strstr(const char *hay, const char *needle)
{
	int i;
	int j;

	if (!*needle)
		return ((char *)hay);
	i = 0;
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return (&((char *)hay)[i]);
		}
		i++;
	}
	return (NULL);
}
// function to find the stem (longest common 
// substring) from the string array 
char *findstem(int n, char **arr) 
{ 
	// Determine size of the array 
	//int n = arr.size(); 
	// Take first word from array as reference 
	int i, j, k;
    char *s;
	int len;
    char *stem;
	//char *p;

    s = ft_strdup(arr[0]); // using malloc on first string to create s
    len = ft_strlen(s); 
	//printf("222a %s  %d\n", s, len);
	
	char *res = (char *)malloc(sizeof(char) * (len + 1)); 

	for (i = 0; i < len; i++) 
	{ 
		// not sure why the author had 'j = i + 1'
		// it should be j <= len - i, instead of j <= len
		for (j = 1; j <= len - i; j++) 
		{ 
			// generating all possible substrings 
			// of our reference string arr[0] i.e s 
			// substring of s from i for length j
			stem = ft_strsub(s, i, j);
			//printf("333a %d %d %s\n", i, j, stem);
			for (k = 1; k < n; k++) 
			{ 
				// Check if the generated stem is 
				// common to to all words 
				// return NULL if stem is not within string k
				if (ft_strstr(arr[k], stem) == NULL) 
				//if (find(arr.begin(), arr.end(), stem) == arr.end() 
					break; 
			} 

			// If current substring is present in 
			// all strings and its length is greater 
			// than current result 
			if (k == n && ft_strlen(res) < ft_strlen(stem)) 
				ft_strcpy(res, stem); // copy from stem to res
			free(stem);
		} 
	}
	free(s); 
	return (res); 
} 
int main(int ac, char **av) 
{ 
	//char s[] = {"grace", "graceful", "disgraceful", 
	//				"gracefully"}; 
    char *p;

	//printf("%d\n", ac);

    if (ac >= 2)
    {
        p = findstem(ac - 1, &av[1]); 
		ft_putstr(p);
    }
	ft_putchar('\n');
}
// This code is contributed by 
// sanjeev2552 