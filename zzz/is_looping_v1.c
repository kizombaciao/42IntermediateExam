
struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	if (!node)
		return 0;

	struct s_node *s = node;
	struct s_node *f = node->next;

	while (f->next && f->next->next)
	{
		if (s == f)
		{
			return 1;
		}
		s = s->next;
		f = f->next->next;
	}
	return 0;
}

