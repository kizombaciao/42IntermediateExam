#include <stdio.h>
#include <stdlib.h>

//#define max(a, b) ((a > b) ? a : b)

int max(int a , int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};
int w(struct s_node *r, int *ans)
{
	int le;
	int ri;

	if (!r)
		return 0;

	le = w(r->left, ans);
	ri = w(r->right, ans);
	*ans = max(*ans, 1 + le + ri);
	return(1 + max(le, ri));
}
int width_tree(struct s_node *n)
{
	int ans = 0;
	int h;

	if (!n)
		return 0;

	h = w(n, &ans);	
	return (ans);
}
/////////////////////////////////////////////////////
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