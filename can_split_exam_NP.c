//#include <stdio.h> // del
//#include <stdlib.h> // del

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int cn(struct s_node *r)
{;
	if (!r)
		return (0);
	
	return(1 + cn(r->left) + cn(r->right));
}

void cs(struct s_node *r, int c, int n, int *res)
{
	if (!r)
		return;

	if (c == n - c)
		*res = 1;

	cs(r->left, c + 1, n, res);
	cs(r->right, c + 1, n, res);
	//return (1 + ll + rr);
}

int can_split(struct s_node *n)
{
	int num;
	int cur = 0;
	int res = 0;
	if (!n)
		return -1;

	num = cn(n);
	cs(n, cur, num, &res);
	return (res);
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

void pr(struct s_node *r)
{
    if (!r)
        return;
    pr(r->left);
    printf("%d ", r->value);
    pr(r->right);
}

int main()
{
    struct s_node *p;
    struct s_node *r;
    struct s_node *r2;
    struct s_node *r3;

    p = new(28);
    p->left = new(51);
    p->left->left = new(26);
    p->left->right = new(48);
    p->left->left->left = new(76);
    p->left->left->right = new(13);
	printf("%d\n", can_split(p));

    r = new(28);
    r->left = new(51);
    r->right = new(51);
    r->left->left = new(26);
    r->right->left = new(51);
	printf("%d\n", can_split(r));

    r2 = new(28);
    r2->right = new(51);
	printf("%d\n", can_split(r2));

    r3 = new(5);
    r3->left = new(1);
    r3->right = new(6);
    r3->right->left = new(7);
    r3->right->right = new(4);
    r3->right->left->left = new(3);
    r3->right->left->right = new(2);
    r3->right->right->right = new(8);
	printf("%d\n", can_split(r3));
}
*/
