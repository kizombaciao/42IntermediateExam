

void    equation(int n)
{
    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (((a * 10) + b) + ((c * 10) + a) == n)
                {
                    printf("A = %d, B = %d, C = %d\n", a, b, c);
                }
            }
        }
    }
}