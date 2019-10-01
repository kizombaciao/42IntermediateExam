#include <unistd.h>
#include <stdlib.h>

//#ifdef TEST
//#include <stdio.h>
//#endif

int        ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        ++i;
    return (i);
}

void    sort_args(char **big, char **smol)
{
    char *b = *big;
    char *s = *smol;
    char *temp;

    if (*b == '-')
        ++b;
    if (*s == '-')
        ++s;

    if (ft_strlen(b) > ft_strlen(s))
        return;
    else if (ft_strlen(s) > ft_strlen(b))
    {
        temp = *big;
        *big = *smol;
        *smol = temp;
        return;
    }

    while (*b && *b == *s)
    {
        ++b;
        ++s;
    }

    if (*b < *s)
    {
        temp = *big;
        *big = *smol;
        *smol = temp;
    }
}

void    infin_add(char *big, char *smol)
{
    int lenb = ft_strlen(big);
    int ib = lenb;
    int lens = ft_strlen(smol);
    int is = lens;
    int leno = lenb + 1;
    int io = leno;
    int carry = 0;

    char *out = malloc(sizeof(char) * (leno + 1));
    out[leno] = '\0';
    for (int i = 0; i < leno; ++i)
        out[i] = '0';

    while ((ib > 0 || is > 0 || carry != 0) /*&& io >= 0*/)
    {
        --io;
        if (ib > 0)
            carry += big[--ib] - '0';
        if (is > 0)
            carry += smol[--is] - '0';
        out[io] = (carry % 10) + '0';
        carry /= 10;
    }

    io = 0;
    while (out[io] == '0' && out[io + 1])
        ++io;
    write(1, out + io, ft_strlen(out + io));
}

void    infin_sub(char *big, char *smol)
{
    int lenb = ft_strlen(big);
    int ib = lenb;
    int lens = ft_strlen(smol);
    int is = lens;
    int leno = lenb + 1;
    int io = leno;
    int carry = 0;
    int result;

    char *out = malloc(sizeof(char) * (leno + 1));
    out[leno] = '\0';
    for (int i = 0; i < leno; ++i)
        out[i] = '0';

    while ((ib > 0 || is > 0 || carry != 0) /*&& io >= 0*/)
    {
        --io;
        result = carry;
        carry = 0;
        if (ib > 0)
            result += big[--ib] - '0';
        if (is > 0)
            result -= smol[--is] - '0';
        if (result < 0)
        {
            result += 10;
            carry = -1;
        }
        out[io] = (result % 10) + '0';
    }

    io = 0;
    while (out[io] == '0' && out[io + 1])
        ++io;
    write(1, out + io, ft_strlen(out + io));
}

int    main(int ac, char **av)
{
    if (ac == 3)
    {
        char *big = av[1];
        char *smol = av[2];
        int add_or_sub = 1;

        sort_args(&big, &smol);
//#ifdef TEST
//        printf("big:  %s\nsmol: %s\n", big, smol);
//#endif

        if ((*big == '-' || *smol == '-') && *smol != *big)
            add_or_sub = -1;

        if (*smol == '-')
            ++smol;
        if (*big == '-')
        {
            ++big;
            write(1, "-", 1);
        }

        if (add_or_sub == 1)
            infin_add(big, smol);
        else
            infin_sub(big, smol);
    }
    write(1, "\n", 1);
}