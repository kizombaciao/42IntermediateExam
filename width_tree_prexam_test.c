#include <stdio.h>
#include <stdlib.h>


#define max(a, b) (a > b) ? a : b

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int wl(struct s_node *r, int *res)
{
	int le;
	int ri;

	if (!r)
		return 0;

	le = wl(r->left, res);
	ri = wl(r->right, res);

	*res = max(*res, 1 + le + ri);

	return (1 + (max(le, ri)));
}

int	width_tree(struct s_node *n)
{
	int res = 0;

	if (!n)
		return 0;

	wl(n, &res);
	return res;
}

// 2 func
// int 2 args
// post order

struct s_node* newNode(int data) 
{ 
	struct s_node *node = (struct s_node *)malloc(sizeof(struct s_node)); 
	node->value = data; 
	node->left = node->right = NULL; 
	return (node); 
} 
int main() 
{ 
	struct s_node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	printf("Diameter is 4 == %d\n", width_tree(root)); 
	return 0; 
} 
