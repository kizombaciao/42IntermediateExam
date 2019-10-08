// examshell test this code given the new trick below !!!

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
    {
        ft_putchar(s[i]);
    }
}

int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]) ;
    return i;
}

char *ft_strdup(char *s, int len)
{
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    p[len] = 0;
    for (int i = 0; i < len; i++)
    {
        p[i] = s[i];
    }
    return p;
}

char *ft_strsub(char *s, int len)
{
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    p[len] = 0;

    for (int i = 0; i < len; i++)
    {
        p[i] = s[i];    
    }
    return p;
}

int ft_strstr(char *h, char *n)
{
    int i = 0;
    int j;

    if (!*n)
        return 0;

    while (h[i])
    {
        j = 0;
        while (h[i + j] == n[j])
        {
            j++;
            if (!n[j])
                return 1;
        }
        i++;
    }
    return 0;
}

void ft_strcpy(char *d, char *s)
{
    int i = 0;
    while (s[i])
    {
        d[i] = s[i];
        i++;
    }
    d[i] = 0;
}

void sm(char **w, int ac)
{
    char *stem;
    int k;

    int len = ft_strlen(w[0]);
    char *s = ft_strdup(w[0], len);
    char *res = (char *)malloc(sizeof(char) * (len + 1));

    // start
    for (int i = 0; i < len; i++)
    {
        // length
        for (int j = 1; j <= len - i; j++)
        {
            stem = ft_strsub(&s[i], j); // trick!!!
            for (k = 1; k < ac; k++)
            {
                if (ft_strstr(w[k], stem) == 0)
                    break;
            }
            if (k == ac)
            {
                if (ft_strlen(res) < ft_strlen(stem))
                {
                    ft_strcpy(res, stem); // ??
                }
            }
            free(stem);
        }
    }
    //free(w);
    ft_putstr(res);
}

/*
    ft_strdup
    ft_strsub
    ft_strstr
    ft_strcpy
*/

int main(int ac, char **av)
{
    if (ac >= 2) // greater than 2 ???
    {
        sm(&av[1], ac - 1);
    }
    ft_putchar('\n');
    return 0;
}

