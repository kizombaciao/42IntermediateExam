// https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
// C program to convert a binary tree 
// to its mirror 
#include<stdio.h> 
#include<stdlib.h> 
/* A binary tree node has data, pointer 
to left child and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 
void mirror(struct Node* node) 
{
	struct Node* temp; 

	if (node == NULL) 
		return; 
	else
	{ 
		/* do the subtrees */
		// think of 'postorder traveral', 
		// we first travel to the leaf and start there
		mirror(node->left); 
		mirror(node->right); 

		// from the leaf upwards, we do the swaps
		/* swap the pointers in this node */
		temp	 = node->left; 
		node->left = node->right; 
		node->right = temp; 
	} 
} 
/////////////////////////////////////////////////
/* Helper function to print Inorder traversal.*/
void inOrder(struct Node* node) 
{ 
	if (node == NULL) 
		return; 
	inOrder(node->left); 
	printf("%d ", node->data); 
	inOrder(node->right); 
} 
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 
int main() 
{ 
	struct Node *root = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	/* Print inorder traversal of the input tree */
	printf("Inorder traversal of the constructed"
			" tree is \n"); 
	inOrder(root); 

	/* Convert tree to its mirror */
	mirror(root); 

	/* Print inorder traversal of the mirror tree */
	printf("\nInorder traversal of the mirror tree"
			" is \n"); 
	inOrder(root); 

	return 0; 
} 

/*
Inorder traversal of the constructed tree is 
4 2 5 1 3 
Inorder traversal of the mirror tree is 
3 1 5 2 4 
*/

/* Change a tree so that the roles of the left and 
	right pointers are swapped at every node. 

So the tree... 
	4 
	/ \ 
	2 5 
	/ \ 
1 3 

is changed to... 
	4 
	/ \ 
	5 2 
		/ \ 
	3 1 
*/