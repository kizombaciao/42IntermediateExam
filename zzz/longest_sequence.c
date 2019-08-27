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
	return (a > b ? a : b);
}
void ls2(struct s_node *r, int cur, int exp, int *res)
{
	if (!r)
		return;

	if (exp == r->value)
		cur++;
	else
		cur = 1;

	*res = max(cur, *res); // remember!!!

	ls2(r->left, cur, r->value + 1, res);
	ls2(r->right, cur, r->value + 1, res);

}

int ls(struct s_node *r)
{
	int res = 0;

	if (!r)
		return 0;

	ls2(r, 0, r->value, &res);
	return (res);
}

struct s_node* newNode(int data) 
{ 
	struct s_node *temp = (struct s_node *)malloc(sizeof(struct s_node)); 
	temp->value = data; 
	temp->left = NULL;
	temp->right = NULL; 
	return temp; 
} 

int main() 
{ 
	struct s_node* root;
	root = newNode(6); 
	root->right = newNode(9); 
	root->right->left = newNode(7); 
	root->right->right = newNode(10); 
	root->right->right->right = newNode(11); 
	printf("%d\n", ls(root)); 
	return 0; 
} 


/*
int main()
{
	struct s_node *r;
	int res;

	res = ls(r);

}
*/





// parent

