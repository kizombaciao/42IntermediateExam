// TEST AGAIN!!!
// NEEDED TO INCLUDE NEWLINE AT THE END!!!

#include <stdlib.h>
#include <stdio.h>

	struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};

void pbl(struct s_node *r)
{
	if (!r)
		return ;
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
void pl(struct s_node *r)
{
	if (!r)
		return ;
	pl(r->left);
	if (r->left == NULL && r->right == NULL)
	{
		printf(" %d", r->value);
	}
	pl(r->right);
}
void pbr(struct s_node *r)
{
	if (!r)
		return ;
	if (r->right)
	{
		pbl(r->right);
		printf(" %d", r->value);
	}
	else if (r->left)
	{
		pbl(r->left);		
		printf(" %d", r->value);
	}
}
void perimeter(struct s_node *root)
{
	if (!root) // small mistake!!!
		return ;

	printf("%d", root->value);
	pbl(root->left);
	pl(root->left);
	pl(root->right);
	pbr(root->right);
	printf("\n");
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

int main()
{
	struct s_node *p;

	p = new(1);
	p->left = new(2);
	p->right = new(4);
	p->right->left = new(5);
	p->right->right = new(6);

	p->left->left = new(3);
	perimeter(p);
}
*/