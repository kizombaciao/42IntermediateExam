 #include <stdlib.h>
#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *left;
	struct s_node *right;
};
struct s_node *left(struct s_node *r)
{
	while (r->left)
	{
		r = r->left;
	}
	return (r);
}
struct s_node *right(struct s_node *r)
{
	while (r->right)
	{
		r = r->right;
	}
	return (r);
}
void cb2(struct s_node *r, struct s_node **prev)
{
	if (!r)
		return;

	cb2(r->left, prev);

	if (*prev)
	{

		(*prev)->right = r;
		r->left = (*prev);
	}
	(*prev) = r; // REMEMBER !!!
	cb2(r->right, prev);
}

struct s_node *cb(struct s_node *r)
{
	struct s_node *prev = 0;
	struct s_node *min;

	if (r == 0)
		return (0);
	cb2(r, &prev);	

	min = left(r);
	min->left = right(r);
	min->left->right = min;
	return (min);
}

//////////////////////////////////////////
struct s_node *new(int d)
{
    struct s_node *n =(struct s_node *)malloc(sizeof(struct s_node));
    n->value = d;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// inorder traversal
void p(struct s_node *r)
{
    if(!r)
        return ;
    p(r->left);
    printf("%d\n", r->value);
    p(r->right);
}
int main()
{
    struct s_node *a = new(12);
    a->left = new(6);
    a->left->left = new(3);
    a->left->right = new(9);

    a->right = new(18);
    a->right->right = new(20);
    a->right->left = new(15);
    struct s_node *c = a;
    p(c); // INORDER TRAVERSAL PRINTOUT
    printf("-----------------------------\ncir Doub linklist: \n");
    
    struct s_node *r = cb(a);
    int i = 0;
    while (i++ < 15)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
}