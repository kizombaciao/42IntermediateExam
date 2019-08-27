#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node **nodes;
};

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int height_tree(struct s_node *r)
{
	int i = 0;
	int res = 0;
	int res2 = 0;

	if (!r)
		return -1;

	while (r->nodes[i])
	{
		res = 1 + height_tree(r->nodes[i]);
		res2 = max(res, res2);
		i++;
	}
	return (res2);
}

struct s_node *new_node(int value)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->nodes = malloc(1000); // note !!!
	return (p);
}

int main()
{
	struct s_node *t;
	t = new_node(94);
	t->nodes[0] = new_node(34);
	t->nodes[1] = new_node(52);
	t->nodes[0]->nodes[0] = new_node(1);
	t->nodes[0]->nodes[1] = new_node(99);
	t->nodes[0]->nodes[2] = new_node(11);
	t->nodes[0]->nodes[1]->nodes[0] = new_node(13);
	printf("%d", height_tree(t));
	return (0);
}
