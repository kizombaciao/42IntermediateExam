#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int ww(struct s_node *r, int *res)
{
	int le, ri;

	if (!r)
		return 0;

	le = ww(r->left, res);
	ri = ww(r->right, res);
	*res = max(*res, 1 + le + ri);
	return (1 + max(le, ri));
}

int	width_tree(struct s_node *n)
{
	int res = 0;
	int cl;

	if (!n)
		return 0;

	cl = ww(n, &res);

	return res;
}
// width_tree is similar to height_tree structure
// postorder
// 2 func
// int, 2 args


/*
struct s_node* newNode(int data) 
{ 
	struct s_node* node = (struct s_node *)malloc(sizeof(struct s_node)); 
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
	printf("Diameter is %d\n", width_tree(root)); 
	return 0; 
} 
*/