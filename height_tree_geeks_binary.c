// https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
/* 
N-Ary tree can be traversed just like a normal tree. 
We just have to consider all childs of a given node 
and recursively call that function on every node.
*/

#include<stdio.h> 
#include<stdlib.h> 

// HEIGHT FOR A BINARY TREE
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* Compute the "maxDepth" of a tree -- the number of 
	nodes along the longest path from the root node 
	down to the farthest leaf node.*/
int maxDepth(struct node* node) 
{ 
	if (node == NULL) 
		return 0; // change to -1 if counting edges
	else
	{ 
		/* compute the depth of each subtree */
		int lDepth;
		int rDepth;

		lDepth = maxDepth(node->left); 
		rDepth = maxDepth(node->right); 

		return (1 + max(lDepth, rDepth));

		/* use the larger one */
	/*	
		if (lDepth > rDepth) 
			return(lDepth+1); 
		else return(rDepth+1); 
	*/
	} 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
								malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	
	return(node); 
} 
	
int main() 
{ 
	struct node *root = newNode(1); 

	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	
	printf("Height of tree is %d", maxDepth(root)); 
	
	getchar(); 
	return 0; 
} 

/*
Height of tree is 3
*/

