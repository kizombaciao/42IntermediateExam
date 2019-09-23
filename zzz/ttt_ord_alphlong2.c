
int nwords(char *s)
{
    int i = 0;
    int flag = 0;

    while (s[i])
    {
        if (isb(s[i]))
            flag = 0;
        else if (flag = 0)
        {
            flag = 1;
            num++;
        }
    
        i++;
    }
}

char **ft_split(char *s)
{
    int nw = nwords(s);


}

void pr(char **w)
{
    for (int i = 0; w[i]; i++)
    {
        cl = wlen(w[i]);
        if (i == 0)
        {
            last = cl;
            //
        }
        else if (last == cl)
        {
            // " "
            //
            last = cl;
        }
        else if (last != c)
        {
            // "\n"

        }
    }
}

void oa(char *s)
{
    ft_split(s);
    sortabc(s);
    sortlen(s);

}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        oa(av[1]);
    }
}

//////////////////////////////////////////////////

// ft_strdup
// ft_strsub
// ft_strstr
// ft_strcpy