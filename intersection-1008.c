//#include <stdio.h> // del

#include <stdlib.h>

struct s_node {
        void *content;
        struct s_node *next;
};

int llen(struct s_node *p)
{
	if (!p)
		return 0;

	int i = 0;

	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	if (!lst1 || !lst2)
		return NULL;

	int diff;

	int l1 = llen(lst1);
	int l2 = llen(lst2);

	if (l1 > l2)
	{
		diff = l1 - l2;
		for (int i = 0; i < diff; i++)
		{
			lst1 = lst1->next;
		}
	}
	else
	{
		diff = l2 - l1;
		for (int i = 0; i < diff; i++)
		{
			lst2 = lst2->next;
		}
	}
	while (lst1 && lst2)
	{
		if (lst1 == lst2)
		{
			return lst1;
		}
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return NULL;
}

// why above diff method works ????
////////////////////////////////////////////////////
/*
struct s_node *new(void *c)
{
	struct s_node *p;
	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->content = c;
	p->next = NULL;
	return p;
}

int main()
{
	struct s_node *p;
	struct s_node *q;

	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	int n5 = 5;
	
	void *p1 = &n1;
	void *p2 = &n2;
	void *p3 = &n3;
	void *p4 = &n4;
	void *p5 = &n5;


	q = new(p1);
	q->next = new(p2);
	q->next->next = new(p3);
	//q->next->next->next = new(p4);
	//q->next->next->next->next = p;

	p = new(p1);
	p->next = new(p2);
	p->next->next = new(p3);
	p->next->next->next = new(p4);
	p->next->next->next->next = q->next;


	printf("%p\n", intersection(p, q));


	p5 = &n4;


//	p->next->next->next->next->next = p->next->next->next->next;
//	printf("%d\n", is_looping(p));
}
*/


