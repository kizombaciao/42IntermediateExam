// Passed Moulinette on 2019.05.19
#include <stdlib.h>
#include <stdio.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node	*create_node(int data)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->data = data;
	new->next = NULL;
	new->other = NULL;
	return (new);
}

// to find the index location within old list of where 'other' points at
// we loop through haystack to find 'other'
int	find_node_index(struct s_node *needle, struct s_node *haystack)
{
	int i = 0;
	while (haystack)
	{
		if (needle == haystack) // BECAREFUL!!! matching node to other!
			return (i);				// returns index location
		++i;
		haystack = haystack->next;
	}
	return (-1);
}

// to find the address corresponding to the index within the new list
struct s_node	*get_node_by_index(int index, struct s_node *haystack)
{
	int i = 0;
	while (i < index)
	{
		++i;
		haystack = haystack->next;
	}
	return (haystack); 
}

struct s_node	*clone_list(struct s_node *node)
{
	struct s_node *head;
	struct s_node *new_cur;
	struct s_node *new_head;

	if (node == NULL)
		return (NULL);
	head = node;
	new_cur = create_node(head->data);
	new_head = new_cur;
	
	// traverse the old list to get its data for the new list
	node = node->next;
	while (node)
	{
		// NOTE!!! need to be new_cur->next here to avoid segdefault!
		new_cur->next = create_node(node->data);
		new_cur = new_cur->next; 	
		node = node->next; 			
	}
	node = head; 					
	new_cur = new_head; 			
	while (node)
	{
		if (node->other != NULL)
			new_cur->other = get_node_by_index(find_node_index(node->other, head), new_head);
		new_cur = new_cur->next;	
		node = node->next;			
	}
	return (new_head);
}
//////////////////////////////////////////////
void	print_list(struct s_node *head)
{
	while (head)
	{
		printf("Node: %p\nData: %d\nOther: %p; ", head, head->data, head->other);
		if (head->other)
			printf("%d", head->other->data);
		printf("\n---\n");
		head = head->next;
	}
}


int main()
{
	struct s_node *p;
	struct s_node *q;

	p = create_node(1);
	p->next = create_node(2);
	p->next->next = create_node(3);
	p->next->next->other = p;
	print_list(p);

	q = clone_list(p);
	print_list(p);

}
/*/
int		main(void)
{
	struct s_node *head;
	
	head = create_node(5);
	head->next = create_node(10);
	head->next->next = create_node(15);
	head->next->next->next = create_node(20);
	head->next->next->next->next = create_node(25);
	head->next->next->next->next->next = create_node(30);
	head->next->next->next->next->next->other = head->next->next->next->next; // 30 -> 25
	head->next->next->next->next->other = head; // 25 -> 5
	head->next->next->next->other = head->next; // 20 -> 10
	head->next->next->other = head->next->next; //15 -> 15

	printf("%%%%%%%%%%%%%%%%%%\n\n");
	print_list(head);
	printf("%%%%%%%%%%%%%%%%%%\n\n");
	print_list(clone_list(head));
}
*/