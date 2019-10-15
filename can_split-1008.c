//#include <stdio.h> // del

#include <stdlib.h>

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

int tlen(struct s_node *r)
{
	if (!r)
		return 0;

	return (1 + tlen(r->left) + tlen(r->right));
}

int cs(struct s_node *r, int n, int *res)
{
	if (!r)
		return 0;

	int le = cs(r->left, n, res);
	int ri = cs(r->right, n, res);

	int c = 1 + le + ri;

	if (n - c == c)
		*res = 1;

	return c;
}

int can_split(struct s_node *n)
{
	int res = 0;
	int len;
	int ans;

	if (!n)
		return 0;

	len = tlen(n);

	ans = cs(n, len, &res);

	return res;
}

////////////////////////////////////
/*
struct s_node *new(int v)
{
	struct s_node *p;
	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int main()
{
	struct s_node *p;
	struct s_node *q = new(5);
	//struct s_node *q2 = new(5);

	p = new(28);
	p->left = new(51);
	p->left->left = new(26);
	p->left->right = new(48);
	p->left->left->left = new(76);
	p->left->left->right = new(13);

	printf("%d\n", can_split(p));

	q->left = new(1);
	//q->left->left = new(61);
	q->right = new(6);
	q->right->left = new(7);
	q->right->left->left = new(3);
	q->right->left->right = new(2);
	q->right->right = new(4);
	q->right->right->right = new(8);

	printf("%d\n", can_split(q));

//	printf("%d\n", can_split(q));
//	printf("%d\n", can_split(q2));

}
*/