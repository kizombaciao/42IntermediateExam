

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void ls(struct s_node *r, int cl, int exp, int *res)
{
	if (!r)
		return ;

	if (exp == r->value)
		cl++;
	else
		cl = 1; // note!

	*res = max(*res, cl);
	ls(r->left, cl, r->value + 1, res);
	ls(r->right, cl, r->value + 1, res);
}

int	longest_sequence(struct s_node *node)
{
	if (!node)
		return 0;

	int res = 0;

	ls(node, 0, node->value, &res);
	return res;
}
