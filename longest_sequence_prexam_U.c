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

void ll(struct s_node *r, int cl, int exp, int *res) // remember void!
{
	if (!r)
		return; // DON'T FORGET

	if (r->value == exp) // comparing against r->value 
		cl++;
	else
		cl = 1; // NOTE!!! THIS NEEDS TO BE 1.
		
	*res = max(*res, cl); // don't forget!

	ll(r->left, cl, r->value + 1, res);
	ll(r->right, cl, r->value + 1, res);
}

int	longest_sequence(struct s_node *node)
{
	int res = 0; // yes, starts at zero !

	if (!node)
		return 0;

	ll(node, 0, node->value, &res); // note! cl starts at 0.
	return res;
}
// 2 func
// void
// 4 args
// postorder ??? why? b/c you need to pass the update cl value to the function ?

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
