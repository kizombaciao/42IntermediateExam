#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ABS(V) (((V) < 0) ? -(V) : (V))

int max(int a, int b)
{
    return (a > b ? a : b);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]);
    return i;
}
void ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}
///////////////////////////////////
char *init_str(int len)
{
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    int i = -1;
    while (++i < len)
        p[i] = '0';
    p[i] = '\0';
    return p;
}

void input_result(int value, char *out, int i)
{
    int carry = 0;

    while (value > 0 || carry > 0)
    {
        i--;
        value += carry;
        carry = (value % 10) + (out[i] - '0');
        out[i] = (carry % 10) + '0';
        carry /= 10;
        value /= 10;
    }
}

void pr(char *s, int len)
{
    int i = 0;
    while (i < len && s[i] == '0')
        i++;
    ft_putstr(&s[i]);
}

void infin_mult(char *s1, char *s2, char *out, int len)
{
    int l1 = ft_strlen(s1);
    int l2 = ft_strlen(s2);
    int i1 = l1;
    int i2 = l2;
    int res;
    int offset;

    while (--i1 >= 0)
    {
        i2 = l1;
        while (--i2 >= 0)
        {
            res = (s1[i1] - '0') * (s2[i2] - '0');
            offset = (l1 - i1 - 1) + (l2 - i2 - 1);
            input_result(res, out, len - offset); 
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *a = av[1];
        char *b = av[2];

        if (*a == '0' || *b == '0')
        {
            ft_putchar('0');
        }
        else
        {
            if ((*a == '-' && *b != '-') || (*a != '-' && *b == '-') )
                ft_putchar('-');
            if (*a == '-')
                a++;

            if (*b == '-')
                b++;

            int len = 1 + ft_strlen(a) + ft_strlen(b); // ???
            char *out = init_str(len);
            infin_mult(a, b, out, len);
            pr(out, len);
            free(out);
        }
    }
    ft_putchar('\n');
    return 0;
}
