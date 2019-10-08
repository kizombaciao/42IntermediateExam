// passed!!! as of 10/07

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // del

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *s)
{
	for (int i = 0; s[i]; i++)
	{
		ft_putchar(s[i]);
	}
}
int isb(char c)
{
	return (c == ' ' || c == '\t');
}
char low(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return c;
}


int cw(char *s)
{
    int i = 0;
    int len = 0;
    int flag = 0;

    while (s[i])
    {
        if (isb(s[i]))
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            len++;
            flag = 1;
        }
        i++;
    }
    return len;
}

int ft_wlen(char *s)
{
    int i = 0;
    while (s[i] && !isb(s[i]))
    {
        i++;
    }
    return i;
}

char **ft_split(char *s)
{
    int i, j, k;
    char **w;

//    printf("333a HEY\n");

    int len = cw(s);
    w = (char **)malloc(sizeof(char *) * (len + 1));
    w[len] = 0;
//    printf("333a %d\n", len);

    k = 0;
    for (i = 0; i < len; i++)
    {
        while (isb(s[k]) && s[k])
            k++;
        if (s[k])
        {
            int wlen = ft_wlen(&s[k]);
            w[i] = (char *)malloc(sizeof(char) * (wlen + 1));
            w[i][wlen] = 0;
        }
        j = 0;
        while (!isb(s[k]) && s[k])
        {
            w[i][j] = s[k];
            k++;
            j++;
        }
        //printf("222a %d %s\n", i, w[i]);

    }
    return w;
}

// trick !
int lower(char c)
{
    return ((c >= 'A' && c <= 'Z') ? c + 32 : c);
}

void p2(char **w)
{
	for (int i = 0; w[i] != 0; i++)
	{
		printf("%s\n", w[i]);
	}

}

void ft_swap(char **w, int i, int j)
{
    char *t;

    t = w[i];
    w[i] = w[j];
    w[j] = t;
}

int ft_strcmp(char *a, char *b)
{
    int i = 0;
    while (lower(a[i]) == lower(b[i]))
    {
        i++;
    }
    return (lower(a[i]) - lower(b[i]));
}

void sortabc(char **w)
{
    for (int i = 0; w[i] != 0; i++)
    {
        for (int j = i + 1; w[j] != 0; j++)
        {
            if (ft_strcmp(w[i], w[j]) < 0)
            {
                ft_swap(w, i, j);
            }
        }
    }
}

void sortlen(char **w)
{
    int l1, l2;

    for (int i = 0; w[i] != 0; i++)
    {
        l1 = ft_wlen(w[i]);
        for (int j = i; w[j] != 0; j++)
        {
            l2 = ft_wlen(w[j]);
            if (l1 >= l2)
            {
                ft_swap(w, i, j);
                l1 = ft_wlen(w[i]);
            }
        }
    }
}

void pr(char **w)
{
    int lastlen = 0;
    int cl;
    
    for (int i = 0; w[i] != 0; i++)
    {
        cl = ft_wlen(w[i]);
        if (lastlen == 0)
        {
            lastlen = cl;
            ft_putstr(w[i]);
        }
        else if (lastlen == cl)
        {
            ft_putchar(' ');
            ft_putstr(w[i]);
        }
        else if (lastlen != cl)
        {
            ft_putchar('\n');
            ft_putstr(w[i]);
            lastlen = cl;
        }
    }

}

void oa(char *s)
{
    char **w;
    w = ft_split(s);
    sortabc(w);
    sortlen(w);
    pr(w);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        oa(av[1]);
    }
    ft_putchar('\n');
}