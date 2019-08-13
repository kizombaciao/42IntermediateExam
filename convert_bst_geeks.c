// C++ Program to convert a Binary Tree 
// to a Circular Doubly Linked List 
//#include<iostream> 
//using namespace std; 
#include <stdio.h>
#include <stdlib.h>

// To represents a s_node of a Binary Tree 
struct s_node 
{ 
	struct s_node *left;
	struct s_node *right; 
	int data; 
}; 

// A function that appends rightList at the end 
// of leftList. 
struct s_node *concatenate(struct s_node *leftList, struct s_node *rightList) 
{ 
	// If either of the list is empty 
	// then return the other list 
	if (leftList == NULL) 
		return rightList; 
	if (rightList == NULL) 
		return leftList; 

	// Store the last s_node of left List 
	struct s_node *leftLast = leftList->left; 

	// Store the last s_node of right List 
	struct s_node *rightLast = rightList->left; 

	// Connect the last s_node of Left List 
	// with the first s_node of the right List 
	leftLast->right = rightList; 
	rightList->left = leftLast; 

	// Left of first s_node points to 
	// the last s_node in the list 
	leftList->left = rightLast; 

	// Right of last s_node refers to the first 
	// s_node of the List 
	rightLast->right = leftList; 

	return leftList; 
} 

// Function converts a tree to a circular Linked List 
// and then returns the head of the Linked List 
struct s_node *bTreeToCList(struct s_node *root) 
{ 
	if (root == NULL) 
		return NULL; 

	// Recursively convert left and right subtrees 
	struct s_node *left = bTreeToCList(root->left); 
	struct s_node *right = bTreeToCList(root->right); 

	// Make a circular linked list of single s_node 
	// (or root). To do so, make the right and 
	// left pointers of this s_node point to itself 
	root->left = root->right = root; 

	// Step 1 (concatenate the left list with the list 
	//		 with single s_node, i.e., current s_node) 
	// Step 2 (concatenate the returned list with the 
	//		 right List) 
	return concatenate(concatenate(left, root), right); 
} 

// Display Circular Link List 
void displayCList(struct s_node *head) 
{ 
	printf("Circular Linked List is :\n"); 
	struct s_node *itr = head; 
	do
	{ 
		printf("%d  ", itr->data); 
		itr = itr->right; 
	} while (head!=itr); 
	printf("\n"); 
} 


// Create a new s_node and return its address 
struct s_node *news_node(int data) 
{ 
	struct s_node *temp = (struct s_node *)malloc(sizeof(struct s_node)); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver Program to test above function 
int main() 
{ 
	struct s_node *root = news_node(10); 
	root->left = news_node(12); 
	root->right = news_node(15); 
	root->left->left = news_node(25); 
	root->left->right = news_node(30); 
	root->right->left = news_node(36); 

	struct s_node *head = bTreeToCList(root); 
    
	displayCList(head); 

	return 0; 
} 

// 25 12 30 10 36 15  Code Output
// https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/
