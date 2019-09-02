// PASS!

#include <stdio.h> // del
#include <stdlib.h>

	struct s_node {
		int           data;
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
	return p;
}

int bb(struct s_node *o, struct s_node *h)
{
	int i = 0;
	while (h)
	{
		if(h == o) // BECAREFUL!!! NOT h->other
		{
			return i;
		}
		i++;
		h = h->next;
	}
	return 0;
}

struct s_node *aa(int idx, struct s_node *h1)
{
	int i = 0;

	while (i != idx)
	{
		h1 = h1->next;
		i++;
	}
	return (h1);
}

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *h;
	struct s_node *h1;
	struct s_node *p1;

	if (!node)
		return NULL;

	h = node;
	h1 = new(node->data);
	p1 = h1;
	node = node->next;
	while (node)
	{
		p1->next = new(node->data);
		node = node->next;
		p1 = p1->next;
	}
	node = h;
	p1 = h1;
	while (node)
	{
		if (node->other != NULL)
		{
			p1->other = aa(bb(node->other, h), h1);
		}
		node = node->next;
		p1 = p1->next;
	}
	return (h1);
}

void pr(struct s_node *r)
{
	if (!r)
		return;
	while (r)
	{
		printf("%d %d\n", r->data, (r->other) ? r->other->data : -1);
		r = r->next;
	}
	printf("\n");
}

int main()
{
	struct s_node *p;
	struct s_node *q;

	p = new(1);
	p->next = new(2);
	p->next->next = new(3);
	p->next->next->other = p;
	pr(p);

	q = clone_list(p);
	pr(p);
}