// FINALLY PASSED, WAS MISSING KEY ERROR STATEMENTS WITH WRITE()
// THE BELOW CODE DID NOT PASS, NOT SURE WHY ???
// TEST IF PASS ???

//#include <stdio.h> // d
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h> // needed ???

int fill(int fd, char t[][1024])
{
	int bytes = 0;
	// it is char and not int buf !!! careful, hard to debug!!!
	char buf[1025] = {'\0'}; // {[0 ... 1024] = '\0'};
	// 1025, in order to add '\0'
	int i = 0; // b
	int r = 0;
	int c = 0;
	int linelen = 0;

	while ((bytes = read(fd, buf, 1024)) > 0)
	{
		buf[bytes] = '\0';
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
			{
				if (linelen == 0) // checking if irregular grid
				{
					linelen = c; // first c sets lastlen!
				}
				else if (linelen != c) // afterwards, check against lastlen
				{
					return 0; // error
				}
				t[r][c] = '\0';
				r++;
				c = 0; // remember !
			}
			else if (buf[i] == '.' || buf[i] == 'X')
			{
				t[r][c] = buf[i];
				c++;
			}
			else
			{
				return 0; // error
			}
			i++;
		}
	}
	t[r][0] = '\0'; // don't forget !
	return 1; // success
}

void ff(char t[][1024], int r, int c, char idx)
{
	// note, the dim can be smaller than the max of 1024!!!
	if (r < 0 || r >= 1024 || c < 0 || c >= 1024)
		return ;

	// t[r][0] == '\0' means we are already on past the final row!!!
	if (t[r][c] != 'X' || t[r][0] == '\0' || t[r][c] == '\0')
		return ;

	t[r][c] = idx;
	ff(t, r - 1, c, idx);
	ff(t, r + 1, c, idx);
	ff(t, r, c -1, idx);
	ff(t, r, c + 1, idx);
}

void island(char t[][1024])
{
	int r = 0;
	int c;
	char idx = '0';

	// note, condition is on '\0' and not 1024 !!!
	while (t[r][0] != '\0') // traverse row, while not last row
	{
		c = 0;
		while (t[r][c] != '\0') // traverse col
		{
			if (t[r][c] == 'X') // REMEMBER THIS IF CONDITION !!!
			{
				ff(t, r, c, idx);
				idx++; // REMEMBER !!!
				// note, which ever X you pursue via recursion will be part of the same island.
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
	char t[1024][1024]; // don't you need ptr to ensure t is ascessible ???

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			if ((res = fill(fd, t)) != 0)
			{
				island(t);
			}
			else
				write(1, "\n", 1); // not optional!
			close(fd);
		}
		else
			// why don't i need the error write below ??? test with it.
			write(1, "\n", 1); // not optional!
	}
	else
		write(1, "\n", 1); // not optional!
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