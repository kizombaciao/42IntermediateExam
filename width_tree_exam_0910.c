// pass!
//#include <stdio.h>
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
	int res = 0;
	int ans = 0;

	if (!n)
		return 0;

	ans = wt(n, &res);
	return res;
}

//////////////////////////////////
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
    p->right = new(5);
    p->left->left = new(3);
    p->left->right = new(4);
    p->left->right->left = new(6);
    p->right->left = new(7);
    p->right->right = new(8);
    printf("222a   %d\n", width_tree(p));

    p = new(1);
    p->right = new(5);
	printf("222b   %d\n", width_tree(p));

    p = new(4);
    p->left = new(5);
    p->left->right = new(9);
    p->left->left = new(6);
    p->left->right->left = new(6);
	printf("222c   %d\n", width_tree(p));

    p = new(1);
	printf("222d   %d\n", width_tree(p));

    p = new(4);
    p->left = new(5);
    p->left->right = new(9);
    p->left->left = new(6);
    p->left->left->left = new(7);
    p->left->left->right = new(13);

    printf("111a %d\n", width_tree(p));

    p = new(5);
    p->left = new(6);
    p->right = new(4);
    p->right->left = new(9);
    p->right->right = new(3);
    p->right->left->left = new(3);
    p->right->left->right = new(2);
    p->right->right->right = new(2);
    printf("111b %d\n", width_tree(p));

    p = new(30);
    p->left = new(15);
    p->right = new(41);
    p->left->left = new(61);
    p->right->left = new(80);

    printf("111c %d\n", width_tree(p));

    p = NULL;
    printf("111d %d\n", width_tree(p));
}
*/
