

int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]);
    return i;
}

int isodd(char c)
{
    return (((c - '0') % 2) ? 1 : 0);
}

int moe(char *s)
{
    int o = 0;
    int e = 0;

    for (int i = 0; s[i]; i++)
    {
        if (isodd(s[i]))
            o++;
        else
            e++;
    }
    return (min(o, e));
}
int bal(char *p, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (isodd(p[i]))
            sum++;
        else
        {
            sum--;
        }
    }
    return sum;
}

char *ft_strndup(char *s, int len)
{
    char *p = (char *)malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
    {
        p[i] = s[i];
    }
    p[len] = '\0';
    return p;
}

char *ls(char *p)
{
    int maxlen = ft_strlen(p);
    int moelen = 2 * moe(p);
    // ?

    int i = 0;
    int cl = moelen;
    while (bal(&p[i], cl) != 0)
    {
        if (i + cl >= maxlen)
        {
            i = 0;
            cl--;
        }
        else
        {
            i++;
        }
    }
    return (ft_strndup(&p[i], cl));
}