

int    volume_histogram(int *histogram, int size)
{
    int maxl[size];
    int maxr[size];


    maxl[0] = histogram[0];
    for (int i = 1; i < size; i++)
    {
        maxl[i] = max(histogram[i], maxl[i - 1]);
    }

    maxr[size - 1] = histogram[size - 1];
    for (int j = size - 2; j >= 0; j--)
    {
        maxr[j] = max(histogram[j], maxr[j + 1]);
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += min(maxl[i], maxr[i]) - histogram[i];
    }
    return sum;
}







/*
int    histogram[] = {1, 0, 2, 0, 2};
int    size = 5;
*/