//#include <stdio.h>
//#include <stdlib.h>
#include <fcntl.h> // open()
#include <unistd.h> // read()
#include <stdio.h> // del

int f(int fd, char t[][1024])
{
	char buf[1025] = {[0 ... 1024] = '\0'};
	int bytes = 0;
	int b;
	int row = 0;;
	int col = -1;
	int linelen = 0; // to capture the num of columns

	while ((bytes = read(fd, buf, 1024)) > 0)
	{
		printf("%d\n", bytes);
		buf[bytes] = '\0';
		b = 0;
		while (buf[b] != '\0')
		{
			if (buf[b] == '\n')
			{
				if (linelen == 0)
				{
					linelen = col;
				}
				else if (linelen != col)
				{
					return (0);
				}
				t[row][++col] = '\0'; //end each row w/ '\0', like a string!
				row++; // set row and col for start of next row
				col = -1;
			}
			else if (buf[b] == '.' || buf[b] == 'X')
			{
				t[row][++col] = buf[b];
			}
			else
			{
				return (0);
			}
			b++;
		}
	}
	t[++row][0] = '\0'; // final row marked with NULL!
	return (1);
}

void ff(char t[][1024], int r, int c, char idx)
{
	if (r < 0 || r >= 1024 || t[r][0] == '\0'
		|| c < 0 || c >= 1024 || t[r][c] == '\0'
		|| t[r][c] != 'X')
	{
		return;
	}

	t[r][c] = idx;
	ff(t, r-1, c, idx);
	ff(t, r+1, c, idx);
	ff(t, r, c-1, idx);
	ff(t, r, c+1, idx);
}

void island(char t[][1024])
{
	int r = -1;
	int c;
	char idx = '0' - 1;

	while (t[++r][0] != '\0')
	{
		c = -1;
		while (t[r][++c] != '\0')
		{
			if (t[r][c] == 'X')
			{
				ff(t, r, c, ++idx);
			}
			write(1, &t[r][c], 1);
		}
		write(1, "\n", 1);
	}
}

int main(int ac, char **av)
{
	int fd;
	char t[1024][1024];
	int res; // ???

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			if ((res = f(fd, t)) != 0) // how this condtion works ? see learnC
			{
				island(t);
			}
			else
			{
				write(1, "\n", 1);
			}
			close(fd);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
