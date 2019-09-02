// PASS!

//#include <stdlib.h> // del
//#include <stdio.h> // del
// count total nodes
// c = 
// c == n - c
// res boolean

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int ct(struct s_node *r)
{
	int num;

	if (!r)
		return(0);
	num = 1 + ct(r->left) + ct(r->right);
	return (num);
}

int can(struct s_node *r, int num, int *res)
{
	int c;

	if (!r)
		return (0);

	c = 1 + can(r->left, num, res) + can(r->right, num, res);
	if (c == num - c)
	{
		*res = 1;
	}
	return (c);
}

int can_split(struct s_node *n)
{
	int ans;
	int num;
	int res = 0;

	if (!n)
		return (0);

	num = ct(n);

	ans = can(n, num, &res);
	return (res);
}
/*
struct s_node *new(int v)
{
    struct s_node *p;

    p = (struct s_node *)malloc(sizeof(struct s_node));
    p->value = v;
    p->right = NULL;
    p->left = NULL;
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
    p = new(28);
    p->left = new(51);
    p->right = new(52);

//    p->left->left = new(26);
//    p->left->right = new(48);

//    p->left->left->left = new(76);
    //p->left->right->left = new(83);
//    p->left->left->right = new(13);

//    p->left->right->left->right = new(61);
//    p->left->right->right->left = new(37);
//    p->left->right->right->right = new(67);

    pr(p);
    printf("\n");

	printf("%d\n", can_split(p));

    return (0);
}
*/
/*
    p = new(28);
    p->left = new(51);
    //p->right = new(52);

    p->left->left = new(26);
    p->left->right = new(48);

    p->left->left->left = new(76);
    //p->left->right->left = new(83);
    p->left->left->right = new(13);
 */

