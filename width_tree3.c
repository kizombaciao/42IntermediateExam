struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static int	max_depth(struct s_node *node, int depth)
{
	int left = 0;
	int right = 0;

	if (!(node->left || node->right))
		return (depth);
	if (node->left)
		left = max_depth(node->left, depth + 1);
	if (node->right)
		right = max_depth(node->right, depth + 1);
	return ((left >= right) ? left : right);
}

static void	send_snake_down(struct s_node *node, int *ptr)
{
	int	left;
	int	right;

	left = (node->left) ? max_depth(node->left, 1) : 0;
	right = (node->right) ? max_depth(node->right, 1) : 0;
	if (left + right + 1 > *ptr)
		*ptr = left + right + 1;
	if (node->left)
		send_snake_down(node->left, ptr);
	if (node->right)
		send_snake_down(node->right, ptr);
}

int		width_tree(struct s_node *n)
{
	int	ptr = 0;
	if (!n)
		return (0);
	send_snake_down(n, &ptr);
	return (ptr);
}

https://github.com/motaylormo/42-Intermediate-Exam/blob/master/3-width_tree/mine/width_tree.c
