#include <stdio.h>
#include <stdlib.h>




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

// probably don't need it to be this generalized
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

char *find_sum(char *s1, char *s2)
{
	int l1 = ft_strlen(s1);
	int l2 = ft_strlen(s2);
	int carry;
	char *res = "";
	
	if (l1 < l2)
	{
		ft_swap(&s1, &s2); // after swap, does l1 need to be redefined ???
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);	
	}
	printf("222a %s %s\n", s1, s2);

	s1 = reverse(s1);
	s2 = reverse(s2);
	printf("222b %s %d %s %d\n", s1, l1, s2, l2);

	carry = 0;
	for (int i = 0; i < l2; i++)
	{
		int sum = n(s1[i]) + n(s2[i]) + carry;
		printf("33a %c %c %d\n", s1[i], s2[i], sum);

		res = ft_strjoin(res, str(sum % 10));
		carry = sum / 10;
		printf("33b %s %d\n", res, carry);

	}

	for (int i = l2; i < l1; i++)
	{
		int sum = n(s1[i]) + carry;
		res = ft_strjoin(res, str(sum % 10));
		carry = sum / 10;
	}

	if (carry)
		res = ft_strjoin(res, str(carry));
	printf("222a %s\n", res);

	res = reverse(res);
	printf("222b %s\n", res);

	return res;
}


int main()
{
	char *s1;
	char *s2;
	char *res;

	s1 = ft_strdup("67");
	s2 = ft_strdup("12345");
	printf("%s %s\n", s1, s2);

	res = find_sum(s1, s2);
	printf("111a %s\n", res);
}
