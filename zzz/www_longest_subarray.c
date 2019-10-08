

char    *longest_subarray(char *arr)
{
    int i = 0;
    int cl;

    int maxl = ft_strlen(arr);
    int cl = 2 * ft_moe(arr);


    while (bal(&arr[i], cl) != 0)
    {
        if ((i + cl) >= maxl)
        {
            i = 0;
            cl--;
        }
        else
        {
            i++;
        }
    }
    return (ft_strdup(&arr[i], cl));
}
