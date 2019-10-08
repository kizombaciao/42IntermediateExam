#include <stdio.h>

// lower!!!

char lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int abc(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return 1;
    }
    return 0;
}

// how do i know that changes to s[] will be kept???
int ca2(char *s, char c)
{
    int num = 0;
    int i = 0;
    while (s[i])
    {
        if (lower(s[i]) == c)
        {
            num++;
            s[i] = ' ';
        }
        i++;
    }
    return num;
}

int ca(char *s)
{
    int num = 0;
    char c;
    int i = 0;

    while (s[i])
    {
        if (abc(s[i]))
        {
            c = lower(s[i]);
            num = ca2(&s[i], c);
            //
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ca(av[1])
    }
    //
}