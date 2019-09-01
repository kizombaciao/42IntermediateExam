//#include <stdio.h>
//#include <stdlib.h>
#include <fcntl.h>
//#include <unistd.h>


int f(int fd, char t[1024][1024])
{
	char buf[1025] = {[0 ... 1025] = '\0'};
	int bytes = 0;
	int b;
	int row = 0;;
	int col = -1;
	int linelen = 0; // to capture the num of columns

	while ((bytes = read(fd, buf, 1024)) > 0)
	{
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

	return (1);
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
			if ((res = f(fd, t)) != 0) // how this condtion works ???




		}

	}
}