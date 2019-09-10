
struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int wt(struct s_node *r, int *res)
{
	if (!r)
		return 0;

	int le = wt(r->left);
	int ri = wt(r->right);

	res = max(res, 1 + le + ri);

	return (1 + max(le, ri));
}

int	width_tree(struct s_node *n)
{
	int res = 0;

	if (!n)
		return 0;

	wt(n, &res);

}