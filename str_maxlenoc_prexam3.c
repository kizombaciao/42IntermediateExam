// test this code if a chance.

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h> // del

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

char *ft_strdup(char *s)
{
    int i = -1;
    int len = ft_strlen(s);
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    while (s[++i])
    {
        p[i] = s[i];
    }
    p[i] = '\0';
    return p;
}

char *ft_strsub(char *s, int st, int len)
{
    int i = 0;
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    while (len-- && s[i])
    {
        p[i++] = s[st++];
    }
    p[i] = '\0';
    return p;
}

int ft_strstr(char *h, char *n)
{
    int i = -1;
    int j = 0;

    while (h[++i])
    {
        while (h[i + j] == n[j])
        {
            j++;
            if (!n[j])
                return 1;
        }
    }
    return 0;
}

void ft_strcpy(char *d, char *s)
{
    int i = -1;
    while (s[++i])
    {
        d[i] = s[i];
    }
    d[i] = '\0';
}

char *sm(int ac, char **av)
{
    int k;

    //printf("222a %s\n", av[0]);

    char *s = ft_strdup(av[0]);
    int len = ft_strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            char *stem = ft_strsub(s, i, j);
            //printf("222b %s\n", stem);
            
            for (k = 1; k < ac; k++)
            {
                if (ft_strstr(av[k], stem) == 0)
                {
                    break;
                }
            }
            if (k == ac)
            {
                if (ft_strlen(res) < ft_strlen(stem))
                {
                    ft_strcpy(res, stem);
                }
            }
            free(stem);
        }
    }
    free (s);
    return res;
}

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        char *p = sm(ac - 1, &av[1]);
        ft_putstr(p);
    }
    ft_putchar('\n');
}