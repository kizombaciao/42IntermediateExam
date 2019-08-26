#include <stdio.h>
#include <stdlib.h>


struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *other;	
};

struct s_node *new(int d)
{
	struct s_node *t;

	t = (struct s_node *)malloc(sizeof(struct s_node));
	t->data = d;
	t->next = t->other = NULL;
	return (t);
}

int findidx(struct s_node *r, struct s_node *h)
{
	struct s_node *t;
	int i = 0;

	t = h;
	while (t)
	{
		if (t == r) // becareful!!!
		{
			return (i);
		}
		t = t->next;
		i++;
	}
	return (-1);
}

struct s_node *findptr(int idx, struct s_node *h1)
{
	struct s_node *t;
	int i = 0;

	while (i < idx)
	{
		i++;
		h1 = h1->next;
	}
	return (h1);

/*	
	while (t)
	{
		if (i == idx)
		{
			return (t);
		}
		t = t->next;
		i++;
	}
	return (NULL);
*/
}

struct s_node *cl(struct s_node *r)
{
	struct s_node *h;
	struct s_node *h1;
	struct s_node *r1;

	if (!r)
		return NULL;

	h = r;
	r1 = new(r->data);
	h1 = r1;

	r = r->next;
	//r1 = r1->next;
	while (r)
	{
		r1->next = new(r->data);
		r = r->next;
		r1 = r1->next;		
	}	

	r = h;
	r1 = h1;

	while (r)
	{
		if (r->other != NULL)
		{
			r1->other = findptr(findidx(r->other, h), h1);
		}
		r = r->next;
		r1 = r1->next;		
	}
	return (h1);
}

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
int		main(void)
{
	struct s_node *head;
	
	head = new(5);
	head->next = new(10);
	head->next->next = new(15);
	head->next->next->next = new(20);
	head->next->next->next->next = new(25);
	head->next->next->next->next->next = new(30);
	head->next->next->next->next->next->other = head->next->next->next->next; // 30 -> 25
	head->next->next->next->next->other = head; // 25 -> 5
	head->next->next->next->other = head->next; // 20 -> 10
	head->next->next->other = head->next->next; //15 -> 15

	printf("%%%%%%%%%%%%%%%%%%\n\n");
	print_list(head);
	printf("%%%%%%%%%%%%%%%%%%\n\n");
	print_list(cl(head));
}