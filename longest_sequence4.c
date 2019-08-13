struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

#define UPDATE_MAX(x, max)	if (x > max) max = x
#define CONSEC(a, b)	(a + 1 == b)// "nodes with consecutive values in increasing order."

static void	send_snake_down(struct s_node *n, int *max, int seq)
{
	if (n)
	{
		seq++;
		UPDATE_MAX(seq, *max);
		if (n->left)
		{
			send_snake_down(n->left, max,
					(CONSEC(n->value, n->left->value)) ? seq : 0);
		}
		if (n->right)
		{
			send_snake_down(n->right, max,
					(CONSEC(n->value, n->right->value)) ? seq : 0);
		}
	}
}

int		longest_sequence(struct s_node *node)
{
	int	max = 0;
	send_snake_down(node, &max, 0);
	return (max);
}

https://github.com/motaylormo/42-Intermediate-Exam

