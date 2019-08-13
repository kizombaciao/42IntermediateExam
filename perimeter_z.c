#include <stdio.h>
#include <stdlib.h>

struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
};

void print_left(struct s_node *n)
{
    if (!n || (!n->left && !n->right))
        return ;
    printf(" %d", n->value);
    print_left(n->left);
}

void print_right(struct s_node *n)
{
    if (!n || (!n->left && !n->right))
        return ;
    print_right(n->right);
    printf(" %d", n->value);
}

void print_leafs(struct s_node *n)
{
    if (!n)
        return ;
    if (!n->left && !n->right)
    {
        printf(" %d", n->value);
    }
    else
    {
        print_leafs(n->left);
        print_leafs(n->right);
    }
}

void perimeter(struct s_node *root)
{
    if (!root)
        return ;
    printf("%d", root->value);
    print_left(root->left);
    if (root->left || root->right)
        print_leafs(root);
    print_right(root->right);
    printf("\n");
}


// A utility function to create a node 
struct s_node* newNode(int data) 
{ 
	struct s_node* temp = (struct s_node*)malloc(sizeof(struct s_node)); 

	temp->value = data; 
	temp->left = temp->right = NULL; 

	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
/*
	// Let us construct the tree given in the above diagram 
	struct s_node* root = newNode(92); 
	root->left = newNode(85); 
	root->left->left = newNode(79); 
	root->left->left->right = newNode(10); 
	root->left->left->right->left = newNode(39); 
	root->left->left->right->left = newNode(35); 
	root->left->left->right->left = newNode(96); 
	
	root->right = newNode(26);
	root->right->right = newNode(64);
	root->right->right->right = newNode(78);

	root->right->right->left = newNode(40);
	root->right->right->left->left = newNode(88);
	root->right->right->left->left->left = newNode(12);
	root->right->right->left->left->left->left = newNode(58);

	root->right->right->left->left->right = newNode(55);
	root->right->right->left->left->right->left = newNode(58);
	root->right->right->left->left->right->right = newNode(41);

	root->right->right->left->right = newNode(10);
	root->right->right->left->right->left = newNode(52);
	root->right->right->left->right->right = newNode(87);
	root->right->right->left->right->left->left = newNode(22);
	root->right->right->left->right->left->right = newNode(35);
	root->right->right->left->right->right = newNode(87);	
	root->right->right->left->right->right->right = newNode(31);

	root->right->right->right->left = newNode(2);
	root->right->right->right->right = newNode(85);
	root->right->right->right->right->right = newNode(51);

	root->right->right->right->left->left = newNode(33);
	root->right->right->right->left->right = newNode(11);
	root->right->right->right->left->left->right = newNode(55);
	root->right->right->right->left->right->left = newNode(99);
*/

	struct s_node* root = newNode(20); 
	root->left = newNode(8); 
	root->left->left = newNode(4); 
	root->left->right = newNode(12); 
	root->left->right->left = newNode(10); 
	root->left->right->right = newNode(14); 
	root->right = newNode(22); 
	root->right->right = newNode(25); 

	perimeter(root); 

	return 0; 
} 

// 20 8 4 10 14 25 22  code output

// 92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26  code output
// 92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26  correct answer output