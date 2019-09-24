// PASS!

#include <stdio.h> // del
#include <stdlib.h>

	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};


struct s_node *leftmost(struct s_node *r)
{
	if (!r)
		return NULL;

	while (r->left) // REMEMBER !!! not r but r->left!!!
		r = r->left;
	return (r);
}

struct s_node *rightmost(struct s_node *r)
{
	if (!r)
		return NULL;

	while (r->right) // REMEMBER !!!
		r = r->right;
	return (r);
}

// BECAUSE YOU WANT INORDER TRAVERSAL, THAT IS WHY THE EVAL IS NOT IN THE MIDDLE!
// WHEN PREV IS THE LAST CURRENT, ACCORDING TO INORDER TRAVERSAL
void cc(struct s_node *r, struct s_node **prev)
{
	if (!r)
		return;

	cc(r->left, prev);
	if (*prev) // important !!!
	{
		(*prev)->right = r; // DON'T FORGET ()!  (*p)
		r->left = (*prev);
	}
	*prev = r; // NOTE!!!
	
	cc(r->right, prev);
}
struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *prev = 0; // REMEMBER TO SET TO ZERO !!! NULL okay?
	struct s_node *min;

	if (!bst)
		return NULL;

	cc(bst, &prev);

	min = leftmost(bst);
	min->left = rightmost(bst);
	min->left->right = min;
	return (min); // NOTE! RETURN MIN !!!
}
////////////////////////////////////////////////////////////
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
/*
int main()
{
	struct s_node *p;
	struct s_node *q;

	p = new(1);
	p->left = new(2);
	p->right = new(4);
	p->left->left = new(3);

	q = convert_bst(p);
	pr(q);
}
*/
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
