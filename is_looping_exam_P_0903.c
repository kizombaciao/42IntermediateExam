//#include <stdio.h>
#include <stdlib.h>

struct s_node {
    int value;
    struct s_node *next;
};

int is_looping(struct s_node *node)
{
    struct s_node *s;
    struct s_node *f;

	if (!node)
		return 0;

	s = node;
	f = node->next;

	while (f->next && f->next->next)
	{
		if (f == s)
		{
			return 1;
		}
		s = s->next;
		f = f->next->next;
	}
	return 0;
}
/*
struct s_node *new(int v)
{
    struct s_node *p;

    p = (struct s_node *)malloc(sizeof(struct s_node));
    p->value = v;
    p->next = NULL;
    return p;
}

int main()
{
    struct s_node *p;
    struct s_node *p1 = NULL;

    p = new(1);
    p->next = new(2);
    p->next->next = new(3);
    p->next->next->next = p->next;

	printf("%d\n", is_looping(p));
	printf("%d\n", is_looping(p1));
}
*/
