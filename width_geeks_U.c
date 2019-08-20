// https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/
/*
In this post a new simple O(n) method is discussed. 
Diameter of a tree can be calculated by only using the height function, 
because the diameter of a tree is nothing but maximum value of 
(left_height + right_height + 1) for each node. 
So we need to calculate this value (left_height + right_height + 1) 
for each node and update the result. Time complexity – O(n)
*/
// Simple C++ program to find diameter of a binary tree. 
#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -2147483648
/* Tree node structure used in the program */
struct Node { 
	int data; 
	struct Node *left, *right; 
}; 
/* Function to find height of a tree */
int height(struct Node *root, int *ans) 
{ 
	int left_height;
	int right_height;

	if (root == NULL) 
		return 0; 
	left_height = height(root->left, ans); // left sub_tree
	right_height = height(root->right, ans); // right sub_tree

	// update the answer, because diameter of a 
	// tree is nothing but maximum value of 
	// (left_height + right_height + 1) for each node 
	*ans = max(ans, 1 + left_height + right_height); 
	return 1 + max(left_height, right_height); 
} 
/* Computes the diameter of binary tree with given root. */
int diameter(struct Node* root) 
{ 
	if (root == NULL) 
		return 0; 
	int ans = INT_MIN; // This will store the final answer 
	int height_of_tree = height(root, &ans); 
	return ans; 
} 
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node *)malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 
int main() 
{ 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	printf("Diameter is %d\n", diameter(root)); 
	return 0; 
} 
// INT_MIN
// https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
/*
Most of the times, in competitive programming, 
there is a need to assign the variable, 
the maximum or minimum value that data type can hold, 
but remembering such a large and precise number comes out to be a difficult job. 
Therefore, C++ has certain macros to represent these numbers, 
so that these can be directly assigned to the variable 
without actually typing the whole number.
INT_MAX is a macro 
that specifies that an integer variable cannot store any value beyond this limit.
INT_MIN specifies that an integer variable cannot store any value below this limit.
*/