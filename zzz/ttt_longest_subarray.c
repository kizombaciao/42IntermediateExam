










int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int isodd(char c)
{
    if (((c - '0') % 2) == 1)
        return 1;
    return 0;
}

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

int moelen(char *s)
{
    int o = 0;
    int e = 0;
    int i = 0;
    while (s[i])
    {
        if (isodd(s[i]))
            o++;
        else
            e++;
        i++;
    }
    return min(o, e);
}

char *ft_strndup(char *s, int len)
{
    char *p = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
    {
        p[i] = s[i];
    }
    p[i] = '\0';
    return p;
}

int bal(char *s, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (isodd(s[i]))
            sum++;
        else
        {
            sum--;
        }
    }
    return sum;
}

char    *longest_subarray(char *arr)
{
    int ml = ft_strlen(arr);
    int cl = 2 * moelen(arr);
    int st = 0;

    while (bal(&arr[st], cl) != 0)
    {
        if (st + cl >= ml)
        {
            st = 0;
            cl--;
        }
        else
            st++;
    }
    return ft_strndup(&arr[st], cl);
}