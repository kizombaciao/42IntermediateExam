// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
/*
Method 3(Using difference of node counts)

Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list 
from the first node till d nodes 
so that from here onwards both the lists have equal no of nodes.
Then we can traverse 
both the lists in parallel till we come across a common node. 
(Note that getting a common node is done 
by comparing the address of the nodes)
Below image is a dry run of the above approach:
*/
// C program to get intersection point of two linked list 
#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 
/* Function to get the counts of node in a linked list */
int getCount(struct Node* head); 
/* function to get the intersection point of two linked 
lists head1 and head2 where head1 has d more nodes than 
head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2); 

///////////////////////////////////

/* Takes head pointer of the linked list and 
returns the count of nodes in the list */
int getCount(struct Node* head) 
{ 
	struct Node* current = head; 
	int count = 0; 
	while (current != NULL) { 
		count++; 
		current = current->next; 
	} 
	return count; 
} 
/* function to get the intersection point of two linked 
lists head1 and head2 where head1 has d more nodes than 
head2 */
int _getIntesectionNode(int d, struct Node* head1, struct Node* head2) 
{ 
	int i; 
	struct Node* current1 = head1; 
	struct Node* current2 = head2; 
	for (i = 0; i < d; i++) { 
		if (current1 == NULL) { 
			return -1; 
		} 
		current1 = current1->next; 
	} 
	while (current1 != NULL && current2 != NULL) { 
		if (current1 == current2) 
			return current1->data; 
		current1 = current1->next; 
		current2 = current2->next; 
	} 
	return -1; 
} 
/* function to get the intersection point of two linked 
lists head1 and head2 */
int getIntesectionNode(struct Node* head1, struct Node* head2) 
{ 
	int c1 = getCount(head1); 
	int c2 = getCount(head2); 
	int d; 

	if (c1 > c2) { 
		d = c1 - c2; 
		return _getIntesectionNode(d, head1, head2); 
	} 
	else { 
		d = c2 - c1; 
		return _getIntesectionNode(d, head2, head1); 
	} 
} 

/* IGNORE THE BELOW LINES OF CODE. THESE LINES 
ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main() 
{ 
	/* 
	Create two linked lists 

	1st 3->6->9->15->30 
	2nd 10->15->30 

	15 is the intersection point 
*/

	struct Node* newNode; 
	struct Node* head1 = (struct Node*)malloc(sizeof(struct Node)); 
	head1->data = 10; 

	struct Node* head2 = (struct Node*)malloc(sizeof(struct Node)); 
	head2->data = 3; 

	newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = 6; 
	head2->next = newNode; 

	newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = 9; 
	head2->next->next = newNode; 

	newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = 15; 
	head1->next = newNode; 
	head2->next->next->next = newNode; 

	newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = 30; 
	head1->next->next = newNode; 

	head1->next->next->next = NULL; 

	printf("\n The node of intersection is %d \n", 
		getIntesectionNode(head1, head2)); 

	getchar(); 
} 

/*
Method 1(Simply use two loops)
Use 2 nested for loops. 
The outer loop will be for each node of the 1st list 
and inner loop will be for 2nd list. In the inner loop, 
check if any of nodes of the 2nd list is 
same as the current node of the first linked list. 
The time complexity of this method will be O(M * N) 
where m and n are the numbers of nodes in two lists.
*/
