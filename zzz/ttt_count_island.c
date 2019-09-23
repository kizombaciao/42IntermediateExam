#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>



void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    for (int i = 0; s[i]; i++)
        ft_putchar(s[i]);
}

int fill(int fd, char t[][1024])
{
    int bytes = 0;
    char buf[1025] = {'\0'};
    int i;
    int r = 0, c = 0;
    int lastlen = 0;
    int cl;

    while (((bytes = read(fd, buf, 1024)) > 0)) // ???
    {
        buf[bytes] = '\0';
        i = 0;
        while (buf[i])
        {
            if (buf[i] == '\n') // ???
            {
                if (lastlen == 0)
                {
                    lastlen = c;
                }
                else if (lastlen != c) // ???
                {
                    return 0;
                }
                t[r][c] = '\0'; // ???
                r++;
                c = 0; // ???
            }
            else if (buf[i] == '.' || buf[i] == 'X')
            {
                t[r][c] = buf[i];
                c++; // ???
            }
            else
            {
                return 0; // ???
            }
            i++;
        }
    }
    t[r][c] = '\0'; // ???
    return 1;
}

// if
// if
// t
// ff
void ff(char t[][1024], int r, int c, char idx)
{
    // ???
    if (r < 0 || c < 0 || r >= 1024 || c >= 1024)
    {
        return;
    }
    if (t[r][0] == '\0' || t[r][c] == '\0' || t[r][c] != 'X')
    {
        return ;
    }
    t[r][c] = idx;
    ff(t, r + 1, c, idx);
    ff(t, r - 1, c, idx);
    ff(t, r, c + 1, idx);
    ff(t, r, c - 1, idx);
}

// two nested for loops
// if 
// ff
// idx
// ft_putchar
// ft_putchar
void island(char t[][1024])
{
    char idx = '0';

    for (int r = 0; t[r][0]; r++)
    {
        for (int c = 0; t[r][c]; c++)
        {
            if (t[r][c] == 'X') // ??
            {
                ff(t, r, c, idx);
                idx++; // ??
            }
            ft_putchar(t[r][c]); // ??
        }
        ft_putchar('\n'); // ??
    }
}

int main(int ac, char **av)
{
    int fd;
    char t[1024][1024];

    if (ac == 2)
    {
        if (fd = open(av[1], O_RDONLY))
        {
            if (fill(fd, t) != 0) // ???
            {
                island(t);
            }
            else
                ft_putchar("\n");
            close(fd); // ???
        }
        else
            ft_putchar("\n");
    }
    else
        ft_putchar("\n");
    return 0;
}