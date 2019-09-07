#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

int is_smaller(char *s1, char *s2)
{
	int l1, l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);

	if (l1 < l2)
		return 1;
	if (l1 > l2)
		return 0;

	for (int i = 0; i < l1; i++)
	{
		if (s1[i] < s2[i])
			return 1;
		else if (s1[i] > s2[i])
			return 0;
	}
	return 0; // does this mean they are equal in length and value ???
}

void ft_swap(char **s1, char **s2)
{
	char *t;

	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

char *reverse(char *s)
{
	int k;
	char *p;

	int len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	p[len] = '\0';

	k = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		p[i] = s[k];
		k++;
	}
    return p;
}

int n(char c)
{
	return (c - '0');
}

int nlen(int nb)
{
	int i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return i;
}

char *str(int nb)
{
	char *p;
	int len = nlen(nb);

	p = (char *)malloc(sizeof(char) * (len + 1));
	p[len] = '\0';

	for (int i = len - 1; i >= 0; i--)
	{
		p[i] = nb % 10 + '0';
		nb /= 10;
	}
	return p;
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	while (n--)
		*(d)++ = *(s)++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		l1;
	size_t		l2;
	char		*s;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(s = malloc(sizeof(char *) * (l1 + l2 + 1))))
		return (NULL);
	ft_memcpy(s, s1, l1);
	ft_memcpy(s + l1, s2, l2);
	s[l1 + l2] = '\0';
	return (s);
}

char *find_diff(char *s1, char *s2)
{
	int l1 = ft_strlen(s1);
	int l2 = ft_strlen(s2);
	int carry;
	int sub;
	char *res = ""; // cause of seg default ???
	// NULL does not work. Why "" works ???1234

	if (is_smaller(s1, s2)) // ensure that s1 is not smaller than s2
	{
		ft_swap(&s1, &s2);
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
	}	
	printf("222a %s %s\n", s1, s2);

	s1 = reverse(s1);
	s2 = reverse(s2);

	printf("222b %s %s\n", s1, s2);

	carry = 0;
	for (int i = 0; i < l2; i++)
	{
		sub = n(s1[i]) - n(s2[i]) - carry;

		if (sub < 0)
		{
			sub += 10;
			carry = 1;
		}
		else
			carry = 0;
		res = ft_strjoin(res, str(sub));	
	}

	for (int i = l2; i < l1; i++)
	{
		sub = n(s1[i]) - carry;

		if (sub < 0)
		{
			sub += 10;
			carry = 1;
		}
		else
			carry = 0;
		res = ft_strjoin(res, str(sub));
	}

	res = reverse(res);

	return res;
}

// NOTES:
// NEED TO REMOVE THE NEG SIGN FROM THE STRING ???

int main(void)
{
//	char *s1 = av[1];
//	char *s2 = av[2];

	char *s1;
	char *s2;

	s1 = ft_strdup("1234");
	s2 = ft_strdup("456");
	printf("%s %s\n", s1, s2);

	printf("%s\n", find_diff(s1, s2));

	//printf("%s %s\n", s1, s2);
	//ft_swap(&s1, &s2);
	//printf("%s\n", find_diff(s1, s2));
	//printf("%s %s\n", s1, s2);
}


/*
//OR above: reverse() + ft_strcpy + ft_swapchar 

void ft_swapchar(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
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
char *reverse(char *s)
{
	int k;
	char *p;

	int len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	p[len] = '\0';
	p = ft_strcpy(p, s);

	for (int i = 0, j = len - 1; i < j; i++, j--) 
        ft_swapchar(&p[i], &p[j]); // NOTE, WE PASS ADDRESS HERE!   

    return p;
}
*/




/*
void ft_swapchar(char *a, char *b)
{
	char *t;

	t = a;
	a = b;
	b = t;
}
void reverse(char **s)
{
	int len = ft_strlen(*s);

	for (int i = 0; i < len / 2; i++)
	{
		ft_swapchar(&(*s)[i], &(*s)[len - 1 - i]);
	}
}
*/
















