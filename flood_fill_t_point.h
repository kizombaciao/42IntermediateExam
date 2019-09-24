#ifndef T_POINT_FLOOD_FILL
# define T_POINT_FLOOD_FILL

typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

// DON'T FORGET THE TWO FUNCTIONS BELOW !!!
void ff(char **tab, t_point size, int y, int x, char c);
void  flood_fill(char **tab, t_point size, t_point begin);

#endif

