// NOT PASSED!  SEE BELOW

//#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *s)
{
	while(*s)
	{
		ft_putchar(*s++);
	}
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
		|| c == '\f' || c == '\r' || c == ' ');
}
int	ft_atoi(const char *s)
{
	int n;
	int sign;

	while (ft_isspace(*s++))
		;
	s--;
	sign = 1;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	n = 0;
	while (ft_isdigit(*s))
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (sign * n);
}
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
		ft_swap(&s1, &s2); // after swap, does l1 need to be redefined ? yes
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);	
	}
	s1 = reverse(s1);
	s2 = reverse(s2);
	carry = 0;
	for (int i = 0; i < l2; i++)
	{
		int sum = n(s1[i]) + n(s2[i]) + carry;
		res = ft_strjoin(res, str(sum % 10));
		carry = sum / 10;

	}
	for (int i = l2; i < l1; i++)
	{
		int sum = n(s1[i]) + carry;
		res = ft_strjoin(res, str(sum % 10));
		carry = sum / 10;
	}
	if (carry)
		res = ft_strjoin(res, str(carry));
	res = reverse(res);

	return res;
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

char *find_diff(char *s1, char *s2)
{
	int l1 = ft_strlen(s1);
	int l2 = ft_strlen(s2);
	int carry;
	int sub;
	char *res = ""; // cause of seg default ? "" works but not NULL!
	// NULL does not work. Why "" works ???1234

	if (is_smaller(s1, s2)) // is s1 smaller than s2?
	{
		ft_swap(&s1, &s2);
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
	}	
	s1 = reverse(s1);
	s2 = reverse(s2);
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

void ia(char *s1, char *s2)
{
	char *t1;
	char *t2;
	int neg1 = 0;
	int neg2 = 0;
	char *res;

	if (s1[0] == '-')
	{
		neg1 = 1;
		t1 = ft_strdup(&s1[1]);
	}
	else
		t1 = ft_strdup(s1);

	if (s2[0] == '-')
	{
		neg2 = 1;
		t2 = ft_strdup(&s2[1]);
	}
	else
		t2 = ft_strdup(s2);

	if (neg1 == 0 && neg2 == 0)
	{
		res = find_sum(t1, t2);
		if (ft_atoi(res) == 0)
		{
			ft_putchar('0');
		}
		else
			ft_putstr(res);
	}
	else if (neg1 == 0 && neg2 == 1)
	{
		res = find_diff(t1, t2);
		if (ft_atoi(res) == 0)
		{
			ft_putchar('0');
		}
		else if (is_smaller(t1, t2))
		{
			res = ft_strjoin("-", res);
			ft_putstr(res);
		}
		else
			ft_putstr(res);
	}
	else if (neg1 == 1 && neg2 == 0)
	{
		res = find_diff(t1, t2);
		if (ft_atoi(res) == 0)
		{
			ft_putchar('0');
		}
		else if (is_smaller(t1, t2))
			ft_putstr(res);
		else
		{
			res = ft_strjoin("-", res);
			ft_putstr(res);
		}
	}
	else 
	{
		res = find_sum(t1, t2);
		if (ft_atoi(res) == 0)
		{
			ft_putchar('0');
		}
		else
		{
			res = ft_strjoin("-", res);
			ft_putstr(res);
		}	
	}
}

int main()
{
	char *s1 = "4894398524132130";
	char *s2 = "5906754239";

	ia(s1, s2);
	write(1, "\n", 1);
	return 0;
}
/*
int main(int ac, char **av)
{
	if (ac == 3)
	{
		ia(av[1], av[2]);
	}
	write(1, "\n", 1);
	return 0;
}
*/

/*
= Test 5 ===================================================
$> ./cansrgo1kjoxvbtr16kch6cd "4894398524132130" "5906754239"
$> diff -U 3 user_output_test5 test5.output | cat -e
--- user_output_test5   2019-09-08 17:30:28.000000000 -0700$
+++ test5.output        2019-09-08 17:30:28.000000000 -0700$
@@ -1 +1 @@$
-48944443886369$
+4894404430886369$

Diff KO :(
Grade: 0
 */



/*
= Test 1 ===================================================
$> ./hsmqwk9ucdtcjyp837mys7qs "0" "0"
$> diff -U 3 user_output_test1 test1.output | cat -e
--- user_output_test1   2019-09-08 14:34:35.000000000 -0700$
+++ test1.output        2019-09-08 14:34:34.000000000 -0700$
@@ -1 +1 @@$
-$
+0$

Diff KO :(
Grade: 0
 */

/*
int main()
{
	char *s1;
	char *s2;
	//char *res;

	s1 = ft_strdup("12345");
	s2 = ft_strdup("67");
	ia(s1, s2);

	s1 = ft_strdup("12345");
	s2 = ft_strdup("-67");
	ia(s1, s2);

	s1 = ft_strdup("12345");
	s2 = ft_strdup("-67890");
	ia(s1, s2);

	s1 = ft_strdup("-67");
	s2 = ft_strdup("12345");
	ia(s1, s2);

	s1 = ft_strdup("-67890");
	s2 = ft_strdup("12345");
	ia(s1, s2);

	s1 = ft_strdup("-67");
	s2 = ft_strdup("-12345");
	ia(s1, s2);
}
*/
