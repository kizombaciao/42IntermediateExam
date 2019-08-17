// C++ program to check if there exist an edge whose 
// removal creates two trees of same size 
//#include<bits/stdc++.h> 
//using namespace std; 

#include <stdio.h>
#include <stdlib.h>

struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// utility function to create a new node 
struct Node* newNode(int x) 
{ 
	struct Node* temp = (struct Node *)malloc(sizeof(struct Node)); 
	temp->data = x; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

// To calculate size of tree with given root 
int count(struct Node* root) 
{ 
	if (root==NULL) 
		return 0; 
	return count(root->left) + count(root->right) + 1; 
} 

// This function returns size of tree rooted with given 
// root. It also set "res" as true if there is an edge 
// whose removal divides tree in two halves. 
// n is size of tree 
int checkRec(struct Node* root, int n, int *res) 
{ 
	// Base case 
	if (root == NULL) 
	return 0; 

	// Compute sizes of left and right children 
	int c = checkRec(root->left, n, res) + 1 + 
			checkRec(root->right, n, res); 

	// If required property is true for current node 
	// set "res" as true 
	if (c == n - c) 
		*res = 1; 

	// Return size 
	return c; 
} 

// This function mainly uses checkRec() 
int check(struct Node *root) 
{ 
	// Count total nodes in given tree 
	int n = count(root); 

	// Initialize result and recursively check all nodes 
	int res = 0; 
	checkRec(root, n, &res); 

	return res; 
} 
int main() 
{ 
	struct Node* root = newNode(5); 
	root->left = newNode(1); 
	root->right = newNode(6); 
	root->left->left = newNode(3); 
	root->right->left = newNode(7); 
	root->right->right = newNode(4); 

	check(root) ? printf("YES") : printf("NO"); 

	return 0; 
} 
/*
Method 2 (Efficient)
We can find the solution in O(n) time. 
The idea is to traverse tree in bottom up manner 
and while traversing keep updating size 
and keep checking if there is a node that follows the required property.
*/