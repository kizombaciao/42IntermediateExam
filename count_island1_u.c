// when I tried, it did not PASS with examshell!!!

// https://github.com/evandjohnston/ft_alone_in_the_dark/blob/master/Intermediate_Exam/level_5/5-count_island/count_island.c
// Passed Moulinette 2019.08.01

#include <stdio.h> // del
#include <fcntl.h> // REMEMBER!!!, open()
#include <unistd.h> // read()
#include <stdlib.h>

int	fill_arr(int fd, char arr[1024][1024])
{
	// note, 1025 vs 1024 !!!
	char buf[1025] = {[0 ... 1024] = '\0'}; // initialize !!!
	int b; // index for buf
	int	bytes_read = 0; // # bytes read, no more than 1024
	int row = 0;
	int col = -1;
	int line_len = 0; // to capture the num of columns

	while ((bytes_read = read(fd, buf, 1024)) > 0)
	{
		buf[bytes_read] = '\0';
		b = 0;
		while (buf[b] != '\0')
		{
			if (buf[b] == '\n')
			{
				if (line_len == 0) // making sure grid is not irregular
					line_len = col;
				else if (line_len != col)
					return (0);
				arr[row][++col] = '\0'; // each row end marked with '\0'
				row++; // set r and c to start of next row
				col = -1;
			}
			else if (buf[b] == '.' || buf[b] == 'X')
				arr[row][++col] = buf[b];
			else
				return (0);
			b++;
		}
	}
	arr[++row][0] = '\0'; // final row marked with NULL
	// isn't row already incremented ???
	return (1);
}

void	flood_fill(char arr[1024][1024], int row, int col, char fill)
{
	// when arr[r][0] == '\0', it means no more rows
	// when arr[r][c] == '\0', it means end of columns
	// note, 1024 is not inclusive!!!
	if (row < 0 || row > 1023 || arr[row][0] == '\0'
		|| col < 0 || col > 1023 || arr[row][col] == '\0'
		|| arr[row][col] != 'X')
		// last condition previously in separate if condition
		return;
	arr[row][col] = fill;
	flood_fill(arr, row - 1, col, fill);
	flood_fill(arr, row + 1, col, fill);
	flood_fill(arr, row, col - 1, fill);
	flood_fill(arr, row, col + 1, fill);
}

void	update_islands(char arr[1024][1024])
{
	char fill_index = '0' - 1;
	int row = -1;
	int col;

	// check if no more rows
	while (arr[++row][0] != '\0')
	{
		col = -1;
		while (arr[row][++col] != '\0') // traverse rows
		{
			if (arr[row][col] == 'X') // traverse cols
				flood_fill(arr, row, col, ++fill_index);
			write(1, &arr[row][col], 1); // every cell is traversed
			// can also print in a separate nested loop!
		}
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int fd;
	char arr[1024][1024];
	int result;

	if (ac == 2 && (fd = open(av[1], O_RDONLY)) != -1)
	{
		// same as if (result != 0)
		if ((result = fill_arr(fd, arr)) != 0)
			{
				update_islands(arr);
			}
		else
			write(1, "\n", 1); // necessary? in case, for error stmt
		close(fd);
	}
	else
		write(1, "\n", 1);
	return (0);
}

// open file
// read file

/*
= Test 1 ===================================================
$> ./ohvvlshruyvw9r4tf70zzeic test1.prm
Command './ohvvlshruyvw9r4tf70zzeic test1.prm' got killed by a Segmentation fault (Signal -11)
Grade: 0

*/