

int fp(int *nb, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nb[i];
    }
    return sum;
}



int	find_pivot(int *arr, int n)
{
    int sum = fp(arr, n);
    int sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum - arr[i];
        if (sum == sum2)
            return i;

        sum2 = sum2 + arr[i];
    }
    return -1;

}
