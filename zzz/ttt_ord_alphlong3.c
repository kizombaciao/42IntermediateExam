#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int isb(char c)
{
    return (c == ' ' || c == '\t');
}

// check ?
int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]) ;
    return i;
}

// correct ?
int nwords(char *s)
{
    int nw = 0;
    int i = 0;
    int flag = 0;

    while (s[i])
    {
        if (isb(s[i]))
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            flag = 1;
            nw++;
        }
        i++;
    }
    return nw;
}

char **split(char *s)
{
    int nw = nwords(s);
    char **p;

    p = (char **)malloc(sizeof(char *) * (nw + 1));
    p[nw] = 0;

    int k = 0;
    int i = 0;
    while (i < nw)
    {
        while (isb(s[k]) && s[k])
            k++;

        int len = ft_strlen(&s[k]);
        p[i] = (char *)malloc(sizeof(char) * (len + 1));
        p[len] = "\0";
        int j = 0;
        while (!isb(s[k]) && s[k])
        {
            p[i][j] = s[k];
            k++;
            j++;
        }
        i++;
    }
    return p;
}

// don't forget lower case!!!
int ft_strcmp(char *a, char *b)
{
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
    {
        i++;
    }
    return (a[i] - b[i]);
}

void ft_swap(char **w, int i, int j)
{
    char *tmp = w[i];
    w[i] = w[j];
    w[j] = tmp;
}

void sortabc(char **p)
{
    for (int i = 0; p[i] != 0; i++) // ??? limit 
    {
        for (int j = i + 1; p[j] != 0; j++)
        {
            if (ft_strcmp(p[i], p[j]) < 0)
            {
                ft_swap(p, i, j);
            }
        }
    }
}

void sortlen(char **p)
{
    for (int i = 0; p[i] != 0; i++)
    {
        int len1 = ft_strlen(p[i]);
        for (int j = i; p[j] != 0; j++)
        {
            int len2 = ft_strlen(p[j]);
            if (ft_strlen(p[i]) > ft_strlen(p[j]))
            {
                ft_swap(p, i, j);
                int len1 = ft_strlen(p[i]);
            }
        }
    }
}

void pr(char **p)
{
    int lastlen = 0;
    int i = 0;

    while (p[i])
    {
        int len = ft_strlen(p[i]);
        if (lastlen == 0)
        {
            printf("%s", p[i]);
            lastlen = len;
        }
        else if (lastlen == len)
        {
            printf(" %s", p[i]);
        }
        else if (lastlen != len)
        {
            printf("\n");
            printf("%s", p[i]);
            lastlen = len;
        }
        i++;
    }
}

void oa(char *s)
{
    char **p = split(s);
    sortabc(p);
    sortlen(p);
    pr(p);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        oa(av[1]);
    }
    write(1, "\n", 1);
    return 0;
}