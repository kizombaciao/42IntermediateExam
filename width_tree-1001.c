//#include <stdio.h> // del
#include <stdlib.h> // del

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

int max(int a, int b)
{
	return ((a > b ? a : b));
}

int wt(struct s_node *r, int *res)
{
	if (!r)
		return 0;

	int le = wt(r->left, res);
	int ri = wt(r->right, res);

	*res = max(*res, 1 + le + ri);

	return (1 + max(le, ri));
}

int width_tree(struct s_node *n)
{
	int ans;
	if (!n)
		return 0;

	int res = 0;

	ans = wt(n, &res);
	return res;
}

/*
struct s_node *new(int v)
{
	struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int main()
{
	struct s_node *p;

	p = new(1);
	p->left = new(2);
	p->left->left = new(3);
	p->left->right = new(4);
	p->left->right->left = new(6);

	p->right = new(5);
	p->right->left = new(7);
	p->right->right = new(8);
	p->right->right->left = new(9);

	printf("%d\n", width_tree(p));
}
*/