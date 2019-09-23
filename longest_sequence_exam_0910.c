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
/*
int h(struct s_node *r)
{
	if (!r)
		return 0;

	return (1 + max(h(r->left), h(r->right)));
}
*/
void ls(struct s_node *r, int c, int exp, int *res)
{
	if (!r)
		return;

	if (r->value == exp)
		c++;
	else
		c = 1;

	*res = max(*res, c);

	ls(r->left, c, r->value + 1, res);
	ls(r->right, c, r->value + 1, res);
}

int longest_sequence(struct s_node *node)
{
	int res = 0;

	if (!node)
		return 0;

	ls(node, 0, node->value, &res);
	return res;
}


// preorder
// 4 args, int
// 2 func
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

    p = new(4);
	p->left = new(5);
	p->left->right = new(9);
	p->left->left = new(6);
	p->left->left->left = new(7);
	p->left->left->right = new(13);

	printf("111a %d\n", longest_sequence(p));

    p = new(5);
	p->left = new(6);
	p->right = new(4);
	p->right->left = new(9);
	p->right->right = new(3);
	p->right->left->left = new(3);
	p->right->left->right = new(2);
	p->right->right->right = new(2);
	printf("111b %d\n", longest_sequence(p));

    p = new(30);
	p->left = new(15);
	p->right = new(41);
	p->left->left = new(61);
	p->right->left = new(80);

	printf("111c %d\n", longest_sequence(p));

	p = NULL;
	printf("111d %d\n", longest_sequence(p));
}
*/

