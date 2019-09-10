


struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int tlen(struct s_node *r)
{
	if (!r)
		return 0;

	return (1 + tlen(r->left) + tlen(r->right));
}

int cs(struct s_node *r, int n, int *res)
{
	int le;
	int ri;

	le = cs(r->left);
	ri = cs(r->right);

	c = 1 + le + ri;

	if (c == n - c)
		*res = 1;

	return (c);
}

int	can_split(struct s_node *n)
{
	int res = 0;

	if (!n)
		return 0;

	int num = tlen(n);

	cs(n, num, &res)

}