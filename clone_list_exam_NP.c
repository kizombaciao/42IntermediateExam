// NOT PASS!!!  
// WHY DID THIS NOT PASS ???

//#include <stdio.h> // del
#include <stdlib.h>

// normal
// other
// 3 functions

struct s_node {
	int data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *new(int d)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->data = d;
	p->next = NULL;
	p->other = NULL;
	return (p);
}

int g(struct s_node *n, struct s_node *h)
{
	int i = 0;

	while (h)
	{
		if (n == h)
		{
			return (i);
		}
		h = h->next;
		i++;
	}
	return (-1);
}

struct s_node *f(int id, struct s_node *h1)
{
	int i = 0;

	while (i < id)
	{
		h1 = h1->next;
		i++;
	}
	return (h1);
}

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *h;
	struct s_node *c1;
	struct s_node *h1;

	h = node;
	
	if (!node)
		return NULL;

	c1 = new(node->data);
	h1 = c1;

	node = node->next;
	c1 = c1->next;
	while (node)
	{
		c1 = new(node->data);
		node = node->next;
		c1 = c1->next;
	}
	node = h;
	c1 = h1;
	while (node && c1)
	{
		if (node->other != NULL)
		{
			c1->other = f(g(node, h), h1);
		}
		node = node->next;
		c1 = c1->next;
	}
	return (h1);
}
/*
int main()
{
	struct s_node *p;
	struct s_node *p1;

	p = new(1);
	p->next = new(2);
	p->next->next = new(3);
	//p->next->other = p;

	p1 = clone_list(p);

}
*/

