// https://www.geeksforgeeks.org/maximum-consecutive-increasing-path-length-in-binary-tree/

// C++ Program to find Maximum Consecutive Path Length in a Binary Tree 
#include <stdio.h>
#include <stdlib.h>
// To represent a node of a Binary Tree 
struct Node 
{ 
	struct Node *left, *right; 
	int val; 
}; 
// Create a new Node and return its address 
struct Node *newNode(int val) 
{ 
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node)); 
	temp->val = val; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
// Returns the maximum consecutive Path Length 
int maxPathLenUtil(struct Node *root, int prev_val, int prev_len) 
{ 
	if (!root) 
		return prev_len; 
	// Get the value of Current Node 
	// The value of the current node will be 
	// prev Node for its left and right children 
	int cur_val = root->val; 
	// If current node has to be a part of the 
	// consecutive path then it should be 1 greater 
	// than the value of the previous node 
	if (cur_val == prev_val+1) 
	{ 

		// a) Find the length of the Left Path 
		// b) Find the length of the Right Path 
		// Return the maximum of Left path and Right path 
		return max(maxPathLenUtil(root->left, cur_val, prev_len+1), 
				maxPathLenUtil(root->right, cur_val, prev_len+1)); 
	} 
	// Find length of the maximum path under subtree rooted with this 
	// node (The path may or may not include this node) 
	int newPathLen = max(maxPathLenUtil(root->left, cur_val, 1), 
						maxPathLenUtil(root->right, cur_val, 1)); 
	// Take the maximum previous path and path under subtree rooted 
	// with this node. 
	return max(prev_len, newPathLen); 
} 
// A wrapper over maxPathLenUtil(). 
int maxConsecutivePathLength(struct Node *root) 
{ 
	if (root == NULL) 
		return 0; 
	// Else compute Maximum Consecutive Increasing Path 
	// Length using maxPathLenUtil. 
	return maxPathLenUtil(root, root->val - 1, 0); 
} 
int main() 
{ 
	struct Node *root;
	root = newNode(10); 
	root->left = newNode(11); 
	root->right = newNode(9); 
	root->left->left = newNode(13); 
	root->left->right = newNode(12); 
	root->right->left = newNode(13); 
	root->right->right = newNode(8); 
	//cout << "Maximum Consecutive Increasing Path Length is "
	//	<< maxConsecutivePathLength(root); 
	return 0; 
} 

// is this the correct geeks code that matches the question ???