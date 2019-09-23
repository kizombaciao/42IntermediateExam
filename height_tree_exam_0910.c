// pass!
//#include <stdio.h>
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
	int res = 0;
	int i = 0;

	if (!root)
		return -1; // remember -1!

	while (root->nodes[i])
	{
		// remember '1 +' goes inside !!!
		res = max(res, 1 + height_tree(root->nodes[i]));
		i++;
	}

	return (res);
}

/*
struct s_node *new(int v)
{
	struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->nodes = malloc(1000); // set to null ???
	return p;
}

int main()
{
	struct s_node *p;
	struct s_node *q;

	q = new(10);

	p = new(1);
	p->nodes[0] = new(2);
	p->nodes[1] = new(6);
	p->nodes[1]->nodes[0] = new(7);
	p->nodes[1]->nodes[0]->nodes[0] = new(8);
	p->nodes[1]->nodes[0]->nodes[0]->nodes[0] = new(8);
	p->nodes[0]->nodes[0] = new(3);
	p->nodes[0]->nodes[1] = new(4);
	p->nodes[0]->nodes[1]->nodes[0] = new(5);

	printf("111a %d\n", height_tree(p));
	printf("111a %d\n", height_tree(q));
}
*/
