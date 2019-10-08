#include <stdio.h> // del

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int fill(int fd, char t[][1024])
{
    int lastlen = 0;
    int r, c;
    int i = 0;
    int bytes;
    char buf[1025] = {0};

    r = 0;
    c = 0;

    while ((bytes = read(fd, buf, 1024)) > 0)
    {
        buf[bytes] = 0;
        i = 0;
        while (buf[i] != 0)
        {
            if (buf[i] == '\n')
            {
                if (lastlen == 0)
                    lastlen = c;
                else if (lastlen != c)
                    return -1;
                t[r][c] = 0; // ?? b/c it's a string !!!
                r++;
                c = 0;
            }
            else if (buf[i] == '.' || buf[i] == 'X')
            {
                t[r][c] = buf[i];
                c++;
            }
            else // mandatory !!!
            {
                return -1;
            }        
            i++; // ?? don't forget !!!
        }
        t[r][c] = 0;
    }
    return 0;
}

void ff(char t[][1024], int r, int c, char idx)
{
    if (r < 0 || c < 0 || r >= 1024 || c >= 1024)
        return ;

    // careful, you had != instead of == below !
    if (t[r][c] != 'X' || t[r][0] == 0 || t[r][c] == 0)
        return;

    t[r][c] = idx;
    ff(t, r - 1, c, idx);
    ff(t, r + 1, c, idx);
    ff(t, r, c - 1, idx);
    ff(t, r, c + 1, idx);
}

void island(char t[][1024])
{
    char idx = '0';
    // is the [0] neccesar ???
    for (int i = 0; t[i][0] != 0; i++)
    {
        for (int j = 0; t[i][j] != 0; j++) // ??
        {
            if (t[i][j] == 'X')
            {
                ff(t, i, j, idx);
                //printf("222a %c ", idx);
                idx++;
            }
            ft_putchar(t[i][j]);
        }
        ft_putchar('\n');
    }
}

int main(int ac, char **av)
{
    int fd;
    char t[1024][1024];

    if (ac == 2)
    {
        if ((fd = open(av[1], O_RDONLY)) != -1)
        {
            if (fill(fd, t) != -1)
            {
                island(t);
            }
            else
            {
                        ft_putchar('\n');

                // pr
            }
            close(fd);
        }
        else
        {
                    ft_putchar('\n');

            // pri        
        }
    }
            ft_putchar('\n');

    // pr
    return 0;
}