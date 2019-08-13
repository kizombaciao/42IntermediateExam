#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node	*bst_min(struct s_node *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

struct s_node	*bst_max(struct s_node *root)
{
	while (root->right)
		root = root->right;
	return (root);
}

void			in_trav(struct s_node *root, struct s_node *min, struct s_node *max)
{
	static struct s_node	*prev;

	if (root)
	{
		/* prevent from traversing left from min (it points to max) */
		if (root != min)
			in_trav(root->left, min, max);
		/* update links for all nodes except min (for min prev == 0 ) */
		if (prev)
		{
			prev->right = root;
			root->left = prev;
		}
		/* set prev to current node */
		prev = root;
		/* prevent from traversing right from max (it points to min) */
		if (root != max)
			in_trav(root->right, min, max);
	}
}	

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node	*min;
	struct s_node	*max;

	if (!bst)
		return (bst);
	min = bst_min(bst);
	max = bst_max(bst);
	min->left = max;
	max->right = min;

	in_trav(bst, min, max);
	return (min);
}

// https://github.com/ruv1nce/42-exam_intermediate/blob/master/convert_bst.c

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
    
    struct s_node *r = convert_bst(a);
    int i = 0;
    while (i++ < 15)
    {
        printf("%d\n", r->value);
        r = r->right;
    }
}