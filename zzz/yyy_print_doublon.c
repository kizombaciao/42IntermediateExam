

void	print_doublon(int *a, int na, int *b, int nb)
{
    int i = 0, j = 0;

    while (i < na && j < nb)
    {
        if (a[i] == b[j])
        {
            //
            i++;
            j++;
        }
        if (a[i] > b[j])
        {
            j++;
        }
        if (a[i] < b[j])
        {
            i++;
        }
    }
    //
}
