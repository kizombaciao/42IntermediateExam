void ff(char **a, t_point size, int y, int x, char c)
{
    if (y < 0 || x < 0 || y >= size.y || x >= size.x || a[y][x] != c)
    {
        return;
    }
    if (a[y][x] == c)
    {
        a[y][x] = 'F';
        ff()
    }
}