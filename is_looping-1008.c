//#include <stdio.h> // del

#include <stdlib.h>

struct s_node {
    int value;
    struct s_node *next;
};

int is_looping(struct s_node *node)
{
	struct s_node *s = node;
	struct s_node *f = node->next;

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


/////////////////////////////

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

	p = new(1);
	p->next = new(2);
	p->next->next = new(3);
	p->next->next->next = new(4);
	p->next->next->next->next = new(5);

	p->next->next->next->next->next = p->next->next->next->next;


	printf("%d\n", is_looping(p));
}
*/