#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};





struct s_node *clone_list(struct s_node *node)
{
    if (!node)
        return NULL;

    struct s_node *p = node;
    struct s_node *h = node;
    struct s_node *p2 = new(node->data);
    struct s_node *h2 = node;
    p = p->next;

    while (p)
    {
        p2->next = new(p->data);
        p = p->next;
        p2 = p2->next;
    }

}
