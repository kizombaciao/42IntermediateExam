struct 	s_node
{
	int           	value;
	struct s_node 	**nodes;
};

int		height_tree(struct s_node *root)
{
	int	current = 0;
	int	height = 0;

	if (!root)
		return (-1);
        
	for (int i = 0; root->nodes[i]; i++)
		if ((current = height_tree(root->nodes[i]) + 1) > height)
			height = current;
	return (height);
}

/*
#include <stdlib.h>
#include <stdio.h>
int		main(void)
{
	struct s_node *root;
	root = malloc(sizeof(struct s_node));
	root->value = 1;
	root->nodes = malloc(sizeof(struct s_node));
	root->nodes[0] = malloc(sizeof(struct s_node));
	root->nodes[0]->value = 2;
	root->nodes[0]->nodes = malloc(sizeof(struct s_node));
	root->nodes[0]->nodes[0] = malloc(sizeof(struct s_node));
	root->nodes[0]->nodes[0]->value = 3;
	root->nodes[0]->nodes[0]->nodes = malloc(sizeof(struct s_node));
	root->nodes[0]->nodes[0]->nodes[0] = malloc(sizeof(struct s_node));
	root->nodes[0]->nodes[0]->nodes[0]->value = 4;
	root->nodes[0]->nodes[0]->nodes[0]->nodes = malloc(sizeof(struct s_node));
	root->nodes[0]->nodes[0]->nodes[0]->nodes[0] = NULL;
	printf("%d\n", height_tree(root));
	return (0);
}
*/

// https://github.com/jraleman/42.Exam-C-Intermediate/blob/master/level01/height_tree.c
