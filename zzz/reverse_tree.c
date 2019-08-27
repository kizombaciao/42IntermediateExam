#include <stdio.h>
#include <stdlib.h>


struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *swap(struct s_node *r)
{
	struct s_node *p;

	p = r->left;
	r->left = r->right;
	r->right = p;
	return (r);
}

void reverse_tree(struct s_node *r)
{
//	struct s_node *p;

	if (!r)
		return;

	reverse_tree(r->left);
	reverse_tree(r->right);
	r = swap(r);
//	p = r->left;
//	r->left = r->right;
//	r->right = p;
}
//////////////////////////////////////////////////////////
void inOrder(struct s_node* node) 
{ 
	if (node == NULL) 
		return; 
	inOrder(node->left); 
	printf("%d ", node->value); 
	inOrder(node->right); 
} 
struct s_node* newNode(int data) 
{ 
	struct s_node* node = (struct s_node*)malloc(sizeof(struct s_node)); 
	node->value = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 
int main()
{
	struct s_node *r;
	r = newNode(1); 
	r->left	 = newNode(2); 
	r->right	 = newNode(3); 
	r->left->left = newNode(4); 
	r->left->right = newNode(5); 

	/* Print inorder traversal of the input tree */
	printf("Inorder traversal of the constructed"
			" tree is \n"); 
	inOrder(r); 

	/* Convert tree to its mirror */
	reverse_tree(r); 

	/* Print inorder traversal of the mirror tree */
	printf("\nInorder traversal of the mirror tree"
			" is \n"); 
	inOrder(r); 

	return 0; 
}
// swap pointers
// traverse left to a leaf, next find a node with two child