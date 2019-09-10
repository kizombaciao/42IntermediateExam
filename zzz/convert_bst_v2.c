

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
	};


void cb(struct s_node *r, struct s_node **prev)
{
	cb(r->left);

	if (*prev)
	{
		(*prev)->right = r;
		r->left = *prev;
	}
	*prev = r;

	cb(r->right);
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *prev;


	cb(bst, &prev);

	left
}

