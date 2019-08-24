typedef struct 	s_point
{
	int			x;
	int			y;
}				t_point;

void	recur(char **tab, t_point size, t_point begin, char key)
{
	if (begin.x < 0 || begin.x >= size.x ||
		begin.y < 0 || begin.y >= size.y ||
		tab[begin.y][begin.x] != key)
		return;
	tab[begin.y][begin.x] = 'F';
	recur(tab, size, (t_point){begin.x - 1, begin.y}, key);
	recur(tab, size, (t_point){begin.x + 1, begin.y}, key);
	recur(tab, size, (t_point){begin.x, begin.y - 1}, key);
	recur(tab, size, (t_point){begin.x, begin.y + 1}, key);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	recur(tab, size, begin, tab[begin.y][begin.x]);
}

/*
You check the new coordinates before replacing, 
thus not needing to worry about setting up the "key" each time. Neat approach! I just found it easier and less error prone to find the key once, and not keep re-assigning it. On another note, your function has 9 conditionals, mine uses 1. Checking on entry instead of before entering a recursive loop is slightly more efficient. Both work in this case, but your exit condition is abstracted a bit more. Doesn't matter in something like flood fill, but could be important in other algorithms.
 */