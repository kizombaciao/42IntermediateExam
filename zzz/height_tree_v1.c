
	struct s_node {
		int				value;
		struct s_node	**nodes;
	};

int height_tree(struct s_node *root)
{
	int i = 0;
	int res = 0;

	if (!root)
		return -1;

	while (root->nodes[i])
	{
		res = max(res, 1 + height_tree(root->nodes[i]));
		i++;
	}
	return (res);
}
