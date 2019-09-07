//#include <stdio.h> // del
#include <stdlib.h>

struct s_node {
	int           value;
	struct s_node **nodes;
};

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int height_tree(struct s_node *root)
{
	int i = 0;
	int res = 0;

	if (!root)
		return -1;

	while (root->nodes[i])
	{
		res = max(res, 1 + height_tree(root->nodes[i]));
		i++;
	}
	return res;
}

/*
struct s_node *new(int v)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->nodes = malloc(1000);
	return p;
}

int main()
{
	struct s_node *p;
	struct s_node *p1;
	struct s_node *p2;

	p = new(1);
	p->nodes[0] = new(2);
	p->nodes[1] = new(3);
	p->nodes[0]->nodes[0] = new(4);
	p->nodes[0]->nodes[0]->nodes[0] = new(5);

	p->nodes[1]->nodes[0] = new(3);
	p->nodes[1]->nodes[0]->nodes[0] = new(3);
	p->nodes[1]->nodes[0]->nodes[0]->nodes[0] = new(3);
	p->nodes[1]->nodes[0]->nodes[0]->nodes[1] = new(3);

	printf("%d\n", height_tree(p));

	p1 = NULL;
	printf("%d\n", height_tree(p1));

	p2 = new(1);
	printf("%d\n", height_tree(p2));
}
*/

