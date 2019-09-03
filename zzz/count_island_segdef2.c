// i can't see why this seg defaults, given it is similar to prexam!

#include <unistd.h>
#include <fcntl.h>

// make sure there is only one carriage return !!!
// why must the buffer be 1, buf[1025], unit longer ???

//error checks:
// check if bytes read is > 0

// to fill table with data from file
int fill(int fd, char t[][1024])
{
	int bytes = 0;
	char buf[1025] = {[0 ... 1024] = '\0'}; // ok ???
	int i;
	int r, c;
	int len = 0;

	r = 0;
	c = 0;
	while ((bytes = read(fd, buf, 1024)) > 0)
	{
		buf[bytes] = '\0';
		i = 0; 
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
			{
				if (len == 0)
				{
					len = c;
				}
				else if (len != c)
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
		}
		i++;
	}
	t[r][0] = '\0';
	return 1;
}

void ff(char t[][1024], int r, int c, int idx)
{
	if (r < 0 || c < 0 || r >= 1024 || c >= 1024)
		return ;
	if (t[r][c] != 'X' || t[r][0] == '\0' || t[r][c] == '\0')
		return ;
	
	t[r][c] = idx;
	ff(t, r + 1, c, idx);
	ff(t, r - 1, c, idx);
	ff(t, r, c + 1, idx);
	ff(t, r, c - 1, idx);
}

void island(char t[][1024])
{
	int r, c;
	char idx; // it is a char !!!

	idx = '0';

	r = 0;
	while (t[r][0] != '\0')
	{
		c = 0;
		while (t[r][c] != '\0')
		{
			if (t[r][c] == 'X')
			{
				ff(t, r, c, idx);
				idx++;
			}
			write(1, &t[r][c], 1); // print it!!!
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
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return 0;
		res = fill(fd, t);
		if (res != 0)
		{
			island(t);
		}
		close(fd);
	}
	return 0;
}

/*
If the file is empty, 
or there is an error (Incoherent input, for example), 
or no parameters are passed, 
the program must display a newline.
*/

// open file
// fill char table
// update island

// fill:
// two nested while loops
// outer while reads upto 1024 char into buffer
// inner file populates the table with the read string
// if, else if, else
// if irregular grid.  is this required ???
// else if . or X, then populate table
// else return 0

// island:
// two nested while loops
// outer traverses row
// inner traverses col
// if t element == 'X', call ff()


