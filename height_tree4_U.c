/************************************ #### Passed Final Exam #### *************************************/

struct s_node {
	int value;
	struct s_node **nodes; // why double pointer?  array of pointers!
};

int height_tree(struct s_node *root)
{
	int height = 0;
	int i = 0;
	if (!root)
		return -1;
	else
	{
		while (root->nodes[i])
		{
			int res = 1 + height_tree(root->nodes[i++]);
			height = (res > height) ? res : height;
		}
	}
	return(height);
}

#include "stdio.h"
#include "stdlib.h"

struct s_node *new_node(int item)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = item;
	new->nodes = malloc(1000); // why 1000 ???
	return (new);
}

int main (void)
{
	struct s_node *t = new_node(94);
	t->nodes[0] = new_node(34);
	t->nodes[1] = new_node(52);
	
	t->nodes[0]->nodes[0] = new_node(1);
	t->nodes[0]->nodes[1] = new_node(99);
	t->nodes[0]->nodes[2] = new_node(11);
	
	t->nodes[0]->nodes[1]->nodes[0] = new_node(13);
	
	
	printf("%d", height_tree(t));
	return (0);
}

// https://github.com/Manmeet2018/42_Exam-C-Intermediate/blob/master/level1/height_tree/height_tree.c
