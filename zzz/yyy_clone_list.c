#include <stdlib.h>


	struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};

struct s_node *new(int data)
{
    struct s_node *p = (struct s_node *)malloc(sizeof(struct s_node));
    p->data = data;
    p->next = NULL;
    p->other = NULL;
}

int bb(struct s_node *n, struct s_node *h)
{
    int i = 0;
    while (h)
    {
        if (h = n)
            return i;
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
        if (i == idx)
            return h;
        i++;
        h = h->next;
    }
    return NULL;
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
        if (p->other)
        {
            p2->other = aa(bb(p->other, h), h2);
        }
        p = p->next;
        p2 = p2->next;        
    }
    return h2;
}
