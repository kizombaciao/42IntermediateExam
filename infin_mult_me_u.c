// NOT PASS, SEE BELOW !!!

//#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
void ft_putstr(char *s)
{
	while(*s)
	{
		ft_putchar(*s++);
	}
}
*/
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
char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len-- && s[i]) // does s[i] condition make sense ???
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (n--)
		((unsigned char *)s)[i++] = '\0';
}
void	*ft_memalloc(size_t size)
{
	void *p;

	if (!(p = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(p, size);
	return (p);
}

int n(char c)
{
	return (c - '0');
}

char str(int nb)
{
	return (nb + '0');
}

int max(int a, int b)
{
	return ((a > b ? a : b));
}

void pr(int *res, int size, int neg)
{
	//printf("NEG %d\n", neg);
	if (neg)
		ft_putchar('-');
	for (int i = size; i >= 0; i--)
	{
		ft_putchar(str(res[i]));
	}
	free(res);
}

void multiply(char *s1, int l1, char *s2, int l2, int neg)
{
	
	int i1 = 0;
	int i2 = 0;
	int maxlen = 0;

	int *res = (int *)malloc(sizeof(int) * (l1 + l2));
	ft_bzero((void *)res, sizeof(int) * (l1 + l2));

	for (int i = l1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = n(s1[i]);

		i2 = 0;
		for (int j = l2 - 1; j >= 0; j--)
		{
			int n2 = n(s2[j]);
			int sum = n1 * n2 + res[i1 + i2] + carry;        
			carry = sum / 10;
			res[i1 + i2] = sum % 10;
			maxlen = max(maxlen, i1 + i2);
			//printf("222a %d %d %d %d\n", sum, carry, res[i1+i2], maxlen);
			i2++;
		}
		if (carry > 0)
			res[i1 + i2] += carry;
		i1++;
	}
	pr(res, maxlen, neg);
}

void pre(char *s1, char *s2)
{
	int neg = 0;

	if ((ft_atoi(s1) == 0 || ft_atoi(s2) == 0))
	{
		ft_putchar('0');
	}
	else
	{
		if ((s1[0] == '-' || s2[0] == '-') && (s1[0] != '-' || s2[0] != '-'))
			neg = 1;
		if (s1[0] == '-')
		{
			s1 = ft_strsub(s1, 1, ft_strlen(s1));
		}
		if (s2[0] == '-')
		{
			s2 = ft_strsub(s2, 1, ft_strlen(s2));
		}
		int l1 = ft_strlen(s1);
		int l2 = ft_strlen(s2);
		if (l1 == 0 || l2 == 0)
			return;	
		multiply(s1, l1, s2, l2, neg);
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		pre(av[1], av[2]);
	}
	ft_putchar('\n');
	return 0;
}
/*
= Test 5 ===================================================
$> ./x0ph56r4594tg6jxuh855f4s "4894398524132130" "5906754239"
$> diff -U 3 user_output_test5 test5.output | cat -e
--- user_output_test5   2019-09-08 14:23:54.000000000 -0700$
+++ test5.output        2019-09-08 14:23:54.000000000 -0700$
@@ -1 +1 @@$
-8910009229772802673599070$
+28910009229772802673599070$

Diff KO :(
Grade: 0
 */
/*

Diff OK :D
= Test 3 ===================================================
$> ./e6a3gz6kiub4r66q4iaiaxt9 "0" "-2"
$> diff -U 3 user_output_test3 test3.output | cat -e
--- user_output_test3   2019-09-08 12:14:43.000000000 -0700$
+++ test3.output        2019-09-08 12:14:43.000000000 -0700$
@@ -1 +1 @@$
--0$
+0$

Diff KO :(
Grade: 0
 */

// NOT SURE HOW TO HANDLE THE ZEROS IN RES INT ARRAY ? using maxlen.

/*

	char *s1 = "-123";
	char *s2 = "-45";
	//printf("111a %s  %s\n", s1, s2);
	pre(s1, s2);

	char *r1 = "123";
	char *r2 = "45";
	//printf("111a %s  %s\n", r1, r2);
	pre(r1, r2);

	char *q1 = "-123";
	char *q2 = "45";
	//printf("111a %s  %s\n", q1, q2);
	pre(q1, q2);

	char *t1 = "123";
	char *t2 = "-45";
	//printf("111a %s  %s\n", t1, t2);
	pre(t1, t2); 
	
*/
