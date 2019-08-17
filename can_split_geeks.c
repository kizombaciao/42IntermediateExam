// NOT EFFICIENT ENOUGH
// IGNORE THIS ONE

// C++ program to check if there exist an edge whose 
// removal creates two trees of same size 
//#include<bits/stdc++.h> 
//using namespace std; 
#include <stdlib.h>
#include <stdio.h>

struct Node 
{ 
	int data; 
	struct Node *left; 
	struct Node *right; 
}; 

// utility function to create a new node 
struct Node* newNode(int x) 
{ 
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node)); 
	temp->data = x; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

// To calculate size of tree with given root 
int count(struct Node *root) 
{ 
	if (root == NULL) 
		return 0; 
	return count(root->left) + count(root->right) + 1; 
} 

// This function returns true if there is an edge 
// whose removal can divide the tree in two halves 
// n is size of tree 
int checkRec(struct Node *root, int n) 
{ 
	// Base cases 
	if (root == NULL) 
	return 0; 

	// Check for root 
	if (count(root) == n - count(root)) 
		return 1; 

	// Check for rest of the nodes 
	return checkRec(root->left, n) || 
		checkRec(root->right, n); 
} 

// This function mainly uses checkRec() 
int check(struct Node *root) 
{ 
	// Count total nodes in given tree 
	int n = count(root); 

	// Now recursively check all nodes 
	return checkRec(root, n); 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(5); 
	root->left = newNode(1); 
	root->right = newNode(6); 
	root->left->left = newNode(3); 
	root->right->left = newNode(7); 
	root->right->right = newNode(4); 

	check(root)? printf("YES") : printf("NO"); 

	return 0; 
} 

/*
First count number of nodes in whole tree. 
Let count of all nodes be n. 
Now traverse tree and for every node, 
find size of subtree rooted with this node. 
Let the subtree size be s. If n-s is equal to s, 
then return true, else false.

Time complexity of above solution is 
O(n2) where n is number of nodes in given Binary Tree.
*/
// https://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/
