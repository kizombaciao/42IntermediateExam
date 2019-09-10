

struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
	};


struct aa(int idx, struct *h2)
{
	while (i != idx)
	{
		//h2
		i++;
	}
	return h2;
}

int bb(struct s_node *n, struct *h)
{
	int i = 0;

	while (h)
	{
		if (h == n)
		{
			return i
		}
		i++;
		h = h->next;
	}
	return 0;
}

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *p = node;
	struct s_node *h = p;
	struct s_node *p2 = new(p->data);
	struct s_node *h2 = p2;
	p = p->next;

	while (p)
	{
		p2->next = new(p->data);
		//p
		//p2
	}
	p = h;
	p2 = h2;

	while (p)
	{
		if (p->other != NULL)
		{
			p2->other = aa(bb(p->other, h), h2);
		}
		// p
		// p2
	}
	return h2;
}