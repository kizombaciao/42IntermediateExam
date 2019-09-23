#include <unistd.h>
#include <fcntl.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int fill(int fd, char t[][1024])
{
    int bytes;
    char buf[1025] = {'\0'}; // ??
    int r = 0, c = 0;
    int linelen = 0;

    while ((bytes = read(fd, buf, 1024)) > 0) // ??
    {
        buf[bytes] = '\0';
        int i = 0;
        while (buf[i] != '\0') // ??
        {
            if (buf[i] == '\n')
            {
                if (linelen == 0)
                {
                    linelen = c;
                }
                else if (linelen != c)
                {
                    return -1; // ??? okay?
                }
                c = 0;
                r++;
                t[r][c] = '\0';
            }
            else if (buf[i] == '.' || buf[i] == 'X')
            {
                t[r][c] = buf[i];
                c++;
            }
            else
            {
                return -1; //???
            }
            i++;
        }
    }
    t[r][0] = '\0'; // is it the same as 0 ???
    return 1;
}

void ff(char t[][1024], int r, int c, char idx)
{
    if (r < 0 || c < 0 || r >= 1024 || c >= 1024)
    {
        return ;
    }
    if (t[r][c] != 'X' || t[r][0] == '\0' || t[r][c] == '\0')
    {
        return ;
    }
    t[r][c] = idx;
    ff(t, r - 1, c, idx);
    ff(t, r + 1, c, idx);
    ff(t, r, c - 1, idx);
    ff(t, r, c + 1, idx);
}

void island(char t[][1024])
{
    char idx = '0';

    for (int r = 0; t[r][0] != '\0'; r++)
    {
        for (int c = 0; t[r][c] != '\0'; c++)
        {
            if (t[r][c] == 'X')
            {
                ff(t, r, c, idx);
                idx++;
            }
            ft_putchar(t[r][c]);
        }
        ft_putchar('\n');
    }
}

// 
// can we use -1 for error flag ???
int main(int ac, char **av)
{
    int fd;
    int res;
    char t[1024][1024];

    if (ac == 2)
    {
        if ((fd = open(av[1], O_RDONLY)) != -1) // ??
        {
            if ((res = fill(fd, t)) != -1) // ??
            {
                island(t);
            }
            else
            {
                ft_putchar('\n');
            }
            close(fd); // ??
        }
        else
        {
        ft_putchar('\n');        
        }
    }
    ft_putchar('\n');
    return 0;
}

/* 
= Test 1 ===================================================
$> ./pjplpfb5t4znsz7cmaa8zm2n test1.prm
$> diff -U 3 user_output_test1 test1.output | cat -e
--- user_output_test1   2019-09-22 19:13:48.000000000 -0700$
+++ test1.output        2019-09-22 19:13:48.000000000 -0700$
@@ -12,4 +12,3 @@$
 ...................................................................$
 .................................................................8.$
 .....................99999.......................................88$
-$

Diff KO :(
Grade: 0
*/