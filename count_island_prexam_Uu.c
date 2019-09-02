// THE BELOW CODE DID NOT PASS, NOT SURE WHY ???
// TEST IF PASS ???

//#include <stdio.h> // d
#include <fcntl.h>
#include <unistd.h>

int fill(int fd, char t[][1024])
{
	int bytes = 0;
	char buf[1025] = {'\0'};
	int i = 0;
	int r = 0;
	int c = 0;
	int linelen = 0;

	while ((bytes = read(fd, buf, 1024)) > 0)
	{
		buf[bytes] = '\0';
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
			{
				if (linelen == 0) // checking if irregular grid
				{
					linelen = c;
				}
				else if (linelen != c)
				{
					return 0;
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
				return 0;
			}
			i++;
		}
	}
	t[r][0] = '\0';
	return 1;
}

void ff(char t[][1024], int r, int c, char idx)
{
	if (r < 0 || r >= 1024 || c < 0 || c >= 1024)
		return ;

	if (t[r][c] != 'X' || t[r][0] == '\0' || t[r][c] == '\0')
		return ;

	t[r][c] = idx;
	ff(t, r + 1, c, idx);
	ff(t, r - 1, c, idx);
	ff(t, r, c + 1, idx);
	ff(t, r, c -1, idx);
}

void island(char t[][1024])
{
	int r = 0;
	int c;
	char idx = '0';

	while (t[r][0] != '\0') // traverse row
	{
		c = 0;
		while (t[r][c] != '\0') // traverse col
		{
			if (t[r][c] == 'X')
			{
				ff(t, r, c, idx);
				idx++;
			}
			write(1, &t[r][c], 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int main(int ac, char **av)
{
	int fd;
	int res;
	char t[1024][1024];

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			if ((res = fill(fd, t)) != 0)
			{
				island(t);

			}
			close(fd);
		}
	}
	write(1, "\n", 1);
	return 0;
}

/*
// check if ac == 2
// open file, handler fd
void p(char t[][1024])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (t[i][j] != '\0')
				printf("%c", t[i][j]);
		}
		printf("\n");
	}
}

*/