int	rain(int *hist, int ht, int size)
{
	char	map[ht][size];
	int	x, y, water;

	if (!hist || size < 3)
		return (0);
	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < ht)
		{
			if (ht - y <= hist[x])
				map[y][x] = '#';
			else
				map[y][x] = ' ';
		}
	}
	y = -1;
	while (++y < ht)
	{
		x = -1;
		while (++x < size)
		{
			if (map[y][x] == ' ')
				map[y][x] = 'X';
			else
				break ;
		}
		x = size;
		while (--x >= 0)
		{
			if (map[y][x] == ' ')
				map[y][x] = 'X';
			else
				break ;
		}
	}
	y = -1;
	water = 0;
	while (++y < ht)
	{
		x = -1;
		while (++x < size)
		{
			if (map[y][x] == ' ')
				water++;
		}
	}
	return (water);
}

int	volume_histogram(int *histogram, int size)
{
	int	ht;
	int	x;

	ht = 0;
	x = -1;
	while (++x < size)
	{
		if (ht < histogram[x])
			ht = histogram[x];
	}
	return (rain(histogram, ht, size));
}



= volume_histogram =============================================================
$> gcc -Wextra -Wall -Werror volume_histogram.c main.c -o user_exe 

= Test 1 ===================================================
$> ./pgf099nb9ksep1z97qebgqi1 0
$> diff -U 3 user_output_test1 test1.output | cat -e

Diff OK :D
= Test 2 ===================================================
$> ./xlhx8ejnoxxflei5hxmf76hl 1
$> diff -U 3 user_output_test2 test2.output | cat -e

Diff OK :D
= Test 3 ===================================================
$> ./1fibp0yt6rjl44fgrctznhwi 1 0 1
$> diff -U 3 user_output_test3 test3.output | cat -e

Diff OK :D
= Test 4 ===================================================
$> ./ld7zgvfv2ayd7gxkn6fk02p8 0 1 0
$> diff -U 3 user_output_test4 test4.output | cat -e

Diff OK :D
= Test 5 ===================================================
$> ./jlyr32s5ybob5rowftbf6urx 0 1 0 5 0 0 3 3 3 0 0 1 0 0 2 2 0 1
$> diff -U 3 user_output_test5 test5.output | cat -e

Diff OK :D
= Test 6 ===================================================
$> ./ral4j2nivcimxrqog0auj1xv 0 10 0 0 0 5 0 0 0 6 0 0 8 0 0 0 0 9 0 0 0 2 0 0 0 7 0 0 0 6 0 0 0 9 0 0 0 4 0 0 0 3 0 0 5 0 0 0 4 0 0 7 0 0 2 1 0
$> diff -U 3 user_output_test6 test6.output | cat -e

Diff OK :D
= Test 7 ===================================================
$> ./hjnhys5808ir4k2q0uif9e9q  2 0 0 5 6 6 5 0 0 8 9 0 5 0 0 4 0 7 0 8 0 9 0 3 0 1 0 5 0 5 0 6 0 4 0 6 0 7 0 5 5 6 5 4 7 0 8 0 5 0 0 0
$> diff -U 3 user_output_test7 test7.output | cat -e

Diff OK :D
= Test 8 ===================================================
$> ./3kyhu7lr08da14twfthad1wd 0 0 4 0 0 6 0 0 3 0 5 0 1 0 0 0
$> diff -U 3 user_output_test8 test8.output | cat -e

Diff OK :D
= Test 9 ===================================================
$> ./vi52td5hrhpyli3vekeukmcx 0 0 4 0 0 6 0 0 3 0 8 0 2 0 5 2 0 3 0 0
$> diff -U 3 user_output_test9 test9.output | cat -e

Diff OK :D
Grade: 1

= Final grade: 1 ===============================================================