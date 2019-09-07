//#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *new(int v)
{
    struct s_node *p;

    p = (struct s_node *)malloc(sizeof(struct s_node));
    p->data = v;
    p->next = NULL;
    p->other = NULL;
    return p;
}

int aa(struct s_node *r, struct s_node *h)
{
	int i = 0;

	while (h)
	{
		if (h == r)
		{
			return i;
		}
		h = h->next;
		i++;
	}
	return 0; // valid ???
}

struct s_node *bb(int idx, struct s_node *h1)
{
	int i = 0;

	while (i < idx)
	{
		h1 = h1->next;
		i++;
	}
	return h1;
}

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *p;
	struct s_node *h;
	struct s_node *p1;
	struct s_node *h1;

	if (!node)
		return NULL;

	p = node;
	h = p;

	p1 = new(p->data);
	h1 = p1;
	p = p->next;

	while (p)
	{
		p1->next = new(p->data); // must be p1->next !!!
		p = p->next;
		p1 = p1->next;
	}
	
	p = h;
	p1 = h1;
	while (p)
	{
		if (p->other != NULL)
		{
			p1->other = bb(aa(p->other, h), h1);
		}
		p = p->next;
		p1 = p1->next;		
	}
	return h1;
}

/*
//////////////////////
void pr(struct s_node *r)
{
	int num;

	while (r)
	{
		if (r->other)
		{
			num = r->other->data;
		}
		else
			num = 0;

		printf("%d  %d\n", r->data, num);
		r = r->next;
	}
	printf("\n");
}

int main()
{
    struct s_node *p;
    struct s_node *q;
    struct s_node *r = NULL;

    p = new(1);
    p->other = p;
	p->next = new(2);
    p->next->next = new(3);
    p->next->next->next = new(4);
    p->next->next->next->next = new(5);
	p->next->next->next->other = p->next;
    p->next->next->other = p->next->next->next->next;
	//pr(p);

	q = clone_list(p);
	pr(q);

	q = clone_list(r);
	pr(q);

//    p->next->next->next = p->next;

//    printf("%d\n", is_looping(p));
//    printf("%d\n", is_looping(p1));
}
*/

