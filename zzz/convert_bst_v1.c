#include <stdlib.h>
#include <stdio.h>

	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

struct s_node *le(struct s_node *r)
{
	if (!r)
		return NULL;
	while (r->left)
	{
		r = r->left;
	}
	return r;
}

struct s_node *ri(struct s_node *r)
{
	if (!r)
		return NULL;
	while (r->right)
	{
		r = r->right;
	}
	return r;
}

void cb(struct s_node *r, struct s_node **prev)
{
	if (!r)
		return;

	cb(r->left, prev); // ???

	if (*prev) // ???
	{
		(*prev)->right = r;
		r->left = (*prev);
	}
	*prev = r;
	cb(r->right, prev);
}
struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *prev = 0;

	if (!bst)
		return NULL;

	cb(bst, &prev); // ???
	struct s_node *min = le(bst);
	min->left = ri(bst);
	min->left->right = min;
	return min;
}

// inorder traversal

/////////////////////////////////////////////
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
	struct s_node *;

	p = new(1);
	p->left = new(2);
	p->right = new(4);
	p->left->right = new(3);
	pr(p);

	r = convert_bst(p);
	
	// NOTE, CAREFUL WITH INFINITE LOOP WHEN PRINTING !!!
	int i = 0;
    while (i++ < 15)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
}
/*
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
    pr(c); // INORDER TRAVERSAL PRINTOUT
    printf("-----------------------------\ncir Doub linklist: \n");
    
    struct s_node *r = convert_bst(a);
    int i = 0;
    while (i++ < 15)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
}
*/
