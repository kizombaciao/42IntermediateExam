
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]) ;
    return i;
}

int isodd(char c)
{
    if (((c - '0') % 2) == 1)
        return 1;
    else
    {
        return 0;
    }
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int ft_moe(char *s)
{
    int i = 0;
    int e = 0;
    int o = 0;

    while (s[i])
    {
        if (isodd(s[i]))
            o++;
        else
        {
            e++;
        }
        i++;
    }
    return (min(o, e));
}

int bal(char *s, int cl)
{
    int sum = 0;
    for (int i = 0; i < cl; i++)
    {
        if (isodd(s[i]))
        {
            sum++;
        }
        else
        {
            sum--;
        }
    }
    return sum;
}

char *ft_strndup(char *s, int cl)
{
    char *p = (char *)malloc(sizeof(char) * (cl + 1));


    for (int i = 0; i < cl; i++)
    {
        p[i] = s[i];
    }
    p[cl] = 0;
    return p;
}

char    *longest_subarray(char *arr)
{
    int i = 0;
    int maxl = ft_strlen(arr);
    int cl = 2 * ft_moe(arr);

    // no need to create storage!!! 
    //char *p = (char *)malloc(sizeof(char) * (moel + 1));

    while (bal(&arr[i], cl) != 0)
    {
        if (i + cl >= maxl)
        {
            i = 0;
            cl--;
        }
        else
        {
            i++;
        }
    }
    return (ft_strndup(&arr[i], cl));
}

int main()
{
    char s1[] = "1357913579024680213579";
	printf("%s\n", longest_subarray(s1));
}