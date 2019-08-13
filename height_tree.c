// Passed Moulinette 2019.05.27

struct s_node {
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	if (root == 0) // IS ZERO SAME AS NULL ???
		return (-1); // USING EDGES AS CONVENTION

	// what is *(root->nodes) ???	
	if (root->nodes == 0 || *(root->nodes) == 0)
		return (0);

	int i = 0;
	int max_height = height_tree((root->nodes)[i]);
	int cur_height;
	while ((root->nodes)[++i] != 0)
	{
		cur_height = height_tree((root->nodes)[i]);
		if (cur_height > max_height)
			max_height = cur_height;
	}
	return (max_height + 1);
}

// https://www.youtube.com/watch?v=_pnqMz5nrRs&list=PLSpTzxrSpOsR0aq-pPdaB45wyY4zkEC7J&index=7

//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	struct s_node *node94 = malloc(sizeof(struct s_node *)); // 8 bytes since pointer
	struct s_node *node34 = malloc(sizeof(struct s_node *));
	struct s_node *node52 = malloc(sizeof(struct s_node *));
	struct s_node *node1 = malloc(sizeof(struct s_node *));
	struct s_node *node99 = malloc(sizeof(struct s_node *));
	struct s_node *node11 = malloc(sizeof(struct s_node *));
	struct s_node *node13 = malloc(sizeof(struct s_node *));
	node94->nodes = malloc(sizeof(struct s_node *) * 10); // why 10???
	node94->nodes[0] = node34;
	node94->nodes[1] = node52;
	node94->nodes[2] = 0;
	node34->nodes = malloc(sizeof(struct s_node *) * 10);
	node34->nodes[0] = 0;//node1;
	node34->nodes[1] = 0;//node99;
	node34->nodes[2] = 0;
	node52->nodes = malloc(sizeof(struct s_node *) * 10);
	node52->nodes[0] = node11;
	node52->nodes[1] = 0;
	node1->nodes = malloc(sizeof(struct s_node *) * 10);
	node1->nodes[0] = 0;
	node99->nodes = malloc(sizeof(struct s_node *) * 10);
	node99->nodes[0] = node13;
	node99->nodes[1] = 0;
	node11->nodes = malloc(sizeof(struct s_node *) * 10);
	node11->nodes[0] = 0;
	node13->nodes = malloc(sizeof(struct s_node *) * 10);
	node13->nodes[0] = 0;
	printf("%d\n", height_tree(node94));
}

// Is sizeof for a struct equal to the sum of sizeof of each member?
// https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/
