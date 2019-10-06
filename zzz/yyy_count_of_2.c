
int n2(int nb)
{
    int sum = 0;

    while (nb > 0)
    {
        if ((nb % 10) == 2)
        {
            sum++;
        }
        nb / 10;
    }
    return sum;
}

int		count_of_2(int n)
{
    int ct = 0;

    for (int i = 2; i <= n; i++)
    {
        ct += n2(i);
    }
    return ct;
}