#include <stdio.h> // del
#include <stdlib.h>
#include <unistd.h>
#define MAX 100

int slen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return i;
}

char *r(char *s)
{
	char *p;
	int len;
	int k;

	len = slen(s);
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

char *ftstrdup(char *s)
{
	char *p;
	int len;
	int i = 0;

	len = slen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	return p;
}

int n(char c)
{
	return (c - '0');
}

void ft_putchar(char c)
{
	write(1, &c, 1);
} 

void ft_putnum(int i)
{
	char c;

	c = '0' + i;
	ft_putchar(c);
}

void pr(int num[MAX])
{
	int flag = 1;

	// i++ error can cause undecipherable bug!!!
	for (int i = MAX - 1; i >=0; i--)
	{
		if (num[i] > 0 && flag == 1)
		{
//			printf("%d", num[i]);
			ft_putnum(num[i]);
			flag = 0;
		} else if (flag == 0)
		{
//			printf("%d", num[i]);
			ft_putnum(num[i]);
		}
	}
	ft_putchar('\n');
//	ft_putchar('\n');
}

void add1(char *s1, char *s2)
{
	int l1, l2;
	int diff;
	int num[MAX] = {0};
	int carry = 0;

	l1 = slen(s1);
	l2 = slen(s2);

	if (l1 > l2)
	{
		diff = l1 - l2;
		for (int i = 0; i < diff; i++)
		{
			num[i] = (n(s1[i]) + n(s2[i]) + carry) % 10;
			carry =  (n(s1[i]) + n(s2[i]) + carry) / 10;
		}
		for (int i = diff; i <= l1; i++)
		{
			num[i] = (n(s1[i]) + carry) % 10;
			carry = (n(s1[i]) + carry) / 10;
		}
		pr(num);
	}
	else
	{
		diff = l2 - l1;
		for (int i = 0; i < diff; i++)
		{
			num[i] = (n(s2[i]) + n(s1[i]) + carry) % 10;
			carry =  (n(s2[i]) + n(s1[i]) + carry) / 10;
		}
		for (int i = diff; i <= l2; i++)
		{
			num[i] = (n(s2[i]) + carry) % 10;
			carry = (n(s2[i]) + carry) / 10;
		}
		pr(num);
	}
}

void sub(char *s1, char *s2)
{
	int l1, l2;
	int diff;
	int num[MAX] = {0};
	int carry = 0;

	l1 = slen(s1);
	l2 = slen(s2);

	if (l1 > l2)
	{
		diff = l1 - l2;
		for (int i = 0; i < diff; i++)
		{
			if ((n(s1[i]) + carry) >= n(s2[i]))
			{
				num[i] = (n(s1[i]) - n(s2[i]) + carry) % 10;
				carry = 0;
			}
			else
			{
				num[i] = (10 + n(s1[i]) - n(s2[i]) + carry) % 10;
				carry =  -1;				
			}
		}
		for (int i = diff; i <= l1; i++)
		{
			num[i] = (n(s1[i]) + carry) % 10;
			carry = (n(s1[i]) + carry) / 10;
		}
		pr(num);
	}
}

void ia(char *s1, char *s2)
{
	char *t1;
	char *t2;
	char *rt1;
	char *rt2;
	int neg1 = 0;
	int neg2 = 0;
	
	if (s1[0] == '-')
	{
		neg1 = 1;
		t1 = ftstrdup(&s1[1]);
	}
	else
		t1 = ftstrdup(s1);

	if (s2[0] == '-')
	{
		neg2 = 1;
		t2 = ftstrdup(&s2[1]);
	}
	else
		t2 = ftstrdup(s2);

	rt1 = r(t1);
	rt2 = r(t2);
	//printf("%d  %s\n", neg1, rt1);
//	printf("%d  %s\n", neg2, rt2);

	if (neg1 == 0 && neg2 == 0)
	{
		add1(rt1, rt2);
	}
	else if (neg1 == 0 && neg2 == 1)
	{
		sub(rt1, rt2);
	}
	else if (neg1 == 1 && neg2 == 0)
	{

	}
	else 
	{

	}
}

int main(int ac, char **av)
{
	//printf("\n\n\nhey111a\n");
	
	if (ac == 3)
	{
		ia(av[1], av[2]);
	}
//	write(1, "\n", 1);
	return 0;
}


