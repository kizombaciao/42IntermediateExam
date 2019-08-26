// NOT PASS!!!

//#include <stdlib.h> // del
#include <stdio.h>

struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

void pbl(struct s_node *r)
{
	if (r)
	{
		if (r->left)
		{
			printf(" %d", r->value);
			pbl(r->left);
		}
		else if (r->right)
		{
			printf(" %d", r->value);
			pbl(r->right);
		}
	}
}

void pl(struct s_node *r)
{
	if (r)
	{
		pl(r->left);
		pl(r->right);
		
		if (!(r->left) && !(r->right))
		{
			printf(" %d", r->value);
		}
	}
}

void pbr(struct s_node *r)
{
	if (r)
	{
		if (r->right)
		{
			pbr(r->right);
			printf(" %d", r->value);
		}
		else if (r->left)
		{
			pbr(r->left);
			printf(" %d", r->value);
		}
	}
}

void perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		pbl(root->left);
		pl(root->left);
		pl(root->right);
		pbl(root->right);
	}
	printf("\n");
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

int main()
{
	struct s_node *p;
	p = new(94);
	p = new(94);
    p->left = new(34);
    p->right = new(52);
	p->right->right = new(62);
    
	p->left->left = new(1);
    p->left->right = new(99);
    p->left->left->left = new(20);
    p->left->right->left = new(83);
    p->left->right->right = new(39);
    p->left->right->left->right = new(61);
    p->left->right->right->left = new(37);
    p->left->right->right->right = new(67);
    //p->left->right->right->right = new(77);

	perimeter(p);
}
*/
