// https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
/* C program for boundary traversal of a binary tree */
#include <stdio.h> 
#include <stdlib.h> 
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node { 
	int data; 
	struct node *left, *right; 
}; 
// A simple function to print leaf nodes of a binary tree 


// A function to print all right boundary nodes, except a leaf node 
// Print the nodes in BOTTOM UP manner 
void printBoundaryRight(struct node* root) 
{ 
	if (root) { 
		if (root->right) { 
			// to ensure bottom up order, first call for right 
			// subtree, then print this node 
			printBoundaryRight(root->right); 
			printf("%d ", root->data); // the print stmt can be before as well ? NO!
			// b/c you need to start printing from bottom right toward root, counter clock wise.
		} 
		else if (root->left) { 
			printBoundaryRight(root->left); 
			printf("%d ", root->data); 
		} 
		// do nothing if it is a leaf node, this way we avoid 
		// duplicates in output 
	} 
} 
void printLeaves(struct node* root) 
{ 
	if (root) { 
		printLeaves(root->left); 

		// Print it if it is a leaf node 
		if (!(root->left) && !(root->right)) 
			printf("%d ", root->data); 

		printLeaves(root->right); // NOTE!!! THIS NEEDS TO AT THE END !!!
	} 
} 
// A function to print all left boundary nodes, except a leaf node. 
// Print the nodes in TOP DOWN manner 
void printBoundaryLeft(struct node* root) 
{ 
	if (root) { 
		if (root->left) { 
			// to ensure top down order, print the node 
			// before calling itself for left subtree 
			printf("%d ", root->data); 
			printBoundaryLeft(root->left); 
		} 
		else if (root->right) { // note! need if also!
			printf("%d ", root->data); 
			printBoundaryLeft(root->right); 
		} 
		// do nothing if it is a leaf node, this way we avoid 
		// duplicates in output 
	} 
} 
// A function to do boundary traversal of a given binary tree 
void printBoundary(struct node* root) 
{ 
	if (root) { 
		printf("%d ", root->data); 

		// Print the left boundary in top-down manner. 
		printBoundaryLeft(root->left); 

		// Print all leaf nodes 
		printLeaves(root->left); 
		printLeaves(root->right); 

		// Print the right boundary in bottom-up manner 
		printBoundaryRight(root->right); 
	} 
} 
// A utility function to create a node 
struct node* newNode(int data) 
{ 
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
int main() 
{ 
	// Let us construct the tree given in the above diagram 
	struct node* root;
	root = newNode(20); 
	root->left = newNode(8); 
	root->left->left = newNode(4); 
	root->left->right = newNode(12); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(14); 
	root->right = newNode(22); 
	root->right->right = newNode(25); 
	printBoundary(root); 

/*
	struct node* root = newNode(92); 
	root->left = newNode(85); 
	root->left->left = newNode(79); 
	root->left->left->right = newNode(10); 
	root->left->left->right->left = newNode(39); 
	root->left->left->right->left = newNode(35); 
	root->left->left->right->left = newNode(96); 
	
	root->right = newNode(26);
	root->right->right = newNode(64);
	root->right->right->right = newNode(78);

	root->right->right->left = newNode(40);
	root->right->right->left->left = newNode(88);
	root->right->right->left->left->left = newNode(12);
	root->right->right->left->left->left->left = newNode(58);

	root->right->right->left->left->right = newNode(55);
	root->right->right->left->left->right->left = newNode(58);
	root->right->right->left->left->right->right = newNode(41);

	root->right->right->left->right = newNode(10);
	root->right->right->left->right->left = newNode(52);
	root->right->right->left->right->right = newNode(87);
	root->right->right->left->right->left->left = newNode(22);
	root->right->right->left->right->left->right = newNode(35);
	root->right->right->left->right->right = newNode(87);	
	root->right->right->left->right->right->right = newNode(31);

	root->right->right->right->left = newNode(2);
	root->right->right->right->right = newNode(85);
	root->right->right->right->right->right = newNode(51);

	root->right->right->right->left->left = newNode(33);
	root->right->right->right->left->right = newNode(11);
	root->right->right->right->left->left->right = newNode(55);
	root->right->right->right->left->right->left = newNode(99);
*/

	return 0; 
} 

// 92 85 79 10 96 58 58 41 22 35 31 55 99 51 85 78 64 26  code output
// 92 85 79    96 58 58 41 22 35 31 55 99 51 85 78 64 26  correct answer output

/*
We break the problem in 3 parts:
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.

We need to take care of one thing that nodes are not printed again. 
e.g. The left most node is also the leaf node of the tree.
*/

// BELOW IS ADDITIONAL MATERIAL:
// Print all leaf nodes of a binary tree from right to left
// https://www.geeksforgeeks.org/print-all-leaf-nodes-of-a-binary-tree-from-right-to-left/
