















void sm(char **w, int ac)
{
    int k;
    int len = ft_strlen(w[0]);
    char *s = ft_strdup(w[0]);
    char *res = (char *)malloc(sizeof(char) * (len + 1));


    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j <= len - i; j++)
        {
            char *stem = ft_strsub(&s[i], j);
            for (k = 1; k < ac; k++)
            {
                if (ft_strstr(w[k], stem) == 0)
                    break;
            }
            if (k == ac)
            {
                if (ft_strlen(res) < ft_strlen(stem))
                    ft_strcpy(res, stem);
            }
            free(stem);
        }
    }
}