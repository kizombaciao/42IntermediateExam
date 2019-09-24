//#include <stdio.h> // del

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_strlen(char *s)
{
    int i = -1;
    while (s[++i]);
    return i;
}
void ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

int fill(int fd, char t[][1024])
{
    int bytes;
    char buf[1025] = {'\0'};
    int r = 0;
    int c = 0;
    int lastlen = 0;
    int i = 0;

    while ((bytes = read(fd, buf, 1024)) > 0)
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
                    //ft_putstr("error! 444");        
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
                //printf("error! 555  %c %c %d %d\n", buf[i], buf[i], r, c);        
                //if (buf[i] != '.')
                    //printf("hey\n");
                return -1;
            }
            i++;
        }
    }
    t[r][0] = '\0';
    return 1;
}

void ff(char t[][1024], int r, int c, char idx)
{
    if (r < 0 || c < 0 || r >= 1024 || c >= 1024)
        return ;

    if (t[r][c] != 'X' || t[r][0] == '\0' || t[r][c] == '\0')
        return ;

    t[r][c] = idx;
    ff(t, r - 1, c, idx);
    ff(t, r + 1, c, idx);
    ff(t, r, c - 1, idx);
    ff(t, r, c + 1, idx);
}

void island(char t[][1024])
{
    int i;
    int j;
    char idx = '0';

    for (i = 0; t[i][0] != '\0'; i++)
    {
        for (j = 0; t[i][j] != '\0'; j++)
        {
            if (t[i][j] == 'X')
            {
                ff(t, i, j, idx);
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
                //ft_putstr("error! 111");        
                ft_putchar('\n');                
            }
            close(fd);
        }
        else
        {
        //ft_putstr("error! 222");        
        ft_putchar('\n');        
        }
    }
    //ft_putstr("error! 333");        
    ft_putchar('\n');
    return 0;
}