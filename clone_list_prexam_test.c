#include <stdio.h>
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
	p->next = NULL;
	p->other = NULL;
	return p;
}

int bb(struct s_node *n, struct s_node *h)
{
	int i = 0;
	while (h)
	{
		if (h == n)
		{
			return (i);
		}
		h = h->next;
		i++;
	}
	return 0;
}

struct s_node *aa(int idx, struct s_node *h)
{
	int i = 0;

	while (h)
	{
		if (idx == i)
		{
			return h;
		}
		h = h->next;
		i++;
	}
	return NULL;
}

struct s_node *clone_list(struct s_node *node)
{
	if (!node)
		return NULL;

	struct s_node *p = node;
	struct s_node *h = p;
	struct s_node *p2 = new(p->data);
	struct s_node *h2 = p2;
	
	p = p->next;
	//p2 = p2->next;
	while (p) // or p->next ???
	{
		p2->next = new(p->data);
		p = p->next;
		p2 = p2->next;
	}
	p = h;
	p2 = h2;
	while (p)
	{
		if (p->other)
			p2->other = aa(bb(p->other, h), h2);
		p = p->next;
		p2 = p2->next;
	}
	return h2;
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
