// PASSED!!!

//#include <stdio.h> // del
#include <stdlib.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

void ll(struct s_node *r, int cl, int exp, int *res)
{
	if (!r)
		return;

	if (r->value == exp)
		cl++;
	else
		cl = 1;
	*res = max(*res, cl);

	ll(r->left, cl, r->value + 1, res);
	ll(r->right, cl, r->value + 1, res);
}

int	longest_sequence(struct s_node *node)
{
	int res = 0;

	if (!node)
		return 0;

	ll(node, 0, node->value, &res);
	return res;
}
/*
struct s_node *new(int v)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->left = NULL;
	p->right = NULL;
	return (p);
}

int main()
{
	struct s_node *p;

	p = new(1);
	p->left = new(2);
	p->right = new(4);
	p->left->left = new(3);

	printf("%d\n", longest_sequence(p));
}
*/
