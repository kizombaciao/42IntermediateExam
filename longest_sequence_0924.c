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

void ls(struct s_node *r, int cl, int exp, int *res)
{
	if (!r)
		return;

	if (exp == r->value)
	{
		cl++;
	}
	else
		cl = 1;

	*res = max(*res, cl);

	ls(r->left, cl, r->value + 1,  res);
	ls(r->right, cl, r->value + 1, res);
}

int longest_sequence(struct s_node *node)
{
	if (!node)
		return 0;

	int res = 0; // yes, start at zero !

	ls(node, 0, node->value, &res); // yes, cl starts at zero !
	return res;
}

/*
struct s_node *new(int v)
{
	struct s_node *r = (struct s_node *)malloc(sizeof(struct s_node));
	r->value = v;
	r->left = NULL;
	r->right = NULL;
	return r;
}

int main()
{
	struct s_node *p;
	p = new(4);
	p->left = new(5);
	p->left->right = new(6);
	p->left->right->right = new(7);
	p->left->right->right->right = new(8);
	p->left->left = new(6);
	p->left->left->right = new(13);
	p->left->left->left = new(7);

	printf("%d\n", longest_sequence(p));
}
*/

