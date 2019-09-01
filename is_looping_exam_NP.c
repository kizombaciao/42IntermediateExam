//#include <stdio.h> // del
//#include <stdlib.h> // del

struct s_node
{
	int value;
	struct s_node *next;
};

int is_looping(struct s_node *node)
{
	if (!node)
		return -1;

	while (node)
	{
		if (node->value == -1)
		{
			return (1);
		}
		node->value = -1;
		node = node->next;
	}
	return (0);
}
/*
struct s_node *new(int v)
{
	struct s_node *p;

	p = (struct s_node *)malloc(sizeof(struct s_node));
	p->value = v;
	p->next = NULL;
	return (p);
}

int main()
{
	struct s_node *p;

	p = new(1);
	p->next = new(2);
	p->next->next = new(3);
	p->next->next->next = new(4);

	printf("%d\n", is_looping(p));
}
*/
