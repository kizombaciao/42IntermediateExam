#include <stdio.h> // d
#include <stdlib.h> // d

struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *lll(struct s_node *r)
{
	if (!r)
		return NULL;

	while (r)
	{
		r = r->left;
	}
	return (r);
}
struct s_node *rrr(struct s_node *r)
{
	if (!r)
		return NULL;

	while (r)
	{
		r = r->right;
	}
	return (r);
}

void cb(struct s_node *r, struct s_node **p)
{
	if (!r)
		return;

	cb(r->left, p);

	printf("%d\n", r->value);

	if (*p)
	{
		(*p)->right = r;
		r->left = (*p);
	}
	(*p) = r;

	cb(r->right, p);
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *prev;

	prev = NULL; // why NULL ???  try step through notes
	cb(bst, &prev);


	return (NULL);
}
//////////////////////////////////////////////////////
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

    p = new(94);
    p->left = new(34);
    p->right = new(52);
    p->left->left = new(1);
    p->left->right = new(99);

    pr(p);
	convert_bst(p);

//    printf("\n");
//    reverse_tree(p);
//    pr(p);
}
