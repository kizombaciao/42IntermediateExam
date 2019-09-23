
	struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};

struct s_node *clone_list(struct s_node *node)
{
    struct s_node *p = node;
    struct s_node *h = node;
    struct s_node *p2 = new(p->data);
    struct s_node *h2 = p2;
    p = p->next;

    while (p)
    {
        p2->next = new(p->data);

    }


}
