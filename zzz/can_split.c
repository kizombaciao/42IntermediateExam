#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};
int len(struct s_node *r)
{
	int i;

	if (!r)
		return 0;
	i = 1 + len(r->left) + len(r->right);
	return (i);
}

int cs(struct s_node *r, int n, int *res)
{
	int c;

	if (!r)
		return 0;

	c = 1 + cs(r->left, n, res) + cs(r->right, n, res);

	if (c == n - c)
		*res = 1;

	return (c);
}

int can_split(struct s_node *r)
{
	int n;
	int res = 0;

	if (!r)
		return 0;

	n = len(r);
	
	cs(r, n, &res);
	return (res);
}
///////////////////////////////////////////
struct s_node* newNode(int x) 
{ 
	struct s_node* temp = (struct s_node *)malloc(sizeof(struct s_node)); 
	temp->value = x; 
	temp->left = temp->right = NULL; 
	return temp; 
}
int main() 
{ 

	struct s_node* root;
	root = newNode(5); 
	root->left = newNode(1); 
	root->right = newNode(6); 
	root->left->left = newNode(3); 
	root->right->left = newNode(7); 
	root->right->right = newNode(4); 

	can_split(root) ? printf("YES") : printf("NO"); 

	return 0; 
} 

// n - c trick!