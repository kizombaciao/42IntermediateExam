// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
// using a hash table to keep track of what nodes that have been visited already
// if new node matches any in the hash table, then that means loop

// C++ program to detect loop in a linked list 
//#include <bits/stdc++.h> 
//using namespace std; 
#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node **head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node;
	new_node = (struct Node *)malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// Returns true if there is a loop in linked list 
// else returns false. 
int detectLoop(struct Node* h) 
{ 
	unordered_set<Node*> s; 
	while (h != NULL) { 
		// If this node is already present 
		// in hashmap it means there is a cycle 
		// (Because you we encountering the 
		// node for the second time). 
		if (s.find(h) != s.end()) 
			return 1; 

		// If we are seeing the node for 
		// the first time, insert it in hash 
		s.insert(h); 

		h = h->next; 
	} 

	return 0; 
} 

/* Drier program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Create a loop for testing */
	head->next->next->next->next = head; 

	if (detectLoop(head)) 
		printf("Loop found"); 
	else
		printf("No Loop"); 

	return 0; 
} 