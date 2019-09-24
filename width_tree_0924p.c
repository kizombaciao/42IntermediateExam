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
	int ans = 0;
	int res = 0;

	if(!n)
		return 0;

	ans = wt(n, &res);
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
    p->left->left->right->left = new(13);
    p->left->left->right->left->right = new(13);

    p->left->left->left = new(7);
	p->left->left->left->left = new(7);

    printf("%d\n", width_tree(p));
}
*/
