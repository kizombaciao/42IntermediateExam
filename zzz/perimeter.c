#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};
void pbl(struct s_node *r)
{
	if (!r)
		return;
	if (r->left)
	{
		printf("%d ", r->value);
		pbl(r->left);	
	}
	else if (r->right)
	{
		printf("%d ", r->value);
		pbl(r->right);
	}
}
void pl(struct s_node *r)
{
	if (!r)
		return;
	pl(r->left);
	if (r->left == NULL && r->right == NULL)
		printf("%d ", r->value);
	pl(r->right);

}
void pbr(struct s_node *r)
{
	if (!r)
		return;
	if (r->right)
	{
		pbr(r->right);	
		printf("%d ", r->value);
	}
	else if (r->left)
	{
		pbr(r->left);
		printf("%d ", r->value);
	}
}
void per(struct s_node *r)
{
	if (!r)
		return;
	printf("%d ", r->value);
	pbl(r->left);
	pl(r->left);
	pl(r->right);
	pbr(r->right);
}
////////////////////////////////////////////////
struct s_node* newNode(int data) 
{ 
	struct s_node* temp = (struct s_node*)malloc(sizeof(struct s_node)); 
	temp->value = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
int main() 
{ 
	struct s_node* root;
	root = newNode(20); 
	root->left = newNode(8); 
	root->left->left = newNode(4); 
	root->left->right = newNode(12); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(14); 
	root->right = newNode(22); 
	root->right->right = newNode(25); 
	per(root); 
}