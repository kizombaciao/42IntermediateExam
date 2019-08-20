// https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/

// C program to Implement a stack 
//using singly linked list 
#include <stdio.h>
#include <stdlib.h>

struct Node { 
	int data; 
	struct Node* link; 
}; 
struct Node* top; 

// Utility function to add an element data in the stack 
// insert at the beginning 
void push(int data) 
{ 
	// create new node temp and allocate memory 
	struct Node* temp; 
	temp = (struct Node *)malloc(sizeof(struct Node)); 

	// check if stack (heap) is full. Then inserting an element would 
	// lead to stack overflow 
	if (!temp) { 
		printf("\nHeap Overflow"); 
		exit(1); 
	} 

	// initialize data into temp data field 
	temp->data = data; 

	// put top pointer reference into temp link 
	temp->link = top; 

	// make temp as top of Stack 
	top = temp; 
} 

// Utility function to check if the stack is empty or not 
int isEmpty() 
{ 
	return top == NULL; 
} 
// Utility function to return top element in a stack 
int peek() 
{ 
	// check for empty stack 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 
// Utility function to pop top 
// element from the stack 
void pop() 
{ 
	struct Node* temp; 

	// check for stack underflow 
	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		// top assign into temp 
		temp = top; 

		// assign second node to top 
		top = top->link; 

		// destroy connection between first and second 
		temp->link = NULL; 

		// release memory of top node 
		free(temp); 
	} 
} 
// Function to print all the 
// elements of the stack 
void display() 
{ 
	struct Node* temp; 

	// check for stack underflow 
	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL) { 

			// print node data 
			printf("%d ", temp->data); 

			// assign temp link to temp 
			temp = temp->link; 
		} 
	} 
} 
int main() 
{ 
	// push the elements of stack 
	push(11); 
	push(22); 
	push(33); 
	push(44); 

	// display stack elements 
	display(); 
	// print top elementof stack 
	printf("\nTop element is %d\n", peek()); 

	// delete top elements of stack 
	pop(); 
	pop(); 

	// display stack elements 
	display(); 
	// print top elementof stack 
	printf("\nTop element is %d\n", peek()); 
	return 0; 
} 