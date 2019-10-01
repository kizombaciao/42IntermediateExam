#include <fcntl.h>

int fill(int fd, int t[][1024])
{
    int bytes;
    char buf[1025] = {'\0'};
    int lastlen = 0;
    int cl;
    int i, r = 0, c = 0;

    while (bytes = read(fd, buf, 1024) > 0)
    {
        buf[bytes] = '\0';
        i = 0;
        while (buf[i] != '\0')
        {
            if (buf[i] == '\n')
            {
                if (lastlen == 0)
                {
                    lastlen = c;
                }
                else if (lastlen != c)
                {
                    return -1;
                }
                t[r][c] = '\0';
                r++;
                c = 0;
            }
            else if (buf[i] == '.' || buf[i] == 'X')
            {
                t[r][c] = buf[i];
                c++;
            }
            else
            {
                return -1;
            }
            i++;
        }
    }
    t[r][0] = '\0';
    return 1;
}

void ff(int t[][1024], int r, int c, char idx)
{
    if (r < 0 || c < 0 || r >= 1024 || c >= 1024)
    {
        return ;
    }
    if (t[r][c] != 'X' || t[r][0] == 0 || t[r][c] == 0)
        return ;
        
    t[r][c] = idx;
    ff(t, r - 1, c, idx);
    ff(t, r + 1, c, idx);
    ff(t, r, c - 1, idx);
    ff(t, r, c + 1, idx);
}

void island(char t[][1024])
{
    char idx = '0';

    for (int r = 0; t[r][0] != 0; r++)
    {
        for (int c = 0; t[r][c] != 0; c++)
        {
            if (t[r][c] == 'X')
            {
                ff(t, r, c, idx);
                idx++;
            }
            // putchar(t[][])
        }
        // putchar
    }
}

int main(int ac, char **av)
{
    int fd;
    char t[1024][1024];

    if (ac == 2)
    {
        if (fd = open(av[1], O_RDONLY) != -1)
        {
            if (fill(fd, t) != -1)
            {
                island(t);
            }
            else
            {
                //putchar
            }
            close(fd);            
        }
        else
        {
            // putchar
        }
    }
    else
    {
        ft_putchar('\n');
    }
    // re
}