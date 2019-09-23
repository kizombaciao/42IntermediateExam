// pass!
//#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *new(int d)
{
    struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
    p->data = d;
    p->next = NULL;
    p->other = NULL;
	return p;
}

int aa(struct s_node *n, struct s_node *h)
{
	int i = 0;
	if (!n || !h)
		return 0;

	while (h)
	{
		if (h == n)
			return i;
		i++;
		h = h->next;
	}
	return 0;
}

struct s_node *bb(int idx, struct s_node *h2)
{
	int i = 0;
	if (!h2)
		return NULL;

	while (i != idx)
	{
		h2 = h2->next;
		i++;
	}
	return h2;
}

struct s_node *clone_list(struct s_node *node)
{
	if (!node)
		return NULL;

	struct s_node *p = node;
	struct s_node *h = node;
	struct s_node *p2 = new(p->data);
	struct s_node *h2 = p2;
	p = p->next;

	while (p)
	{
		p2->next = new(p->data);
		p = p->next;
		p2 = p2->next;
	}
	p = h;
	p2 = h2;

	while (p)
	{
		if (p->other != NULL)
		{
			p2->other = bb(aa(p->other, h), h2);
		}
		p = p->next;
		p2 = p2->next;
	}
	return h2;
}
////////////////////////////////////////////////
/*
void pr(struct s_node *r)
{
	while (r)
	{
		printf("%d\n", r->data);
		r = r->next;
	}
}

int main()
{
	struct s_node *h2;

	struct s_node *p = new(1);
	p->next = new(2);
	p->next->next = new(3);
	p->next->next->next = new(4);

	h2 = clone_list(p);
	pr(h2);

	p->next->next->next->other = p->next;
	p->next->next->other = p;
	p->other = p->next->next->next;
	p->next->other = p->next;

	while (p)
	{
		if (p->other != NULL)
			printf("111b  %d  %d\n", p->data, p->other->data);
		p = p->next;
	}
}
*/
