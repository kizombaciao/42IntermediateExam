// https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/

// C/C++ program to find longest consecutive 
// sequence in binary tree 
//#include <bits/stdc++.h> 
//using namespace std; 
#include <stdlib.h>
#include <stdio.h>

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node *left;
	struct Node *right; 
}; 

// A utility function to create a node 
struct Node* newNode(int data) 
{ 
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 
	temp->data = data; 
	temp->left = NULL;
	temp->right = NULL; 
	return temp; 
} 

int max(int a, int b)
{
	return (a > b ? a : b);
}

// Utility method to return length of longest 
// consecutive sequence of tree 
void longestConsecutiveUtil(struct Node* root, int curLength, int expected, int *res) 
{ 
	if (root == NULL) 
		return; 

	// if root data has one more than its parent 
	// then increase current length 
	if (root->data == expected) 
		curLength++; 
	else
		curLength = 1; // why even have an 'else' ??? necessary to reset to 1 ???

	// update the maximum by current length 
	*res = max(*res, curLength); 

	// recursively call left and right subtree with 
	// expected value 1 more than root data 
	longestConsecutiveUtil(root->left, curLength, 
						root->data + 1, res); 
	longestConsecutiveUtil(root->right, curLength, 
						root->data + 1, res); 
} 

// method returns length of longest consecutive 
// sequence rooted at node root 
int longestConsecutive(struct Node* root) 
{ 
	if (root == NULL) 
		return 0; 
	int res = 0; 
	// call utility method with current length 0 
    // root->data represent parent value ???
	longestConsecutiveUtil(root, 0, root->data, &res); 
	return res; 
} 

// Driver code to test above methods 
int main() 
{ 
	struct Node* root = newNode(6); 
	root->right = newNode(9); 
	root->right->left = newNode(7); 
	root->right->right = newNode(10); 
	root->right->right->right = newNode(11); 
/*
	struct Node* root = newNode(1); 
	root->left = newNode(2); 	
	root->right = newNode(2); 
	root->left->left = newNode(3); 	
	root->left->left->right = newNode(4); 	
	
	root->right->left = newNode(3); 
	root->right->right = newNode(3); 
	//root->right->right->left = newNode(4); 
*/
	printf("%d\n", longestConsecutive(root)); 
	return 0; 
} 

/*
We can solve above problem recursively. 
At each node we need information of its parent node, 
if current node has value one more than its parent node 
then it makes a consecutive path, 
at each node we will compare node’s value with its parent value 
and update the longest consecutive path accordingly.
For getting the value of parent node, 
we will pass the (node_value + 1) as an argument to the recursive method 
and compare the node value with this argument value, 
if satisfies, 
update the current length of consecutive path 
otherwise reinitialize current path length by 1.
*/

