#include <stdio.h> // del

#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    int i = -1;
    while (s[++i])
        ft_putchar(s[i]);
}

int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]);
    return i;    
}

int ft_strcmp(char *a, char *b)
{
    int i = 0;
    while (a[i] && b[i] && (a[i] == b[i]))
    {
        i++;
    }
    return (a[i] - b[i]);
}

void bigfirst(char **s1, char**s2)
{
    char *a = *s1;
    char *b = *s2;

    if (*a == '-')
        a++;
    if (*b == '-')
        b++;

    if (ft_strlen(a) < ft_strlen(b) || (ft_strlen(a) == ft_strlen(b) && ft_strcmp(a, b) < 0)) 
    {
        char *t = *s1;
        *s1 = *s2;
        *s2 = t;
    }
}

// determine if we need to use subtract or not
// 3 things:
// 1. determine if substract
// 2. print '-'
// 3. skip forward one step
int checkneg(char **a, char **b)
{
    int flag = 0;

    if ((**a == '-' && **b != '-') || (**a != '-' && **b == '-'))
        flag = 1;
    if ((**a == '-' && **b == '-') || (**a == '-' && **b != '-'))
        ft_putchar('-');

    if (**a == '-')
        (*a)++;
    if (**b == '-')
        (*b)++;
    
    return flag;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

// find len and use it as index
// create memory for resutl
// do computation
void add(char *a, char *b)
{
    int l1 = ft_strlen(a) - 1;
    int l2 = ft_strlen(b) - 1;
    int l3 = max(l1, l2);
    char *c = (char *)malloc(sizeof(char) * (l3 + 1));
    
    int carry = 0;
    while (l1 >= 0 || carry) // 
    {
        carry += a[l1] - '0';
        if (l2 >= 0)
            carry += b[l2] - '0';
        c[l3] = carry % 10 + '0';
        carry /= 10;
        //printf("222a %d", carry);
        l1--;
        l2--;
        l3--;
    }
    ft_putstr(c);
}

void subtract(char *a, char *b)
{
    int l1 = ft_strlen(a) - 1;
    int l2 = ft_strlen(b) - 1;
    int l3 = max(l1, l2);
    char *c = (char *)malloc(sizeof(char) * (l3 + 1));
    
    int carry = 0;
    while (l1 >= 0)
    {
        carry += a[l1] - '0';
        if (l2 >= 0)
            carry -= b[l2] - '0';
        if (carry < 0)
        {
            carry -= 10;
            c[l3] = 10 - abs(carry % 10) + '0';
        }
        else
        {
            c[l3] = carry % 10 + '0';
        }
        carry /= 10;
        l1--;
        l2--;
        l3--;
    }
    ft_putstr(c);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        bigfirst(&av[1], &av[2]);
        if (checkneg(&av[1], &av[2]) == 1)
        {
            subtract(av[1], av[2]);
        }
        else
        {
            add(av[1], av[2]);
        }
    }
    ft_putchar('\n');
    return 0;
}