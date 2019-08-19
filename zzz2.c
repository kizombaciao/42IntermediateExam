

struct s_node
{
	int v;
	struct s_node **n;
}

int h(struct s_node *r)
{
	int h = 0;
	int i = 0;
	int res;
	if (!r)
		return -1;
	else
		while (r->n[i])
		{
			res = 1 + h(r->n[i]);
			h = max(res, h);
			i++;
		}
	return h;
}